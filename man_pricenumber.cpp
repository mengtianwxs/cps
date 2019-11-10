#include "man_pricenumber.h"

man_pricenumber::man_pricenumber()
{

}

QString man_pricenumber::readMan()
{
    data="-price*number DEMO -100*10 排价格*10次 用于相同价的重复计算";
    return data;


}
