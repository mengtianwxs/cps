#include "mode_2abcn.h"

mode_2abcn::mode_2abcn()
{

}

void mode_2abcn::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{
    initMap(map);

    pabc=sl_jiahao.at(0);
    pn=sl_jiahao.at(1);

    sl_xinghaoabc=pabc.split("*");
     sl_xinghaon=pn.split("*");

     pabc_sl=sl_xinghaoabc.at(0).toInt();
    pabc_width=sl_xinghaoabc.at(1).toInt();
    pabc_deep=sl_xinghaoabc.at(2).toInt();


     pn_width=sl_xinghaon.at(0).toInt();
     pn_deep=sl_xinghaon.at(1).toInt();



    sl_content.append(QString::number(pabc_sl)+"*"+QString::number(pabc_width)+"*"+QString::number(pabc_deep)+"+"+QString::number(pn_width)+"*"+QString::number(pn_deep));

    if(state=="t"){
       sl_status.append(QString::number(pabc_sl)+"ABCN MODE | 复排单零 材质 铜");

       Pabc=pabc_width*pabc_deep*8.9*dj/1000;
        Pn=pn_width*pn_deep*8.9*dj/1000;

        sl_content.append(QString::number(Pabc)+" Tabc "+QString::number(Pn)+" Tn");


    }

    if(state=="l"){
       sl_status.append(QString::number(pabc_sl)+"ABCN MODE | 复排单零 材质 铝");

        Pabc=pabc_width*pabc_deep*2.7*dj/1000;
        Pn=pn_width*pn_deep*2.7*dj/1000;

        sl_content.append(QString::number(Pabc)+" Labc "+QString::number(Pn)+" Ln");

    }

    PAI="Tabc*"+QString::number(pabc_sl)+"*3*(0.6*"+str_t600num+
            "+0.8*"+str_t800num+
            "+1*"+str_t1000num+
            "+1.2*"+str_t1200num+
            "+0.4*"+str_t400num+"+"+
            str_tfb1_width+"*"+str_tfb1_num+"+"+
            str_tfb2_width+"*"+str_tfb2_num+"+"+
            str_tfb3_width+"*"+str_tfb3_num+")"+

            ")+Pn*(0.6*"+str_t600num+
            "+0.8*"+str_t800num+
            "+1*"+str_t1000num+
            "+1.2*"+str_t1200num+
            "+0.4*"+str_t400num+"+"+
            str_tfb1_width+"*"+str_tfb1_num+"+"+
            str_tfb2_width+"*"+str_tfb2_num+"+"+
            str_tfb3_width+"*"+str_tfb3_num+")";

    sl_content.append(PAI);
    SUMP=Pabc*pabc_sl*3*(0.4*t400_num+0.6*t600_num+0.8*t800_num+1*t1000_num+1.2*t1200_num+tfb1_width*tfb1_num+tfb2_width*tfb2_num+tfb3_width*tfb3_num)+
            Pn*(0.4*t400_num+0.6*t600_num+0.8*t800_num+1*t1000_num+1.2*t1200_num+tfb1_width*tfb1_num+tfb2_width*tfb2_num+tfb3_width*tfb3_num);
    sl_content.append("= "+QString::number(SUMP)+"\n");
    list.append(QString::number(SUMP));


}
