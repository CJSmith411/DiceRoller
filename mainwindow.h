#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cbDie_currentIndexChanged(const QString &arg1);

    void on_sbNum_valueChanged(int arg1);

    void on_sbKeep_valueChanged(int arg1);

    void on_cbAdd_currentTextChanged(const QString &arg1);

    void on_sbMin_valueChanged(int arg1);

    void on_sbMax_valueChanged(int arg1);

    void on_pbRoll_clicked();

private:
    Ui::MainWindow *ui;

private:
    void set_statusbar();
};
#endif // MAINWINDOW_H
