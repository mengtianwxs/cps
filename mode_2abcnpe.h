#ifndef MODE_2ABCNPE_H
#define MODE_2ABCNPE_H

#include "mode_base.h"



class mode_2abcnpe : public mode_base
{
public:
    mode_2abcnpe();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_2ABCNPE_H
