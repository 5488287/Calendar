#ifndef MARKLIST_H
#define MARKLIST_H
#include<QVector>
#include"marktimeitem.h"
class MarkList
{

public:
     bool isEmpty();
     size_t lenth();
     const MarkTimeItem& get(int i);
     void set(MarkTimeItem mti);
     friend MarkList& operator<<(MarkList&mkl,MarkTimeItem&mki)
     {
         mkl.set(mki);
         return mkl;
     }
private:
     QVector<MarkTimeItem*> vec_item;

};

#endif // MARKLIST_H
