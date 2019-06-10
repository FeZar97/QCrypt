#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::Widget),
                                  keyLenght{DEFAULT_RSA_KEY_LENGTH}
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_encButton_clicked()
{
    inData = (ui->encInText->text()).toUtf8();

    auto timeBegin = std::chrono::high_resolution_clock::now();
    e.generatePairKey(pub, priv, keyLenght);
    auto timeGeneratePair = std::chrono::high_resolution_clock::now();

    encData = e.encode(inData, pub);
    auto timeEncode = std::chrono::high_resolution_clock::now();

    decData = e.decode(encData, priv);
    auto timeDecode = std::chrono::high_resolution_clock::now();

    ui->resTB->setText(QString("Time to generate RSA keys: %1 ns\n"
                               "Time to encode: %2 ns\n"
                               "Time to decode: %3 ns\n")
                               .arg(std::chrono::duration_cast<std::chrono::nanoseconds>(timeGeneratePair - timeBegin).count())
                               .arg(std::chrono::duration_cast<std::chrono::nanoseconds>(timeEncode - timeGeneratePair).count())
                               .arg(std::chrono::duration_cast<std::chrono::nanoseconds>(timeDecode - timeEncode).count()));
}

void Widget::on_rsaLengthCB_currentIndexChanged(int keyLengthIdx)
{
    keyLenght = getKeyLength(keyLengthIdx);
}

QRSAEncryption::Rsa Widget::getKeyLength(int idx)
{
    switch(idx){

        case 0:
            return QRSAEncryption::Rsa::RSA_64;
        case 1:
            return QRSAEncryption::Rsa::RSA_128;
        default:
            return QRSAEncryption::Rsa::RSA_64;
    }
}

void Widget::on_edsButton_clicked()
{
    inData = (ui->encInText->text()).toUtf8();

    e.generatePairKey(pub, priv, keyLenght);

    QByteArray signedMessage = e.signMessage(inData, priv);

    qDebug() << "signedMessage = " << signedMessage;

    ui->resTB->setText(signedMessage);

    if (e.checkSignMessage(signedMessage, pub)) {

        ui->resTB->setText("EDS is valid");
    }
}
