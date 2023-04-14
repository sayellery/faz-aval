/****************************************************************************
** Meta object code from reading C++ file 'signup_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../signup_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signup_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_signup_page_t {
    QByteArrayData data[12];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_signup_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_signup_page_t qt_meta_stringdata_signup_page = {
    {
QT_MOC_LITERAL(0, 0, 11), // "signup_page"
QT_MOC_LITERAL(1, 12, 22), // "on_captcha_btn_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "on_tab_btn1_clicked"
QT_MOC_LITERAL(4, 56, 19), // "on_tab_btn2_clicked"
QT_MOC_LITERAL(5, 76, 25), // "on_show_pass_btn1_clicked"
QT_MOC_LITERAL(6, 102, 25), // "on_hide_pass_btn1_clicked"
QT_MOC_LITERAL(7, 128, 25), // "on_show_pass_btn2_clicked"
QT_MOC_LITERAL(8, 154, 25), // "on_hide_pass_btn2_clicked"
QT_MOC_LITERAL(9, 180, 19), // "on_back_btn_clicked"
QT_MOC_LITERAL(10, 200, 21), // "on_signup_btn_clicked"
QT_MOC_LITERAL(11, 222, 20) // "on_login_btn_clicked"

    },
    "signup_page\0on_captcha_btn_clicked\0\0"
    "on_tab_btn1_clicked\0on_tab_btn2_clicked\0"
    "on_show_pass_btn1_clicked\0"
    "on_hide_pass_btn1_clicked\0"
    "on_show_pass_btn2_clicked\0"
    "on_hide_pass_btn2_clicked\0on_back_btn_clicked\0"
    "on_signup_btn_clicked\0on_login_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_signup_page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void signup_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<signup_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_captcha_btn_clicked(); break;
        case 1: _t->on_tab_btn1_clicked(); break;
        case 2: _t->on_tab_btn2_clicked(); break;
        case 3: _t->on_show_pass_btn1_clicked(); break;
        case 4: _t->on_hide_pass_btn1_clicked(); break;
        case 5: _t->on_show_pass_btn2_clicked(); break;
        case 6: _t->on_hide_pass_btn2_clicked(); break;
        case 7: _t->on_back_btn_clicked(); break;
        case 8: _t->on_signup_btn_clicked(); break;
        case 9: _t->on_login_btn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject signup_page::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_signup_page.data,
    qt_meta_data_signup_page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *signup_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *signup_page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_signup_page.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int signup_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
