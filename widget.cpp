#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);

    qDebug() << __FUNCTION__;
}

Widget::~Widget()
{
    delete ui;

    qDebug() << __FUNCTION__;
}

void Widget::dropEvent(QDropEvent *event)
{
    ui->textEdit->setText("dropEvent");

    qDebug() << __FUNCTION__;
}

void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    ui->textEdit->setText("dragEnterEvent");

    event->acceptProposedAction();

    qDebug() << __FUNCTION__;
}

void Widget::dragMoveEvent(QDragMoveEvent *event)
{
    ui->textEdit->setText("dragMoveEvent");

    event->setDropAction(Qt::MoveAction);

    qDebug() << __FUNCTION__;
}

void Widget::dragLeaveEvent(QDragLeaveEvent *event)
{
    ui->textEdit->setText("dragLeaveEvent");

    qDebug() << __FUNCTION__;
}
