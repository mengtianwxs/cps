#ifndef MODE_ABC_H
#define MODE_ABC_H

#include "mode_base.h"



class mode_abc : public mode_base
{
public:
    mode_abc();

    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_ABC_H
