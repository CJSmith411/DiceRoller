#include "mainwindow.h"
#include "dieroller.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sbKeep->setMaximum(ui->sbNum->value());
    ui->sbMin->setMaximum(ui->cbDie->currentText().toInt()-1);
    ui->sbMax->setMaximum(ui->cbDie->currentText().toInt());
    ui->statusbar->showMessage("1d6");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_statusbar()
{
    QString s = ui->sbNum->text().append("d").append(ui->cbDie->currentText()); // basic roll
    // conditional notation for keeping/discarding some dice
    if (ui->sbKeep->text().toInt() < ui->sbNum->text().toInt())
    {
        s.append("k").append(ui->sbKeep->text());
    }
    // conditional notation for modifiers & sign
    if (ui->cbAdd->currentText().toInt() < 0)
    {
        s.append(ui->cbAdd->currentText());
    }
    else if (ui->cbAdd->currentText().toInt()>0)
    {
        s.append("+").append(ui->cbAdd->currentText());
    }
    // conditional notation for minimum die values
    if (ui->sbMin->text().toInt() > 1)
    {
        s.append(">").append(QString::number(ui->sbMin->text().toInt() - 1));
    }
    // conditional notation for maximum die values
    if (ui->sbMax->text().toInt() < ui->cbDie->currentText().toInt())
    {
        s.append("<").append(QString::number(ui->sbMax->text().toInt() + 1));
    }

    ui->statusbar->showMessage(s);
}

void MainWindow::on_cbDie_currentIndexChanged(const QString &arg1)
{
    ui->sbMin->setMaximum(arg1.toInt()-1);
    bool atMax = ui->sbMax->value() == ui->sbMax->maximum();
    ui->sbMax->setMaximum(arg1.toInt());
    if (atMax)
    {
        ui->sbMax->setValue((arg1.toInt()));
    }
    set_statusbar();
}

void MainWindow::on_sbNum_valueChanged(int arg1)
{
    bool atMax = ui->sbKeep->text().toInt() == ui->sbKeep->maximum();
    ui->sbKeep->setMaximum(arg1);
    if (atMax)
    {
        ui->sbKeep->setValue((arg1));
    }
    set_statusbar();
}


void MainWindow::on_sbKeep_valueChanged(int arg1)
{
    ui->cbAdd->setItemText(0, QString::number(arg1 * -2));
    ui->cbAdd->setItemText(1, QString::number(arg1 * -1));
    ui->cbAdd->setItemText(3, QString::number(arg1));
    ui->cbAdd->setItemText(4, QString::number(arg1 * 2));
    set_statusbar();
}


void MainWindow::on_cbAdd_currentTextChanged(const QString &arg1)
{
    QRegExp re("\\d*");
    if (!re.exactMatch(arg1))
    {
        ui->cbAdd->setCurrentText("0");
    }
    set_statusbar();
}


void MainWindow::on_sbMin_valueChanged(int arg1)
{
    ui->sbMax->setMinimum(arg1 + 1);
    set_statusbar();
}


void MainWindow::on_sbMax_valueChanged(int arg1)
{
    ui->sbMin->setMaximum(arg1 - 1);
    set_statusbar();
}


void MainWindow::on_pbRoll_clicked()
{
    DieRoller dr(
                ui->cbDie->currentText().toInt(),
                ui->sbNum->value(),
                ui->sbKeep->value(),
                ui->cbAdd->currentText().toInt(),
                ui->sbMin->value(),
                ui->sbMax->value());
    dr.rollDice();
    ui->txtTotal->setPlainText(QString::number(dr.getTotal()));
    ui->txtResult->setPlainText(dr.getResult());
}

