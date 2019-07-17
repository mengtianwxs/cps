#ifndef MODE_SEGMENTPLUS_H
#define MODE_SEGMENTPLUS_H

#include "mode_base.h"



class mode_segmentplus : public mode_base
{
public:
    mode_segmentplus();

    void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

};

#endif // MODE_SEGMENTPLUS_H
