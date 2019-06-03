#include "mode_pricem.h"

mode_pricem::mode_pricem()
{

}

void mode_pricem::method_calc(QStringList sl_jiahao, QMap<QString, QString> map)
{
    initMap(map);
    QString txt=sl_jiahao.at(0);
    QString pr=txt.mid(1,-1);
    int p=pr.split("*").at(0).toInt();
    double m=pr.split("*").at(1).toDouble();

    sl_content.append("- "+QString::number(p)+" * "+QString::number(m));
    double SUMP=p*m;
    sl_status.append("- PRICE MODE | 分支排");
    sl_content.append("= "+QString::number(SUMP)+"\n");
    list.append(QString::number(SUMP));

}
