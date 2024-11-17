#ifndef ADDRELIC_H
#define ADDRELIC_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>
namespace Ui {
class addrelic;
}

class addrelic : public QWidget
{
    Q_OBJECT

public:
    explicit addrelic(QWidget *parent = nullptr);
    ~addrelic();
    int sum=0;
signals:
    void updaterl();
private slots:
    void getcheckbox();

    void on_checkBox_1_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_calcelbtn_clicked();

    void on_configuebtn_clicked();

    void on_Slot_currentTextChanged(const QString &arg1);

    void on_MainStat_currentTextChanged(const QString &arg1);

    void on_concept_editingFinished();

private:
    Ui::addrelic *ui;
    QSqlTableModel *model=nullptr;
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
        "The Wondrous BananAmusement Park",
    };
    QString CavernRelicsHead[20]={
        "Band’s Polarized Sunglasses",
        "Champion’s Boxing Headgear",
        "Eagle’s Soaring Helmet",
        "Firesmith’s Molten Mask",
        "Genius’s Starry Crown",
        "Guard’s Frosted Helm",
        "Hunter’s Frosted Cap",
        "Iron Cavalry's Homing Helm",
        "Knight’s Iron Visor",
        "Longevous Disciple’s Cap",
        "Messenger’s Feathered Cap",
        "Musketeer’s Wheat Hat",
        "Passer’s Cloud Hat",
        "Pioneer’s Diver Helmet",
        "Prisoner’s Confinement Mask",
        "Grand Duke's Crown of Netherflame",
        "Valorous Wind-Soaring Helm",
        "Thief’s Myriad-Faced Mask",
        "Wastelander’s Heavy Helmet",
        "Watchmaker’s Dream Cap"
    };
    QString CavernRelicsHands[20] = {
        "Band's Leather Gloves",
        "Champion's Boxing Gloves",
        "Eagle's Grasping Claws",
        "Firesmith's Forging Gauntlets",
        "Genius's Stellar Gloves",
        "Guard's Icy Gauntlets",
        "Hunter's Icebound Gloves",
        "Iron Cavalry's Crushing Wristguard",
        "Knight's Iron Gauntlets",
        "Longevous Disciple's Gloves",
        "Messenger's Feathered Gloves",
        "Musketeer's Leather Gloves",
        "Passer's Wandering Gloves",
        "Pioneer's Diver Gloves",
        "Prisoner's Confinement Gloves",
        "Grand Duke's Gloves of Fieryfur",
        "Valorous Wind-Soaring Gloves",
        "Thief's Myriad-Faced Gloves",
        "Wastelander's Heavy Gauntlets",
        "Watchmaker's Dream Gloves"
    };
    QString CavernRelicsBody[20] = {
        "Band's Electric Jacket",
        "Champion's Boxing Robe",
        "Eagle's Winged Armor",
        "Firesmith's Lava Armor",
        "Genius's Radiant Robe",
        "Guard's Snowy Armor",
        "Hunter's Glacial Coat",
        "Iron Cavalry's Silvery Armor",
        "Knight's Iron Armor",
        "Longevous Disciple's Robe",
        "Messenger's Feathered Coat",
        "Musketeer's Field Jacket",
        "Passer's Cloud Robe",
        "Pioneer's Diver Suit",
        "Prisoner's Confinement Suit",
        "Grand Duke's Robe of Grace",
        "Valorous Wind-Soaring Armor",
        "Thief's Myriad-Faced Suit",
        "Wastelander's Heavy Armor",
        "Watchmaker's Dream Coat"
    };
    QString CavernRelicsFeet[20] = {
        "Band's Lightning Boots",
        "Champion's Boxing Shoes",
        "Eagle's Swift Talons",
        "Firesmith's Ember Boots",
        "Genius's Comet Boots",
        "Guard's Winter Boots",
        "Hunter's Snowshoes",
        "Iron Cavalry's Skywalk Greaves",
        "Knight's Iron Boots",
        "Longevous Disciple's Boots",
        "Messenger's Feathered Boots",
        "Musketeer's Riding Boots",
        "Passer's Wandering Boots",
        "Pioneer's Diver Boots",
        "Prisoner's Confinement Boots",
        "Grand Duke's Ceremonial Boots",
        "Valorous Wind-Soaring Boots",
        "Thief's Myriad-Faced Boots",
        "Wastelander's Heavy Boots",
        "Watchmaker's Dream Boots"
    };
    QString PlanarOrnamentsSphere[18] = {
        "Belobog's Fortress of Preservation",
        "Insumousu's Whalefall Ship",
        "Planet Screwllum's Mechanical Sun",
        "Duran's Tent of Golden Sky",
        "Glamoth's Iron Cavalry Regiment",
        "The Xianzhou Luofu's Celestial Ark",
        "Forge's Lotus Lantern Wick",
        "Salsotto's Moving City",
        "Izumo's Magatsu no Morokami",
        "Lushaka's Waterscape",
        "The IPC's Mega HQ",
        "Penacony's Grand Hotel",
        "Taikiyan Laser Stadium",
        "Sigonia's Gaiathra Berth",
        "Herta's Space Station",
        "Vonwacq's Island of Birth",
        "Talia's Nailscrap Town",
        "BananAmusement Park's BananAxis Plaza"
    };
    QString PlanarOrnamentsLinkRope[18] =
        {
            "Belobog's Iron Defense",
            "Insumousu's Frayed Hawser",
            "Planet Screwllum's Ring System",
            "Duran's Mechabeast Bridle",
            "Glamoth's Silent Tombstone",
            "The Xianzhou Luofu's Ambrosial Arbor Vines",
            "Forge's Heavenly Flamewheel Silk",
            "Salsotto's Terminator Line",
            "Izumo's Blades of Origin and End",
            "Lushaka's Twinlanes",
            "The IPC's Mega HQ",
            "Penacony's Dream-Seeking Tracks",
            "Taikiyan's Arclight Race Track",
            "Sigonia's Knot of Cyclicality",
            "Herta's Wandering Trek",
            "Vonwacq's Islandic Coast",
            "Talia's Exposed Electric Wire",
            "BananAmusement Park's Memetic Cables",
        };

};

#endif // ADDRELIC_H
