#include "addcharacter.h"
#include "ui_addcharacter.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QCompleter>
AddCharacter::AddCharacter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddCharacter)
{
    ui->setupUi(this);
    QStringList wordList;
    wordList << "Acheron" << "Argenti" << "Arlan" << "Asta" << "Aventurine"
        << "Bailu" << "Black Swan" << "Blade" << "Boothill" << "Bronya"
        << "Clara"
        << "Dan Heng" << "Dan Heng Imbibitor Lunae"
        << "Feixiao" << "Firefly" << "Fu Xuan"
        << "Gallagher" << "Gepard" << "Guinaifen"
        << "Hanya" << "Herta" << "Himeko" << "Hook" << "Huohuo"
        << "Jade" << "Jiaoqiu" << "Jing Yuan" << "Jingliu"
        << "Kafka"
        << "Lingsha" << "Luka" << "Luocha" << "Lynx"
        << "March 7th Preservation" << "March 7th The Hunt" << "Misha" << "Moze" << "Natasha"
        << "Pela"
        << "Qingque"
        << "Robin" << "Ruan Mei" << "Ratio"
        << "Sampo" << "Seele" << "Serval" << "Silver Wolf" << "Sparkle" << "Sushang"
        << "Tingyun" << "Topaz Numby" << "Trailblazer Destruction" << "Trailblazer Harmony"<< "Trailblazer Preservation"
        << "Welt"
        << "Xueyi"
        << "Yanqing" << "Yukong" << "Yunli";
    QCompleter *completer = new QCompleter(wordList, ui->concept);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->concept->setCompleter(completer);
    QRegularExpression  re("[ a-zA-Z0-9]+$");
    QValidator  *regv = new QRegularExpressionValidator(re, this);
    ui->concept->setValidator(regv);
    model = new QSqlTableModel(this);
    model->setTable("Characters");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    connect(ui->checkBox_1, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_2, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_3, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_4, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_5, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_6, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_7, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_8, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_9, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_10, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_11, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_12, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_13, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_14, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_15, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_16, SIGNAL(clicked()), this, SLOT(getcheckbox()));
}

AddCharacter::~AddCharacter()
{
    delete ui;
}
void AddCharacter::getcheckbox()
{

    QObject *obj = QObject::sender();
    QCheckBox *chb = qobject_cast<QCheckBox *>(obj);
    if (chb->isChecked())
        sum++;
    else
        sum--;
    if (4 == sum)
    {
        chb->toggle();
        sum--;
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You must choose 3 traces.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}


void AddCharacter::on_checkBox_1_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->ATKBoostPercentage->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->ATKBoostPercentage->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->DEFBoostPercentage->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->DEFBoostPercentage->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->HPBoostPercentage->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->HPBoostPercentage->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->SPDBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->SPDBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->BreakEffect->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->BreakEffect->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_6_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->EffectHitRate->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->EffectHitRate->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_7_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->EffectRES->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->EffectRES->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_8_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->CritRate->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->CritRate->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_9_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->CritDMG->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->CritDMG->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_10_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->PhysialDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->PhysialDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_11_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->FireDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->FireDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_12_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->IceDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->IceDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_13_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->LightningDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->LightningDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_14_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->WindDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->WindDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_15_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->QuantumDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->QuantumDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_checkBox_16_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->ImaginaryDMGBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->ImaginaryDMGBoost->setReadOnly(true);
    }
}


void AddCharacter::on_calcelbtn_clicked()
{
    this->close();
}


