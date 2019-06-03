#ifndef MODE_ABC2N_H
#define MODE_ABC2N_H

#include "mode_base.h"



class mode_abc2n : public mode_base
{
public:
    mode_abc2n();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_ABC2N_H
