#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

#include <qrsaencryption.h>

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

    void on_decButton_clicked();

private:
    Ui::Widget *ui;

    QByteArray pub, priv;
    QRSAEncryption e;
};

#endif // WIDGET_H
