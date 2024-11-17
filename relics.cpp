#include "relics.h"
#include "addrelic.h"
#include <QScrollBar>
#include <QMessageBox>
#include <QSqlQuery>
Ui::MainWindow *uirl = nullptr;
static int nCurScroller2=0; //翻页时的当时滑动条位置
static int pageValue2 = 10; // 一页显示条数
int dprl=-1;

void ui_init_relics(Ui::MainWindow *ui_ptr)
{
    uirl = ui_ptr;
}

void MainWindow::initrltable()
{
    QRegularExpression  re("[ a-zA-Z0-9',]+$");
    QValidator  *regv = new QRegularExpressionValidator(re, this);
    uirl->searchrl->setValidator(regv);
    rlmodel = new QSqlTableModel(this);
    rlmodel->setTable("Relics");
    rlmodel->setHeaderData(1, Qt::Horizontal, tr("Set Name"));
    rlmodel->setHeaderData(3, Qt::Horizontal, tr("Name"));
    rlmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    rlmodel->select();
    uirl->rltable->setModel(rlmodel);
    uirl->rltable->setColumnHidden(0,true);
    uirl->rltable->setColumnHidden(5,true);
    uirl->rltable->setColumnHidden(6,true);
    uirl->rltable->setColumnHidden(7,true);
    uirl->rltable->setColumnHidden(8,true);
    uirl->rltable->setColumnHidden(9,true);
    uirl->rltable->setColumnHidden(10,true);
    uirl->rltable->setColumnHidden(11,true);
    uirl->rltable->setColumnHidden(12,true);
    uirl->rltable->setColumnHidden(13,true);
    uirl->rltable->setColumnHidden(14,true);
    uirl->rltable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    uirl->rltable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:transparent;}");
    uirl->rltable->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    uirl->rltable->verticalHeader()->setDefaultSectionSize(50);
    uirl->rltable->setColumnWidth(1,250);
    uirl->rltable->setColumnWidth(2,100);
    uirl->rltable->setColumnWidth(3,250);
    uirl->rltable->setColumnWidth(4,100);
    uirl->rltable->setColumnWidth(15,100);
    uirl->rltable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    uirl->rltable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    uirl->rltable->setCurrentIndex(rlmodel->index(-1,-1));
    connect(rlmodel, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), uirl->rltable, SLOT(update()));
}


