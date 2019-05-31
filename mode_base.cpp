#include "mode_base.h"


mode_base::mode_base()
{

}

QMap<QString, QString> mode_base::method_calc(QStringList sl_jiahao, QMap<QString, int> map)
{
    state_num=map.value("state_num");
    dj=map.value("dj");
    t600_num=map.value("s600");
    t400_num=map.value("s400");
    t800_num=map.value("s800");
    t1000_num=map.value("s1000");
    t1200_num=map.value("s1200");
    tfb1_width=map.value("sfb1_width");
    tfb2_width=map.value("sfb2_width");
    tfb3_width=map.value("sfb3_width");
    tfb1_num=map.value("sfb1_num");
    tfb2_num=map.value("sfb2_num");
    tfb3_num=map.value("sfb3_num");
}

