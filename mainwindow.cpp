#include "mainwindow.h"
#include "mode_2abc.h"
#include "mode_2abc2n.h"
#include "mode_2abc2n2pe.h"
#include "mode_2abc2npe.h"
#include "mode_2abcn.h"
#include "mode_2abcn2pe.h"
#include "mode_2abcnpe.h"
#include "mode_4abcn.h"
#include "mode_4abcnpe.h"
#include "mode_abc.h"
#include "mode_abc2n.h"
#include "mode_abc2n2pe.h"
#include "mode_abc2npe.h"
#include "mode_abcn.h"
#include "mode_abcn2pe.h"
#include "mode_abcnpe.h"
#include "mode_pm.h"
#include "mode_price.h"
#include "mode_pricem.h"
#include "mode_pricemt.h"
#include "mode_sstype.h"
#include "ui_mainwindow.h"

#include <QRegExpValidator>
#include <qtextcodec.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    initNetworkAccessManager();
    initUI();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initNetworkAccessManager()
{
    nw_am=new QNetworkAccessManager(this);
    connect(nw_am,SIGNAL(finished(QNetworkReply*)),this,SLOT(method_tongreplyFinished(QNetworkReply*)));
    nr=nw_am->get(QNetworkRequest(QUrl("https://hq.smm.cn/tong/category/201102250376")));

    nw_amlv=new QNetworkAccessManager(this);
    connect(nw_amlv,SIGNAL(finished(QNetworkReply*)),this,SLOT(method_lvreplyFinished(QNetworkReply*)));
    nrlv=nw_amlv->get(QNetworkRequest(QUrl("https://hq.smm.cn/lv/category/201102250311")));
}

