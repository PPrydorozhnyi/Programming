#include "activewindow.h"
#include "ui_activewindow.h"

ActiveWindow::ActiveWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActiveWindow)
{
    ui->setupUi(this);
}

ActiveWindow::~ActiveWindow()
{
    delete ui;
}

void ActiveWindow::run()
{

}

void ActiveWindow::onDelete()
{
    char* temp = new char[40];
    emit forLogger(strcat(strcpy(temp, typeid(*this).name() ), " deleted") );
    delete[] temp;
}
