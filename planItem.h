#ifndef PLANITEM_H
#define PLANITEM_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"texthead.h"
#include"otherhead.h"
#include"marktimeitem.h"
struct PlanItem:public MarkTimeItem
{
private:
//    QString content;
//    QDateTime time_start;
//    QDateTime time_end;
    QDateTime dateStart;
    QDateTime dateEnd;
public:

    void setDateStart(const QDateTime&time);
    void setDateEnd(const QDateTime&time);
    const QDateTime&getStartDate();
    const QDateTime&getEndDate();
//    PlanItem();
//    PlanItem(const PlanItem&pi);
//    const PlanItem&operator=(const PlanItem&pi);

//    const QDateTime& getStartTime();
//    const QDateTime & getEndTime();
//    const QString& getContent();
//    void setContent(const QString &);
//    void setStartTime(const QDateTime &);
//    void setEndTime(const QDateTime &);
};

#endif // PLANITEM_H
