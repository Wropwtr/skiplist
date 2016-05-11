/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *btnAdd;
    QLineEdit *edtAddData;
    QLineEdit *edtAddKey;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnFind;
    QLabel *label_3;
    QLineEdit *edtDFKey;
    QPushButton *btnDelete;
    QPushButton *btnLoad;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QSpinBox *sbLvl;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *sbProb;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(679, 405);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(2, 1, 451, 351));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(511, 180, 161, 24));
        edtAddData = new QLineEdit(centralWidget);
        edtAddData->setObjectName(QStringLiteral("edtAddData"));
        edtAddData->setGeometry(QRect(510, 150, 161, 23));
        edtAddData->setMaxLength(100);
        edtAddKey = new QLineEdit(centralWidget);
        edtAddKey->setObjectName(QStringLiteral("edtAddKey"));
        edtAddKey->setGeometry(QRect(510, 120, 161, 23));
        edtAddKey->setMaxLength(15);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 123, 51, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 150, 51, 16));
        label_2->setFont(font);
        btnFind = new QPushButton(centralWidget);
        btnFind->setObjectName(QStringLiteral("btnFind"));
        btnFind->setGeometry(QRect(601, 249, 71, 24));
        QFont font1;
        font1.setPointSize(8);
        btnFind->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(468, 220, 51, 16));
        label_3->setFont(font);
        edtDFKey = new QLineEdit(centralWidget);
        edtDFKey->setObjectName(QStringLiteral("edtDFKey"));
        edtDFKey->setGeometry(QRect(510, 220, 161, 23));
        edtDFKey->setMaxLength(15);
        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(509, 249, 71, 24));
        btnDelete->setFont(font1);
        btnLoad = new QPushButton(centralWidget);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setGeometry(QRect(509, 289, 71, 24));
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(601, 289, 71, 24));
        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(511, 326, 161, 24));
        btnClear->setFont(font1);
        sbLvl = new QSpinBox(centralWidget);
        sbLvl->setObjectName(QStringLiteral("sbLvl"));
        sbLvl->setGeometry(QRect(590, 8, 81, 22));
        sbLvl->setMaximum(30);
        sbLvl->setValue(4);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(470, 10, 111, 20));
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(470, 40, 61, 20));
        label_7->setFont(font);
        sbProb = new QDoubleSpinBox(centralWidget);
        sbProb->setObjectName(QStringLiteral("sbProb"));
        sbProb->setGeometry(QRect(590, 40, 81, 22));
        sbProb->setMaximum(1);
        sbProb->setSingleStep(0.05);
        sbProb->setValue(0.5);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(589, 70, 81, 24));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 679, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Database", 0));
        btnAdd->setText(QApplication::translate("MainWindow", "Add node", 0));
        edtAddData->setText(QString());
        edtAddKey->setText(QApplication::translate("MainWindow", "0", 0));
        label->setText(QApplication::translate("MainWindow", "Key", 0));
        label_2->setText(QApplication::translate("MainWindow", "Data", 0));
        btnFind->setText(QApplication::translate("MainWindow", "Find node", 0));
        label_3->setText(QApplication::translate("MainWindow", "Key", 0));
        edtDFKey->setText(QApplication::translate("MainWindow", "0", 0));
        btnDelete->setText(QApplication::translate("MainWindow", "Delete node", 0));
        btnLoad->setText(QApplication::translate("MainWindow", "Load table", 0));
        btnSave->setText(QApplication::translate("MainWindow", "Save table", 0));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        label_6->setText(QApplication::translate("MainWindow", "Maximum node level", 0));
        label_7->setText(QApplication::translate("MainWindow", "Probability", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Show levels", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
