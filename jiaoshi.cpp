#include "jiaoshi.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtCore/QProcess>
#include <QMessageBox>
#include <QtCore/QSettings>
#include <QtCore/QVariant>
#include <QtCore/QTimer>
#include <QtCore/QDateTime>
#include <QAbstractButton>
#include <QtCore/QDebug>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jiaoshi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_jiaoshi[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      26,    8,    8,    8, 0x08,
      40,    8,    8,    8, 0x08,
      60,    8,    8,    8, 0x08,
      83,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_jiaoshi[] = {
    "jiaoshi\0\0zhucebiao_mima()\0guanbi_lima()\0"
    "five_min_close(int)\0chuangkou_dingzhi(int)\0"
    "chuangkou_xianshi()\0"
};

void jiaoshi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        jiaoshi *_t = static_cast<jiaoshi *>(_o);
        switch (_id) {
        case 0: _t->zhucebiao_mima(); break;
        case 1: _t->guanbi_lima(); break;
        case 2: _t->five_min_close((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->chuangkou_dingzhi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->chuangkou_xianshi(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData jiaoshi::staticMetaObjectExtraData = {
    0,  qt_static_metacall
};

const QMetaObject jiaoshi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_jiaoshi,
      qt_meta_data_jiaoshi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &jiaoshi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *jiaoshi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *jiaoshi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_jiaoshi))
        return static_cast<void*>(const_cast< jiaoshi*>(this));
    return QWidget::qt_metacast(_clname);
}

int jiaoshi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

jiaoshi::jiaoshi(QWidget *parent) : QWidget(parent)
{
    mima = new QLabel(QString::fromLocal8Bit("����"));
    mima_pojie = new QLineEdit;
    button_pojie = new QPushButton(QString::fromLocal8Bit("һ���ƽ�����"));
    button_guanbi = new QPushButton(QString::fromLocal8Bit("����ر�ѧ����"));
    checkbox_jieshu = new QCheckBox(QString::fromLocal8Bit("ÿ5���ӽ���ѧ����"),this);
    checkbox_zhiding = new QCheckBox(QString::fromLocal8Bit("����ѭ���ö�(���Թ���)"));
    //checkbox_zhiding->setCheckState(QAbstractButton::setChecked(true));

    timer = new QTimer(this);
    timer2 = new QTimer(this);

    connect(button_pojie,SIGNAL(clicked()),this,SLOT(zhucebiao_mima()));
    connect(button_guanbi,SIGNAL(clicked()),this,SLOT(guanbi_lima()));
    connect(checkbox_jieshu,SIGNAL(stateChanged(int)),this,SLOT(five_min_close(int)));
    connect(checkbox_zhiding,SIGNAL(stateChanged(int)),this,SLOT(chuangkou_dingzhi(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout -> addWidget(mima);
    layout -> addWidget(mima_pojie);
    layout -> addWidget(button_pojie);
    QHBoxLayout *layout_1 = new QHBoxLayout;
    layout_1 -> addWidget(button_guanbi);
    layout_1 -> addWidget(checkbox_jieshu);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout -> addLayout(layout);
    mainLayout -> addLayout(layout_1);
    mainLayout ->addWidget(checkbox_zhiding);
    setLayout(mainLayout);
    setWindowTitle(QString::fromLocal8Bit("���������ƽ�ѧ����By�޸�1.0������"));
    resize(400,100);
    //setWindowFlags(Qt::WindowStaysOnTopHint); //����c�����ö�
}

void jiaoshi::zhucebiao_mima() //�ܲ��ܶ��Ҳ�֪��
{
    QSettings regedit("HKEY_LOCAL_MACHINE\\SOFTWARE\\TopDomain\\e-Learning Class Standard\\1.00",QSettings::NativeFormat);
    QString s = regedit.value("UninstallPasswd").toString();
    mima_pojie -> setText(s);
    if(s == "")
    {
        //�����ȡΪ��
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ȡ����ʧ��"));
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ɹ���ȡ����"));
    }
}

void jiaoshi::guanbi_lima()
{
    QProcess *StudentMain = new QProcess();
    StudentMain ->start("taskkill /im StudentMain.exe /f"); //ִ�н�������
    QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ִ�н�������"));
//    QString s = QDateTime::currentDateTime().toString().append(QString::fromLocal8Bit("�����˽�������"));
//    qDebug()<<s;
}

void jiaoshi::five_min_close(int state)
{
    if(state == Qt::Checked) //ѡ�� ������ʱ�رչ���
    {
        //�����ر��ź�
        timer -> start(300000); //5min
        connect(timer,SIGNAL(timeout()),this,SLOT(guanbi_lima()));
    }
    if(state == Qt::Unchecked) //û�д򹴣�ֹͣ��ʱ��
        timer -> stop();
}

void jiaoshi::chuangkou_dingzhi(int state)
{
    if(state == Qt::Checked)
    {
        timer2 -> start(400); //ÿ0.4��ѭ���ö�����
        connect(timer2,SIGNAL(timeout()),this,SLOT(chuangkou_xianshi()));
    }
    if(state == Qt::Unchecked)
    {
        timer2 -> stop();
        this -> setWindowFlags(NULL);
        this -> show();
        qDebug()<<"quxiao_gouxuan";
    }
}

void jiaoshi::chuangkou_xianshi()
{
      this -> setWindowFlags(Qt::WindowStaysOnTopHint); //���ô����ö�
      this -> show();
      qDebug()<<"chuangkou_zhiding_chufa";
}
