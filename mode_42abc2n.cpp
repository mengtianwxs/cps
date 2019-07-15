#include "mode_42abc2n.h"

mode_42abc2n::mode_42abc2n()
{

}

void mode_42abc2n::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{

    //4*2*100*10
    initMap(map);

    pabc=sl_jiahao.at(0);




    //以 *号为分割符，查看是排的数量  100*10
     sl_xinghaoabc=pabc.split("*");

     int num=sl_xinghaoabc.at(1).toInt();
     pabc_width=sl_xinghaoabc.at(2).toInt();
     pabc_deep=sl_xinghaoabc.at(3).toInt();


     pn_width=sl_xinghaoabc.at(2).toInt();
     pn_deep=sl_xinghaoabc.at(3).toInt();



    sl_content.append("4*"+QString::number(num)+"*"+QString::number(pabc_width)+"*"+QString::number(pabc_deep));

    if(state=="t"){
       sl_status.append("42ABC2N MODE | 复排复零 材质 铜");



        Pabc=pabc_width*pabc_deep*8.9*dj/1000;
        Pn=pn_width*pn_deep*8.9*dj/1000;


        sl_content.append(QString::number(Pabc)+" Tabc "+QString::number(Pn)+" Tn");



    }

    if(state=="l"){
       sl_status.append("4ABC2N MODE | 复排复零 材质 铝");


        Pabc=pabc_width*pabc_deep*2.7*dj/1000;
        Pn=pn_width*pn_deep*2.7*dj/1000;


        sl_content.append(QString::number(Pabc)+" Labc "+QString::number(Pn)+" Ln");


    }

    PAI="Pabc*3*"+QString::number(num)+"*"+PAICONTENT+"+"+"Pn*"+QString::number(num)+"*"+PAICONTENT;

    sl_content.append(PAI);
    SUMP=Pabc*3*num*PAICONTENTD+Pn*num*PAICONTENTD;
   sl_content.append("= "+QString::number(SUMP)+"\n");
    list.append(QString::number(SUMP));


}
