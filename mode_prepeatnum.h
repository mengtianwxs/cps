#ifndef MODE_PREPEATNUM_H
#define MODE_PREPEATNUM_H

#include "mode_base.h"



class mode_prepeatnum : public mode_base
{
public:
    mode_prepeatnum();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_PREPEATNUM_H
