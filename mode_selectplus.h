#ifndef MODE_SELECTPLUS_H
#define MODE_SELECTPLUS_H

#include "mode_base.h"



class mode_selectplus : public mode_base
{
public:
    mode_selectplus();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_SELECTPLUS_H
