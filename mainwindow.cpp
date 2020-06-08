#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

double firstNum;
bool UserIsTypingSecondNumber=false;
double mem;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_puta,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_podijeljeno,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_korijen,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_kvadrat,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_sinus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_cosinus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_tangens,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_cotan,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_log,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_kub,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_mem,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_mclear,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_puta->setCheckable(true);
    ui->pushButton_podijeljeno->setCheckable(true);
    ui->pushButton_korijen->setCheckable(true);
    ui->pushButton_kvadrat->setCheckable(true);
    ui->pushButton_sinus->setCheckable(true);
    ui->pushButton_cosinus->setCheckable(true);
    ui->pushButton_tangens->setCheckable(true);
    ui->pushButton_cotan->setCheckable(true);
    ui->pushButton_log->setCheckable(true);
    ui->pushButton_kub->setCheckable(true);
    ui->pushButton_mem->setCheckable(true);
    ui->pushButton_mclear->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton*button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||
            ui->pushButton_puta->isChecked() || ui->pushButton_podijeljeno->isChecked()|| ui->pushButton_korijen->isChecked()|| ui->pushButton_kvadrat->isChecked()||
            ui->pushButton_sinus->isChecked()|| ui->pushButton_cosinus->isChecked()|| ui->pushButton_tangens->isChecked()|| ui->pushButton_cotan->isChecked()||
        ui->pushButton_log->isChecked()|| ui->pushButton_kub->isChecked())&&(!UserIsTypingSecondNumber))
    {
        labelNumber=button->text().toDouble();
        UserIsTypingSecondNumber=true;
        newLabel=QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains('.')&& button->text()=="0")
        {
           newLabel=ui->label->text()+button->text();
        }
        else
        {
            labelNumber=(ui->label->text()+button->text()).toDouble();
            newLabel=QString::number(labelNumber,'g',15);
        }
    }
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_tocka_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton*button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if(button->text()=="+/-")
    {
        labelNumber=ui->label->text().toDouble();
        labelNumber=labelNumber*-1;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text()=="%")
    {
        labelNumber=ui->label->text().toDouble();
        labelNumber=labelNumber*0.01;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_puta->setChecked(false);
    ui->pushButton_podijeljeno->setChecked(false);
    ui->pushButton_korijen->setChecked(false);
    ui->pushButton_kvadrat->setChecked(false);
    ui->pushButton_sinus->setChecked(false);
    ui->pushButton_cosinus->setChecked(false);
    ui->pushButton_tangens->setChecked(false);
    ui->pushButton_cotan->setChecked(false);
    ui->pushButton_log->setChecked(false);
    ui->pushButton_kub->setChecked(false);
    ui->pushButton_mem->setChecked(false);
    ui->pushButton_mclear->setChecked(false);

    UserIsTypingSecondNumber=false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_jednako_released()
{
    double labelNumber,secondNum;
    QString newLabel;
    double pi=3.14159265;
    secondNum =ui->label ->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {
        labelNumber=firstNum + secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber=firstNum - secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_puta->isChecked())
    {
        labelNumber=firstNum * secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_puta->setChecked(false);
    }
    else if(ui->pushButton_podijeljeno->isChecked())
    {
        labelNumber=firstNum / secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_podijeljeno->setChecked(false);
    }
    else if(ui->pushButton_korijen->isChecked())
    {
        labelNumber=sqrt(firstNum);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_korijen->setChecked(false);
    }
    else if(ui->pushButton_kvadrat->isChecked())
    {
        labelNumber=pow(firstNum,2);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_kvadrat->setChecked(false);
    }
    else if(ui->pushButton_sinus->isChecked())
    {
        labelNumber=sin(firstNum*pi/180);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_sinus->setChecked(false);
    }
    else if(ui->pushButton_cosinus->isChecked())
    {
        labelNumber=cos(firstNum*pi/180);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_cosinus->setChecked(false);
    }
    else if(ui->pushButton_tangens->isChecked())
    {
        labelNumber=tan(firstNum*pi/180);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_tangens->setChecked(false);
    }
    else if(ui->pushButton_cotan->isChecked())
    {
        labelNumber=1/tan(firstNum*pi/180);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_cotan->setChecked(false);
    }
    else if(ui->pushButton_log->isChecked())
    {
        labelNumber=log(firstNum);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_log->setChecked(false);
    }
    else if(ui->pushButton_kub->isChecked())
    {
        labelNumber=pow(firstNum,3);
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_kub->setChecked(false);
    }
    else if(ui->pushButton_mem->isChecked())
    {
        mem=firstNum;
        ui->label->setText(0);
        ui->pushButton_mem->setChecked(false);
    }
    else if(ui->pushButton_mclear->isChecked())
    {
        mem=0;
        ui->label->setText(0);
        ui->pushButton_mem->setChecked(false);
    }
    UserIsTypingSecondNumber=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton*button=(QPushButton*)sender();
    firstNum=ui->label->text().toDouble();
}
