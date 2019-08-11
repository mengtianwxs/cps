#ifndef MODE_MERGE_H
#define MODE_MERGE_H

#include "mode_base.h"



class mode_merge : public mode_base
{
public:
    mode_merge();
    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);
};

#endif // MODE_MERGE_H
