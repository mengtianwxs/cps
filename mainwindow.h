#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mode_base.h"

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include<QDebug>
#include <QTextEdit>
#include <QCheckBox>
#include <QKeyEvent>
#include<QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton* pb_calc;
    QPushButton* pb_clear;
    QPushButton* pb_sumadd;
    QPushButton* pb_reset;
    QPushButton* pb_pop;

    QLineEdit* le_guige;
    QTextEdit* te_content;
    QLineEdit* le_dj;
    QCheckBox* cb_tong;
    QCheckBox* cb_lv;
    QLineEdit* le_400;
    QLineEdit* le_600;
    QLineEdit* le_800;
    QLineEdit* le_1000;
    QLineEdit* le_1200;
    QString state;
    int stage_num;

    QLineEdit* le_fb1_size;
    QLineEdit* le_fb2_size;
    QLineEdit* le_fb3_size;

    QLineEdit* le_fb1_sl;
    QLineEdit* le_fb2_sl;
    QLineEdit* le_fb3_sl;

    QStringList list_guige;
    int numListGG=0;




     QString pnum;
     QString pabc;
    QString pn;
    QString ppe;
    QString pabc_width;
     QString pabc_deep;
    QString pn_width;
    QString pn_deep;
     QString ppe_width;
    QString ppe_deep;

    QStringList list;
    QStringList sl_content;
    QStringList sl_state;

    int counter=0;



    //配电柜的数量
    int s400=0;
    int s600=0;
    int s800=0;
    int s1000=0;
    int s1200=0;

    int fb1_num=0;
    int fb2_num=0;
    int fb3_num=0;

    //非标配电柜的宽度
    double fb1_width=0;
    double fb2_width=0;
    double fb3_width=0;


    QNetworkAccessManager* nw_am;
    QNetworkReply* nr;
     QString netprice_tong="";

    QNetworkAccessManager* nw_amlv;
    QNetworkReply* nrlv;
    QString netprice_lv="";
    QStringList sl_taishu;
    int TotalTaiShu=0;

    mode_base* mabc=NULL;

    int startlist=0;




protected:
    void initNetworkAccessManager();
    void initUI();
    void method_Addcontent(QStringList sl,QStringList sl_state);
    void method_counter();
    void method_counterreset();
    void method_createLabelforListinfo();



private slots:
    void method_clear();
    void method_calc();
    void method_cbt(int);
    void method_cbl(int);
    void method_textedit_cursormove();
    void method_sumadd();
    void method_reset();
    void method_enterGuiGe();
    void method_enterp();
    void method_pop();
    void keyPressEvent(QKeyEvent* event);
    //获取铜排的网上价格
    void method_tongreplyFinished(QNetworkReply*);
    //获取铝排的网上价格
     void method_lvreplyFinished(QNetworkReply*);
     void method_g();



};

#endif // MAINWINDOW_H