void MainWindow::initUI()
{
    this->setWindowTitle("cps     made by mengtianwxs (calc pai price)");
    le_guige=ui->le_pai_guige;

    pb_calc=ui->pb_calc;
    pb_clear=ui->pb_clear;
    pb_sumadd=ui->pb_sumadd;
    pb_reset=ui->pb_reset;
    pb_pop=ui->pb_pop;
    le_dj=ui->le_p_danjia;

    cb_tong=ui->cb_tong;
    cb_lv=ui->cb_lv;
    cb_tong->setChecked(true);
    cb_lv->setChecked(false);



    state="t";

    te_content=ui->te_content;
    le_400=ui->le_400;
    le_600=ui->le_600;
    le_800=ui->le_800;
    le_1000=ui->le_1000;
    le_1200=ui->le_1200;

    le_400->setPlaceholderText("0");
    le_600->setPlaceholderText("0");
    le_800->setPlaceholderText("0");
    le_1000->setPlaceholderText("0");
    le_1200->setPlaceholderText("0");

    le_fb1_size=ui->le_fb1_size;
    le_fb2_size=ui->le_fb2_size;
    le_fb3_size=ui->le_fb3_size;

    if(le_fb1_size->text()==""){
        le_fb1_size->setText("900");
        fb1_width=900;
    }else{
        fb1_width=le_fb1_size->text().toInt();
    }

    if(le_fb2_size->text()==""){
        le_fb2_size->setText("700");
        fb2_width=700;
    }else{
        fb2_width=le_fb2_size->text().toInt();
    }

    if(le_fb3_size->text()==""){
        le_fb3_size->setText("750");
        fb3_width=750;
    }else{
        fb3_width=le_fb3_size->text().toInt();
    }



    le_fb1_sl=ui->le_fb1_sl;
    le_fb2_sl=ui->le_fb2_sl;
    le_fb3_sl=ui->le_fb3_sl;



    QRegExp regx("[1-9][0-9]{0,4}");
    QValidator *vali=new QRegExpValidator(regx,this);
    le_800->setValidator(vali);
    le_600->setValidator(vali);
    le_400->setValidator(vali);
    le_1000->setValidator(vali);
    le_1200->setValidator(vali);
    le_dj->setValidator(vali);

    le_fb1_size->setValidator(vali);
    le_fb2_size->setValidator(vali);
    le_fb3_size->setValidator(vali);

    QRegExp regsl("[0-9][0-9]{0,4}");
     QValidator *vali1=new QRegExpValidator(regsl,this);

    le_fb1_sl->setValidator(vali1);
    le_fb2_sl->setValidator(vali1);
    le_fb3_sl->setValidator(vali1);


    QRegExp regx_guige("([1-3]?\\*?[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?\\+[1-9]?\\*?[1-9][0-9]?[0-9]?\\*([1-9][0-9]?)?)|"
                       "(4\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9]?[0-9]?\\*[1-9][0-9]?)|"
                       "(\\-[1-9][0-9][0-9]?\\*[1-9][0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?\\.?[0-9]?[0-9]?[0-9]?)|"
                       "(\\-[1-9][0-9][0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?)|"
                       "(\\-[1-9][0-9][0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?\\.?[0-9]?[0-9]?[0-9]?)|"
                       "(\\-[1-9][0-9][0-9]?\\*[1-9][0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?\\.?[0-9]?[0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?)|"
                       );

    QValidator* vali_gg=new QRegExpValidator(regx_guige,this);
    le_guige->setValidator(vali_gg);
    le_guige->setPlaceholderText("2*100*10+2*80*8+2*60*6");
    le_guige->setFocus();

    te_content->setEnabled(true);

    //hotkey setting
//   this->setFocusPolicy(Qt::StrongFocus);

    connect(cb_tong,SIGNAL(stateChanged(int)),this,SLOT(method_cbt(int)));
    connect(cb_lv,SIGNAL(stateChanged(int)),this,SLOT(method_cbl(int)));
    connect(pb_calc,SIGNAL(clicked()),this,SLOT(method_calc()));
    connect(pb_clear,SIGNAL(clicked()),this,SLOT(method_clear()));
    connect(te_content,SIGNAL(textChanged()),this,SLOT(method_textedit_cursormove()));
    connect(pb_sumadd,SIGNAL(clicked()),this,SLOT(method_sumadd()));
    connect(pb_reset,SIGNAL(clicked()),this,SLOT(method_reset()));
    connect(pb_pop,SIGNAL(clicked()),this,SLOT(method_pop()));

    connect(le_guige,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_400,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_600,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_800,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_1000,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_1200,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_fb1_sl,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_fb2_sl,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
    connect(le_fb3_sl,SIGNAL(returnPressed()),SLOT(method_enterGuiGe()));
}

void MainWindow::method_Addcontent(QStringList sl_content,QStringList sl_state)
{
    for(int i=0;i<sl_content.length();i++){

        te_content->append(sl_content.at(i));
    }

    ui->statusBar->showMessage(sl_state.join(","));



}




void MainWindow::method_lvreplyFinished(QNetworkReply *)
{
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QString str=codec->toUnicode(nrlv->readAll());
    QRegExp reg("ml10");

    int ci=reg.indexIn(str);
    QString content=str.mid(ci,20);
//              qDebug()<<content;


    QRegExp regint("(m.*>)(\\d+)");
    regint.indexIn(content);
   QString strcap=regint.cap(2);
   if(strcap==""){
       netprice_lv="24";

   }
    netprice_lv=QString::number(strcap.toInt()/1000+10);
//    qDebug()<<netprice_lv;

}

void MainWindow::method_g()
{
    method_sumadd();
    list.clear();
    method_clear();
    le_guige->setFocus();
    sl_state.clear();
    sl_content.clear();
    sl_taishu.clear();

}

void MainWindow::method_tongreplyFinished(QNetworkReply *)
{

              QTextCodec *codec=QTextCodec::codecForName("utf-8");
              QString str=codec->toUnicode(nr->readAll());
              QRegExp reg("ml10");

              int ci=reg.indexIn(str);
               QString content=str.mid(ci,20);
//              qDebug()<<content;


              QRegExp regint("(m.*>)(\\d+)");
              regint.indexIn(content);
              QString strcap=regint.cap(2);
              if(strcap==" "){
                  netprice_tong="60";
              }
              netprice_tong=QString::number(strcap.toInt()/1000+10);
             (netprice_tong=="")?le_dj->setText("60"):le_dj->setText(netprice_tong);

//              qDebug()<<netprice_tong;

//               int tp_start=reg_start.indexIn(content);
//               int tp_end=reg_end.indexIn(content);
//               qDebug()<<content;
//               qDebug()<<tp_start<<"@"<<tp_end;
//               qDebug()<<content.mid(tp_start+1,5);

}

void MainWindow::method_clear()
{
    le_guige->clear();
    le_600->clear();
    le_800->clear();
    le_1000->clear();
    le_1200->clear();
    le_400->clear();
    le_fb1_sl->clear();
    le_fb2_sl->clear();
    le_fb3_sl->clear();

}

void MainWindow::method_calc()
{


    //@@重新设计思路 用正则表达式匹配
    //@1 100*10
    QRegExp re_abc("[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@2 2*100*10
    QRegExp re_2abc("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@3 100*10+100*10
    QRegExp re_abcn("[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@4 100*10+2*100*10
    QRegExp re_abc2n("[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@5 2*100*10+100*10
    QRegExp re_2abcn("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@6 2*100*10+2*100*10
    QRegExp re_2abc2n("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@7 100*10+100*10+50*5
    QRegExp re_abcnpe("[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@8 100*10+100*10+2*50*5
    QRegExp re_abcn2pe("[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@9 100*10+2*100*10+50*5
    QRegExp re_abc2npe("[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@10 100*10+2*100*10+2*50*5
    QRegExp re_abc2n2pe("[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@11 2*100*10+100*10+50*5
    QRegExp re_2abcnpe("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@12 2*100*10+100*10+2*50*5
    QRegExp re_2abcn2pe("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@13 2*100*10+2*100*10+50*5
    QRegExp re_2abc2npe("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@14 2*100*10+2*100*10+2*50*5
    QRegExp re_2abc2n2pe("[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-3]\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");

    //@15 4*100*10
    QRegExp re_4abcn("4\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@16 4*100*10+80*8
    QRegExp re_4abcnpe("4\\*[1-9][0-9][0-9]?\\*[1-9][0-9]?\\+[1-9][0-9][0-9]?\\*[1-9][0-9]?");
    //@17  pm         100*10*12  //p: 100*10 m:12 p代表排的规格，m代表数量
    QRegExp re_pm("\\-[1-9][0-9][0-9]?\\*[1-9][0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?\\.?[0-9]?[0-9]?[0-9]?");

//    @18  price      p1000  单台柜子的价格
    QRegExp re_price("\\-[1-9][0-9][0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?");

//    @19  price*m    p800*10
    QRegExp re_pricem("\\-[1-9][0-9][0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?\\.?[0-9]?[0-9]?[0-9]?");
//    @20 price*m*t p代表规格，m代表数量 ,t代表台数
    QRegExp re_pricemt("\\-[1-9][0-9][0-9]?\\*[1-9][0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?\\.?[0-9]?[0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?[0-9]?");
    //@21 size*sl@TYPE 700*10@100*10
    QRegExp re_sstype("[1-9][0-9][0-9]?\\*[1-9][0-9]?@[1-3]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?\\+?[1-3]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?\\+[1-3]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?");


    (le_400->text()=="")?s400=0:s400=le_400->text().toInt();
    (le_600->text()=="")?s600=0:s600=le_600->text().toInt();
    (le_800->text()=="")?s800=0:s800=le_800->text().toInt();
    (le_1000->text()=="")?s1000=0:s1000=le_1000->text().toInt();
    (le_1200->text()=="")?s1200=0:s1200=le_1200->text().toInt();

    fb1_width=le_fb1_size->text().toDouble();
    fb2_width=le_fb2_size->text().toDouble();
    fb3_width=le_fb3_size->text().toDouble();



    fb1_num=le_fb1_sl->text().toInt();
    fb2_num=le_fb2_sl->text().toInt();
    fb3_num=le_fb3_sl->text().toInt();



    //判断有几个加号，同时也需要判断柜子的数量不能为0，如果全为0则没有什么意义。
    bool ggd_bool=s400!=0 || s600!=0 || s800!=0 || s1000!=0 || s1200!=0 || fb1_num!=0 || fb2_num!=0 || fb3_num !=0 ;

    //排的单价
    int dj=le_dj->text().toInt();
    //排的规格
     QString txt=le_guige->text();
    QStringList sl_jiahao=txt.split("+");

    //把柜体的数量，柜体的宽度传入map
    QMap<QString,QString> map;




    map.insert("s400",QString::number(s400));
    map.insert("s600",QString::number(s600));
    map.insert("s800",QString::number(s800));
    map.insert("s1000",QString::number(s1000));
    map.insert("s1200",QString::number(s1200));

    map.insert("sfb1_width",QString::number(fb1_width/1000));
    map.insert("sfb2_width",QString::number(fb2_width/1000));
    map.insert("sfb3_width",QString::number(fb3_width/1000));

    map.insert("sfb1_num",QString::number(fb1_num));
    map.insert("sfb2_num",QString::number(fb2_num));
    map.insert("sfb3_num",QString::number(fb3_num));
    map.insert("state",state);
     map.insert("dj",QString::number(dj));




    if(ggd_bool){



        //@@1  --------------------------------------------------------------------------
        if(re_abc.exactMatch(txt))
        {
            mabc=new mode_abc();

        }


        //    @@2  -------------------------------------------------------
        if(re_2abc.exactMatch(txt))
        {

            mabc=new mode_2abc();



        }

        //    @@3 ------------------------------------

        if(re_abcn.exactMatch(txt)){

            mabc=new mode_abcn();


        }



        //    @@4---------------------------------------------------

        if(re_abc2n.exactMatch(txt)){

            mabc=new mode_abc2n();


        }



        //    @@5 ------------------------------------------------------
        if(re_2abcn.exactMatch(txt)){

            mabc=new mode_2abcn();



        }

        //    @@6 ------------------------------------------------------

        if(re_2abc2n.exactMatch(txt)){



            mabc=new mode_2abc2n();



        }


        //    @@7 ------------------------------------------------------
        if(re_abcnpe.exactMatch(txt)){

            mabc=new mode_abcnpe();



        }

        //    @@8 ------------------------------------------------------
        if(re_abcn2pe.exactMatch(txt)){


          mabc=new mode_abcn2pe();

        }


        //    @@ 9------------------------------------------------------
        if(re_abc2npe.exactMatch(txt)){

           mabc=new mode_abc2npe();

        }

        //    @@ 10------------------------------------------------------

        if(re_abc2n2pe.exactMatch(txt)){


             mabc=new mode_abc2n2pe();


        }

        //    @@ 11------------------------------------------------------


        if(re_2abcnpe.exactMatch(txt)){


          mabc=new mode_2abcnpe();


        }




        //    @@ 12------------------------------------------------------

        if(re_2abcn2pe.exactMatch(txt)){
          mabc=new mode_2abcn2pe();
        }



        //    @@ 13------------------------------------------------------

        if(re_2abc2npe.exactMatch(txt)){
            mabc=new mode_2abc2npe();
        }


        //    @@ 14------------------------------------------------------

        if(re_2abc2n2pe.exactMatch(txt)){

         mabc=new mode_2abc2n2pe();


        }

        //    @@ 15------------------------------------------------------
        //4*100*10
        if(re_4abcn.exactMatch(txt)){


          mabc=new mode_4abcn();
        }


        //    @@ 16------------------------------------------------------
        //abcnpe 4*100*10+80*8
        if(re_4abcnpe.exactMatch(txt)){


        mabc=new mode_4abcnpe();


        }




 }//ggd_bool end
        //@  17------------------------------------------------------------
        //@17  pm  abc mode        p100*10*12  //p: 100*10 m:12 p代表排的规格，m代表数量

    if(re_pm.exactMatch(txt)){

          mabc=new mode_pm();


          }

        //    @18  price      p1000  单台柜子的价格
//            QRegExp re_price("\\-[1-9][0-9][0-9]?[0-9]?");
        if(re_price.exactMatch(txt)){


          mabc=new mode_price();


        }

        //    @19  price*m    p800*10
//            QRegExp re_pricem("\\-[1-9][0-9][0-9]?[0-9]?\\*[1-9][0-9]?[0-9]?[0-9]?");
        if(re_pricem.exactMatch(txt)){
           mabc=new mode_pricem();

        }



        //@  20------------------------------------------------------------
        //@20  pmt  abc mode        p100*10*12*10  //p: 100*10 m:12 p代表排的规格，m代表数量 ,t代表台数
        if(re_pricemt.exactMatch(txt))
        {
           mabc=new mode_pricemt();

        }



        //判断mabc是否实例化，如果没实例化就不执行
        if(mabc!=NULL){
            mabc->method_calc(sl_jiahao,map);
            sl_content=mabc->getSLContent();
            sl_state=mabc->getSLStatus();
            list.append(mabc->getList());
            sl_taishu.append(QString::number(mabc->getTaiShu()));
            method_Addcontent(sl_content,sl_state);

        }









}//end



void MainWindow::method_cbt(int s)
{
    if(s==Qt::Checked){
        cb_lv->setChecked(false);
        cb_tong->setChecked(true);
        state="t";
        if(netprice_tong==""){
             le_dj->setText("60");
        }else{

            le_dj->setText(netprice_tong);
        }


    }
    //    qDebug()<<"state "<<state;

}

void MainWindow::method_cbl(int s)
{
    if(s==Qt::Checked){
        cb_tong->setChecked(false);
        cb_lv->setChecked(true);
        state="l";



        if(netprice_lv==""){
            le_dj->setText("23");
        }else{

            le_dj->setText(netprice_lv);
        }
    }


}

void MainWindow::method_textedit_cursormove()
{
    te_content->moveCursor(QTextCursor::End);
}

void MainWindow::method_sumadd()
{

    int len=list.length();
    if(len>0){
        double sum=0;
        for (int i=0;i<len;i++){
            sum=sum+list.at(i).toDouble();

        }

        qDebug()<<"sltaishu="<<sl_taishu.length();

        for(int d=0;d<sl_taishu.length();d++)
        {
            TotalTaiShu=TotalTaiShu+sl_taishu.at(d).toInt();
            qDebug()<<TotalTaiShu<<"="<<sl_taishu;
        }

        te_content->append("sum ( "+list.join(",")+" )");
        te_content->append("sum ==========>> "+QString::number(sum)+" Total "+QString::number(TotalTaiShu)+" 台"+"\n");
          TotalTaiShu=0;
    }
}

void MainWindow::method_reset()
{
    te_content->clear();
    list.clear();
    method_clear();
    le_guige->setFocus();
    sl_state.clear();
    sl_content.clear();
    sl_taishu.clear();
}

void MainWindow::method_enterGuiGe()
{
    method_calc();
    le_guige->clearFocus();
    le_400->clearFocus();
    le_600->clearFocus();
    le_800->clearFocus();
    le_1000->clearFocus();
    le_1200->clearFocus();

}

void MainWindow::method_pop()
{
    if(!list.isEmpty()){
        list.pop_back();

        te_content->append("list pop >>>> "+list.join(",")+"\n");
    }

    if(!sl_taishu.isEmpty()){
        sl_taishu.pop_back();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//    qDebug()<<event->key();

    if(event->key()==Qt::Key_C)
    {

        method_sumadd();

    }

    if(event->key()==Qt::Key_W){
        le_guige->clear();

        le_guige->setFocus();

    }
    if(event->key()==Qt::Key_B){
        method_clear();
        le_guige->setFocus();
    }
    if(event->key()==Qt::Key_R){
        method_reset();
    }

    if(event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_E){
        le_guige->clearFocus();
        le_400->clearFocus();
        le_600->clearFocus();
        le_800->clearFocus();
        le_1000->clearFocus();
        le_1200->clearFocus();
        le_fb1_sl->clearFocus();
        le_fb2_sl->clearFocus();
        le_fb3_sl->clearFocus();
        le_fb1_size->clearFocus();
        le_fb2_size->clearFocus();
        le_fb3_size->clearFocus();

    }



    if(event->key()==Qt::Key_P){
        method_pop();
    }

    if(event->key()==Qt::Key_G){
        method_g();
    }

    //- key
    if(event->key()==45){
        le_guige->clear();
        le_guige->setText("-");
        le_guige->setFocus();
    }

}


