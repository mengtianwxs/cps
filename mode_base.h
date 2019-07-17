#ifndef BASE_MODE_H
#define BASE_MODE_H

#include <QMap>
#include <QStatusBar>
#include<QTextEdit>
#include<QString>
#include<QDebug>

class mode_base
{
public:
    mode_base();
    virtual void method_calc(QStringList sl_jiahao,QMap<QString,QString> map);

    QStringList getList();
    QStringList getSLContent();
    QStringList getSLStatus();
    void initMap(QMap<QString,QString> map);
    int getTaiShu();


public:

    QStringList sl_jiahao;
    QStringList sl_xinghao;
    QString pabc_guige="";

    QString state="";// tong 0 lv 1
    double dj=0;
    int gtnum=0;
    int repeatnum=0;

   int t400_num=0;
   int t600_num=0;
   int t800_num=0;
   int t1000_num=0;
   int t1200_num=0;
   int tfb1_num=0;
   int tfb2_num=0;
   int tfb3_num=0;
    double tfb1_width=0;
    double tfb2_width=0;
    double tfb3_width=0;
    double T=0;
    double L=0;
    int taishu=0;

    QString str_t400num="";
    QString str_t600num="";
    QString str_t800num="";
    QString str_t1000num="";
    QString str_t1200num="";
    QString str_tfb1_width="";
    QString str_tfb2_width="";
    QString str_tfb3_width="";
    QString str_tfb1_num="";
    QString str_tfb2_num="";
    QString str_tfb3_num="";

    QStringList list;
    double SUMP=0;
    QStringList sl_content;
    QStringList sl_status;

    double P=0;
    QString PAI="";
    double Pabc=0;
    double Pn=0;
    double Ppe=0;
    QString PAICONTENT="";
    double PAICONTENTD=0;

    QString pabc="";
    QString pn="";
    QString ppe="";

    QStringList sl_xinghaoabc;
    QStringList sl_xinghaon;
    QStringList sl_xinghaope;



    int ppe_sl=0;
    int pn_sl=0;
    int pabc_sl=0;


    int pabc_width=0;
    int pabc_deep=0;
    int pn_width=0;
    int ppe_width=0;
    int pn_deep=0;
    int ppe_deep=0;



};

#endif // BASE_MODE_H