void MainWindow::on_rltable_doubleClicked(const QModelIndex &index)
{
    QString str1=rlmodel->data(rlmodel->index(index.row(),1)).toString();
    QString str2=rlmodel->data(rlmodel->index(index.row(),2)).toString();
    dprl=rlmodel->data(rlmodel->index(index.row(),0)).toInt();
    if(str2=="Head"||str2=="Hands"||str2=="Body"||str2=="Feet")
    {
        QString iconPath=QString("%1%2%3%4%5").arg(":/relics/relic/res/Relics/Relic/").arg(str1).arg("/").arg(str2).arg(".png");
        uirl->rlicon->setPixmap(QPixmap(iconPath));
    }
    else if(str2=="PlanarSphere"||str2=="LinkRope")
    {
        QString iconPath=QString("%1%2%3%4%5").arg(":/relics/Planar Ornaments/res/Relics/Planar Ornaments/").arg(str1).arg("/").arg(str2).arg(".png");
        uirl->rlicon->setPixmap(QPixmap(iconPath));
    }
    QTableWidgetItem *rlms=new QTableWidgetItem(rlmodel->data(rlmodel->index(index.row(),5)).toString());
    QTableWidgetItem *rlmsv=new QTableWidgetItem(QString::number(rlmodel->data(rlmodel->index(index.row(),6)).toDouble(),'f',4));
    QTableWidgetItem *rlss1=new QTableWidgetItem(rlmodel->data(rlmodel->index(index.row(),7)).toString());
    QTableWidgetItem *rlssv1=new QTableWidgetItem(QString::number(rlmodel->data(rlmodel->index(index.row(),8)).toDouble(),'f',4));
    QTableWidgetItem *rlss2=new QTableWidgetItem(rlmodel->data(rlmodel->index(index.row(),9)).toString());
    QTableWidgetItem *rlssv2=new QTableWidgetItem(QString::number(rlmodel->data(rlmodel->index(index.row(),10)).toDouble(),'f',4));
    QTableWidgetItem *rlss3=new QTableWidgetItem(rlmodel->data(rlmodel->index(index.row(),11)).toString());
    QTableWidgetItem *rlssv3=new QTableWidgetItem(QString::number(rlmodel->data(rlmodel->index(index.row(),12)).toDouble(),'f',4));
    QTableWidgetItem *rlss4=new QTableWidgetItem(rlmodel->data(rlmodel->index(index.row(),13)).toString());
    QTableWidgetItem *rlssv4=new QTableWidgetItem(QString::number(rlmodel->data(rlmodel->index(index.row(),14)).toDouble(),'f',4));
    uirl->rlbase->setItem(0,0,rlms);
    uirl->rlbase->setItem(0,1,rlmsv);
    uirl->rlbase->setItem(1,0,rlss1);
    uirl->rlbase->setItem(1,1,rlssv1);
    uirl->rlbase->setItem(2,0,rlss2);
    uirl->rlbase->setItem(2,1,rlssv2);
    uirl->rlbase->setItem(3,0,rlss3);
    uirl->rlbase->setItem(3,1,rlssv3);
    uirl->rlbase->setItem(4,0,rlss4);
    uirl->rlbase->setItem(4,1,rlssv4);
    uirl->rlbase->item(0,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    uirl->rlbase->item(1,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    uirl->rlbase->item(2,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    uirl->rlbase->item(3,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    uirl->rlbase->item(4,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    uirl->rlbase->item(0,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uirl->rlbase->item(1,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uirl->rlbase->item(2,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uirl->rlbase->item(3,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uirl->rlbase->item(4,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uirl->rlbase->item(0,0)->setFont(QFont("Microsoft Yahei",9,QFont::Bold));
    uirl->rlbase->item(0,1)->setFont(QFont("Microsoft Yahei",9,QFont::Bold));
    uirl->rlbase->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}



void MainWindow::resetrl()
{
    rlmodel->submitAll();

}







void MainWindow::on_addrl_clicked()
{
    addrelic* a= new addrelic;
    connect(a, &addrelic::updaterl, this, &MainWindow::resetrl);
    a->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    a->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    a->setWindowModality(Qt::ApplicationModal);//模态
    a->show();
}


void MainWindow::on_removerl_clicked()
{
    QSqlQuery q;
    q.prepare("select Equipped from Relics where ID=:id");
    q.bindValue(":id",rlmodel->data(rlmodel->index(uirl->rltable->currentIndex().row(),0)).toString());
    q.exec();
    q.next();
    if(q.value(0).toString()!="")
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(""+rlmodel->data(rlmodel->index(uirl->rltable->currentIndex().row(),3)).toString()+" are be equipped by "+q.value(0).toString()+".");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    if(uirl->rltable->currentIndex().row()!=-1)
    {
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText("Do you really want to remove "+rlmodel->data(rlmodel->index(uirl->rltable->currentIndex().row(),3)).toString()+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec()==QMessageBox::No)
            return;
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You have not choose Relic which you want to remove.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }

    if(uirl->rltable->currentIndex().row()!=-1)
    {
        QString derl=rlmodel->data(rlmodel->index(uirl->rltable->currentIndex().row(),3)).toString();
        int derlid=rlmodel->data(rlmodel->index(uirl->rltable->currentIndex().row(),0)).toInt();
        rlmodel->removeRow(uirl->rltable->currentIndex().row());
        if(rlmodel->submitAll())
        {
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("Succeed in delete Relic: "+derl+" .");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            if(dprl==derlid)
            {
                uirl->rlicon->setPixmap(QPixmap("://res/empty.png"));
                QTableWidgetItem *rlms=new QTableWidgetItem("MainStat");
                QTableWidgetItem *rlmsv=new QTableWidgetItem(QString::number(0,'f',4));
                QTableWidgetItem *rlss1=new QTableWidgetItem("SubStat1");
                QTableWidgetItem *rlssv1=new QTableWidgetItem(QString::number(0,'f',4));
                QTableWidgetItem *rlss2=new QTableWidgetItem("SubStat2");
                QTableWidgetItem *rlssv2=new QTableWidgetItem(QString::number(0,'f',4));
                QTableWidgetItem *rlss3=new QTableWidgetItem("SubStat3");
                QTableWidgetItem *rlssv3=new QTableWidgetItem(QString::number(0,'f',4));
                QTableWidgetItem *rlss4=new QTableWidgetItem("SubStat4");
                QTableWidgetItem *rlssv4=new QTableWidgetItem(QString::number(0,'f',4));
                uirl->rlbase->setItem(0,0,rlms);
                uirl->rlbase->setItem(0,1,rlmsv);
                uirl->rlbase->setItem(1,0,rlss1);
                uirl->rlbase->setItem(1,1,rlssv1);
                uirl->rlbase->setItem(2,0,rlss2);
                uirl->rlbase->setItem(2,1,rlssv2);
                uirl->rlbase->setItem(3,0,rlss3);
                uirl->rlbase->setItem(3,1,rlssv3);
                uirl->rlbase->setItem(4,0,rlss4);
                uirl->rlbase->setItem(4,1,rlssv4);
                uirl->rlbase->item(0,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
                uirl->rlbase->item(1,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
                uirl->rlbase->item(2,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
                uirl->rlbase->item(3,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
                uirl->rlbase->item(4,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
                uirl->rlbase->item(0,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                uirl->rlbase->item(1,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                uirl->rlbase->item(2,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                uirl->rlbase->item(3,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                uirl->rlbase->item(4,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                uirl->rlbase->item(0,0)->setFont(QFont("Microsoft Yahei",9,QFont::Bold));
                uirl->rlbase->item(0,1)->setFont(QFont("Microsoft Yahei",9,QFont::Bold));
                uirl->rlbase->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            }
        }
        else
            qDebug()<<"更新数据库失败";
    }
}


void MainWindow::on_prepage_2_clicked()
{
    int maxValue = uirl->rltable->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller2 = uirl->rltable->verticalScrollBar()->value();

    if(nCurScroller2>0)
        uirl->rltable->verticalScrollBar()->setSliderPosition(nCurScroller2-pageValue2);
    else
        uirl->rltable->verticalScrollBar()->setSliderPosition(maxValue);
}


void MainWindow::on_nexpage_2_clicked()
{
    int maxValue = uirl->rltable->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller2 = uirl->rltable->verticalScrollBar()->value(); //获得当前scroller值

    if(nCurScroller2<maxValue)
        uirl->rltable->verticalScrollBar()->setSliderPosition(pageValue2+nCurScroller2);
    else
        uirl->rltable->verticalScrollBar()->setSliderPosition(0);
}


void MainWindow::on_searchrl_textChanged(const QString &arg1)
{
    QString filterstr=tr("Concept like '%%1%'").arg(arg1);
    rlmodel->setFilter(filterstr);
}























