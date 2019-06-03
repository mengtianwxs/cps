#ifndef MODE_PRICE_H
#define MODE_PRICE_H

#include "mode_base.h"



class mode_price : public mode_base
{
public:
    mode_price();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_PRICE_H
