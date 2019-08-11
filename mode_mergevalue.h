#ifndef MODE_MERGEVALUE_H
#define MODE_MERGEVALUE_H

#include "mode_base.h"



class mode_mergevalue : public mode_base
{
public:
    mode_mergevalue();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_MERGEVALUE_H
