#include "mainwindow.h"
#include "characters.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "lightcones.h"
#include "characters.h"
#include "relics.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QCloseEvent>
bool isinitch=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_init_lightcones(ui);
    ui_init_characters(ui);
    ui_init_relics(ui);
    ui->stackedWidget->setCurrentIndex(0);
    ui->subpanel->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:transparent;}");
    ui->subpanel->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->lcpanel->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:transparent;}");
    ui->lcpanel->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->exitbtn, SIGNAL(clicked()), qApp, SLOT(quit()) );
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_chtbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->ch->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:red;");
    ui->lc->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:white;");
    ui->rl->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:white;");
    if(!isinitch)
    {
        initch();
        isinitch=true;
    }


}


void MainWindow::on_lcbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->ch->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:white;");
    ui->lc->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:red;");
    ui->rl->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:white;");
    if(!lcmodel)
        initlctable();
    else
        lcmodel->submitAll();
}


void MainWindow::on_rlbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->ch->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:white;");
    ui->lc->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:white;");
    ui->rl->setStyleSheet("font: 700 16pt \"Meiryo UI\";color:red;");
    if(!rlmodel)
        initrltable();
    else
        rlmodel->submitAll();
}


void MainWindow::closeEvent(QCloseEvent *event)//重载关闭事件
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QPixmap(":/res/icon.png"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Are you really going to quit ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec()==QMessageBox::No)
        event->ignore();
    else
    {
        if(lcmodel)
            delete lcmodel;
        if(rlmodel)
            delete rlmodel;
        rmConnection();
    }
}







