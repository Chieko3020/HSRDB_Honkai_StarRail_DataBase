#ifndef CHANGELC_H
#define CHANGELC_H

#include <QWidget>
#include <QSqlTableModel>
namespace Ui {
class changelc;
}

class changelc : public QWidget
{
    Q_OBJECT

public:
    explicit changelc(QWidget *parent = nullptr,QString ch="", QString lcp="", QString clc="");
    ~changelc();
signals:
    void sendlc(QString lc);

private slots:
    void on_help_clicked();

    void on_cancel_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::changelc *ui;
    QSqlTableModel *model=nullptr;
    void inittable();
    void equip(QString concept);
    void setCurrentlc(QString clc);
    QString lcpath;
    QString character;
    QString currentlc;
};

#endif // CHANGELC_H
