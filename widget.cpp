#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_encButton_clicked()
{
    e.generatePairKey(pub, priv, QRSAEncryption::Rsa::RSA_128); // or QRSAEncryption::Rsa::RSA_64
    QByteArray msg = "123";//(ui->encInText->text()).toUtf8();

    //auto encodeData = e.encode(msg, pub);
    //auto decodeData = e.decode(encodeData, priv);

    //qDebug() << encodeData << endl;
}

void Widget::on_decButton_clicked()
{

}
