#include "characters.h"
#include "changech.h"
#include "changelc.h"
#include "changerl.h"
#include "panel.h"
#include <QSqlQuery>
#include <QMessageBox>
Ui::MainWindow *uich = nullptr;

void ui_init_characters(Ui::MainWindow *ui_ptr)
{
    uich = ui_ptr;
}


void MainWindow::initch()
{
    uich->tachie->setPixmap(QPixmap(":/characters/4stars/res/Characters/4stars/The Hunt/March 7th The Hunt.png"));
    uich->concept->setText("March 7th The Hunt (Default)");
    uich->path->setText("The Hunt");
    uich->lcconcept->setText("In the night");
    uich->lcp->setPixmap(QPixmap(":/lightcones/icon/res/LightCones/icon/5stars/The Hunt/In the Night.png"));
    uich->lcskill->setText("Increases the wearer's CRIT Rate by 18%. While the wearer is in battle, for every 10 SPD that exceeds 100, increases DMG dealt by Basic ATK and Skill by 6%. At the same time, increases the CRIT DMG of Ultimate by 12%. This effect can stack up to 6 time(s).");
    uich->relicset1->setText("Musketeer of Wild Wheat");
    uich->relicset2->setText("Rutilant Arena");
    uich->cavern2->setText("Increases ATK by 12%.");
    uich->cavern4->setText("The wearer's SPD increases by 6% and DMG dealt by Basic ATK increases by 10%.");
    uich->planar2->setText("Increases the wearer's CRIT Rate by 8%. When the wearer's current CRIT Rate reaches 70% or higher, DMG dealt by Basic ATK and Skill increases by 20%.");
    uich->Head->setStyleSheet("border-image: url(:/relics/relic/res/Relics/Relic/Musketeer of Wild Wheat/Head.png);");
    uich->Hands->setStyleSheet("border-image: url(:/relics/relic/res/Relics/Relic/Musketeer of Wild Wheat/Hands.png);");
    uich->Body->setStyleSheet("border-image: url(:/relics/relic/res/Relics/Relic/Musketeer of Wild Wheat/Body.png);");
    uich->Feet->setStyleSheet("border-image: url(:/relics/relic/res/Relics/Relic/Musketeer of Wild Wheat/Feet.png);");
    uich->PlanarSphere->setStyleSheet("border-image: url(:/relics/Planar Ornaments/res/Relics/Planar Ornaments/Rutilant Arena/PlanarSphere.png);");
    uich->LinkRope->setStyleSheet("border-image: url(:/relics/Planar Ornaments/res/Relics/Planar Ornaments/Rutilant Arena/LinkRope.png);");
}





