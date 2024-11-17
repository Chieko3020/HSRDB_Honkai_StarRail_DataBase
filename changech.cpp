#include "changech.h"
#include "ui_changech.h"
#include "addcharacter.h"
#include <QSqlQuery>
#include <QMessageBox>
changech::changech(QWidget *parent,QString cch)
    : QWidget(parent)
    , ui(new Ui::changech)
{
    ui->setupUi(this);
    currentcharacter=cch;
    inittable();
}

changech::~changech()
{
    delete ui;
}

void changech::inittable()
{
    QRegularExpression  re("[ a-zA-Z0-9]+$");
    QValidator  *regv = new QRegularExpressionValidator(re, this);
    ui->search->setValidator(regv);
    model = new QSqlTableModel(this);
    model->setTable("Characters");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(12, Qt::Horizontal, tr("Trace1"));
    model->setHeaderData(13, Qt::Horizontal, tr("Value1"));
    model->setHeaderData(14, Qt::Horizontal, tr("Trace2"));
    model->setHeaderData(15, Qt::Horizontal, tr("Value2"));
    model->setHeaderData(16, Qt::Horizontal, tr("Trace3"));
    model->setHeaderData(17, Qt::Horizontal, tr("Value3"));
    model->setHeaderData(18, Qt::Horizontal, tr("SPDBoost"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setCurrentIndex(model->index(-1,-1));
    ui->sum->setText(QString("Total: %1").arg(ui->tableView->model()->rowCount()));
    connect(model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), ui->tableView, SLOT(update()));
}

void changech::updatetableviewafterinserted()
{
    model->submitAll();
    ui->sum->setText(QString("Total: %1").arg(ui->tableView->model()->rowCount()));
}

void changech::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString concept=model->data(model->index(index.row(),0)).toString();
    QString path=model->data(model->index(index.row(),3)).toString();
    emit sendch(concept,path);
    this->close();
}


void changech::on_add_clicked()
{
    AddCharacter* a=new AddCharacter;
    connect(a, &AddCharacter::updatetableview, this, &changech::updatetableviewafterinserted);
    a->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    a->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    a->setWindowModality(Qt::ApplicationModal);//模态
    a->show();
}


void changech::on_cancel_clicked()
{
    this->close();
}



void changech::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setText("Double click row to choose character.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void changech::on_remove_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    if(ui->tableView->currentIndex().row()!=-1)
    {
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText("Do you really want to delete "+model->data(model->index(ui->tableView->currentIndex().row(),0)).toString()+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec()==QMessageBox::No)
            return;
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You have not choose character who you want to remove.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }

    if(ui->tableView->currentIndex().row()!=-1)
    {
        QString dech=model->data(model->index(ui->tableView->currentIndex().row(),0)).toString();
        QSqlQuery query;
        query.prepare("delete Equipped where Concept= :Concept");
        query.bindValue(":Concept", dech);
        model->removeRow(ui->tableView->currentIndex().row());
        //删除选中的行
        if(query.exec()&&model->submitAll())
        {  
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("Succeed in delete character: "+dech+" .");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            ui->sum->setText(QString("Total: %1").arg(ui->tableView->model()->rowCount()));
            if(dech==currentcharacter)
                emit sendch("","");
        }
        else
            qDebug()<<"更新数据库失败";
    }
}


void changech::on_search_textChanged(const QString &arg1)
{
    QString filterstr=tr("Concept like '%%1%'").arg(arg1);
    model->setFilter(filterstr);
    ui->sum->setText(QString("Total: %1").arg(ui->tableView->model()->rowCount()));
}



