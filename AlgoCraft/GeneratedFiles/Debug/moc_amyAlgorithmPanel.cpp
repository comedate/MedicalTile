/****************************************************************************
** Meta object code from reading C++ file 'amyAlgorithmPanel.h'
**
** Created: Fri Mar 21 11:13:15 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../headers/amyAlgorithmPanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'amyAlgorithmPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_amyAlgorithmPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_amyAlgorithmPanel[] = {
    "amyAlgorithmPanel\0\0s_focusout()\0"
};

void amyAlgorithmPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        amyAlgorithmPanel *_t = static_cast<amyAlgorithmPanel *>(_o);
        switch (_id) {
        case 0: _t->s_focusout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData amyAlgorithmPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject amyAlgorithmPanel::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_amyAlgorithmPanel,
      qt_meta_data_amyAlgorithmPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &amyAlgorithmPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *amyAlgorithmPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *amyAlgorithmPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_amyAlgorithmPanel))
        return static_cast<void*>(const_cast< amyAlgorithmPanel*>(this));
    return QFrame::qt_metacast(_clname);
}

int amyAlgorithmPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void amyAlgorithmPanel::s_focusout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
