#ifndef TIME_SELECT_H
#define TIME_SELECT_H

#include <QWidget>

namespace Ui {
class Time_Select;
}

class Time_Select : public QWidget
{
    Q_OBJECT

public:
    explicit Time_Select(QWidget *parent = 0);
    ~Time_Select();

private slots:
    void on_MinuteSlider_valueChanged(int value);

    void on_HourSlider_valueChanged(int value);

    void on_ConfirmTime_clicked();

private:
    Ui::Time_Select *ui;
};

#endif // TIME_SELECT_H
