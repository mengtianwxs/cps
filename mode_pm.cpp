#include "mode_pm.h"

mode_pm::mode_pm()
{

}
 //@17  pm  abc mode        p100*10*12  //p: 100*10 m:12 p代表排的规格，m代表数量
void mode_pm::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{

    initMap(map);
    qDebug()<<"this is method calc";

    //-100*10*12
    QString txt=sl_jiahao.at(0);
    QString psabc=txt.mid(1,-1);

     sl_xinghao=psabc.split("*");
     pabc_width=sl_xinghao.at(0).toInt();
     pabc_deep=sl_xinghao.at(1).toInt();
    double pabc_ms=sl_xinghao.at(2).toDouble();

   sl_content.append("- "+QString::number(pabc_width)+"*"+QString::number(pabc_deep)+"*"+QString::number(pabc_ms));


    if(state=="t")
    {
        sl_status.append("- ABC MODE | 分支排 材质 铜");

        T=pabc_width*pabc_deep*8.9*dj/1000;
       SUMP=T*pabc_ms;
       sl_content.append(QString::number(T)+" T");

        PAI="T*"+QString::number(pabc_ms);




    }

    if(state=="l")
    {
        sl_status.append("- ABC MODE | 分支排  材质 铝");

        L=pabc_width*pabc_deep*2.7*dj/1000;
         SUMP=L*pabc_ms;
       sl_content.append(QString::number(L)+" L");
       PAI="L*"+QString::number(pabc_ms);


    }

    sl_content.append(PAI);

   sl_content.append("= "+QString::number(SUMP)+"\n");
    list.append(QString::number(0));
}





