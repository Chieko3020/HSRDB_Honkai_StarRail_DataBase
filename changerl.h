#ifndef CHANGERL_H
#define CHANGERL_H
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class changerl;
}

class changerl : public QWidget
{
    Q_OBJECT

public:
    explicit changerl(QWidget *parent = nullptr,QString st="",QString ch="");
    ~changerl();
signals:
    void sendrl(QString st,QString cp);
private slots:
    void on_help_clicked();

    void on_cancel_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:


private:
    Ui::changerl *ui;
    QSqlTableModel *model=nullptr;
    QString character;
    QString slot;
    void inittable();
    void equip(QString concept);
    void setCurrentrl(QString ch);
};




#endif // CHANGERL_H