void AddCharacter::on_configuebtn_clicked()
{
    if(sum!=3)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("You must choose 3 traces.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if(ui->concept->text()=="")
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Concept is NULL.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if(ui->BaseHP->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("BaseHP is NULL.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if(ui->BaseATK->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("BaseATK is NULL.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if(ui->BaseDEF->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("BaseDEF is NULL.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if(ui->BaseSPD->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("BaseSPD is NULL.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    double checkbox[16]={0.000};
    if(ui->checkBox_1->isChecked())
    {
        if(ui->ATKBoostPercentage->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("ATKBoostPercentage is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[0]=ui->ATKBoostPercentage->value();
    }
    if(ui->checkBox_2->isChecked())
    {
        if(ui->DEFBoostPercentage->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("DEFBoostPercentage is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[1]=ui->DEFBoostPercentage->value();
    }
    if(ui->checkBox_3->isChecked())
    {
        if(ui->HPBoostPercentage->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("HPBoostPercentage is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[2]=ui->HPBoostPercentage->value();
    }
    if(ui->checkBox_4->isChecked())
    {
        if(ui->SPDBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("SPDBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[3]=ui->SPDBoost->value();
    }
    if(ui->checkBox_5->isChecked())
    {
        if(ui->BreakEffect->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("BreakEffect is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[4]=ui->BreakEffect->value();
    }
    if(ui->checkBox_6->isChecked())
    {
        if(ui->EffectHitRate->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("EffectHitRate is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[5]=ui->EffectHitRate->value();
    }
    if(ui->checkBox_7->isChecked())
    {
        if(ui->EffectRES->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("EffectRES is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[6]=ui->EffectRES->value();
    }
    if(ui->checkBox_8->isChecked())
    {
        if(ui->CritRate->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("CritRate is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[7]=ui->CritRate->value();
    }
    if(ui->checkBox_9->isChecked())
    {
        if(ui->CritDMG->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("CritDMG is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[8]=ui->CritDMG->value();
    }
    if(ui->checkBox_10->isChecked())
    {
        if(ui->PhysialDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("PhysialDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[9]=ui->PhysialDMGBoost->value();
    }
    if(ui->checkBox_11->isChecked())
    {
        if(ui->FireDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("FireDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[10]=ui->FireDMGBoost->value();
    }
    if(ui->checkBox_12->isChecked())
    {
        if(ui->IceDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("IceDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[11]=ui->IceDMGBoost->value();
    }
    if(ui->checkBox_13->isChecked())
    {
        if(ui->LightningDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("LightningDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[12]=ui->LightningDMGBoost->value();
    }
    if(ui->checkBox_14->isChecked())
    {
        if(ui->WindDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("WindDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[13]=ui->WindDMGBoost->value();
    }
    if(ui->checkBox_15->isChecked())
    {
        if(ui->QuantumDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("QuantumDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[14]=ui->QuantumDMGBoost->value();
    }
    if(ui->checkBox_16->isChecked())
    {
        if(ui->ImaginaryDMGBoost->value()==0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
            msgBox.setText("ImaginaryDMGBoost is NULL.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        checkbox[15]=ui->ImaginaryDMGBoost->value();
    }

    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Are you really going to submit ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(msgBox.exec()==QMessageBox::No)
        return;

    int t1=-1,t2=-1,t3=-1;
    for(int i=0;i<=15;i++)
    {
        if(checkbox[i]!=0)
        {
            t1=i;
            for(int j=i+1;j<=15;j++)
            {
                if(checkbox[j]!=0)
                {
                    t2=j;
                    for(int k=j+1;k<=15;k++)
                    {
                        if(checkbox[k]!=0)
                        {
                            t3=k;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    int row = model->rowCount();
    model->insertRow(model->rowCount());
    model->setData(model->index(row,0),ui->concept->text());
    model->setData(model->index(row,1),ui->Faction->currentText());
    model->setData(model->index(row,2),ui->rairty->currentText());
    model->setData(model->index(row,3),ui->path->currentText());
    model->setData(model->index(row,4),ui->combat->currentText());
    model->setData(model->index(row,5),ui->level->value());
    model->setData(model->index(row,6),ui->eidolon->value());
    model->setData(model->index(row,7),ui->BaseHP->value());
    model->setData(model->index(row,8),ui->BaseATK->value());
    model->setData(model->index(row,9),ui->BaseDEF->value());
    model->setData(model->index(row,10),ui->BaseSPD->value());
    model->setData(model->index(row,11),ui->Energy->value());
    if(t1!=-1)
    {
        if(t1==0)
        {
            model->setData(model->index(row,12),ui->ATKBoostPercentage->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==1)
        {
            model->setData(model->index(row,12),ui->DEFBoostPercentage->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==2)
        {
            model->setData(model->index(row,12),ui->HPBoostPercentage->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==3)
        {
            model->setData(model->index(row,12),ui->SPDBoost->objectName());
            model->setData(model->index(row,13),0);
            model->setData(model->index(row,18),checkbox[t1]);
        }
        else if(t1==4)
        {
            model->setData(model->index(row,12),ui->BreakEffect->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==5)
        {
            model->setData(model->index(row,12),ui->EffectHitRate->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==6)
        {
            model->setData(model->index(row,12),ui->EffectRES->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==7)
        {
            model->setData(model->index(row,12),ui->CritRate->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==8)
        {
            model->setData(model->index(row,12),ui->CritDMG->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==9)
        {
            model->setData(model->index(row,12),ui->PhysialDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==10)
        {
            model->setData(model->index(row,12),ui->FireDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==11)
        {
            model->setData(model->index(row,12),ui->IceDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==12)
        {
            model->setData(model->index(row,12),ui->LightningDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==13)
        {
            model->setData(model->index(row,12),ui->WindDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==14)
        {
            model->setData(model->index(row,12),ui->QuantumDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        else if(t1==15)
        {
            model->setData(model->index(row,12),ui->ImaginaryDMGBoost->objectName());
            model->setData(model->index(row,13),checkbox[t1]);
        }
        if(t2!=-1)
        {
            if(t2==0)
            {
                model->setData(model->index(row,14),ui->ATKBoostPercentage->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==1)
            {
                model->setData(model->index(row,14),ui->DEFBoostPercentage->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==2)
            {
                model->setData(model->index(row,14),ui->HPBoostPercentage->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==3)
            {
                model->setData(model->index(row,14),ui->SPDBoost->objectName());
                model->setData(model->index(row,15),0);
                model->setData(model->index(row,18),checkbox[t2]);
            }
            else if(t2==4)
            {
                model->setData(model->index(row,14),ui->BreakEffect->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==5)
            {
                model->setData(model->index(row,14),ui->EffectHitRate->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==6)
            {
                model->setData(model->index(row,14),ui->EffectRES->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==7)
            {
                model->setData(model->index(row,14),ui->CritRate->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==8)
            {
                model->setData(model->index(row,14),ui->CritDMG->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==9)
            {
                model->setData(model->index(row,14),ui->PhysialDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==10)
            {
                model->setData(model->index(row,14),ui->FireDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==11)
            {
                model->setData(model->index(row,14),ui->IceDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==12)
            {
                model->setData(model->index(row,14),ui->LightningDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==13)
            {
                model->setData(model->index(row,14),ui->WindDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==14)
            {
                model->setData(model->index(row,14),ui->QuantumDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            else if(t2==15)
            {
                model->setData(model->index(row,14),ui->ImaginaryDMGBoost->objectName());
                model->setData(model->index(row,15),checkbox[t2]);
            }
            if(t3!=-1)
            {
                if(t3==0)
                {
                    model->setData(model->index(row,16),ui->ATKBoostPercentage->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==1)
                {
                    model->setData(model->index(row,16),ui->DEFBoostPercentage->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==2)
                {
                    model->setData(model->index(row,16),ui->HPBoostPercentage->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==3)
                {
                    model->setData(model->index(row,16),ui->SPDBoost->objectName());
                    model->setData(model->index(row,17),0);
                    model->setData(model->index(row,18),checkbox[t3]);
                }
                else if(t3==4)
                {
                    model->setData(model->index(row,16),ui->BreakEffect->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==5)
                {
                    model->setData(model->index(row,16),ui->EffectHitRate->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==6)
                {
                    model->setData(model->index(row,16),ui->EffectRES->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==7)
                {
                    model->setData(model->index(row,16),ui->CritRate->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==8)
                {
                    model->setData(model->index(row,16),ui->CritDMG->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==9)
                {
                    model->setData(model->index(row,16),ui->PhysialDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==10)
                {
                    model->setData(model->index(row,16),ui->FireDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==11)
                {
                    model->setData(model->index(row,16),ui->IceDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==12)
                {
                    model->setData(model->index(row,16),ui->LightningDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==13)
                {
                    model->setData(model->index(row,16),ui->WindDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==14)
                {
                    model->setData(model->index(row,16),ui->QuantumDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
                else if(t3==15)
                {
                    model->setData(model->index(row,16),ui->ImaginaryDMGBoost->objectName());
                    model->setData(model->index(row,17),checkbox[t3]);
                }
            }
        }
    }
    if(t1!=3&&t2!=3&&t3!=3)
        model->setData(model->index(row,18),0);
    QSqlQuery query;
    query.prepare("insert into Equipped(Concept) VALUES(:Concept)");
    query.bindValue(":Concept", ui->concept->text());
    if(model->submitAll()&&query.exec())
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Succeed in add character: "+ui->concept->text()+" .");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        emit updatetableview();
        this->close();
    }
    else
        qDebug()<<"更新数据库失败";
}


void AddCharacter::on_concept_editingFinished()
{
    QString concept = ui->concept->text();
    QSqlQuery q;
    q.prepare("select * from Characters where Concept=:concept");
    q.bindValue(":concept", concept);
    q.exec();
    q.next();
    if(q.value(0).toString()!="")
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(""+concept+" has been added.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        ui->concept->clear();
        return;
    }

}

