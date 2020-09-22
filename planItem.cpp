#include"planItem.h"
//PlanItem::PlanItem()
//{
//    str="";
//    time_start=QDateTime::currentDateTime();
//    time_end=time_start;
//}

//const PlanItem& PlanItem::operator=(const PlanItem &pi)
//{
//    str=pi.str;
//    time_start=pi.time_start;
//    time_end=pi.time_end;
//    return *this;
//}

//PlanItem::PlanItem(const PlanItem&pi)
//{
//    *this=pi;
//}

//PlanItem::~PlanItem()
//{
//    str="";
//    time_start=QDateTime(QDate());
//    time_end=time_start;
//}

//const QDateTime& PlanItem::getStartTime()
//{
//    return time_start;
//}
//const QDateTime& PlanItem::getEndTime()
//{
//    return time_end;
//}

//const QString&PlanItem::getContent()
//{
//    return content;
//}

//void PlanItem::setContent(const QString &c)
//{
//    content=c;
//}

//void PlanItem::setStartTime(const QDateTime &time)
//{
//    time_start=time;
//}

//void PlanItem::setEndTime(const QDateTime &time)
//{
//    time_end=time;
//}

void PlanItem::setDateStart(const QDateTime &time)
{
    dateStart=time;
}

void PlanItem::setDateEnd(const QDateTime &time)
{
    dateEnd=time;
}

const QDateTime&PlanItem::getStartDate()
{
    return dateStart;
}
const QDateTime&PlanItem::getEndDate()
{
    return dateEnd;
}


