#ifndef MODE_PREPEAT_H
#define MODE_PREPEAT_H

#include "mode_base.h"



class mode_prepeat : public mode_base
{
public:
    mode_prepeat();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_PREPEAT_H
