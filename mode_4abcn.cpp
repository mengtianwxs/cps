#include "mode_4abcn.h"

mode_4abcn::mode_4abcn()
{

}

void mode_4abcn::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{

    initMap(map);

    pabc=sl_jiahao.at(0);




    //以 *号为分割符，查看是排的数量  100*10
     sl_xinghaoabc=pabc.split("*");


     pabc_width=sl_xinghaoabc.at(1).toInt();
     pabc_deep=sl_xinghaoabc.at(2).toInt();


     pn_width=sl_xinghaoabc.at(1).toInt();
     pn_deep=sl_xinghaoabc.at(2).toInt();



    sl_content.append("4*"+QString::number(pabc_width)+"*"+QString::number(pabc_deep));

    if(state=="t"){
       sl_status.append("4ABCN MODE | 单排单零 材质 铜");



        Pabc=pabc_width*pabc_deep*8.9*dj/1000;
        Pn=pn_width*pn_deep*8.9*dj/1000;


        sl_content.append(QString::number(Pabc)+" Tabc "+QString::number(Pn)+" Tn");



    }

    if(state=="l"){
       sl_status.append("4ABCN MODE | 单排单零 材质 铝");


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
