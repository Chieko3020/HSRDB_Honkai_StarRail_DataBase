#ifndef ADDCHARACTER_H
#define ADDCHARACTER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QCheckBox>

namespace Ui {
class AddCharacter;
}

class AddCharacter : public QWidget
{
    Q_OBJECT

public:
    explicit AddCharacter(QWidget *parent = nullptr);
    ~AddCharacter();
    int sum=0;
signals:
    void updatetableview();

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

    void on_checkBox_13_stateChanged(int arg1);

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_checkBox_16_stateChanged(int arg1);

    void on_calcelbtn_clicked();

    void on_configuebtn_clicked();

    void on_concept_editingFinished();

private:
    Ui::AddCharacter *ui;
    QSqlTableModel *model=nullptr;
};

#endif // ADDCHARACTER_H
