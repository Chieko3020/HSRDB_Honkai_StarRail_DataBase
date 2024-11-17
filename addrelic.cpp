#include "addrelic.h"
#include "ui_addrelic.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QCompleter>
addrelic::addrelic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addrelic)
{
    ui->setupUi(this);
    QStringList wordList;
    wordList << "Band of Sizzling Thunder" << "Belobog of the Architects" << "Broken Keel"
             << "Celestial Differentiator" << "Champion of Streetwise Boxing"
             << "Duran, Dynasty of Running Wolves"
             << "Eagle of Twilight Line"
             << "Firesmith of Lava-Forging" << "Firmament Frontline Glamoth" << "Fleet of the Ageless" << "Forge of the Kalpagni Lantern"
             << "Genius of Brilliant Stars" << "Guard of Wuthering Snow"
             << "Hunter of Glacial Forest"
             << "Inert Salsotto" << "Iron Cavalry Against the Scourge" << "Izumo Gensei and Takama Divine Realm"
             << "Knight of Purity Palace"
             << "Longevous Disciple" << "Lushaka, the Sunken Seas"
             << "Messenger Traversing Hackerspace" << "Musketeer of Wild Wheat"
             << "Pan-Cosmic Commercial Enterprise" << "Passerby of Wandering Cloud" << "Penacony, Land of the Dreams" << "Pioneer Diver of Dead Waters" << "Prisoner in Deep Confinement"
             << "Rutilant Arena"
             << "Sigonia, the Unclaimed Desolation" << "Space Sealing Station" << "Sprightly Vonwacq"
             << "Talia Kingdom of Banditry" << "The Ashblazing Grand Duke" << "The Wind-Soaring Valorous" << "The Wondrous BananAmusement Park" << "Thief of Shooting Meteor"
             << "Wastelander of Banditry Desert" << "Watchmaker, Master of Dream Machinations";
    QCompleter *completer = new QCompleter(wordList, ui->concept);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->concept->setCompleter(completer);
    QRegularExpression  re("[ a-zA-Z0-9-',]+$");
    QValidator  *regv = new QRegularExpressionValidator(re, this);
    ui->concept->setValidator(regv);
    ui->SlotName->setValidator(regv);
    model = new QSqlTableModel(this);
    model->setTable("Relics");
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
}






addrelic::~addrelic()
{
    delete ui;
}



