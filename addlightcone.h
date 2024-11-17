#ifndef ADDLIGHTCONE_H
#define ADDLIGHTCONE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QCheckBox>
namespace Ui {
class AddLightCone;
}

class AddLightCone : public QWidget
{
    Q_OBJECT

public:
    explicit AddLightCone(QWidget *parent = nullptr);
    ~AddLightCone();
    int sum=0;
signals:
    void updatelc();
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

    void on_calcelbtn_clicked();

    void on_configuebtn_clicked();
    void on_concept_editingFinished();

private:
    Ui::AddLightCone *ui;
    QSqlTableModel *model=nullptr;
};

#endif // ADDLIGHTCONE_H
