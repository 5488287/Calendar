#ifndef INFO_H
#define INFO_H
#include"markList.h"
#include"planList.h"
#include"todoList.h"
#include"speciallist.h"
#include"festivallist.h"
#include"weather.h"

class Info
{
private:
    PlanList pl;
    TodoList tl;
    SpecialList sl;
    FestivalList fl;
    Weather weather;
public:
    const PlanList& getPlanList()
    {
        return pl;
    }
    const TodoList& getTodoList()
    {
        return tl;
    }
    const SpecialList&getSpecialList()
    {
        return sl;
    }
    const FestivalList& getFestivalList()
    {
        return fl;
    }

    void setPlanList(const PlanList&pl)
    {
        this->pl=pl;
    }
    void setTodoList(const TodoList&tl)
    {
        this->tl=tl;
    }
    void setSpecialList(const SpecialList&sl)
    {
        this->sl=sl;
    }
    void setFestivalList(const FestivalList&fl)
    {
        this->fl=fl;
    }

    const Weather& getWeather()
    {
        return weather;
    }
    void setWeather(const Weather&w)
    {
        weather=w;
    }

    bool isEmpty()
    {
     if(pl.isEmpty()&&tl.isEmpty()&&fl.isEmpty()&&sl.isEmpty()&&weather.isEmpty())
         return true;
     else
         return false;
    }
};

#endif // INFO_H
