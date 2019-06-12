#ifndef JIAOSHI_H
#define JIAOSHI_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;
class QCheckBox;
class QTimer;

class jiaoshi :public QWidget
{
    Q_OBJECT
public:
    jiaoshi(QWidget *parent = 0);
signals:

private slots:
    void zhucebiao_mima();
    void guanbi_lima();
    void five_min_close(int);
    void chuangkou_dingzhi(int);
    void chuangkou_xianshi();

private:
    QLabel *mima;
    QLineEdit *mima_pojie;
    QPushButton *button_pojie;
    QPushButton *button_guanbi;
    QCheckBox *checkbox_jieshu;
    QCheckBox *checkbox_zhiding;
    QTimer *timer;  //��ʱ��ʱ�ر�
    QTimer *timer2; //��ʱ�����ö�
};

#endif // JIAOSHI_H
