#ifndef CHANGECH_H
#define CHANGECH_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>

namespace Ui {
class changech;
}

class changech : public QWidget
{
    Q_OBJECT

public:
    explicit changech(QWidget *parent = nullptr,QString cch="");
    ~changech();
signals:
    void sendch(QString c, QString p);

private slots:

    void updatetableviewafterinserted();
    void on_add_clicked();
    void on_cancel_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_help_clicked();

    void on_remove_clicked();

    void on_search_textChanged(const QString &arg1);


private:
    Ui::changech *ui;
    QSqlTableModel *model=nullptr;
    QString currentcharacter;
    void inittable();
};

#endif // CHANGECH_H
