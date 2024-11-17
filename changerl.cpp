#include "changerl.h"
#include "ui_changerl.h"
#include <QMessageBox>
#include <QSqlQuery>
changerl::changerl(QWidget *parent,QString st,QString ch)
    : QWidget(parent)
    , ui(new Ui::changerl)
{
    ui->setupUi(this);
    slot=st;
    character=ch;
    inittable();
}

changerl::~changerl()
{
    delete ui;
}





void changerl::inittable()
{
    model = new QSqlTableModel(this);
    model->setTable("Relics");
    model->setFilter("Slot ='"+slot+"'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(1, Qt::Horizontal, tr("Set Name"));
    model->setHeaderData(3, Qt::Horizontal, tr("Name"));
    model->setHeaderData(4, Qt::Horizontal, tr("Level"));
    model->setHeaderData(6, Qt::Horizontal, tr("MainValue"));
    model->setHeaderData(8, Qt::Horizontal, tr("Value1"));
    model->setHeaderData(10, Qt::Horizontal, tr("Value2"));
    model->setHeaderData(12, Qt::Horizontal, tr("Value3"));
    model->setHeaderData(14, Qt::Horizontal, tr("Value4"));
    model->setHeaderData(15, Qt::Horizontal, tr("WhoEquipped"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    setCurrentrl(character);
    connect(model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), ui->tableView, SLOT(update()));
}


void changerl::setCurrentrl(QString ch)
{

    for (int row = 0; row < model->rowCount(); row++)
    {
        QModelIndex index = model->index(row, 1);
        if (model->data(model->index(row, 15)).toString() == ch)
        {
            ui->tableView->setCurrentIndex(index);
            return;
        }
    }
}









void changerl::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setText("Double click row to choose relic you want to equip.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void changerl::on_cancel_clicked()
{
    this->close();
}


void changerl::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString eq=model->data(model->index(index.row(),15)).toString();
    QSqlQuery query;
    QString renamenew=model->data(model->index(index.row(),3)).toString();
    int reidnew=model->data(model->index(index.row(),0)).toInt();
    if(eq!="")
    {
        if(eq==character)
        {
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setIcon(QMessageBox::Question);
            msgBox.setText("Do you want to remove '"+renamenew+"' from '"+character+"' ?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            if(msgBox.exec()==QMessageBox::No)
                return;
            else
            {
                query.prepare("update Equipped set "+slot+"=NULL where Concept=:Concept");
                query.bindValue(":Concept",character);
                if(query.exec())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                    msgBox.setText("Succeed in remove Relic: "+renamenew+" .");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    emit sendrl(slot,"");
                    this->close();
                }
                else
                    qDebug()<<"更新数据库失败";
            }
        }
        else
        {
            QSqlQuery query2,query3,query4;
            query2.prepare("select "+slot+" from Equipped where Concept=:Concept");
            query2.bindValue(":Concept",character);
            query2.exec();
            query2.next();
            if(query2.value(0).toInt()!=0)
            {
                int reidold=query2.value(0).toInt();
                query2.prepare("select SlotName from Relics where ID=:id");
                query2.bindValue(":id",reidold);
                query2.exec();
                query2.next();
                QString renameold=query2.value(0).toString();
                QMessageBox msgBox;
                msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                msgBox.setIcon(QMessageBox::Question);
                msgBox.setText("The '"+renamenew+"' is equipped in '"+eq+"' .\n"
                            "Now the '"+renameold+"' is equippd in '"+character+"' .\n"
                            "Do you want to replace '"+renameold+"' by '"+renamenew+"' ?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                if(msgBox.exec()==QMessageBox::No)
                    return;
                else
                {
                    query.prepare("update Equipped set "+slot+"=NULL where Concept=:Concept");
                    query.bindValue(":Concept",character);
                    query2.prepare("update Equipped set "+slot+"=NULL where Concept=:Concept");
                    query2.bindValue(":Concept",eq);
                    query3.prepare("update Relics set Equipped=:Concept where ID=:id");
                    query3.bindValue(":Concept",character);
                    query3.bindValue(":id",reidnew);
                    query4.prepare("update Relics set Equipped=:Concept where ID=:id");
                    query4.bindValue(":Concept",eq);
                    query4.bindValue(":id",reidold);
                    if(query.exec()&&query2.exec()&&query3.exec()&&query4.exec())
                    {
                        QMessageBox msgBox;
                        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                        msgBox.setText("Succeed in replace Relic by : "+renamenew+" .");
                        msgBox.setStandardButtons(QMessageBox::Ok);
                        msgBox.exec();
                        emit sendrl(slot,model->data(model->index(index.row(),1)).toString());
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
                msgBox.setText("The '"+renamenew+"' is equipped in '"+eq+"' .\n"
                                "Do you want to remove '"+renamenew+"' from '"+eq+"'\n"
                                "and equip it in '"+character+"' ?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                if(msgBox.exec()==QMessageBox::No)
                    return;
                else
                {
                    query.prepare("update Equipped set "+slot+"=NULL where Concept=:Concept");
                    query.bindValue(":Concept",eq);
                    query2.prepare("update Relics set Equipped=:Concept where ID=:id");
                    query2.bindValue(":Concept",character);
                    query2.bindValue(":id",reidnew);
                    if(query.exec()&&query2.exec())
                    {
                        QMessageBox msgBox;
                        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                        msgBox.setText("Succeed in equip Relic : "+renamenew+" .");
                        msgBox.setStandardButtons(QMessageBox::Ok);
                        msgBox.exec();
                        emit sendrl(slot,model->data(model->index(index.row(),1)).toString());
                        this->close();
                    }
                    else
                        qDebug()<<"更新数据库失败";
                }
            }

        }
    }
    else
    {
        QSqlQuery query2;
        query2.prepare("select "+slot+" from Equipped where Concept=:Concept");
        query2.bindValue(":Concept",character);
        query2.exec();
        query2.next();
        if(query2.value(0).toInt()!=0)
        {
            int reidold=query2.value(0).toInt();
            query2.prepare("select SlotName from Relics where ID=:id");
            query2.bindValue(":id",reidold);
            query2.exec();
            query2.next();
            QString renameold=query2.value(0).toString();
            QMessageBox msgBox;
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setIcon(QMessageBox::Question);
            msgBox.setText("Now the '"+renameold+"' is equippd in '"+character+"' .\n"
                            "Do you want to replace '"+renameold+"' by '"+renamenew+"' ?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            if(msgBox.exec()==QMessageBox::No)
                return;
            else
            {
                query.prepare("update Equipped set "+slot+"=NULL where Concept=:Concept");
                query.bindValue(":Concept",character);
                query2.prepare("update Relics set Equipped=:Concept where ID=:id");
                query2.bindValue(":Concept",character);
                query2.bindValue(":id",reidnew);
                if(query.exec()&&query2.exec())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                    msgBox.setText("Succeed in replace Relic by : "+renamenew+" .");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    emit sendrl(slot,model->data(model->index(index.row(),1)).toString());
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
            msgBox.setText("Do you want to Equip '"+renamenew+"' in '"+character+"' ?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            if(msgBox.exec()==QMessageBox::No)
                return;
            else
            {
                query.prepare("update Relics set Equipped=:Concept where ID=:id");
                query.bindValue(":Concept",character);
                query.bindValue(":id",reidnew);
                if(query.exec())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
                    msgBox.setText("Succeed in equip Relic : "+renamenew+" .");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    emit sendrl(slot,model->data(model->index(index.row(),1)).toString());
                    this->close();
                }
                else
                    qDebug()<<"更新数据库失败";
            }
        }
    }
}





















