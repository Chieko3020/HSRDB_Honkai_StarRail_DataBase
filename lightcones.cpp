#include "lightcones.h"
#include "addlightcone.h"
#include <QScrollBar>
#include <QMessageBox>
#include <QSqlQuery>
Ui::MainWindow *uilc = nullptr;
static int nCurScroller=0; //翻页时的当时滑动条位置
static int pageValue = 5; // 一页显示条数
QString dplc="";

void ui_init_lightcones(Ui::MainWindow *ui_ptr)
{
    uilc = ui_ptr;

}




void MainWindow::resetlc()
{
    lcmodel->submitAll();

}




void MainWindow::initlctable()
{
    QRegularExpression  re("[ a-zA-Z0-9',!-]+$");
    QValidator  *regv = new QRegularExpressionValidator(re, this);
    uilc->searchlc->setValidator(regv);
    lcmodel = new QSqlTableModel(this);
    lcmodel->setTable("LightCones");
    lcmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    lcmodel->select();
    uilc->lctable->setModel(lcmodel);
    uilc->lctable->setColumnHidden(5,true);
    uilc->lctable->setColumnHidden(6,true);
    uilc->lctable->setColumnHidden(7,true);
    uilc->lctable->setColumnHidden(8,true);
    uilc->lctable->setColumnHidden(9,true);
    uilc->lctable->setColumnHidden(10,true);
    uilc->lctable->setColumnHidden(11,true);
    uilc->lctable->setColumnHidden(12,true);
    uilc->lctable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    uilc->lctable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:transparent;}");
    uilc->lctable->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    uilc->lctable->verticalHeader()->setDefaultSectionSize(100);
    uilc->lctable->horizontalHeader()->setDefaultSectionSize(175);
    uilc->lctable->setColumnWidth(0,100);
    uilc->lctable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    uilc->lctable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    uilc->lctable->setCurrentIndex(lcmodel->index(-1,-1));
    uilc->lctable->setItemDelegateForColumn(0,new ImageDelegate(lcmodel));
    connect(lcmodel, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), uilc->lctable, SLOT(update()));
}


void MainWindow::on_lctable_doubleClicked(const QModelIndex &index)
{
    QTableWidgetItem *lchp=new QTableWidgetItem(QString::number(lcmodel->data(lcmodel->index(index.row(),5)).toDouble(),'f',2));
    lchp->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
    QTableWidgetItem *lcatk=new QTableWidgetItem(QString::number(lcmodel->data(lcmodel->index(index.row(),6)).toDouble(),'f',2));
    lcatk->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
    QTableWidgetItem *lcdef=new QTableWidgetItem(QString::number(lcmodel->data(lcmodel->index(index.row(),7)).toDouble(),'f',2));
    lcdef->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
    uilc->skill->setText(lcmodel->data(lcmodel->index(index.row(),12)).toString());
    uilc->lcbase->setItem(0,0,lchp);
    uilc->lcbase->setItem(0,1,lcatk);
    uilc->lcbase->setItem(0,2,lcdef);
    uilc->lcbase->item(0,0)->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
    uilc->lcbase->item(0,1)->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
    uilc->lcbase->item(0,2)->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
    QString str1=lcmodel->data(lcmodel->index(index.row(),1)).toString();
    QString str2=lcmodel->data(lcmodel->index(index.row(),2)).toString();
    QString str3=lcmodel->data(lcmodel->index(index.row(),0)).toString();
    QString tachiePath=QString("%1%2%3%4%5%6%7").arg(":/lightcones/tachie/res/LightCones/tachie/")
                            .arg(str1).arg("stars/").arg(str2).arg("/").arg(str3).arg(".png");
    uilc->lctachie->setPixmap(QPixmap(tachiePath));
    dplc=str3;

}


void MainWindow::on_addlc_clicked()
{
    AddLightCone* a= new AddLightCone;
    connect(a, &AddLightCone::updatelc, this, &MainWindow::resetlc);
    a->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    a->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    a->setWindowModality(Qt::ApplicationModal);//模态
    a->show();
}


void MainWindow::on_removelc_clicked()
{
    QSqlQuery q;
    q.prepare("select Concept from Equipped where LightCone=:lc");
    q.bindValue(":lc",lcmodel->data(lcmodel->index(uilc->lctable->currentIndex().row(),0)).toString());
    q.exec();
    q.next();
    if(q.value(0).toString()!="")
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(""+lcmodel->data(lcmodel->index(uilc->lctable->currentIndex().row(),0)).toString()+" are be equipped by "+q.value(0).toString()+".\n Please remove it first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    if(uilc->lctable->currentIndex().row()!=-1)
    {
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText("Do you really want to delete "+lcmodel->data(lcmodel->index(uilc->lctable->currentIndex().row(),0)).toString()+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec()==QMessageBox::No)
            return;
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You have not choose LightCone which you want to delete.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }

    if(uilc->lctable->currentIndex().row()!=-1)
    {
        QString delc=lcmodel->data(lcmodel->index(uilc->lctable->currentIndex().row(),0)).toString();
        lcmodel->removeRow(uilc->lctable->currentIndex().row());
        if(lcmodel->submitAll())
        {
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("Succeed in delete LightCone: "+delc+" .");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            if(dplc==delc)
            {
                QTableWidgetItem *lchp=new QTableWidgetItem(QString::number(0.00,'f',2));
                lchp->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
                QTableWidgetItem *lcatk=new QTableWidgetItem(QString::number(0.00,'f',2));
                lcatk->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
                QTableWidgetItem *lcdef=new QTableWidgetItem(QString::number(0.00,'f',2));
                lcdef->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
                uilc->skill->setText("");
                uilc->lcbase->setItem(0,0,lchp);
                uilc->lcbase->setItem(0,1,lcatk);
                uilc->lcbase->setItem(0,2,lcdef);
                uilc->lcbase->item(0,0)->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                uilc->lcbase->item(0,1)->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                uilc->lcbase->item(0,2)->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                uilc->lctachie->setPixmap(QPixmap("://res/empty.png"));
            }
        }
        //删除选中的行
        else
            qDebug()<<"更新数据库失败";

    }
}




void MainWindow::on_prepage_clicked()
{
    int maxValue = uilc->lctable->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = uilc->lctable->verticalScrollBar()->value();

    if(nCurScroller>0)
        uilc->lctable->verticalScrollBar()->setSliderPosition(nCurScroller-pageValue);
    else
        uilc->lctable->verticalScrollBar()->setSliderPosition(maxValue);
}


void MainWindow::on_nexpage_clicked()
{
    int maxValue = uilc->lctable->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = uilc->lctable->verticalScrollBar()->value(); //获得当前scroller值

    if(nCurScroller<maxValue)
        uilc->lctable->verticalScrollBar()->setSliderPosition(pageValue+nCurScroller);
    else
        uilc->lctable->verticalScrollBar()->setSliderPosition(0);
}


void MainWindow::on_searchlc_textChanged(const QString &arg1)
{
    QString filterstr=tr("Concept like '%%1%'").arg(arg1);
    lcmodel->setFilter(filterstr);
}














