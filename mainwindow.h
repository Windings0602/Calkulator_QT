#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
#include "calk.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void Button_Input_Click(string s);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Button_Equal_Click();

private:
    Ui::MainWindow *ui;
    Calk Calkulator;
};

#endif // MAINWINDOW_H
