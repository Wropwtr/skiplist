#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sbLvl_editingFinished();

    void on_sbProb_editingFinished();

    void on_btnAdd_clicked();

    void on_btnLoad_clicked();

    void on_btnClear_clicked();

    void on_btnSave_clicked();

    void on_btnFind_clicked();

    void on_sbLvl_valueChanged(const QString &arg1);

    void on_sbLvl_valueChanged(int arg1);

    void on_sbProb_valueChanged(double arg1);

    void on_btnDelete_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
