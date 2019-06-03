#ifndef MODE_2ABC_H
#define MODE_2ABC_H

#include "mode_base.h"



class mode_2abc : public mode_base
{
public:
    mode_2abc();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_2ABC_H
