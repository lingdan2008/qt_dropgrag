#include "widget.h"
#include "ui_widget.h"
#include <QMimeData>
#include <QList>
#include <QUrl>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);
    ui->textEdit_2->setAcceptDrops(false);

    qDebug() << __FUNCTION__;
}

Widget::~Widget()
{
    delete ui;

    qDebug() << __FUNCTION__;
}

void Widget::dropEvent(QDropEvent *event)
{
    //ui->textEdit->setText("dropEvent");

    QList<QUrl> list = (event->mimeData())->urls();
    if(list.isEmpty()) {
        qDebug() << __FUNCTION__ << "url is empty";
    }

    foreach (QUrl url, list) {
        QString sFileName = url.toLocalFile();
        ui->textEdit->append(sFileName);

        readFile(sFileName);

        qDebug() << __FUNCTION__ << sFileName;
    }

    qDebug() << __FUNCTION__;
}

void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    //ui->textEdit->setText("dragEnterEvent");

    if((event->mimeData())->hasFormat("text/uri-list")) {
        event->acceptProposedAction();

        qDebug() << __FUNCTION__ << "acceptProposedAction";
    }

    qDebug() << __FUNCTION__;
}

void Widget::dragMoveEvent(QDragMoveEvent *event)
{
    //ui->textEdit->setText("dragMoveEvent");

    event->setDropAction(Qt::MoveAction);

    qDebug() << __FUNCTION__;
}

void Widget::dragLeaveEvent(QDragLeaveEvent *event)
{
    //ui->textEdit->setText("dragLeaveEvent");

    qDebug() << __FUNCTION__;
}

bool Widget::readFile(const QString sFileName)
{
    int len = 0;
    QFile file(sFileName);
    if(file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        ui->textEdit_2->setText(QString(data));

        len = data.length();
    }

    qDebug() << __FUNCTION__ << len;
}
