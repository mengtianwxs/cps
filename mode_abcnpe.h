#ifndef MODE_ABCNPE_H
#define MODE_ABCNPE_H

#include "mode_base.h"



class mode_abcnpe : public mode_base
{
public:
    mode_abcnpe();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_ABCNPE_H
