#include "man_getmergenumber.h"

man_getmergenumber::man_getmergenumber()
{

}

QString man_getmergenumber::readMan()
{
    data="+ma DEMO +ma(a取1,2,3)把变量ma的值从系统中取出，并加入新的计算，查看ma变量按F6";
    return data;

}
