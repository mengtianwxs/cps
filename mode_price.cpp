#include "mode_price.h"

mode_price::mode_price()
{

}

void mode_price::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{
    initMap(map);
    QString txt=sl_jiahao.at(0);
    QString price=txt.mid(1,-1);

    sl_content.append("- "+price);
    sl_status.append("- PRICE MODE | 分支排");
    sl_content.append("= "+price+"\n");
    list.append(price);

}