void addrelic::getcheckbox()
{

    QObject *obj = QObject::sender();
    QCheckBox *chb = qobject_cast<QCheckBox *>(obj);
    if(!chb->isCheckable())
        return;
    if (chb->isChecked())
        sum++;
    else
        sum--;
    if (5 == sum)
    {
        chb->toggle();
        sum--;
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You must choose no more than 4 substats.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}



void addrelic::on_concept_editingFinished()
{
    for(int i=0;i<=19;i++)
    {
        if(ui->concept->text()==CavernRelics[i])
        {
            ui->Slot->clear();
            ui->Slot->addItem("Head");
            ui->Slot->addItem("Hands");
            ui->Slot->addItem("Body");
            ui->Slot->addItem("Feet");
            return;
        }
    }
    for(int i=0;i<=17;i++)
    {
        if(ui->concept->text()==PlanarOrnaments[i])
        {
            ui->Slot->clear();
            ui->Slot->addItem("PlanarSphere");
            ui->Slot->addItem("LinkRope");
            return;
        }
    }
}



void addrelic::on_Slot_currentTextChanged(const QString &arg1)
{
    if(arg1=="Head")
    {
        ui->MainStat->clear();
        ui->MainStat->addItem("HPBoost");
        ui->MainStat->setCurrentIndex(0);
        ui->MainStat->setEditable(false);
        for(int i=0;i<=19;i++)
        {
            if(ui->concept->text()==CavernRelics[i])
            {
                ui->SlotName->setText(CavernRelicsHead[i]);
                break;
            }
        }
    }
    else if(arg1=="Hands")
    {
        ui->MainStat->clear();
        ui->MainStat->addItem("ATKBoost");
        ui->MainStat->setCurrentIndex(0);
        ui->MainStat->setEditable(false);
        for(int i=0;i<=19;i++)
        {
            if(ui->concept->text()==CavernRelics[i])
            {
                ui->SlotName->setText(CavernRelicsHands[i]);
                break;
            }
        }

    }
    else if(arg1=="Body")
    {
        ui->MainStat->clear();
        ui->MainStat->addItem("HPBoostPercentage");
        ui->MainStat->addItem("ATKBoostPercentage");
        ui->MainStat->addItem("DEFBoostPercentage");
        ui->MainStat->addItem("CritRate");
        ui->MainStat->addItem("CritDMG");
        ui->MainStat->addItem("OutgoingHealingBoost");
        ui->MainStat->addItem("EffectHitRate");
        ui->MainStat->setCurrentIndex(0);
        for(int i=0;i<=19;i++)
        {
            if(ui->concept->text()==CavernRelics[i])
            {
                ui->SlotName->setText(CavernRelicsBody[i]);
                break;
            }
        }


    }
    else if(arg1=="Feet")
    {
        ui->MainStat->clear();
        ui->MainStat->addItem("HPBoostPercentage");
        ui->MainStat->addItem("ATKBoostPercentage");
        ui->MainStat->addItem("DEFBoostPercentage");
        ui->MainStat->addItem("SPDBoost");
        ui->MainStat->setCurrentIndex(0);
        ui->MainStat->setEditable(false);
        for(int i=0;i<=19;i++)
        {
            if(ui->concept->text()==CavernRelics[i])
            {
                ui->SlotName->setText(CavernRelicsFeet[i]);
                break;
            }
        }

    }
    else if(arg1=="PlanarSphere")
    {
        ui->MainStat->clear();
        ui->MainStat->addItem("HPBoostPercentage");
        ui->MainStat->addItem("ATKBoostPercentage");
        ui->MainStat->addItem("DEFBoostPercentage");
        ui->MainStat->addItem("PhysicalDMGBoost");
        ui->MainStat->addItem("FireDMGBoost");
        ui->MainStat->addItem("IceDMGBoost");
        ui->MainStat->addItem("LightningDMGBoost");
        ui->MainStat->addItem("WindDMGBoost");
        ui->MainStat->addItem("QuantumDMGBoost");
        ui->MainStat->addItem("ImaginaryDMGBoost");
        ui->MainStat->setCurrentIndex(0);
        for(int i=0;i<=17;i++)
        {
            if(ui->concept->text()==PlanarOrnaments[i])
            {
                ui->SlotName->setText(PlanarOrnamentsSphere[i]);
                break;
            }
        }
    }
    else if(arg1=="LinkRope")
    {
        ui->MainStat->clear();
        ui->MainStat->addItem("HPBoostPercentage");
        ui->MainStat->addItem("ATKBoostPercentage");
        ui->MainStat->addItem("DEFBoostPercentage");
        ui->MainStat->addItem("BreakEffect");
        ui->MainStat->addItem("EnergyRegenerationRate");
        ui->MainStat->setCurrentIndex(0);
        for(int i=0;i<=17;i++)
        {
            if(ui->concept->text()==PlanarOrnaments[i])
            {
                ui->SlotName->setText(PlanarOrnamentsLinkRope[i]);
                break;
            }
        }
    }
}


void addrelic::on_MainStat_currentTextChanged(const QString &arg1)
{
    ui->checkBox_5->setCheckable(true);
    ui->checkBox_1->setCheckable(true);
    ui->checkBox_6->setCheckable(true);
    ui->checkBox_2->setCheckable(true);
    ui->checkBox_4->setCheckable(true);
    ui->checkBox_8->setCheckable(true);
    ui->checkBox_9->setCheckable(true);
    ui->checkBox_11->setCheckable(true);
    ui->checkBox_7->setCheckable(true);
    ui->checkBox_10->setCheckable(true);
    if(arg1=="HPBoost")
    {
        ui->MSValue->setValue(705.6);
        if(ui->checkBox_5->isChecked())
            sum--;
        ui->checkBox_5->setCheckState(Qt::CheckState::Unchecked);
        ui->HPBoost->setValue(0.00);
        ui->checkBox_5->setCheckable(false);
    }
    else if(arg1=="ATKBoost")
    {
        ui->MSValue->setValue(352.8);
        if(ui->checkBox_1->isChecked())
            sum--;
        ui->checkBox_1->setCheckState(Qt::CheckState::Unchecked);
        ui->ATKBoost->setValue(0.00);
        ui->checkBox_1->setCheckable(false);
    }
    else if(arg1=="HPBoostPercentage")
    {
        ui->MSValue->setValue(0.432);
        if(ui->checkBox_6->isChecked())
            sum--;
        ui->checkBox_6->setCheckState(Qt::CheckState::Unchecked);
        ui->HPBoostPercentage->setValue(0.0000);
        ui->checkBox_6->setCheckable(false);
    }
    else if(arg1=="ATKBoostPercentage")
    {
        ui->MSValue->setValue(0.432);
        if(ui->checkBox_2->isChecked())
            sum--;
        ui->checkBox_2->setCheckState(Qt::CheckState::Unchecked);
        ui->ATKBoostPercentage->setValue(0.0000);
        ui->checkBox_2->setCheckable(false);
    }
    else if(arg1=="DEFBoostPercentage")
    {
        ui->MSValue->setValue(0.54);
        if(ui->checkBox_4->isChecked())
            sum--;
        ui->checkBox_4->setCheckState(Qt::CheckState::Unchecked);
        ui->DEFBoostPercentage->setValue(0.0000);
        ui->checkBox_4->setCheckable(false);
    }
    else if(arg1=="CritRate")
    {
        ui->MSValue->setValue(0.324);
        if(ui->checkBox_8->isChecked())
            sum--;
        ui->checkBox_8->setCheckState(Qt::CheckState::Unchecked);
        ui->CritRate->setValue(0.0000);
        ui->checkBox_8->setCheckable(false);
    }
    else if(arg1=="CritDMG")
    {
        ui->MSValue->setValue(0.648);
        if(ui->checkBox_9->isChecked())
            sum--;
        ui->checkBox_9->setCheckState(Qt::CheckState::Unchecked);
        ui->CritDMG->setValue(0.0000);
        ui->checkBox_9->setCheckable(false);
    }
    else if(arg1=="OutgoingHealingBoost")
    {
        ui->MSValue->setValue(0.3456);
    }
    else if(arg1=="EffectHitRate")
    {
        ui->MSValue->setValue(0.432);
        if(ui->checkBox_11->isChecked())
            sum--;
        ui->checkBox_11->setCheckState(Qt::CheckState::Unchecked);
        ui->EffectHitRate->setValue(0.0000);
        ui->checkBox_11->setCheckable(false);
    }
    else if(arg1=="SPDBoost")
    {
        ui->MSValue->setValue(25.03);
        if(ui->checkBox_7->isChecked())
            sum--;
        ui->checkBox_7->setCheckState(Qt::CheckState::Unchecked);
        ui->SPDBoost->setValue(0.0);
        ui->checkBox_7->setCheckable(false);
    }
    else if(arg1=="PhysicalDMGBoost"||arg1=="FireDMGBoost"||arg1=="IceDMGBoost"||arg1=="LightningDMGBoost"||arg1=="WindDMGBoost"||arg1=="QuantumDMGBoost"||arg1=="ImaginaryDMGBoost")
    {
        ui->MSValue->setValue(0.3888);
    }
    else if(arg1=="BreakEffect")
    {
        ui->MSValue->setValue(0.648);
        if(ui->checkBox_10->isChecked())
            sum--;
        ui->checkBox_10->setCheckState(Qt::CheckState::Unchecked);
        ui->BreakEffect->setValue(0.0000);
        ui->checkBox_10->setCheckable(false);
    }
    else if(arg1=="EnergyRegenerationRate")
    {
        ui->MSValue->setValue(0.1944);
    }
}



void addrelic::on_checkBox_1_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->ATKBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->ATKBoost->setReadOnly(true);
    }
}


