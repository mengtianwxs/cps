#include "mode_2abc.h"

mode_2abc::mode_2abc()
{

}

void mode_2abc::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{

     initMap(map);
     pabc=sl_jiahao.at(0);
     sl_xinghao=pabc.split("*");
     pabc_sl=sl_xinghao.at(0).toInt();
     pabc_width=sl_xinghao.at(1).toInt();
     pabc_deep=sl_xinghao.at(2).toInt();

      sl_content.append(QString::number(pabc_sl)+"*"+QString::number(pabc_width)+"*"+QString::number(pabc_deep));


      if(state=="t")
      {


          sl_status.append(QString::number(pabc_sl)+"ABC MODE | 复排 材质 铜");
          P=pabc_width*pabc_deep*8.9*dj/1000;
           sl_content.append("P= "+QString::number(P)+" T");

      }
      if(state=="l"){


          sl_status.append(QString::number(pabc_sl)+"ABC MODE | 复排 材质 铝");

         P=pabc_width*pabc_deep*2.7*dj/1000;

          sl_content.append("P= "+QString::number(P)+" L");

      }

         PAI="P*"+QString::number(pabc_sl)+"*3*(0.6*"+str_t600num+
                 "+0.8*"+str_t800num+
                 "+1*"+str_t1000num+
                 "+1.2*"+str_t1200num+
                 "+0.4*"+str_t400num+"+"+
                 str_tfb1_width+"*"+str_tfb1_num+"+"+
                 str_tfb2_width+"*"+str_tfb2_num+"+"+
                 str_tfb3_width+"*"+str_tfb3_num+")";

         sl_content.append(PAI);

         SUMP=P*3*pabc_sl*(0.4*t400_num+0.6*t600_num+0.8*t800_num+1*t1000_num+1.2*t1200_num+tfb1_width*tfb1_num+tfb2_width*tfb2_num+tfb3_width*tfb3_num);

         sl_content.append("= "+QString::number(SUMP)+"\n");

         list.append(QString::number(SUMP));


}
