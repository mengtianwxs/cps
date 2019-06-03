#ifndef MODE_2ABCN_H
#define MODE_2ABCN_H

#include "mode_base.h"



class mode_2abcn : public mode_base
{
public:
    mode_2abcn();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_2ABCN_H
