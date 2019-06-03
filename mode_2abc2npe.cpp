#include "mode_2abc2npe.h"

mode_2abc2npe::mode_2abc2npe()
{

}

void mode_2abc2npe::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{
    initMap(map);
    pabc=sl_jiahao.at(0);
    pn=sl_jiahao.at(1);
    ppe=sl_jiahao.at(2);

    //以 *号为分割符，查看是排的数量  100*10
     sl_xinghaoabc=pabc.split("*");
     sl_xinghaon=pn.split("*");
    sl_xinghaope=ppe.split("*");

     pabc_sl=sl_xinghaoabc.at(0).toInt();
     pabc_width=sl_xinghaoabc.at(1).toInt();
     pabc_deep=sl_xinghaoabc.at(2).toInt();


     pn_sl=sl_xinghaon.at(0).toInt();
     pn_width=sl_xinghaon.at(1).toInt();
   pn_deep=sl_xinghaon.at(2).toInt();



    //复零单地模式


     ppe_width=sl_xinghaope.at(0).toInt();
     ppe_deep=sl_xinghaope.at(1).toInt();


   sl_content.append(QString::number(pabc_sl)+"*"+QString::number(pabc_width)+"*"+QString::number(pabc_deep)+"+"+QString::number(pn_sl)+"*"+QString::number(pn_width)+"*"+QString::number(pn_deep)+"+"+QString::number(ppe_width)+"*"+QString::number(ppe_deep));

    if(state=="t"){
        sl_status.append(QString::number(pabc_sl)+"ABC"+QString(pn_sl)+"NPE MODE | 复排复零单地 材质 铜");


        Pabc=pabc_width*pabc_deep*8.9*dj/1000;
        Pn=pn_width*pn_deep*8.9*dj/1000;
        Ppe=ppe_width*ppe_deep*8.9*dj/1000;

       sl_content.append(QString::number(Pabc)+" Pabc "+QString::number(Pn)+" Tn "+QString::number(Ppe)+" Tpe");



    }

    if(state=="l"){
        sl_status.append(QString::number(pabc_sl)+"ABC"+QString(pn_sl)+"NPE MODE | 复排复零单地 材质 铝");


        Pabc=pabc_width*pabc_deep*2.7*dj/1000;
        Pn=pn_width*pn_deep*2.7*dj/1000;
        Ppe=ppe_width*ppe_deep*2.7*dj/1000;

       sl_content.append(QString::number(Pabc)+" Labc "+QString::number(Pn)+" Ln "+QString::number(Ppe)+" Lpe");

    }

    PAI="Pabc*3*"+QString::number(pabc_sl)+"*"+PAICONTENT +"+Pn*"+QString::number(pn_sl)+PAICONTENT+"+Ppe*"+PAICONTENT;

    sl_content.append(PAI);
    SUMP=Pabc*3*pabc_sl*PAICONTENTD +Pn*pn_sl*PAICONTENTD+ Ppe*PAICONTENTD;
    sl_content.append("= "+QString::number(SUMP)+"\n");
    list.append(QString::number(SUMP));


}
