#ifndef MODE_4ABCN_H
#define MODE_4ABCN_H

#include "mode_base.h"



class mode_4abcn : public mode_base
{
public:
    mode_4abcn();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_4ABCN_H
