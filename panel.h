#ifndef PANEL_H
#define PANEL_H
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QWidget>
namespace Ui {
class Panel;
}

class Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = nullptr,QString ch="");
    ~Panel();

private slots:
    void on_closebtn_clicked();

private:
    Ui::Panel *ui;
    void inittable();
    QString currentch;
};

#endif // PANEL_H
