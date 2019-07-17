#ifndef MODE_PRICEMT_H
#define MODE_PRICEMT_H

#include "mode_base.h"



class mode_paimt : public mode_base
{
public:
    mode_paimt();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_PRICEMT_H
