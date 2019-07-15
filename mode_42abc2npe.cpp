#include "mode_42abc2npe.h"

mode_42abc2npe::mode_42abc2npe()
{

}

void mode_42abc2npe::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{
    //4*2*100*10+80*8
    initMap(map);

    pabc=sl_jiahao.at(0);
    ppe=sl_jiahao.at(1);




    //以 *号为分割符，查看是排的数量  100*10
     sl_xinghaoabc=pabc.split("*");
     sl_xinghaope=ppe.split("*");

     int num=sl_xinghaoabc.at(1).toInt();
     pabc_width=sl_xinghaoabc.at(2).toInt();
     pabc_deep=sl_xinghaoabc.at(3).toInt();


     pn_width=sl_xinghaoabc.at(2).toInt();
     pn_deep=sl_xinghaoabc.at(3).toInt();

     ppe_width=sl_xinghaope.at(0).toInt();
     ppe_deep=sl_xinghaope.at(1).toInt();





    sl_content.append("4*"+QString::number(num)+"*"+QString::number(pabc_width)+"*"+QString::number(pabc_deep)+"+"+
                      QString::number(ppe_width)+"*"+QString::number(ppe_deep));

    if(state=="t"){
       sl_status.append("42ABC2NPE MODE | 复排复零单地 材质 铜");



        Pabc=pabc_width*pabc_deep*8.9*dj/1000;
        Pn=pn_width*pn_deep*8.9*dj/1000;
        Ppe=ppe_width*ppe_deep*8.9*dj/1000;


        sl_content.append(QString::number(Pabc)+" Tabc "+QString::number(Pn)+" Tn "+QString::number(Ppe)+" Tpe");



    }

    if(state=="l"){
       sl_status.append("4ABC2NPE MODE | 复排复零单地 材质 铝");


        Pabc=pabc_width*pabc_deep*2.7*dj/1000;
        Pn=pn_width*pn_deep*2.7*dj/1000;
        Ppe=ppe_width*ppe_deep*2.7*dj/1000;


        sl_content.append(QString::number(Pabc)+" Labc "+QString::number(Pn)+" Ln "+QString::number(Ppe)+" Lpe");


    }

    PAI="Pabc*3*"+QString::number(num)+"*"+PAICONTENT+"+"+"Pn*"+QString::number(num)+"*"+PAICONTENT+"+Ppe*"+PAICONTENT;

    sl_content.append(PAI);
    SUMP=Pabc*3*num*PAICONTENTD+Pn*num*PAICONTENTD+Ppe*PAICONTENTD;
   sl_content.append("= "+QString::number(SUMP)+"\n");
    list.append(QString::number(SUMP));

}
