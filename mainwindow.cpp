#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(3,3);
    ui->BilliardWidget->setFormat(format);

    requestLightFactors();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requestLightFactors()
{
    ui->BilliardWidget->setLightCoefs({
                                 ui->AmbientFactor->value(),
                                 ui->DiffuseFactor->value(),
                                 ui->KFactor->value(),
                                 ui->PFactor->value(),
                                 ui->N->value(),
                                 ui->SpecularFactor->value()
                             });
}

