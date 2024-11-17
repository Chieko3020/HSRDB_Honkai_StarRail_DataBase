#include "panel.h"
#include "ui_panel.h"
#include <QSqlQuery>
Panel::Panel(QWidget *parent,QString ch)
    : QWidget(parent)
    , ui(new Ui::Panel)
{
    ui->setupUi(this);
    currentch=ch;
    inittable();
}

Panel::~Panel()
{
    delete ui;
}

void Panel::inittable()
{
    QSqlQuery query;
    query.prepare("select * from Panel where Concept=:concept");
    query.bindValue(":concept",currentch);
    if(query.exec()&&query.next())
    {
        QTableWidgetItem *Concept=new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem *Eidolons=new QTableWidgetItem(QString::number(query.value(1).toInt()));
        QTableWidgetItem *LightCone=new QTableWidgetItem(query.value(2).toString());
        QTableWidgetItem *SuperimposeLevel=new QTableWidgetItem(QString::number(query.value(3).toInt()));
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(query.value(4).toDouble(),'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(query.value(5).toDouble(),'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(query.value(6).toDouble(),'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(query.value(7).toDouble(),'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(query.value(8).toDouble(),'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(query.value(9).toDouble(),'f',2));
        QTableWidgetItem *BreakEffect=new QTableWidgetItem(QString::number(query.value(10).toDouble(),'f',2));

        QTableWidgetItem *OutgoingHealingBoost=new QTableWidgetItem(QString::number(query.value(11).toDouble(),'f',2));
        QTableWidgetItem *EnergyRegenerationRate=new QTableWidgetItem(QString::number(query.value(12).toDouble(),'f',2));
        QTableWidgetItem *EffectHitRate=new QTableWidgetItem(QString::number(query.value(13).toDouble(),'f',2));
        QTableWidgetItem *EffectRES=new QTableWidgetItem(QString::number(query.value(14).toDouble(),'f',2));
        QTableWidgetItem *PhysicalDMGBoost=new QTableWidgetItem(QString::number(query.value(15).toDouble(),'f',2));
        QTableWidgetItem *FireDMGBoost=new QTableWidgetItem(QString::number(query.value(16).toDouble(),'f',2));
        QTableWidgetItem *IceDMGBoost=new QTableWidgetItem(QString::number(query.value(17).toDouble(),'f',2));
        QTableWidgetItem *LightningDMGBoost=new QTableWidgetItem(QString::number(query.value(18).toDouble(),'f',2));
        QTableWidgetItem *WindDMGBoost=new QTableWidgetItem(QString::number(query.value(19).toDouble(),'f',2));
        QTableWidgetItem *QuantumDMGBoost=new QTableWidgetItem(QString::number(query.value(20).toDouble(),'f',2));
        QTableWidgetItem *ImaginaryDMGBoost=new QTableWidgetItem(QString::number(query.value(21).toDouble(),'f',2));

        ui->tableWidget->setItem(0,0,Concept);
        ui->tableWidget->setItem(1,0,Eidolons);
        ui->tableWidget->setItem(2,0,LightCone);
        ui->tableWidget->setItem(3,0,SuperimposeLevel);
        ui->tableWidget->setItem(4,0,HP);
        ui->tableWidget->setItem(5,0,ATK);
        ui->tableWidget->setItem(6,0,DEF);
        ui->tableWidget->setItem(7,0,SPD);
        ui->tableWidget->setItem(8,0,CritRate);
        ui->tableWidget->setItem(9,0,CritDMG);
        ui->tableWidget->setItem(10,0,BreakEffect);
        ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(1,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(2,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(3,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(4,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(5,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(6,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(7,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(8,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(9,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget->item(10,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        ui->tableWidget_2->setItem(0,0,OutgoingHealingBoost);
        ui->tableWidget_2->setItem(1,0,EnergyRegenerationRate);
        ui->tableWidget_2->setItem(2,0,EffectHitRate);
        ui->tableWidget_2->setItem(3,0,EffectRES);
        ui->tableWidget_2->setItem(4,0,PhysicalDMGBoost);
        ui->tableWidget_2->setItem(5,0,FireDMGBoost);
        ui->tableWidget_2->setItem(6,0,IceDMGBoost);
        ui->tableWidget_2->setItem(7,0,LightningDMGBoost);
        ui->tableWidget_2->setItem(8,0,WindDMGBoost);
        ui->tableWidget_2->setItem(9,0,QuantumDMGBoost);
        ui->tableWidget_2->setItem(10,0,ImaginaryDMGBoost);
        ui->tableWidget_2->item(0,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(1,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(2,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(3,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(4,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(5,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(6,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(7,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(8,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(9,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        ui->tableWidget_2->item(10,0)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    }


}

void Panel::on_closebtn_clicked()
{
    this->close();
}

