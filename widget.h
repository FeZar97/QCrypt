#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <chrono>

#include <qrsaencryption.h>

#define  DEFAULT_RSA_KEY_LENGTH     QRSAEncryption::Rsa::RSA_64

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_encButton_clicked();

    void on_rsaLengthCB_currentIndexChanged(int index);

private:
    Ui::Widget *ui;

    QRSAEncryption::Rsa keyLenght;

    QByteArray pub, priv;
    QRSAEncryption e;

    QByteArray inData;
    QByteArray encData;
    QByteArray decData;

    QRSAEncryption::Rsa getKeyLength(int idx = 0);
};

#endif // WIDGET_H
