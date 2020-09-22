#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"calendarItem.h"
#include"otherhead.h"
#include"weather.h"
#include <QMainWindow>
#include <QDomDocument>
#include"network.h"
#include"info.h"
class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    Calendar(QWidget *parent = nullptr);
   // ~Calendar();

public slots:
void slot_setNextMonth();
void slot_setNextYear();
void slot_setPriorMonth();
void slot_setPriorYear();
void slot_setCalendarWeather();
private:
    enum Week {SUNDAY,MONDAY,TUESDAY,WEDNSDAY,THURSDAY,FRIDAY,SATURDAY};
    enum Month{JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
    enum WeekdayRange{SUNFIRST,MONFIRST};


    QPushButton *btn_nextMonth;
    QPushButton *btn_priorMonth;

    QPushButton *btn_nextYear;
    QPushButton *btn_priorYear;

    QLineEdit   *edt_year;
    QLineEdit   *edt_month;

    QWidget *widget_center;
    QWidget *widget_grid;
    QWidget *widget_control;

    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QGridLayout *glayout;

    QVector<QLabel*> vec_weekDay;
    QVector<QLabel*> vec_weekNum;


private:

    QString currentYear;
    QString currentMonth;
    QString currentDay;
    QDateTime currentDateTime;

    QString activeYear;
    QString activeMonth;



    Week firstDayOfActiveMonth;




    QVector<CalendarItem*> calendarList;

    Network *network;
    Weather weather;
    QMap<QDateTime,Info> mapCalendarInfo;
    QString xmlPath;


private:
    int  getWeekNumStart();
    void setWeekNum(int start,int num);
    void setWeekDayArrange(WeekdayRange wr,QVector<QLabel*>& vec_weekNum);
    void setCurrentCalendarPage();
    Week convertWeekDay2Week(QString&str);
    bool isLeapYear(QString year);
    int getMonthDays(const QString&year,const QString&month);
    void readCalendarXML(QString&path);
    void saveCalendar2XML(QString&path);
    void newRecord(const QDateTime&,const Info&info);
    CalendarItem* find(QDateTime&date);


};
#endif // MAINWINDOW_H
