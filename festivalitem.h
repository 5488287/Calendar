#ifndef FESTIVALITEM_H
#define FESTIVALITEM_H
#include"texthead.h"
#include"otherhead.h"
#include"marktimeitem.h"
struct FestivalItem:public MarkTimeItem
{
private:
    QString content;
    QDateTime timeStart;
    QDateTime timeEnd;
public:
    const QDateTime& getStartTime();
    const QDateTime & getEndTime();
    const QString& getContent();
    void setContent(const QString &);
    void setStartTime(const QDateTime &);
    void setEndTime(const QDateTime &);
};

#endif // FESTIVALITEM_H
