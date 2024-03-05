#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"
#include "QString"

void MainWindow::Button_Input_Click(string s){
    ui->Input->setText(ui->Input->text()+QString::fromStdString(s));

}
void MainWindow::Button_Equal_Click(){
    string input = ui->Input->text().toStdString();
    double result = Calkulator.Run(input);
    string strResult = to_string(result);
    ui->Output->setText(QString::fromStdString(strResult));
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->b0, &QPushButton::clicked, this, [this](){this->Button_Input_Click("0");});
    connect(ui->b1, &QPushButton::clicked, this, [this](){this->Button_Input_Click("1");});
    connect(ui->b2, &QPushButton::clicked, this, [this](){this->Button_Input_Click("2");});
    connect(ui->b3, &QPushButton::clicked, this, [this](){this->Button_Input_Click("3");});
    connect(ui->b4, &QPushButton::clicked, this, [this](){this->Button_Input_Click("4");});
    connect(ui->b5, &QPushButton::clicked, this, [this](){this->Button_Input_Click("5");});
    connect(ui->b6, &QPushButton::clicked, this, [this](){this->Button_Input_Click("6");});
    connect(ui->b7, &QPushButton::clicked, this, [this](){this->Button_Input_Click("7");});
    connect(ui->b8, &QPushButton::clicked, this, [this](){this->Button_Input_Click("8");});
    connect(ui->b9, &QPushButton::clicked, this, [this](){this->Button_Input_Click("9");});
    connect(ui->bA, &QPushButton::clicked, this, [this](){this->Button_Input_Click("A");});
    connect(ui->bB, &QPushButton::clicked, this, [this](){this->Button_Input_Click("B");});
    connect(ui->bC, &QPushButton::clicked, this, [this](){this->Button_Input_Click("C");});
    connect(ui->bD, &QPushButton::clicked, this, [this](){this->Button_Input_Click("D");});
    connect(ui->bE, &QPushButton::clicked, this, [this](){this->Button_Input_Click("E");});
    connect(ui->bF, &QPushButton::clicked, this, [this](){this->Button_Input_Click("F");});
    connect(ui->b_pov, &QPushButton::clicked, this, [this](){this->Button_Input_Click("^");});
    connect(ui->b_minius, &QPushButton::clicked, this, [this](){this->Button_Input_Click("-");});
    connect(ui->b_plus, &QPushButton::clicked, this, [this](){this->Button_Input_Click("+");});
    connect(ui->b_equal, &QPushButton::clicked, this, [this](){this->Button_Equal_Click();});
    connect(ui->b_divide, &QPushButton::clicked, this, [this](){this->Button_Input_Click("/");});
    connect(ui->b_multiply, &QPushButton::clicked, this, [this](){this->Button_Input_Click("X");});
    connect(ui->b_point, &QPushButton::clicked, this, [this](){this->Button_Input_Click(".");});
    connect(ui->b_braket_close, &QPushButton::clicked, this, [this](){this->Button_Input_Click(")");});
    connect(ui->b_braket_open, &QPushButton::clicked, this, [this](){this->Button_Input_Click("(");});
}


MainWindow::~MainWindow()
{
    delete ui;

}
