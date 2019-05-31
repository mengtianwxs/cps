#ifndef MODE_ABC_H
#define MODE_ABC_H

#include "mode_base.h"



class mode_abc :public mode_base
{
public:
    mode_abc();
    QMap<QString,QString> method_calc(QStringList sl,QMap<QString,int> map);
};

#endif // MODE_ABC_H
