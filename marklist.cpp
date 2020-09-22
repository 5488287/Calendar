#include"markList.h"
const MarkTimeItem& MarkList::get(int i)
{
    return *(vec_item.at(i));
}

void MarkList::set(MarkTimeItem mti)
{
    vec_item.push_back(&mti);
}

bool MarkList::isEmpty()
{
    if(vec_item.isEmpty())
        return true;
    else
        return false;
}

size_t MarkList::lenth()
{
    return vec_item.length();
}
