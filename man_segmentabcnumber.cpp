#include "man_segmentabcnumber.h"

man_segmentabcnumber::man_segmentabcnumber()
{

}

QString man_segmentabcnumber::readMan()
{
    data="-s[a,b,c]*d DEMO -s[2,4,5]*2 取第2，4，5项的和的值，再*2用于实现选择性相加";
    return data;

}
