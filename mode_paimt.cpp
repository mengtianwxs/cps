#include "mode_paimt.h"

mode_paimt::mode_paimt()
{

}

void mode_paimt::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{

    initMap(map);

    QString txt=sl_jiahao.at(0);
    QString psabc=txt.mid(1,-1);

     sl_xinghao=psabc.split("*");
    pabc_width=sl_xinghao.at(0).toInt();
     pabc_deep=sl_xinghao.at(1).toInt();
     double pabc_ms=sl_xinghao.at(2).toDouble();
    int pabc_ts=sl_xinghao.at(3).toInt();

    sl_content.append("- "+QString::number(pabc_width)+"*"+QString::number(pabc_deep)+"*"+QString::number(pabc_ms)+"*"+QString::number(pabc_ts));


    if(state=="t")
    {
        sl_status.append("- ABCMT MODE | 分支排 材质 铜");
        int T=0;
        T=pabc_width*pabc_deep*8.9*dj/1000;

        sl_content.append(QString::number(T)+" T");

        QString TS="T*"+QString::number(pabc_ms)+"*"+QString::number(pabc_ts);
        sl_content.append(TS);

        int SUMTS=T*pabc_ms*pabc_ts;
        sl_content.append("= "+QString::number(SUMTS)+"\n");
        list.append(QString::number(SUMTS));
    }

    if(state=="l")
    {
        sl_status.append("- ABCMT MODE | 分支排  材质 铝");
        int L=0;
        L=pabc_width*pabc_deep*2.7*dj/1000;
        sl_content.append(QString::number(L)+" L");
        QString LS="L*"+QString::number(pabc_ms)+"*"+QString::number(pabc_ts);
        sl_content.append(LS);
        int SUMLS=L*pabc_ms*pabc_ts;
        sl_content.append("= "+QString::number(SUMLS)+"\n");
        list.append(QString::number(SUMLS));

    }

}
