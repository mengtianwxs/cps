#include "man_mergenumber.h"

man_mergenumber::man_mergenumber()
{

}

QString man_mergenumber::readMan()
{
    data="-ma DEMO -m2 把最后2项的值求和，并自动存入变量ma中（a取1,2,3 etc）";
    return data;

}