void addrelic::on_checkBox_2_stateChanged(int arg1)
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


void addrelic::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->DEFBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->DEFBoost->setReadOnly(true);
    }
}


void addrelic::on_checkBox_4_stateChanged(int arg1)
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


void addrelic::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->HPBoost->setReadOnly(false);
    }
    else if(arg1==Qt::Unchecked)
    {
        ui->HPBoost->setReadOnly(true);
    }
}


void addrelic::on_checkBox_6_stateChanged(int arg1)
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


void addrelic::on_checkBox_7_stateChanged(int arg1)
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


void addrelic::on_checkBox_8_stateChanged(int arg1)
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


void addrelic::on_checkBox_9_stateChanged(int arg1)
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


void addrelic::on_checkBox_10_stateChanged(int arg1)
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


void addrelic::on_checkBox_11_stateChanged(int arg1)
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


void addrelic::on_checkBox_12_stateChanged(int arg1)
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




void addrelic::on_calcelbtn_clicked()
{
    this->close();
}


void addrelic::on_configuebtn_clicked()
{
    if(sum<3)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("You must choose stats more than 3.");
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
    if(ui->SlotName->text()=="")
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("SlotName is NULL.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }


    double checkbox[12]={0.0000};
    if(ui->checkBox_1->isChecked())
    {
        checkbox[0]=ui->ATKBoost->value();
    }
    if(ui->checkBox_2->isChecked())
    {
        checkbox[1]=ui->ATKBoostPercentage->value();
    }
    if(ui->checkBox_3->isChecked())
    {
        checkbox[2]=ui->DEFBoost->value();
    }
    if(ui->checkBox_4->isChecked())
    {
        checkbox[3]=ui->DEFBoostPercentage->value();
    }
    if(ui->checkBox_5->isChecked())
    {
        checkbox[4]=ui->HPBoost->value();
    }
    if(ui->checkBox_6->isChecked())
    {
        checkbox[5]=ui->HPBoostPercentage->value();
    }
    if(ui->checkBox_7->isChecked())
    {
        checkbox[6]=ui->SPDBoost->value();
    }
    if(ui->checkBox_8->isChecked())
    {
        checkbox[7]=ui->CritRate->value();
    }
    if(ui->checkBox_9->isChecked())
    {
        checkbox[8]=ui->CritDMG->value();
    }
    if(ui->checkBox_10->isChecked())
    {
        checkbox[9]=ui->BreakEffect->value();
    }
    if(ui->checkBox_11->isChecked())
    {
        checkbox[10]=ui->EffectHitRate->value();
    }
    if(ui->checkBox_12->isChecked())
    {
        checkbox[11]=ui->EffectRES->value();
    }

    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Are you really going to submit ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(msgBox.exec()==QMessageBox::No)
        return;

    int t1=-1,t2=-1,t3=-1,t4=-1;
    for(int i=0;i<=11;i++)
    {
        if(checkbox[i]!=0)
        {
            t1=i;
            for(int j=i+1;j<=11;j++)
            {
                if(checkbox[j]!=0)
                {
                    t2=j;
                    for(int k=j+1;k<=11;k++)
                    {
                        if(checkbox[k]!=0)
                        {
                            t3=k;
                            for(int l=k+1;l<=11;l++)
                            {
                                if(checkbox[l]!=0)
                                {
                                    t4=l;
                                    break;
                                }
                            }
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
    model->setData(model->index(row,1),ui->concept->text());
    model->setData(model->index(row,2),ui->Slot->currentText());
    model->setData(model->index(row,3),ui->SlotName->text());
    model->setData(model->index(row,4),20);
    model->setData(model->index(row,5),ui->MainStat->currentText());
    model->setData(model->index(row,6),ui->MSValue->value());
    if(t1!=-1)
    {
        if(t1==0)
        {
            model->setData(model->index(row,7),ui->ATKBoost->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==1)
        {
            model->setData(model->index(row,7),ui->ATKBoostPercentage->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==2)
        {
            model->setData(model->index(row,7),ui->DEFBoost->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==3)
        {
            model->setData(model->index(row,7),ui->DEFBoostPercentage->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==4)
        {
            model->setData(model->index(row,7),ui->HPBoost->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==5)
        {
            model->setData(model->index(row,7),ui->HPBoostPercentage->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==6)
        {
            model->setData(model->index(row,7),ui->SPDBoost->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==7)
        {
            model->setData(model->index(row,7),ui->CritRate->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==8)
        {
            model->setData(model->index(row,7),ui->CritDMG->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==9)
        {
            model->setData(model->index(row,7),ui->BreakEffect->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==10)
        {
            model->setData(model->index(row,7),ui->EffectHitRate->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        else if(t1==11)
        {
            model->setData(model->index(row,7),ui->EffectRES->objectName());
            model->setData(model->index(row,8),checkbox[t1]);
        }
        if(t2!=-1)
        {
            if(t2==0)
            {
                model->setData(model->index(row,9),ui->ATKBoost->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==1)
            {
                model->setData(model->index(row,9),ui->ATKBoostPercentage->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==2)
            {
                model->setData(model->index(row,9),ui->DEFBoost->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==3)
            {
                model->setData(model->index(row,9),ui->DEFBoostPercentage->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==4)
            {
                model->setData(model->index(row,9),ui->HPBoost->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==5)
            {
                model->setData(model->index(row,9),ui->HPBoostPercentage->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==6)
            {
                model->setData(model->index(row,9),ui->SPDBoost->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==7)
            {
                model->setData(model->index(row,9),ui->CritRate->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==8)
            {
                model->setData(model->index(row,9),ui->CritDMG->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==9)
            {
                model->setData(model->index(row,9),ui->BreakEffect->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==10)
            {
                model->setData(model->index(row,9),ui->EffectHitRate->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            else if(t2==11)
            {
                model->setData(model->index(row,9),ui->EffectRES->objectName());
                model->setData(model->index(row,10),checkbox[t2]);
            }
            if(t3!=-1)
            {
                if(t3==0)
                {
                    model->setData(model->index(row,11),ui->ATKBoost->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==1)
                {
                    model->setData(model->index(row,11),ui->ATKBoostPercentage->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==2)
                {
                    model->setData(model->index(row,11),ui->DEFBoost->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==3)
                {
                    model->setData(model->index(row,11),ui->DEFBoostPercentage->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==4)
                {
                    model->setData(model->index(row,11),ui->HPBoost->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==5)
                {
                    model->setData(model->index(row,11),ui->HPBoostPercentage->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==6)
                {
                    model->setData(model->index(row,11),ui->SPDBoost->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==7)
                {
                    model->setData(model->index(row,11),ui->CritRate->objectName());
                   model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==8)
                {
                    model->setData(model->index(row,11),ui->CritDMG->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==9)
                {
                    model->setData(model->index(row,11),ui->BreakEffect->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==10)
                {
                    model->setData(model->index(row,11),ui->EffectHitRate->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                else if(t3==11)
                {
                    model->setData(model->index(row,11),ui->EffectRES->objectName());
                    model->setData(model->index(row,12),checkbox[t3]);
                }
                if(t4!=-1)
                {
                    if(t4==0)
                    {
                        model->setData(model->index(row,13),ui->ATKBoost->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==1)
                    {
                        model->setData(model->index(row,13),ui->ATKBoostPercentage->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==2)
                    {
                        model->setData(model->index(row,13),ui->DEFBoost->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==3)
                    {
                        model->setData(model->index(row,13),ui->DEFBoostPercentage->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==4)
                    {
                        model->setData(model->index(row,13),ui->HPBoost->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==5)
                    {
                        model->setData(model->index(row,13),ui->HPBoostPercentage->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==6)
                    {
                        model->setData(model->index(row,13),ui->SPDBoost->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==7)
                    {
                        model->setData(model->index(row,13),ui->CritRate->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==8)
                    {
                        model->setData(model->index(row,13),ui->CritDMG->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==9)
                    {
                        model->setData(model->index(row,13),ui->BreakEffect->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==10)
                    {
                        model->setData(model->index(row,13),ui->EffectHitRate->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                    else if(t4==11)
                    {
                        model->setData(model->index(row,13),ui->EffectRES->objectName());
                        model->setData(model->index(row,14),checkbox[t4]);
                    }
                }
            }
        }
    }

    if(model->submitAll())
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Succeed in add relic: "+ui->SlotName->text()+" .");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        emit updaterl();
        this->close();
    }
    else
        qDebug()<<"更新数据库失败";
}





