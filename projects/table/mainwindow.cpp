#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../include/skiptable.h"
#include <QMessageBox>
#include <string.h>
#include <fstream>
#include <iostream>
#include <QFileDialog>
#include <QTime>

using namespace std;

SkipTable<string> *stable;
int RowCount = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Key" << "Data");
    ui->tableWidget->setColumnWidth(0, 110);  
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(1);
    stable = new SkipTable<string>(ui->sbLvl->value(),ui->sbProb->value());
}

MainWindow::~MainWindow()
{
    if (!stable)
        delete stable;
    delete ui;
}

void MainWindow::on_sbLvl_editingFinished()
{
    ui->btnClear->click();
    stable = new SkipTable<string>(ui->sbLvl->value(),ui->sbProb->value());
}

void MainWindow::on_sbProb_editingFinished()
{
    ui->btnClear->click();
    stable = new SkipTable<string>(ui->sbLvl->value(),ui->sbProb->value());
}

void MainWindow::on_btnAdd_clicked()
{
    QString Qkey = ui->edtAddKey->text();
    QString Qdata = ui->edtAddData->text();
    int new_key;
    bool ok;
    new_key = Qkey.toInt(&ok);
    if(ok == false){
        QMessageBox::warning(this,"Error","Can not translate key to int.");
        return;
    }
    string *new_data = new string(Qdata.toStdString());
    if (stable->find(new_key) == 0){
        stable->insert(new_key,new_data);
        int position = stable->getPosition(new_key);
        if( position >= 0){
            QTableWidgetItem *iKey = new QTableWidgetItem(Qkey);
            QTableWidgetItem *iData = new QTableWidgetItem(Qdata);
            ui->tableWidget->insertRow(position);
            ui->tableWidget->setItem(position, 0,iKey);
            ui->tableWidget->setItem(position, 1,iData);
        }
    }
    else{
        QMessageBox::warning(this,"Error","This key is already exist.");
    }
    return;
}

void MainWindow::on_btnLoad_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("The current table will be erased.");
    msgBox.setInformativeText("Download new table?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Cancel)
        return;
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open file"),
                tr(""),
                "All files (*.*)");
    ifstream fin(filename.toStdString().c_str(),ios_base::in);
    if (!fin.is_open()){
        QMessageBox::warning(this,"Error","Can not open this file.");
        return;
    }
    ui->btnClear->click();
    int key;
    string *pdata, data;

    while (fin >> key){
        getline(fin, data);
        pdata = new string(data);
        stable->insert(key,pdata);
    }
    fin.close();
    stable->reset();
    ui->tableWidget->setRowCount(stable->getSize());
    int ins_row = 0;
    while(stable->getCurrent() != 0){
        QTableWidgetItem *iKey = new QTableWidgetItem(
                    QString::number(stable->getCurrent()->key));
        QTableWidgetItem *iData = new QTableWidgetItem(
                    QString::fromStdString(*(stable->getCurrent()->data)));
        ui->tableWidget->setItem(ins_row, 0,iKey);
        ui->tableWidget->setItem(ins_row++, 1,iData);
        stable->goNext();
    }
}

void MainWindow::on_btnClear_clicked()
{
    if(!stable)
        delete stable;
    stable = new SkipTable<string>(ui->sbLvl->value(),ui->sbProb->value());
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->edtAddData->setText("");
    ui->edtAddKey->setText("");
    ui->edtDFKey->setText("");
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Key" << "Data");
}

void MainWindow::on_btnSave_clicked()
{
    if(stable->isEmpty()){
        QMessageBox::warning(this,"Error","No iformation to save.");
        return;
    }
    QString filename = QFileDialog::getSaveFileName(
                this,
                tr("Save file"),
                tr(""),
                "All files (*.*)");
    ofstream fout(filename.toStdString().c_str(),ios_base::out | ios_base::trunc);
    if (!fout.is_open()){
        QMessageBox::warning(this,"Error","Can not create file with this name.");
        return;
    }
    stable->reset();
    while(stable->getCurrent() != 0){
        fout << stable->getCurrent()->key << " ";
        fout << *(stable->getCurrent()->data) << "\n";
        stable->goNext();
    }
    fout.close();
    QMessageBox::information(this,"Success","Information was successfully saved.");
}

void MainWindow::on_btnFind_clicked()
{
    QString Qkey = ui->edtDFKey->text();
    int key;
    bool ok;
    key = Qkey.toInt(&ok);
    if(ok == false){
        QMessageBox::warning(this,"Error","Can not translate key to int.");
        return;
    }

    QTime myTimer;
    myTimer.start();
    int position = stable->getPosition(key);
    if (position == -1){
        QMessageBox::warning(this,"Failed","Element with this key is not in table.");
        return;
    }
    int nMilliseconds = myTimer.elapsed();
    ui->tableWidget->selectRow(position);
    QMessageBox::information(this,"Success","Element finded in "+QString::number(position+1)+" position.\n"+
                             "Search time : "+QString::number(nMilliseconds)+" ms.");
}

void MainWindow::on_sbLvl_valueChanged(int arg1)
{
    if(!stable){
        QMessageBox::warning(this,"Error","You should clear table before change.");
        return;
    }
    ui->btnClear->click();
    stable = new SkipTable<string>(arg1,ui->sbProb->value());
}

void MainWindow::on_sbProb_valueChanged(double arg1)
{
    if(!stable){
        QMessageBox::warning(this,"Error","You should clear table before change.");
        return;
    }
    ui->btnClear->click();
    stable = new SkipTable<string>(ui->sbLvl->value(),arg1);
}

void MainWindow::on_btnDelete_clicked()
{
    QString Qkey = ui->edtDFKey->text();
    int key;
    bool ok;
    key = Qkey.toInt(&ok);
    if(ok == false){
        QMessageBox::warning(this,"Error","Can not translate key to int.");
        return;
    }
    int position = stable->getPosition(key);
    if (position == -1){
        QMessageBox::warning(this,"Error","Element with this key is not in table.");
        return;
    }
    stable->remove(key);
    ui->tableWidget->removeRow(position);
    QMessageBox::information(this,"Success","Element with this key successfully removed.");

}

void MainWindow::on_sbLvl_valueChanged(const QString &arg1)
{
    if(!stable){
        QMessageBox::warning(this,"Error","You should clear table before change.");
        return;
    }
    ui->btnClear->click();
    stable = new SkipTable<string>(arg1.toInt(),ui->sbProb->value());
}

void MainWindow::on_pushButton_clicked()
{
    QWidget *qw = new QWidget();
    QTableWidget *w = new QTableWidget(qw);
    qw->setFixedSize(200,450);
    w->setFixedSize(199,449);
    qw->setWindowFlags(Qt::Popup);

    w->setColumnCount(2);
    w->setColumnWidth(0, 100);
    w->setEditTriggers(QTableWidget::NoEditTriggers);
    w->horizontalHeader()->setStretchLastSection(1);
    w->setHorizontalHeaderLabels(QStringList() << "Key" << "Level");
    w->setRowCount(stable->getSize());
    int ins_row = 0;
    stable->reset();
    while(stable->getCurrent() != 0){
        QTableWidgetItem *iKey = new QTableWidgetItem(
                    QString::number(stable->getCurrent()->key));
        QTableWidgetItem *iLvl = new QTableWidgetItem(
                    QString::number(stable->getCurrent()->level));
        w->setItem(ins_row, 0,iKey);
        w->setItem(ins_row++, 1,iLvl);
        stable->goNext();
    }

    qw->show();
    qw->move(2, 250);
}
