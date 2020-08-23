#include "time_select.h"
#include "ui_time_select.h"

#include "home_screen.h"

#include "opencv2/core.hpp"


Time_Select::Time_Select(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Time_Select)
{
    ui->setupUi(this);
}

Time_Select::~Time_Select()
{
    delete ui;
}



void Time_Select::on_MinuteSlider_valueChanged(int Minutes)
{
    ui->MinuteDisplay->display(Minutes);
}

void Time_Select::on_HourSlider_valueChanged(int Hours)
{
    ui->HourDisplay->display(Hours);
}

void Time_Select::on_ConfirmTime_clicked()
{
    Home_Screen HomeScreen;
    HomeScreen.setModal(true);
    HomeScreen.exec();
}
