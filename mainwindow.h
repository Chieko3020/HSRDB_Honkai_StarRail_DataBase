#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlTableModel>
#include <QMainWindow>
#include <QStyledItemDelegate>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class ImageDelegate;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);



private slots:

    void recvch(QString c,QString p);
    void recvlc(QString lc);
    void recvrl(QString st,QString cp);
    void resetlc();
    void resetrl();
    void on_chtbtn_clicked();

    void on_lcbtn_clicked();

    void on_rlbtn_clicked();

    void on_modifych_clicked();

    void on_modifylc_clicked();

    void on_addlc_clicked();

    void on_prepage_clicked();

    void on_nexpage_clicked();

    void on_searchlc_textChanged(const QString &arg1);

    void on_removelc_clicked();

    void on_lctable_doubleClicked(const QModelIndex &index);

    void on_addrl_clicked();

    void on_removerl_clicked();

    void on_prepage_2_clicked();

    void on_nexpage_2_clicked();

    void on_searchrl_textChanged(const QString &arg1);

    void on_rltable_doubleClicked(const QModelIndex &index);

    void on_Head_clicked();

    void on_Hands_clicked();

    void on_Body_clicked();

    void on_Feet_clicked();

    void on_PlanarSphere_clicked();

    void on_LinkRope_clicked();

    void on_morebtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *lcmodel=nullptr;
    QSqlTableModel *rlmodel=nullptr;
    QString relicset[6]={"","","","","",""};
    QString judgerelicsetCavern2pc(QString set);
    QString judgerelicsetCavern4pc(QString set);
    QString judgerelicsetPlanar2pc(QString set);
    void initch();
    void initlctable();
    void initrltable();
    QString CavernRelics[20]={
        "Band of Sizzling Thunder",
        "Champion of Streetwise Boxing",
        "Eagle of Twilight Line",
        "Firesmith of Lava-Forging",
        "Genius of Brilliant Stars",
        "Guard of Wuthering Snow",
        "Hunter of Glacial Forest",
        "Iron Cavalry Against the Scourge",
        "Knight of Purity Palace",
        "Longevous Disciple",
        "Messenger Traversing Hackerspace",
        "Musketeer of Wild Wheat",
        "Passerby of Wandering Cloud",
        "Pioneer Diver of Dead Waters",
        "Prisoner in Deep Confinement",
        "The Ashblazing Grand Duke",
        "The Wind-Soaring Valorous",
        "Thief of Shooting Meteor",
        "Wastelander of Banditry Desert",
        "Watchmaker, Master of Dream Machinations"
    };
    QString PlanarOrnaments[18]={

        "Belobog of the Architects",
        "Broken Keel",
        "Celestial Differentiator",
        "Duran, Dynasty of Running Wolves",
        "Firmament Frontline Glamoth",
        "Fleet of the Ageless",
        "Forge of the Kalpagni Lantern",
        "Inert Salsotto",
        "Izumo Gensei and Takama Divine Realm",
        "Lushaka, the Sunken Seas",
        "Pan-Cosmic Commercial Enterprise",
        "Penacony, Land of the Dreams",
        "Rutilant Arena",
        "Sigonia, the Unclaimed Desolation",
        "Space Sealing Station",
        "Sprightly Vonwacq",
        "Talia Kingdom of Banditry",
        "The Wondrous BananAmusement Park"
    };
    QString CavernRelics2pc[20]=
        {
            "Increases Lightning DMG by 10%.",
            "Increases Physical DMG by 10%.",
            "Increases Wind DMG by 10%.",
            "Increases Fire DMG by 10%.",
            "Increases Quantum DMG by 10%.",
            "Reduces DMG taken by 8%.",
            "Increases Ice DMG by 10%.",
            "Increases Break Effect by 16%.",
            "Increases DEF by 15%.",
            "Increases Max HP by 12%.",
            "Increases SPD by 6%.",
            "Increases ATK by 12%.",
            "Increases Outgoing Healing by 10%.",
            "Increases DMG dealt to enemies with debuffs by 12%.",
            "Increases ATK by 12%.",
            "Increases the DMG dealt by follow-up attack by 20%.",
            "Increases ATK by 12%.",
            "Increases Break Effect by 16%.",
            "Increases Imaginary DMG by 10%.",
            "Increases Break Effect by 16%."
        };
    QString CavernRelics4pc[20]=
        {
            "When the wearer uses their Skill, increases the wearer's ATK by 20% for 1 turn(s).",
            "After the wearer attacks or is hit, their ATK increases by 5% for the rest of the battle. This effect can stack up to 5 time(s).",
            "After the wearer uses their Ultimate, their action is Advanced Forward by 25%.",
            "Increases DMG by the wearer's Skill by 12%. After unleashing Ultimate, increases the wearer's Fire DMG by 12% for the next attack.",
            "When the wearer deals DMG to the target enemy, ignores 10% DEF. If the target enemy has Quantum Weakness, the wearer additionally ignores 10% DEF.",
            "At the beginning of the turn, if the wearer's HP is equal to or less than 50%, restores HP equal to 8% of their Max HP and regenerates 5 Energy.",
            "After the wearer uses their Ultimate, their CRIT DMG increases by 25% for 2 turn(s).",
            "If the wearer's Break Effect is 150% or higher, the Break DMG dealt to the enemy target ignores 10% of their DEF. If the wearer's Break Effect is 250% or higher, the Super Break DMG dealt to the enemy target additionally ignores 15% of their DEF.",
            "Increases the max DMG that can be absorbed by the Shield created by the wearer by 20%.",
            "When the wearer is hit or has their HP consumed by an ally or themselves, their CRIT Rate increases by 8% for 2 turn(s) and up to 2 stacks.",
            "When the wearer uses their Ultimate on an ally, SPD for all allies increases by 12% for 1 turn(s). This effect cannot be stacked.",
            "The wearer's SPD increases by 6% and DMG dealt by Basic ATK increases by 10%.",
            "At the start of the battle, immediately regenerates 1 Skill Point.",
            "Increases CRIT Rate by 4%. The wearer deals 8%/12% increased CRIT DMG to enemies with at least 2/3 debuffs. After the wearer inflicts a debuff on enemy targets, the aforementioned effects increase by 100%, lasting for 1 turn(s).",
            "For every DoT the enemy target is afflicted with, the wearer will ignore 6% of its DEF when dealing DMG to it. This effect is valid for a max of 3 DoTs.",
            "When the wearer uses follow-up attacks, increases the wearer's ATK by 6% for every time the follow-up attack deals DMG. This effect can stack up to 8 time(s) and lasts for 3 turn(s). This effect is removed the next time the wearer uses a follow-up attack.",
            "Increases the wearer's CRIT Rate by 6%. After the wearer uses follow-up attack, increases DMG dealt by Ultimate by 36%, lasting for 1 turn(s).",
            "Increases the wearer's Break Effect by 16%. After the wearer inflicts Weakness Break on an enemy, regenerates 3 Energy.",
            "When attacking debuffed enemies, the wearer's CRIT Rate increases by 10%, and their CRIT DMG increases by 20% against Imprisoned enemies.",
            "When the wearer uses their Ultimate on an ally, all allies' Break Effect increases by 30% for 2 turn(s). This effect cannot be stacked."
        };
    QString PlanarOrnaments2pc[18]=
        {
            "Increases the wearer's DEF by 15%. When the wearer's Effect Hit Rate is 50% or higher, the wearer gains an extra 15% DEF.",
            "Increases the wearer's Effect RES by 10%. When the wearer's Effect RES is at 30% or higher, all allies' CRIT DMG increases by 10%.",
            "Increases the wearer's CRIT DMG by 16%. When the wearer's current CRIT DMG reaches 120% or higher, after entering battle, the wearer's CRIT Rate increases by 60% until the end of their first attack.",
            "When an ally uses follow-up attack, the wearer gains 1 stack of Merit, stacking up to 5 time(s). Each stack of Merit increases the DMG dealt by the wearer's follow-up attacks by 5%. When there are 5 stacks, additionally increases the wearer's CRIT DMG by 25%.",
            "Increases the wearer's ATK by 12%. When the wearer's SPD is equal to or higher than 135/160, the wearer deals 12%/18% more DMG.",
            "Increases the wearer's Max HP by 12%. When the wearer's SPD reaches 120 or higher, all allies' ATK increases by 8%.",
            "Increases the wearer's SPD by 6%. When the wearer hits an enemy target that has Fire Weakness, the wearer's Break Effect increases by 40%, lasting for 1 turn(s).",
            "Increases the wearer's CRIT Rate by 8%. When the wearer's current CRIT Rate reaches 50% or higher, the DMG dealt by the wearer's Ultimate and follow-up attack increases by 15%.",
            "Increases the wearer's ATK by 12%. When entering battle, if at least one other ally follows the same Path as the wearer, then the wearer's CRIT Rate increases by 12%.",
            "Increases the wearer's Energy Regeneration Rate by 5.0%. If the wearer is not the first character in the team lineup, then increase the ATK of the first character in the team lineup by 15.0%.",
            "Increases the wearer's Effect Hit Rate by 10%. Meanwhile, the wearer's ATK increases by an amount that is equal to 25% of the current Effect Hit Rate, up to a maximum of 25%.",
            "Increases wearer's Energy Regeneration Rate by 5%. Increases DMG by 10% for all other allies that are of the same Type as the wearer.",
            "Increases the wearer's CRIT Rate by 8%. When the wearer's current CRIT Rate reaches 70% or higher, DMG dealt by Basic ATK and Skill increases by 20%.",
            "Increases the wearer's CRIT Rate by 4%. When an enemy target gets defeated, the wearer's CRIT DMG increases by 4%, stacking up to 10 time(s).",
            "Increases the wearer's ATK by 12%. When the wearer's SPD reaches 120 or higher, the wearer's ATK increases by an extra 12%.",
            "Increases the wearer's Energy Regeneration Rate by 5%. When the wearer's SPD reaches 120 or higher, the wearer's action is Advanced Forward by 40% immediately upon entering battle.",
            "Increases the wearer's Break Effect by 16%. When the wearer's SPD reaches 145 or higher, the wearer's Break Effect increases by an extra 20%.",
            "Increases the wearer's CRIT DMG by 16%. When a target summoned by the wearer is on the field, CRIT DMG additionally increases by 32%."
        };

};


class ImageDelegate : public QStyledItemDelegate {
public:
    ImageDelegate(QSqlTableModel *model, QObject *parent = nullptr)
        : QStyledItemDelegate(parent), model(model) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        if (index.column() == 0 && !option.state.testFlag(QStyle::State_Selected))
        { // 仅在第一列绘制图片
            QString str1=model->data(model->index(index.row(),1)).toString();
            QString str2=model->data(model->index(index.row(),2)).toString();
            QString str3=model->data(model->index(index.row(),0)).toString();
            QString iconPath=QString("%1%2%3%4%5%6%7").arg(":/lightcones/icon/res/LightCones/icon/")
                              .arg(str1).arg("stars/").arg(str2).arg("/").arg(str3).arg(".png");
            QPixmap pixmap(iconPath);
            painter->drawPixmap(option.rect, pixmap);
        } else
        {
            QStyledItemDelegate::paint(painter, option, index);
        }
    }


private:
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
