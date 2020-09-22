#ifndef CALENDARITEM_H
#define CALENDARITEM_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"widgethead.h"
#include"otherhead.h"
#include"info.h"
#include<QTextDocument>
class CalendarItem: public QLabel
{
    Q_OBJECT
public:
    CalendarItem();
    CalendarItem(const CalendarItem& ci);
    const CalendarItem&operator=(const CalendarItem&ci);
    ~CalendarItem();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setActiveDate(const QDateTime&time);
    void setPlanEnable(bool flag);
    void setTodoEnable(bool flag);
    void setFestivalEnable(bool flag);
    void setSpecialEnable(bool flag);

    void changePlanAttribute();
    void changeTodoAttribute();
    void changeFestivalAttribute();
    void changeSpecialAttribute();
    void changeWeatherBG(const QString&weather);
    void changeDisplayAttribute();

    bool isMonthDay();

   const QString& getDay();
   const QString& getMonth();
   const QString& getYear();
   const QDateTime& getActivateDate();



signals:
    void planSet(bool);
    void todoSet(bool);
    void festivalSet(bool);
    void specialSet(bool);
private:

    enum Weather {SUNNY,RAINNY,CLOUDY,SNOWY,WINDY,OVERCAST};
    QLabel *lab_tag;
    QLabel *lab_day;
    QLabel *lab_weather;

    QLabel * lab_festival;
    QLabel * lab_special;
    QLabel * lab_plan;
    QLabel * lab_todo;

    QTextDocument *text_detail;

    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QVBoxLayout *v_tagLayout;

    QImage img_weather;
    QString weatherPath;
    QString strDay;
    QString strMonth;
    QString strYear;
    QDateTime calendarDate;



private:
Info info;
private :
    bool flag_plan;
    bool flag_todo;
    bool flag_festival;
    bool flag_special;
    bool flag_display;



protected:
    void mousePressEvent(QMouseEvent *ev) override;

};

#endif // CALENDARITEM_H
