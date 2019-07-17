#include "mode_base.h"



void mode_base::method_calc(QStringList sl_jiahao,QMap<QString,QString> map)
{





}

mode_base::mode_base()
{


}

QStringList mode_base::getList()
{
    return list;


}

QStringList mode_base::getSLContent()
{
    return sl_content;
}

QStringList mode_base::getSLStatus()
{
    return sl_status;
}

void mode_base::initMap(QMap<QString, QString> map)
{
    state=map.value("state");
    dj=map.value("dj").toInt();

    t600_num=map.value("s600").toInt();
    t400_num=map.value("s400").toInt();
    t800_num=map.value("s800").toInt();
    t1000_num=map.value("s1000").toInt();
    t1200_num=map.value("s1200").toInt();

    tfb1_width=map.value("sfb1_width").toDouble();
    tfb2_width=map.value("sfb2_width").toDouble();
    tfb3_width=map.value("sfb3_width").toDouble();

    tfb1_num=map.value("sfb1_num").toInt();
    tfb2_num=map.value("sfb2_num").toInt();
    tfb3_num=map.value("sfb3_num").toInt();

    str_t400num=QString::number(t400_num);
    str_t600num=QString::number(t600_num);
     str_t800num=QString::number(t800_num);
     str_t1000num=QString::number(t1000_num);
     str_t1200num=QString::number(t1200_num);
    str_tfb1_width=QString::number(tfb1_width);
    str_tfb2_width=QString::number(tfb2_width);
     str_tfb3_width=QString::number(tfb3_width);
     str_tfb1_num=QString::number(tfb1_num);
    str_tfb2_num=QString::number(tfb2_num);
    str_tfb3_num=QString::number(tfb3_num);
    taishu=t400_num+t600_num+t800_num+t1200_num+t1000_num+tfb1_num+tfb2_num+tfb3_num;



        PAICONTENT="(0.6*"+str_t600num+
                        "+0.8*"+str_t800num+
                        "+1*"+str_t1000num+
                        "+1.2*"+str_t1200num+
                        "+0.4*"+str_t400num+"+"+
                        str_tfb1_width+"*"+str_tfb1_num+"+"+
                        str_tfb2_width+"*"+str_tfb2_num+"+"+
                        str_tfb3_width+"*"+str_tfb3_num+")";

        PAICONTENTD=0.4*t400_num+0.6*t600_num+0.8*t800_num+1*t1000_num+1.2*t1200_num+tfb1_width*tfb1_num+tfb2_width*tfb2_num+tfb3_width*tfb3_num;


}

int mode_base::getTaiShu()
{
    return taishu;
}

