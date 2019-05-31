#ifndef BASE_MODE_H
#define BASE_MODE_H

#include <QMap>
#include <QStatusBar>
#include<QTextEdit>
#include<QString>

class mode_base
{
public:
    mode_base();
    virtual QMap<QString,QString> method_calc(QStringList sl_jiahao,QMap<QString,int> map);


public:

    QStringList sl_jiahao;
    QStringList sl_xinghao;
    QMap<QString,QString> map_result;
    QString pabc_guige="";

    int pabc_width=0;
    int pabc_deep=0;
    int pn_width=0;
    int ppe_width=0;
    int pn_deep=0;
    int ppe_deep=0;
    int state_num=0;// tong 0 lv 1
    int dj=0;
    int t400_num=0;
    int t600_num=0;
    int t800_num=0;
    int t1000_num=0;
    int t1200_num=0;
    int tfb1_num=0;
    int tfb2_num=0;
    int tfb3_num=0;
    int tfb1_width=0;
    int tfb2_width=0;
    int tfb3_width=0;
    int T=0;
    int L=0;

    QString str_t400="";
    QString str_t600="";
    QString str_t800="";
    QString str_t1000="";
    QString str_t1200="";
    QString str_tfb1_width="";
    QString str_tfb2_width="";
    QString str_tfb3_width="";

};

#endif // BASE_MODE_H
