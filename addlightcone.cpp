#include "addlightcone.h"
#include "ui_addlightcone.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QCompleter>
AddLightCone::AddLightCone(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddLightCone)
{
    ui->setupUi(this);
    QStringList wordList;
    wordList << "A Secret Vow" << "Adversarial" << "After the Charmony Fall	" << "Along the Passing Shore" << "Amber" << "An Instant Before A Gaze" << "Arrows"
             << "Baptism of Pure Thought" << "Before Dawn" << "Before the Tutorial Mission Starts" << "Boundless Choreo" << "Brighter Than the Sun" << "But the Battle Isn't Over"
             << "Carve the Moon, Weave the Clouds" << "Chorus" << "Collapsing Sky" << "Concert for Two" << "Cornucopia" << "Cruising in the Stellar Sea"
             << "Dance at Sunset" << "Dance! Dance! Dance!" << "Darting Arrow" << "Data Bank" << "Day One of My New Life" << "Defense" << "Destiny's Threads Forewoven" << "Dreamville Adventure"
             << "Earthly Escapade" << "Echoes of the Coffin" << "Eternal Calculus" << "Eyes of the Prey	"
             << "Fermata" << "Final Victor" << "Fine Fruit" << "Flames Afar" << "Flowing Nightglow" << "For Tomorrow's Journey"
             << "Geniuses' Repose" << "Good Night and Sleep Well"
             << "Hey, Over Here" << "Hidden Shadow"
             << "I Shall Be My Own Sword" << "I Venture Forth to Hunt" << "In the Name of the World" << "In the Night" << "Incessant Rain" << "Indelible Promise" << "Inherently Unjust Destiny" << "It's Showtime"
             << "Landau's Choice" << "Loop"
             << "Make the World Clamor" << "Mediation" << "Memories of the Past" << "Meshing Cogs" << "Moment of Victory" << "Multiplication" << "Mutual Demise"
             << "Night of Fright" << "Night on the Milky Way" << "Nowhere to Run"
             << "On the Fall of an Aeon" << "Only Silence Remains"
             << "Passkey" << "Past and Future" << "Past Self in Mirror" << "Patience Is All You Need" << "Perfect Timing" << "Pioneering" << "Planetary Rendezvous" << "Poised to Bloom" << "Post-Op Conversation"
             << "Quid Pro Quo"
             << "Reforged Remembrance" << "Resolution Shines As Pearls of Sweat" << "Return to Darkness" << "River Flows in Spring"
             << "Sagacity" << "Sailing Towards a Second Life" << "Scent Alone Stays True" << "Shadowed by Night" << "Shared Feeling" << "Shattered Home" << "She Already Shut Her Eyes" << "Sleep Like the Dead" << "Solitary Healing" << "Something Irreplaceable" << "Subscribe for More!" << "Swordplay"
             << "Texture of Memories" << "The Birth of the Self" << "The Day The Cosmos Fell" << "The Moles Welcome You" << "The Seriousness of Breakfast" << "The Unreachable Side" << "This Is Me!" << "Those Many Springs" << "Time Waits for No One" << "Today Is Another Peaceful Day" << "Trend of the Universal Market"
             << "Under the Blue Sky"
             << "Void"
             << "Warmth Shortens Cold Nights" << "We Are Wildfire" << "We Will Meet Again" << "What Is Real"<< "Whereabouts Should Dreams Rest" << "Woof! Walk Time!" << "Worrisome, Blissful"
             << "Yet Hope Is Priceless";
    QCompleter *completer = new QCompleter(wordList, ui->concept);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->concept->setCompleter(completer);
    QRegularExpression  re("[ a-zA-Z0-9',!-]+$");
    QValidator  *regv = new QRegularExpressionValidator(re, this);
    ui->concept->setValidator(regv);
    model = new QSqlTableModel(this);
    model->setTable("LightCones");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    connect(ui->checkBox_1, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_2, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_3, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_4, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_5, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_6, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_7, SIGNAL(clicked()), this, SLOT(getcheckbox()));
    connect(ui->checkBox_8, SIGNAL(clicked()), this, SLOT(getcheckbox()));
}

AddLightCone::~AddLightCone()
{
    delete ui;
}

