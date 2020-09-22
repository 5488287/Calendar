#ifndef TODOLIST_H
#define TODOLIST_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"todoItem.h"
#include"markList.h"
struct TodoList:public MarkList
{
//private:
//    QVector<TodoItem> vec_plan;
//public:
//bool isEmpty();
//size_t lenth();
//const MarkTimeItem & get(int i);
//void set(const MarkTimeItem &mti);
};

#endif // TODOLIST_H
