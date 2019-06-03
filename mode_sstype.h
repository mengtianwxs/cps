#ifndef MODE_SSTYPE_H
#define MODE_SSTYPE_H

#include "mode_base.h"



class mode_sstype : public mode_base
{
public:
    mode_sstype();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_SSTYPE_H