void AddLightCone::getcheckbox()
{

    QObject *obj = QObject::sender();
    QCheckBox *chb = qobject_cast<QCheckBox *>(obj);
    if (chb->isChecked())
        sum++;
    else
        sum--;
    if (3 == sum)
    {
        chb->toggle();
        sum--;
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You must choose no more than 2 stats.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}


void AddLightCone::on_checkBox_1_stateChanged(int arg1)
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


void AddLightCone::on_checkBox_2_stateChanged(int arg1)
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


void AddLightCone::on_checkBox_3_stateChanged(int arg1)
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



void AddLightCone::on_checkBox_4_stateChanged(int arg1)
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


void AddLightCone::on_checkBox_5_stateChanged(int arg1)
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


void AddLightCone::on_checkBox_6_stateChanged(int arg1)
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


void AddLightCone::on_checkBox_7_stateChanged(int arg1)
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


void AddLightCone::on_checkBox_8_stateChanged(int arg1)
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


void AddLightCone::on_calcelbtn_clicked()
{
    this->close();
}


void AddLightCone::on_configuebtn_clicked()
{

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

    double checkbox[8]={0.000};
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
        checkbox[3]=ui->BreakEffect->value();
    }
    if(ui->checkBox_5->isChecked())
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
        checkbox[4]=ui->EffectHitRate->value();
    }
    if(ui->checkBox_6->isChecked())
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
        checkbox[5]=ui->EffectRES->value();
    }
    if(ui->checkBox_7->isChecked())
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
        checkbox[6]=ui->CritRate->value();
    }
    if(ui->checkBox_8->isChecked())
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
        checkbox[7]=ui->CritDMG->value();
    }

    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Are you really going to submit ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(msgBox.exec()==QMessageBox::No)
        return;

    int t1=-1,t2=-1;
    for(int i=0;i<=7;i++)
    {
        if(checkbox[i]!=0)
        {
            t1=i;
            for(int j=i+1;j<=7;j++)
            {
                if(checkbox[j]!=0)
                {
                    t2=j;
                    break;
                }
            }
            break;
        }
    }

    int row = model->rowCount();
    model->insertRow(model->rowCount());
    model->setData(model->index(row,0),ui->concept->text());
    model->setData(model->index(row,1),ui->rairty->currentText());
    model->setData(model->index(row,2),ui->path->currentText());
    model->setData(model->index(row,3),ui->level->value());
    model->setData(model->index(row,4),ui->superimposelevel->value());
    model->setData(model->index(row,5),ui->BaseHP->value());
    model->setData(model->index(row,6),ui->BaseATK->value());
    model->setData(model->index(row,7),ui->BaseDEF->value());
    model->setData(model->index(row,12),ui->skill->toPlainText());
    if(t1!=-1)
    {
        if(t1==0)
        {
            model->setData(model->index(row,8),ui->ATKBoostPercentage->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==1)
        {
            model->setData(model->index(row,8),ui->DEFBoostPercentage->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==2)
        {
            model->setData(model->index(row,8),ui->HPBoostPercentage->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==3)
        {
            model->setData(model->index(row,8),ui->BreakEffect->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==4)
        {
            model->setData(model->index(row,8),ui->EffectHitRate->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==5)
        {
            model->setData(model->index(row,8),ui->EffectRES->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==6)
        {
            model->setData(model->index(row,8),ui->CritRate->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        else if(t1==7)
        {
            model->setData(model->index(row,8),ui->CritDMG->objectName());
            model->setData(model->index(row,9),checkbox[t1]);
        }
        if(t2!=-1)
        {
            if(t2==0)
            {
                model->setData(model->index(row,10),ui->ATKBoostPercentage->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==1)
            {
                model->setData(model->index(row,10),ui->DEFBoostPercentage->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==2)
            {
                model->setData(model->index(row,10),ui->HPBoostPercentage->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==4)
            {
                model->setData(model->index(row,10),ui->BreakEffect->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==5)
            {
                model->setData(model->index(row,10),ui->EffectHitRate->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==6)
            {
                model->setData(model->index(row,10),ui->EffectRES->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==7)
            {
                model->setData(model->index(row,10),ui->CritRate->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
            else if(t2==8)
            {
                model->setData(model->index(row,10),ui->CritDMG->objectName());
                model->setData(model->index(row,11),checkbox[t2]);
            }
        }
    }

    if(model->submitAll())
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
        msgBox.setText("Succeed in add LightCone: "+ui->concept->text()+" .");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        emit updatelc();
        this->close();
    }
    else
        qDebug()<<"更新数据库失败";
}

void AddLightCone::on_concept_editingFinished()
{
    QString concept = ui->concept->text();
    QSqlQuery q;
    q.prepare("select * from LightCones where Concept=:concept");
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

