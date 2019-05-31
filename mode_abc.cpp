#include "mode_abc.h"

mode_abc::mode_abc()
{

}

QMap<QString, QString> mode_abc::method_calc(QStringList sl, QMap<QString, int> map)
{


    QString pabc=sl_jiahao.at(0);
    QStringList sl_xinghao=pabc.split("*");
    int pabc_width=sl_xinghao.at(0).toInt();
    int pabc_deep=sl_xinghao.at(1).toInt();
    map_result.insert("te1",QString::number(pabc_width)+"*"+QString::number(pabc_deep));

//    te_content->append(QString::number(pabc_width)+"*"+QString::number(pabc_deep));



    if(state_num==0)
    {
        map_result.insert("sbt","ABC MODE | 单排 材质 铜");
//        ui->statusBar->showMessage("ABC MODE | 单排 材质 铜");
        T=pabc_width*pabc_deep*8.9*dj/1000;
        map_result.insert("i2",QString::number(T)+" T");
//        te_content->append(QString::number(T)+" T");

        QString TS="T*3*(0.6*"+QString::number(s600)+
                "+0.8*"+QString::number(s800)+
                "+1*"+QString::number(s1000)+
                "+1.2*"+QString::number(s1200)+
                "+0.4*"+QString::number(s400)+")";
        map_result.insert("i3",TS);
        te_content->append(TS);

        int SUMTS=T*3*(0.4*s400+0.6*s600+0.8*s800+1*s1000+1.2*s1200);
        te_content->append("= "+QString::number(SUMTS)+"\n");
        list.append(QString::number(SUMTS));
    }

    if(state_num==1)
    {
        ui->statusBar->showMessage("ABC MODE | 单排 材质 铝");
        int L=0;
        L=pabc_width*pabc_deep*2.7*dj/1000;
        te_content->append(QString::number(L)+" L");
        QString LS="L*3*(0.6*"+QString::number(s600)+"+0.8*"+QString::number(s800)+"+1*"+QString::number(s1000)+"+1.2*"+QString::number(s1200)+"+0.4*"+QString::number(s400)+")";
        te_content->append(LS);
        int SUMLS=L*3*(0.4*s400+0.6*s600+0.8*s800+1*s1000+1.2*s1200);
        te_content->append("= "+QString::number(SUMLS)+"\n");
        list.append(QString::number(SUMLS));

    }

    return map_result;
}

