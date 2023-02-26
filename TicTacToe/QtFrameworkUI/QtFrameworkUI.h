#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtFrameworkUI.h"
#include <Test.h>

class QtFrameworkUI : public QMainWindow
{
    Q_OBJECT

public:
    QtFrameworkUI(QWidget *parent = nullptr);
    ~QtFrameworkUI();

private slots:
     void on_okButton_clicked();

private:
    Ui::QtFrameworkUIClass ui;
    Test testObject;
};
