#include"marktimeitem.h"
const QDateTime& MarkTimeItem::getStartTime()
{
    return time_start;
}
const QDateTime& MarkTimeItem::getEndTime()
{
    return time_end;
}

const QString&MarkTimeItem::getContent()
{
    return content;
}

void MarkTimeItem::setContent(const QString &c)
{
    content=c;
}

void MarkTimeItem::setStartTime(const QDateTime &time)
{
    time_start=time;
}

void MarkTimeItem::setEndTime(const QDateTime &time)
{
    time_end=time;
}
