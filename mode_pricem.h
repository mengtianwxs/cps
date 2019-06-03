#ifndef MODE_PRICEM_H
#define MODE_PRICEM_H

#include "mode_base.h"



class mode_pricem : public mode_base
{
public:
    mode_pricem();
     void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_PRICEM_H
