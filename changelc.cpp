#include "changelc.h"
#include "ui_changelc.h"
#include <QMessageBox>
#include <QSqlQuery>
changelc::changelc(QWidget *parent,QString ch,QString lcp,QString clc)
    : QWidget(parent)
    , ui(new Ui::changelc)
{
    ui->setupUi(this);
    character=ch;
    lcpath=lcp;
    currentlc=clc;
    inittable();
}

changelc::~changelc()
{
    delete ui;
}


void changelc::inittable()
{
    model = new QSqlTableModel(this);
    model->setTable("LightCones");
    model->setFilter("Path ='"+lcpath+"'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(4, Qt::Horizontal, tr("Superimpose"));
    model->setHeaderData(8, Qt::Horizontal, tr("SkillBoost1"));
    model->setHeaderData(9, Qt::Horizontal, tr("Value1"));
    model->setHeaderData(10, Qt::Horizontal, tr("SkillBoost2"));
    model->setHeaderData(11, Qt::Horizontal, tr("Value2"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setColumnWidth(12,300);
    setCurrentlc(currentlc);
    connect(model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), ui->tableView, SLOT(update()));
}


void changelc::setCurrentlc(QString clc)
{

    for (int row = 0; row < model->rowCount(); row++)
    {
        QModelIndex index = model->index(row, 0);
        if (model->data(index).toString() == clc)
        {
            ui->tableView->setCurrentIndex(index);
            return;
        }
    }
}



void changelc::equip(QString concept)
{
    QSqlQuery query;
    if(currentlc!="")
    {
        if(currentlc==concept)
        {
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setIcon(QMessageBox::Question);
            msgBox.setText("Do you want to remove '"+currentlc+"' from '"+character+"' ?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            if(msgBox.exec()==QMessageBox::No)
                return;
            else
            {
                query.prepare("update Equipped set LightCone=NULL where Concept=:Concept");
                query.bindValue(":Concept",character);
                if(query.exec())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                    msgBox.setText("Succeed in remove LightCone: "+currentlc+" .");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    emit sendlc("");
                    this->close();
                }
                else
                    qDebug()<<"更新数据库失败";
            }
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setIcon(QMessageBox::Question);
            msgBox.setText("Do you want to replace '"+currentlc+"' by '"+concept+"' ?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            if(msgBox.exec()==QMessageBox::No)
                return;
            else
            {
                query.prepare("update Equipped set LightCone=NULL where Concept=:Concept");
                query.bindValue(":Concept",character);
                QSqlQuery query2;
                query2.prepare("update Equipped set LightCone=:Concept where Concept= :character");
                query2.bindValue(":Concept",concept);
                query2.bindValue(":character",character);
                if(query.exec()&&query2.exec())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                    msgBox.setText("Succeed in replace LightCone by : "+concept+" .");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    emit sendlc(concept);
                    this->close();
                }
                else
                    qDebug()<<"更新数据库失败";
            }
        }
    }
    else
    {
        query.prepare("update Equipped set LightCone=:Concept where Concept= :character");
        query.bindValue(":Concept",concept);
        query.bindValue(":character",character);
        if(query.exec())
        {
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("Succeed in equip LightCone: "+concept+" .");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            emit sendlc(concept);
            this->close();
        }
        else
            qDebug()<<"更新数据库失败";
    }
}

void changelc::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setText("Double click row to choose lightcone you want to equip.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void changelc::on_cancel_clicked()
{
    this->close();
}


void changelc::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString concept=model->data(model->index(index.row(),0)).toString();
    equip(concept);
}

