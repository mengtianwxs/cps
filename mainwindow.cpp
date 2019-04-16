#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("cps 计算排abc-n-pe");
    le_guige=ui->le_pai_guige;
    ui->le_p_danjai->setText("60");

    pb_calc=ui->pb_calc;
    pb_clear=ui->pb_clear;
    le_dj=ui->le_p_danjai;

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

     QRegExp regx("[1-9][0-9]{0,4}");
     QValidator *vali=new QRegExpValidator(regx,this);
     le_800->setValidator(vali);
     le_600->setValidator(vali);
     le_400->setValidator(vali);
     le_1000->setValidator(vali);
     le_1200->setValidator(vali);
     le_dj->setValidator(vali);

     QRegExp regx_guige("[1-9]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?\\+[1-9]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?\\+[1-9]?\\*?[1-9][0-9]?[0-9]?\\*[1-9][0-9]?");
     QValidator* vali_gg=new QRegExpValidator(regx_guige,this);
     le_guige->setValidator(vali_gg);



     le_guige->setPlaceholderText("2*100*10+2*80*8+2*40*4");

    connect(cb_tong,SIGNAL(stateChanged(int)),this,SLOT(method_cbt(int)));
    connect(cb_lv,SIGNAL(stateChanged(int)),this,SLOT(method_cbl(int)));




    connect(pb_calc,SIGNAL(clicked()),this,SLOT(method_calc()));
    connect(pb_clear,SIGNAL(clicked()),this,SLOT(method_clear()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::method_clear()
{
   le_guige->clear();

}

void MainWindow::method_calc()
{
    qDebug()<<le_guige->text()<<"ll";
    QString djs=le_dj->text();
    int dj=djs.toInt();
    QString txt=le_guige->text();
    QStringList sl=txt.split("+");
    //先判断+号把数组分成几个元素，首先大于0，才能操作。


    //配电柜的数量
    int s400=0;
    int s600=0;
    int s800=0;
    int s1000=0;
    int s1200=0;

    if(le_400->text()==""){
        s400=0;
    }else{
        s400=le_400->text().toInt();
    }

    if(le_600->text()==""){
        s600=0;

    }else{
        s600=le_600->text().toInt();
    }


    if(sl.length()>0){
        //只有A B C三项时的情况
        if(sl.length()==1){
            pabc=sl.at(0);
            //以 *号为分割符，查看是排的数量  100*10
            QStringList sls=pabc.split("*");
            qDebug()<<sls.length()<<sls.at(0);

            //单排模式
            if(sls.length()==2){
                pabc_width=sls.at(0);
                pabc_deep=sls.at(1);
                te_content->append(pabc_width+"*"+pabc_deep);
                int piabc_width=pabc_width.toInt();
                int piabc_deep=pabc_deep.toInt();


                if(state=="t"){

                te_content->append(QString::number(piabc_width*piabc_deep*8.9*dj/1000)+" TMY");
                te_content->append("=======================");
                }

                if(state=="l"){
                    te_content->append(QString::number(piabc_width*piabc_deep*2.7*dj/1000)+" LMY");
                    te_content->append("=======================");

                }


            }

            //双排以上 2*100*10 3*100*10
            if(sls.length()==3){
                int ps=sls.at(0).toInt();



            }



        }
        //A B C N
        if(sl.length()==2){

        }
        //A B C N PE
        if(sl.length()==3){

        }
    }


}

void MainWindow::method_cbt(int s)
{
    if(s==Qt::Checked){
        cb_lv->setChecked(false);
        cb_tong->setChecked(true);
        state="t";

    }
    qDebug()<<"state "<<state;

}

void MainWindow::method_cbl(int s)
{
    if(s==Qt::Checked){
        cb_tong->setChecked(false);
        cb_lv->setChecked(true);
        state="l";
    }

    qDebug()<<"state "<<state;

}
