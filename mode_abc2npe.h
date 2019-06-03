#ifndef MODE_ABC2NPE_H
#define MODE_ABC2NPE_H

#include "mode_base.h"



class mode_abc2npe : public mode_base
{
public:
    mode_abc2npe();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_ABC2NPE_H
