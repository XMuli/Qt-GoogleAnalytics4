#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ganalytics/ganalytics.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ga, &GAnalytics::sigSendResp, this, [this](const QString& msg) { ui->textBrowser->append(msg); });

    resize(1600, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSend_pressed()
{
    auto& btnSend = ui->btnSend;
    const auto& category = ui->leCategory->text();
    const auto& eventName = ui->leEventName->text();
    const auto& eventParamName = ui->leEventParamName->text();
    const auto& eventParamValue = ui->leEventParamValue->text();

    if (!eventName.isEmpty())
        ga->sendEvent(category, eventName, eventParamName, eventParamValue);
}

