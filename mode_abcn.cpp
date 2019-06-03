#include "mode_abcn.h"

mode_abcn::mode_abcn()
{

}

void mode_abcn::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{

    initMap(map);
     pabc=sl_jiahao.at(0);
     pn=sl_jiahao.at(1);

    sl_xinghaoabc=pabc.split("*");
     sl_xinghaon=pn.split("*");

    pabc_width=sl_xinghaoabc.at(0).toInt();
     pabc_deep=sl_xinghaoabc.at(1).toInt();

    pn_width=sl_xinghaon.at(0).toInt();
     pn_deep=sl_xinghaon.at(1).toInt();

    sl_content.append(QString::number(pabc_width)+"*"+QString::number(pabc_deep)+"+"+QString::number(pn_width)+"*"+QString::number(pn_deep));

    if(state=="t"){
      sl_status.append("ABCN MODE | 单排单零 材质 铜");
      Pabc=pabc_width*pabc_deep*8.9*dj/1000;
      Pn=pn_width*pn_deep*8.9*dj/1000;
      sl_content.append(QString::number(Pabc)+" Tabc "+QString::number(Pn)+" Tn");
     }

    if(state=="l"){
        sl_status.append("ABCN MODE | 单排单零 材质 铝");

        Pabc=pabc_width*pabc_deep*2.7*dj/1000;
        Pn=pn_width*pn_deep*2.7*dj/1000;

       sl_content.append(QString::number(Pabc)+" Labc "+QString::number(Pn)+" Ln");

    }





        PAI="Pabc*3*"+PAICONTENT+"+"+"Pn*"+PAICONTENT;

        sl_content.append(PAI);
        SUMP=Pabc*3*PAICONTENTD+Pn*PAICONTENTD;
       sl_content.append("= "+QString::number(SUMP)+"\n");
        list.append(QString::number(SUMP));





}
