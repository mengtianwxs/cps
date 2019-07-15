#ifndef MODE_42ABCN_H
#define MODE_42ABCN_H

#include "mode_base.h"



class mode_42abc2n : public mode_base
{
public:
    mode_42abc2n();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_42ABCN_H
