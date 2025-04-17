#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    if (money+diff>=0)
    {
        money += diff;
        ui->lcdNumber->display(money);
        ui->pbCoffee->setEnabled(money>=100);
        ui->pbTea->setEnabled(money>=150);
        ui->pbCoke->setEnabled(money>=200);
        ui->pbReset->setEnabled(money>0);
    }
    else
    {
        QMessageBox mb;
        mb.warning(this,"Money Issue!","You need more money!");
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    if(money>0)
    {
        int num500Won, num100Won, num50Won, num10Won, remainder;
        num500Won = money / 500;
        remainder = money % 500;
        num100Won = remainder / 100;
        remainder %= 100;
        num50Won = remainder / 50;
        remainder %= 50;
        num10Won = remainder / 10;
        remainder %= 10;
        QString msgcontents = QString("500won: %1coins\n100won: %2coins\n50won: %3coins\n10won: %4 coins").arg(num500Won).arg(num100Won).arg(num50Won).arg(num10Won);
        mb.information(this,"Change",msgcontents);
        money = 0;
        changeMoney(0);
    }
    else
    {
        mb.warning(this,"Money Issue!","Cannot Reset!");
    }
}

