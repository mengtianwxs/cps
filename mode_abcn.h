#ifndef MODE_ABCN_H
#define MODE_ABCN_H

#include "mode_base.h"



class mode_abcn :public mode_base
{
public:
    mode_abcn();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_ABCN_H