void MainWindow::recvch(QString c,QString p)
{
    uich->concept->setText(c);
    uich->path->setText(p);
    QSqlQuery q;
    q.prepare("select Rairty from Characters where Concept=:concept");
    q.bindValue(":concept",c);
    q.exec();
    q.next();
    if(q.value(0).toString()!="")
    {
        QString str1=q.value(0).toString();
        QString tachiePath=QString("%1%2%3%4%5%6%7%8%9").arg(":/characters/")
                                 .arg(str1).arg("stars/res/Characters/").arg(str1).arg("stars/")
                                 .arg(p).arg("/").arg(c).arg(".png");
        uich->tachie->setPixmap(QPixmap(tachiePath));
    }
    else
        uich->tachie->setPixmap(QPixmap(":/res/empty.png"));
    q.prepare("select HP,ATK,DEF,SPD,CritRate,CritDMG from Panel where Concept=:concept");
    q.bindValue(":concept",c);
    if(q.exec()&&q.next())
    {
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(q.value(0).toDouble(),'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(q.value(1).toDouble(),'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(q.value(2).toDouble(),'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(q.value(3).toDouble(),'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(q.value(4).toDouble(),'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(q.value(5).toDouble(),'f',2));
        HP->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        ATK->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        DEF->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        SPD->setIcon(QIcon(":/staticon/res/statsicon/spd.png"));
        CritRate->setIcon(QIcon(":/staticon/res/statsicon/critrate.png"));
        CritDMG->setIcon(QIcon(":/staticon/res/statsicon/critdmg.png"));
        uich->subpanel->setItem(0,0,HP);
        uich->subpanel->setItem(1,0,ATK);
        uich->subpanel->setItem(2,0,DEF);
        uich->subpanel->setItem(3,0,SPD);
        uich->subpanel->setItem(4,0,CritRate);
        uich->subpanel->setItem(5,0,CritDMG);
        uich->subpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(3,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(4,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(5,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
    else
    {
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(0.00,'f',2));
        HP->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        ATK->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        DEF->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        SPD->setIcon(QIcon(":/staticon/res/statsicon/spd.png"));
        CritRate->setIcon(QIcon(":/staticon/res/statsicon/critrate.png"));
        CritDMG->setIcon(QIcon(":/staticon/res/statsicon/critdmg.png"));
        uich->subpanel->setItem(0,0,HP);
        uich->subpanel->setItem(1,0,ATK);
        uich->subpanel->setItem(2,0,DEF);
        uich->subpanel->setItem(3,0,SPD);
        uich->subpanel->setItem(4,0,CritRate);
        uich->subpanel->setItem(5,0,CritDMG);
        uich->subpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(3,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(4,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(5,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
    q.prepare("select LightCone,Head,Hands,Body,Feet,PlanarSphere,LinkRope from Equipped where Concept=:concept");
    q.bindValue(":concept",c);
    q.exec();
    q.next();
    recvlc(q.value(0).toString());
    if(q.value(1).toInt()!=0)
    {
        QSqlQuery query;
        query.prepare("select Concept from Relics where ID=:id");
        query.bindValue(":id",q.value(1).toInt());
        query.exec();
        query.next();
        recvrl("Head",query.value(0).toString());
    }
    else
    {
        recvrl("Head","");
    }
    if(q.value(2).toInt()!=0)
    {
        QSqlQuery query;
        query.prepare("select Concept from Relics where ID=:id");
        query.bindValue(":id",q.value(2).toInt());
        query.exec();
        query.next();
        recvrl("Hands",query.value(0).toString());
    }
    else
    {
        recvrl("Hands","");
    }
    if(q.value(3).toInt()!=0)
    {
        QSqlQuery query;
        query.prepare("select Concept from Relics where ID=:id");
        query.bindValue(":id",q.value(3).toInt());
        query.exec();
        query.next();
        recvrl("Body",query.value(0).toString());
    }
    else
    {
        recvrl("Body","");
    }
    if(q.value(4).toInt()!=0)
    {
        QSqlQuery query;
        query.prepare("select Concept from Relics where ID=:id");
        query.bindValue(":id",q.value(4).toInt());
        query.exec();
        query.next();
        recvrl("Feet",query.value(0).toString());
    }
    else
    {
        recvrl("Feet","");
    }
    if(q.value(5).toInt()!=0)
    {
        QSqlQuery query;
        query.prepare("select Concept from Relics where ID=:id");
        query.bindValue(":id",q.value(5).toInt());
        query.exec();
        query.next();
        recvrl("PlanarSphere",query.value(0).toString());
    }
    else
    {
        recvrl("PlanarSphere","");
    }
    if(q.value(6).toInt()!=0)
    {
        QSqlQuery query;
        query.prepare("select Concept from Relics where ID=:id");
        query.bindValue(":id",q.value(6).toInt());
        query.exec();
        query.next();
        recvrl("LinkRope",query.value(0).toString());
    }
    else
    {
        recvrl("LinkRope","");
    }

}

void MainWindow::recvlc(QString lc)
{
    if(lc=="")
    {
        QTableWidgetItem *lchp=new QTableWidgetItem(QString::number(0.00,'f',2));
        lchp->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        QTableWidgetItem *lcatk=new QTableWidgetItem(QString::number(0.00,'f',2));
        lcatk->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        QTableWidgetItem *lcdef=new QTableWidgetItem(QString::number(0.00,'f',2));
        lcdef->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        uich->lcpanel->setItem(0,0,lchp);
        uich->lcpanel->setItem(1,0,lcatk);
        uich->lcpanel->setItem(2,0,lcdef);
        uich->lcpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->lcpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->lcpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->lcskill->setText("");
        uich->lcconcept->setText("");
        uich->lcp->setPixmap(QPixmap(":/res/empty.png"));
        return;
    }
    QSqlQuery query;
    query.prepare("select HP,ATK,DEF,Skill from LightCones where Concept=:lc");
    query.bindValue(":lc",lc);
    if(query.exec())
        query.next();
    QTableWidgetItem *lchp=new QTableWidgetItem(QString::number(query.value(0).toDouble(),'f',2));
    lchp->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
    QTableWidgetItem *lcatk=new QTableWidgetItem(QString::number(query.value(1).toDouble(),'f',2));
    lcatk->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
    QTableWidgetItem *lcdef=new QTableWidgetItem(QString::number(query.value(2).toDouble(),'f',2));
    lcdef->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
    uich->lcpanel->setItem(0,0,lchp);
    uich->lcpanel->setItem(1,0,lcatk);
    uich->lcpanel->setItem(2,0,lcdef);
    uich->lcpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uich->lcpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uich->lcpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    uich->lcskill->setText(query.value(3).toString());
    uich->lcconcept->setText(lc);
    query.prepare("select Rairty,Path from LightCones where Concept=:concept");
    query.bindValue(":concept",lc);
    query.exec();
    query.next();
    QString str1=query.value(0).toString();
    QString str2=query.value(1).toString();
    QString iconPath=QString("%1%2%3%4%5%6%7").arg(":/lightcones/icon/res/LightCones/icon/")
                             .arg(str1).arg("stars/").arg(str2).arg("/").arg(lc).arg(".png");
    uich->lcp->setPixmap(QPixmap(iconPath));

    QSqlQuery q;
    q.prepare("select HP,ATK,DEF,SPD,CritRate,CritDMG from Panel where Concept=:concept");
    q.bindValue(":concept",uich->concept->text());
    if(q.exec()&&q.next())
    {
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(q.value(0).toDouble(),'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(q.value(1).toDouble(),'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(q.value(2).toDouble(),'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(q.value(3).toDouble(),'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(q.value(4).toDouble(),'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(q.value(5).toDouble(),'f',2));
        HP->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        ATK->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        DEF->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        SPD->setIcon(QIcon(":/staticon/res/statsicon/spd.png"));
        CritRate->setIcon(QIcon(":/staticon/res/statsicon/critrate.png"));
        CritDMG->setIcon(QIcon(":/staticon/res/statsicon/critdmg.png"));
        uich->subpanel->setItem(0,0,HP);
        uich->subpanel->setItem(1,0,ATK);
        uich->subpanel->setItem(2,0,DEF);
        uich->subpanel->setItem(3,0,SPD);
        uich->subpanel->setItem(4,0,CritRate);
        uich->subpanel->setItem(5,0,CritDMG);
        uich->subpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(3,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(4,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(5,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
    else
    {
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(0.00,'f',2));
        HP->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        ATK->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        DEF->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        SPD->setIcon(QIcon(":/staticon/res/statsicon/spd.png"));
        CritRate->setIcon(QIcon(":/staticon/res/statsicon/critrate.png"));
        CritDMG->setIcon(QIcon(":/staticon/res/statsicon/critdmg.png"));
        uich->subpanel->setItem(0,0,HP);
        uich->subpanel->setItem(1,0,ATK);
        uich->subpanel->setItem(2,0,DEF);
        uich->subpanel->setItem(3,0,SPD);
        uich->subpanel->setItem(4,0,CritRate);
        uich->subpanel->setItem(5,0,CritDMG);
        uich->subpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(3,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(4,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(5,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
}


void MainWindow::recvrl(QString st,QString cp)
{
    if(st=="Head"||st=="Hands"||st=="Body"||st=="Feet")
    {
        QString iconPath=QString("%1%2%3%4%5").arg(":/relics/relic/res/Relics/Relic/").arg(cp).arg("/").arg(st).arg(".png");
        if(st=="Head")
        {
            if(cp!="")
                uich->Head->setStyleSheet(QString("border-image: url(%1);").arg(iconPath));
            else
                uich->Head->setStyleSheet(QString("border-image: url(%1);").arg(":/res/empty.png"));
            relicset[0]=cp;
        }
        else if(st=="Hands")
        {
            if(cp!="")
                uich->Hands->setStyleSheet(QString("border-image: url(%1);").arg(iconPath));
            else
                uich->Hands->setStyleSheet(QString("border-image: url(%1);").arg(":/res/empty.png"));
            relicset[1]=cp;
        }
        else if(st=="Body")
        {
            if(cp!="")
                uich->Body->setStyleSheet(QString("border-image: url(%1);").arg(iconPath));
            else
                uich->Body->setStyleSheet(QString("border-image: url(%1);").arg(":/res/empty.png"));
            relicset[2]=cp;
        }
        else if(st=="Feet")
        {
            if(cp!="")
                uich->Feet->setStyleSheet(QString("border-image: url(%1);").arg(iconPath));
            else
                uich->Feet->setStyleSheet(QString("border-image: url(%1);").arg(":/res/empty.png"));
            relicset[3]=cp;
        }
    }
    else if(st=="PlanarSphere"||st=="LinkRope")
    {
        QString iconPath=QString("%1%2%3%4%5").arg(":/relics/Planar Ornaments/res/Relics/Planar Ornaments/").arg(cp).arg("/").arg(st).arg(".png");
        if(st=="PlanarSphere")
        {
            if(cp!="")
                uich->PlanarSphere->setStyleSheet(QString("border-image: url(%1);").arg(iconPath));
            else
                uich->PlanarSphere->setStyleSheet(QString("border-image: url(%1);").arg(":/res/empty.png"));
            relicset[4]=cp;
        }
        else if(st=="LinkRope")
        {
            if(cp!="")
                uich->LinkRope->setStyleSheet(QString("border-image: url(%1);").arg(iconPath));
            else
                uich->LinkRope->setStyleSheet(QString("border-image: url(%1);").arg(":/res/empty.png"));
            relicset[5]=cp;
        }
    }
    if(relicset[0]==relicset[1])
    {
        ui->relicset1->setText(relicset[0]);
        ui->cavern2->setText(judgerelicsetCavern2pc(relicset[0]));
        if(!(relicset[0]==relicset[1]&&relicset[1]==relicset[2]&&relicset[2]==relicset[3]))
        {
            if(relicset[2]==relicset[3])
            {
                ui->relicset1->setText(QString("%1\n%2").arg(relicset[0]).arg(relicset[2]));
                ui->cavern4->setText(judgerelicsetCavern2pc(relicset[2]));
            }
            else
            {
                ui->cavern4->setText("");
            }
        }
        else
        {
            ui->cavern4->setText(judgerelicsetCavern4pc(relicset[0]));
        }
    }
    else if(relicset[0]==relicset[2])
    {
        ui->relicset1->setText(relicset[0]);
        ui->cavern2->setText(judgerelicsetCavern2pc(relicset[0]));
        if(!(relicset[0]==relicset[1]&&relicset[1]==relicset[2]&&relicset[2]==relicset[3]))
        {
            if(relicset[1]==relicset[3])
            {
                ui->relicset1->setText(QString("%1\n%2").arg(relicset[0]).arg(relicset[1]));
                ui->cavern4->setText(judgerelicsetCavern2pc(relicset[1]));
            }
            else
            {
                ui->cavern4->setText("");
            }
        }
        else
        {
            ui->cavern4->setText(judgerelicsetCavern4pc(relicset[0]));
        }
    }
    else if(relicset[0]==relicset[3])
    {
        ui->relicset1->setText(relicset[0]);
        ui->cavern2->setText(judgerelicsetCavern2pc(relicset[0]));
        if(!(relicset[0]==relicset[1]&&relicset[1]==relicset[2]&&relicset[2]==relicset[3]))
        {
            if(relicset[1]==relicset[2])
            {
                ui->relicset1->setText(QString("%1\n%2").arg(relicset[0]).arg(relicset[1]));
                ui->cavern4->setText(judgerelicsetCavern2pc(relicset[1]));
            }
            else
            {
                ui->cavern4->setText("");
            }
        }
        else
        {
            ui->cavern4->setText(judgerelicsetCavern4pc(relicset[0]));
        }
    }
    else if(relicset[1]==relicset[2])
    {
        ui->relicset1->setText(relicset[1]);
        ui->cavern2->setText(judgerelicsetCavern2pc(relicset[1]));
        if(!(relicset[0]==relicset[1]&&relicset[1]==relicset[2]&&relicset[2]==relicset[3]))
        {
            if(relicset[3]==relicset[4])
            {
                ui->relicset1->setText(QString("%1\n%2").arg(relicset[1]).arg(relicset[3]));
                ui->cavern4->setText(judgerelicsetCavern2pc(relicset[3]));
            }
            else
            {
                ui->cavern4->setText("");
            }
        }
        else
        {
            ui->cavern4->setText(judgerelicsetCavern4pc(relicset[0]));
        }
    }
    else if(relicset[1]==relicset[3])
    {
        ui->relicset1->setText(relicset[1]);
        ui->cavern2->setText(judgerelicsetCavern2pc(relicset[1]));
        if(!(relicset[0]==relicset[1]&&relicset[1]==relicset[2]&&relicset[2]==relicset[3]))
        {
            if(relicset[2]==relicset[4])
            {
                ui->relicset1->setText(QString("%1\n%2").arg(relicset[1]).arg(relicset[2]));
                ui->cavern4->setText(judgerelicsetCavern2pc(relicset[2]));
            }
            else
            {
                ui->cavern4->setText("");
            }
        }
        else
        {
            ui->cavern4->setText(judgerelicsetCavern4pc(relicset[0]));
        }
    }
    else if(relicset[2]==relicset[3])
    {
        ui->relicset1->setText(relicset[2]);
        ui->cavern2->setText(judgerelicsetCavern2pc(relicset[2]));
        if(!(relicset[0]==relicset[1]&&relicset[1]==relicset[2]&&relicset[2]==relicset[3]))
        {
            if(relicset[1]==relicset[4])
            {
                ui->relicset1->setText(QString("%1\n%2").arg(relicset[2]).arg(relicset[1]));
                ui->cavern4->setText(judgerelicsetCavern2pc(relicset[1]));
            }
            else
            {
                ui->cavern4->setText("");
            }
        }
        else
        {
            ui->cavern4->setText(judgerelicsetCavern4pc(relicset[0]));
        }
    }
    else
    {
        ui->relicset1->setText("");
        ui->cavern2->setText("");
        ui->cavern4->setText("");
    }
    if(relicset[4]==relicset[5])
    {
        ui->relicset2->setText(relicset[4]);
        ui->planar2->setText(judgerelicsetPlanar2pc(relicset[4]));
    }
    else
    {
        ui->relicset2->setText("");
        ui->planar2->setText("");
    }

    QSqlQuery q;
    q.prepare("select HP,ATK,DEF,SPD,CritRate,CritDMG from Panel where Concept=:concept");
    q.bindValue(":concept",uich->concept->text());
    if(q.exec()&&q.next())
    {
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(q.value(0).toDouble(),'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(q.value(1).toDouble(),'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(q.value(2).toDouble(),'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(q.value(3).toDouble(),'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(q.value(4).toDouble(),'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(q.value(5).toDouble(),'f',2));
        HP->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        ATK->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        DEF->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        SPD->setIcon(QIcon(":/staticon/res/statsicon/spd.png"));
        CritRate->setIcon(QIcon(":/staticon/res/statsicon/critrate.png"));
        CritDMG->setIcon(QIcon(":/staticon/res/statsicon/critdmg.png"));
        uich->subpanel->setItem(0,0,HP);
        uich->subpanel->setItem(1,0,ATK);
        uich->subpanel->setItem(2,0,DEF);
        uich->subpanel->setItem(3,0,SPD);
        uich->subpanel->setItem(4,0,CritRate);
        uich->subpanel->setItem(5,0,CritDMG);
        uich->subpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(3,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(4,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(5,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
    else
    {
        QTableWidgetItem *HP=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *ATK=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *DEF=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *SPD=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *CritRate=new QTableWidgetItem(QString::number(0.00,'f',2));
        QTableWidgetItem *CritDMG=new QTableWidgetItem(QString::number(0.00,'f',2));
        HP->setIcon(QIcon(":/staticon/res/statsicon/hp.png"));
        ATK->setIcon(QIcon(":/staticon/res/statsicon/atk.png"));
        DEF->setIcon(QIcon(":/staticon/res/statsicon/def.png"));
        SPD->setIcon(QIcon(":/staticon/res/statsicon/spd.png"));
        CritRate->setIcon(QIcon(":/staticon/res/statsicon/critrate.png"));
        CritDMG->setIcon(QIcon(":/staticon/res/statsicon/critdmg.png"));
        uich->subpanel->setItem(0,0,HP);
        uich->subpanel->setItem(1,0,ATK);
        uich->subpanel->setItem(2,0,DEF);
        uich->subpanel->setItem(3,0,SPD);
        uich->subpanel->setItem(4,0,CritRate);
        uich->subpanel->setItem(5,0,CritDMG);
        uich->subpanel->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(2,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(3,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(4,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        uich->subpanel->item(5,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
}







QString MainWindow::judgerelicsetCavern2pc(QString set)
{
    if(set!="")
    for(int i=0;i<=19;i++)
    {
        if(set==CavernRelics[i])
        {
            return CavernRelics2pc[i];
        }
    }
    return "";
}


QString MainWindow::judgerelicsetCavern4pc(QString set)
{
    if(set!="")
    for(int i=0;i<=19;i++)
    {
        if(set==CavernRelics[i])
        {
            return CavernRelics4pc[i];
        }
    }
    return "";
}


QString MainWindow::judgerelicsetPlanar2pc(QString set)
{
    if(set!="")
    for(int i=0;i<=17;i++)
    {
        if(set==PlanarOrnaments[i])
        {
            return PlanarOrnaments2pc[i];
        }
    }
    return "";
}

void MainWindow::on_morebtn_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    Panel* p= new Panel(nullptr,uich->concept->text());
    p->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    p->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    p->setWindowModality(Qt::ApplicationModal);//模态
    p->show();
}



void MainWindow::on_modifych_clicked()
{
    changech* c= new changech(nullptr,uich->concept->text());
    connect(c,&changech::sendch,this,&MainWindow::recvch);
    c->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    c->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    c->setWindowModality(Qt::ApplicationModal);//模态
    c->show();
}

void MainWindow::on_modifylc_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changelc* l= new changelc(nullptr,uich->concept->text(),uich->path->text(),uich->lcconcept->text());
    connect(l,&changelc::sendlc,this,&MainWindow::recvlc);
    l->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    l->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    l->setWindowModality(Qt::ApplicationModal);//模态
    l->show();


}


void MainWindow::on_Head_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changerl* r= new changerl(nullptr,uich->Head->objectName(),uich->concept->text());
    connect(r,&changerl::sendrl,this,&MainWindow::recvrl);
    r->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    r->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    r->setWindowModality(Qt::ApplicationModal);//模态
    r->show();
}


void MainWindow::on_Hands_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changerl* r= new changerl(nullptr,uich->Hands->objectName(),uich->concept->text());
    connect(r,&changerl::sendrl,this,&MainWindow::recvrl);
    r->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    r->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    r->setWindowModality(Qt::ApplicationModal);//模态
    r->show();
}


void MainWindow::on_Body_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changerl* r= new changerl(nullptr,uich->Body->objectName(),uich->concept->text());
    connect(r,&changerl::sendrl,this,&MainWindow::recvrl);
    r->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    r->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    r->setWindowModality(Qt::ApplicationModal);//模态
    r->show();
}


void MainWindow::on_Feet_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changerl* r= new changerl(nullptr,uich->Feet->objectName(),uich->concept->text());
    connect(r,&changerl::sendrl,this,&MainWindow::recvrl);
    r->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    r->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    r->setWindowModality(Qt::ApplicationModal);//模态
    r->show();
}


void MainWindow::on_PlanarSphere_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changerl* r= new changerl(nullptr,uich->PlanarSphere->objectName(),uich->concept->text());
    connect(r,&changerl::sendrl,this,&MainWindow::recvrl);
    r->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    r->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    r->setWindowModality(Qt::ApplicationModal);//模态
    r->show();
}


void MainWindow::on_LinkRope_clicked()
{
    if(ui->concept->text()=="March 7th The Hunt (Default)")
    {   QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Select character first.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    changerl* r= new changerl(nullptr,uich->LinkRope->objectName(),uich->concept->text());
    connect(r,&changerl::sendrl,this,&MainWindow::recvrl);
    r->setAttribute(Qt::WA_DeleteOnClose);//关闭即销毁窗口
    r->setAttribute(Qt::WA_QuitOnClose,false);//仅主窗口关闭可结束进程
    r->setWindowModality(Qt::ApplicationModal);//模态
    r->show();
}
