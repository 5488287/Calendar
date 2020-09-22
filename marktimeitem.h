#ifndef MARK_H
#define MARK_H
#include"texthead.h"
#include"otherhead.h"
class MarkTimeItem
{
public:
    const QString& getContent();
    const QDateTime&getStartTime();
    const QDateTime&getEndTime();
    void setContent(const QString&);
    void setStartTime(const QDateTime&);
     void setEndTime(const QDateTime&);
private:
    QString content;
    QDateTime time_start;
    QDateTime time_end;


};

#endif // MARK_H
