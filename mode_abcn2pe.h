#ifndef MODE_ABCN2PE_H
#define MODE_ABCN2PE_H

#include "mode_base.h"



class mode_abcn2pe : public mode_base
{
public:
    mode_abcn2pe();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_ABCN2PE_H
