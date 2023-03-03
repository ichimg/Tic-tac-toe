#include "QtFrameworkUI.h"
#include <QMessageBox>

QtFrameworkUI::QtFrameworkUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.helloText->setText(QString::fromStdString("hELLO"));
    setWindowTitle("Qt UI");
}

QtFrameworkUI::~QtFrameworkUI()
{}

void QtFrameworkUI::on_okButton_clicked()
{
    QMessageBox qm;
    qm.setText("You just tickled me...");
    qm.exec();
    close();
}