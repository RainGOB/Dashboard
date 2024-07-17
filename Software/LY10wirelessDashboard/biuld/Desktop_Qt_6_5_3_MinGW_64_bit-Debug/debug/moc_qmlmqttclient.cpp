/****************************************************************************
** Meta object code from reading C++ file 'qmlmqttclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qmlmqttclient.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlmqttclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS = QtMocHelpers::stringData(
    "QmlMqttSubscription",
    "topicChanged",
    "",
    "messageReceived",
    "msg",
    "topic",
    "QMqttTopicFilter"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[20];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[4];
    char stringdata5[6];
    char stringdata6[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "QmlMqttSubscription"
        QT_MOC_LITERAL(20, 12),  // "topicChanged"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 15),  // "messageReceived"
        QT_MOC_LITERAL(50, 3),  // "msg"
        QT_MOC_LITERAL(54, 5),  // "topic"
        QT_MOC_LITERAL(60, 16)   // "QMqttTopicFilter"
    },
    "QmlMqttSubscription",
    "topicChanged",
    "",
    "messageReceived",
    "msg",
    "topic",
    "QMqttTopicFilter"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmlMqttSubscriptionENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    2 /* Public */,
       3,    1,   29,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    4,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x0001500b, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QmlMqttSubscription::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmlMqttSubscriptionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t,
        // property 'topic'
        QtPrivate::TypeAndForceComplete<QMqttTopicFilter, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QmlMqttSubscription, std::true_type>,
        // method 'topicChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'messageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void QmlMqttSubscription::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmlMqttSubscription *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->topicChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QmlMqttSubscription::*)(QString );
            if (_t _q_method = &QmlMqttSubscription::topicChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QmlMqttSubscription::*)(const QString & );
            if (_t _q_method = &QmlMqttSubscription::messageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicFilter >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QmlMqttSubscription *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QMqttTopicFilter*>(_v) = _t->m_topic; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QmlMqttSubscription *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_topic != *reinterpret_cast< QMqttTopicFilter*>(_v)) {
                _t->m_topic = *reinterpret_cast< QMqttTopicFilter*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QmlMqttSubscription::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmlMqttSubscription::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QmlMqttSubscription::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QmlMqttSubscription::topicChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QmlMqttSubscription::messageReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQmlMqttClientENDCLASS = QtMocHelpers::stringData(
    "QmlMqttClient",
    "carSpeedChanged",
    "",
    "batLevelChanged",
    "batTempChanged",
    "throPosChanged",
    "gearModeChanged",
    "carModeChanged",
    "batAlarmChanged",
    "batVolChanged",
    "mcu2TempChanged",
    "mcu1TempChanged",
    "carDistanceChanged",
    "brakeTravelChanged",
    "rmotorTempChanged",
    "lmotorTempChanged",
    "rmotorSpeedChanged",
    "lmotorSpeedChanged",
    "rmotortorqChanged",
    "lmotortorqChanged",
    "angleChanged",
    "LbatAlrChanged",
    "acc_xChanged",
    "acc_yChanged",
    "acc_zChanged",
    "stateChanged",
    "onDataRec",
    "QMqttMessage",
    "qmsg",
    "connectToHost",
    "disconnectFromHost",
    "subscribe",
    "QmlMqttSubscription*",
    "topic",
    "carSpeed",
    "batLevel",
    "batTemp",
    "lmotorTemp",
    "rmotorTemp",
    "lmotorSpeed",
    "rmotorSpeed",
    "throPos",
    "gearMode",
    "carMode",
    "carDistance",
    "brakeTravel",
    "mcu1Temp",
    "mcu2Temp",
    "batVol",
    "batAlarm",
    "lmotortorq",
    "rmotortorq",
    "angle",
    "LbatAlr",
    "acc_x",
    "acc_y",
    "acc_z",
    "state",
    "QMqttClient::ClientState"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t {
    uint offsetsAndSizes[118];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[15];
    char stringdata5[15];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[16];
    char stringdata9[14];
    char stringdata10[16];
    char stringdata11[16];
    char stringdata12[19];
    char stringdata13[19];
    char stringdata14[18];
    char stringdata15[18];
    char stringdata16[19];
    char stringdata17[19];
    char stringdata18[18];
    char stringdata19[18];
    char stringdata20[13];
    char stringdata21[15];
    char stringdata22[13];
    char stringdata23[13];
    char stringdata24[13];
    char stringdata25[13];
    char stringdata26[10];
    char stringdata27[13];
    char stringdata28[5];
    char stringdata29[14];
    char stringdata30[19];
    char stringdata31[10];
    char stringdata32[21];
    char stringdata33[6];
    char stringdata34[9];
    char stringdata35[9];
    char stringdata36[8];
    char stringdata37[11];
    char stringdata38[11];
    char stringdata39[12];
    char stringdata40[12];
    char stringdata41[8];
    char stringdata42[9];
    char stringdata43[8];
    char stringdata44[12];
    char stringdata45[12];
    char stringdata46[9];
    char stringdata47[9];
    char stringdata48[7];
    char stringdata49[9];
    char stringdata50[11];
    char stringdata51[11];
    char stringdata52[6];
    char stringdata53[8];
    char stringdata54[6];
    char stringdata55[6];
    char stringdata56[6];
    char stringdata57[6];
    char stringdata58[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t qt_meta_stringdata_CLASSQmlMqttClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QmlMqttClient"
        QT_MOC_LITERAL(14, 15),  // "carSpeedChanged"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 15),  // "batLevelChanged"
        QT_MOC_LITERAL(47, 14),  // "batTempChanged"
        QT_MOC_LITERAL(62, 14),  // "throPosChanged"
        QT_MOC_LITERAL(77, 15),  // "gearModeChanged"
        QT_MOC_LITERAL(93, 14),  // "carModeChanged"
        QT_MOC_LITERAL(108, 15),  // "batAlarmChanged"
        QT_MOC_LITERAL(124, 13),  // "batVolChanged"
        QT_MOC_LITERAL(138, 15),  // "mcu2TempChanged"
        QT_MOC_LITERAL(154, 15),  // "mcu1TempChanged"
        QT_MOC_LITERAL(170, 18),  // "carDistanceChanged"
        QT_MOC_LITERAL(189, 18),  // "brakeTravelChanged"
        QT_MOC_LITERAL(208, 17),  // "rmotorTempChanged"
        QT_MOC_LITERAL(226, 17),  // "lmotorTempChanged"
        QT_MOC_LITERAL(244, 18),  // "rmotorSpeedChanged"
        QT_MOC_LITERAL(263, 18),  // "lmotorSpeedChanged"
        QT_MOC_LITERAL(282, 17),  // "rmotortorqChanged"
        QT_MOC_LITERAL(300, 17),  // "lmotortorqChanged"
        QT_MOC_LITERAL(318, 12),  // "angleChanged"
        QT_MOC_LITERAL(331, 14),  // "LbatAlrChanged"
        QT_MOC_LITERAL(346, 12),  // "acc_xChanged"
        QT_MOC_LITERAL(359, 12),  // "acc_yChanged"
        QT_MOC_LITERAL(372, 12),  // "acc_zChanged"
        QT_MOC_LITERAL(385, 12),  // "stateChanged"
        QT_MOC_LITERAL(398, 9),  // "onDataRec"
        QT_MOC_LITERAL(408, 12),  // "QMqttMessage"
        QT_MOC_LITERAL(421, 4),  // "qmsg"
        QT_MOC_LITERAL(426, 13),  // "connectToHost"
        QT_MOC_LITERAL(440, 18),  // "disconnectFromHost"
        QT_MOC_LITERAL(459, 9),  // "subscribe"
        QT_MOC_LITERAL(469, 20),  // "QmlMqttSubscription*"
        QT_MOC_LITERAL(490, 5),  // "topic"
        QT_MOC_LITERAL(496, 8),  // "carSpeed"
        QT_MOC_LITERAL(505, 8),  // "batLevel"
        QT_MOC_LITERAL(514, 7),  // "batTemp"
        QT_MOC_LITERAL(522, 10),  // "lmotorTemp"
        QT_MOC_LITERAL(533, 10),  // "rmotorTemp"
        QT_MOC_LITERAL(544, 11),  // "lmotorSpeed"
        QT_MOC_LITERAL(556, 11),  // "rmotorSpeed"
        QT_MOC_LITERAL(568, 7),  // "throPos"
        QT_MOC_LITERAL(576, 8),  // "gearMode"
        QT_MOC_LITERAL(585, 7),  // "carMode"
        QT_MOC_LITERAL(593, 11),  // "carDistance"
        QT_MOC_LITERAL(605, 11),  // "brakeTravel"
        QT_MOC_LITERAL(617, 8),  // "mcu1Temp"
        QT_MOC_LITERAL(626, 8),  // "mcu2Temp"
        QT_MOC_LITERAL(635, 6),  // "batVol"
        QT_MOC_LITERAL(642, 8),  // "batAlarm"
        QT_MOC_LITERAL(651, 10),  // "lmotortorq"
        QT_MOC_LITERAL(662, 10),  // "rmotortorq"
        QT_MOC_LITERAL(673, 5),  // "angle"
        QT_MOC_LITERAL(679, 7),  // "LbatAlr"
        QT_MOC_LITERAL(687, 5),  // "acc_x"
        QT_MOC_LITERAL(693, 5),  // "acc_y"
        QT_MOC_LITERAL(699, 5),  // "acc_z"
        QT_MOC_LITERAL(705, 5),  // "state"
        QT_MOC_LITERAL(711, 24)   // "QMqttClient::ClientState"
    },
    "QmlMqttClient",
    "carSpeedChanged",
    "",
    "batLevelChanged",
    "batTempChanged",
    "throPosChanged",
    "gearModeChanged",
    "carModeChanged",
    "batAlarmChanged",
    "batVolChanged",
    "mcu2TempChanged",
    "mcu1TempChanged",
    "carDistanceChanged",
    "brakeTravelChanged",
    "rmotorTempChanged",
    "lmotorTempChanged",
    "rmotorSpeedChanged",
    "lmotorSpeedChanged",
    "rmotortorqChanged",
    "lmotortorqChanged",
    "angleChanged",
    "LbatAlrChanged",
    "acc_xChanged",
    "acc_yChanged",
    "acc_zChanged",
    "stateChanged",
    "onDataRec",
    "QMqttMessage",
    "qmsg",
    "connectToHost",
    "disconnectFromHost",
    "subscribe",
    "QmlMqttSubscription*",
    "topic",
    "carSpeed",
    "batLevel",
    "batTemp",
    "lmotorTemp",
    "rmotorTemp",
    "lmotorSpeed",
    "rmotorSpeed",
    "throPos",
    "gearMode",
    "carMode",
    "carDistance",
    "brakeTravel",
    "mcu1Temp",
    "mcu2Temp",
    "batVol",
    "batAlarm",
    "lmotortorq",
    "rmotortorq",
    "angle",
    "LbatAlr",
    "acc_x",
    "acc_y",
    "acc_z",
    "state",
    "QMqttClient::ClientState"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmlMqttClientENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
      24,  214, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  182,    2, 0x06,   25 /* Public */,
       3,    0,  183,    2, 0x06,   26 /* Public */,
       4,    0,  184,    2, 0x06,   27 /* Public */,
       5,    0,  185,    2, 0x06,   28 /* Public */,
       6,    0,  186,    2, 0x06,   29 /* Public */,
       7,    0,  187,    2, 0x06,   30 /* Public */,
       8,    0,  188,    2, 0x06,   31 /* Public */,
       9,    0,  189,    2, 0x06,   32 /* Public */,
      10,    0,  190,    2, 0x06,   33 /* Public */,
      11,    0,  191,    2, 0x06,   34 /* Public */,
      12,    0,  192,    2, 0x06,   35 /* Public */,
      13,    0,  193,    2, 0x06,   36 /* Public */,
      14,    0,  194,    2, 0x06,   37 /* Public */,
      15,    0,  195,    2, 0x06,   38 /* Public */,
      16,    0,  196,    2, 0x06,   39 /* Public */,
      17,    0,  197,    2, 0x06,   40 /* Public */,
      18,    0,  198,    2, 0x06,   41 /* Public */,
      19,    0,  199,    2, 0x06,   42 /* Public */,
      20,    0,  200,    2, 0x06,   43 /* Public */,
      21,    0,  201,    2, 0x06,   44 /* Public */,
      22,    0,  202,    2, 0x06,   45 /* Public */,
      23,    0,  203,    2, 0x06,   46 /* Public */,
      24,    0,  204,    2, 0x06,   47 /* Public */,
      25,    0,  205,    2, 0x06,   48 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    1,  206,    2, 0x0a,   49 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      29,    0,  209,    2, 0x02,   51 /* Public */,
      30,    0,  210,    2, 0x02,   52 /* Public */,
      31,    1,  211,    2, 0x02,   53 /* Public */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 27,   28,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 32, QMetaType::QString,   33,

 // properties: name, type, flags
      34, QMetaType::UInt, 0x00015103, uint(0), 0,
      35, QMetaType::UInt, 0x00015103, uint(1), 0,
      36, QMetaType::UInt, 0x00015103, uint(2), 0,
      37, QMetaType::UInt, 0x00015103, uint(13), 0,
      38, QMetaType::UInt, 0x00015103, uint(12), 0,
      39, QMetaType::UInt, 0x00015103, uint(15), 0,
      40, QMetaType::UInt, 0x00015103, uint(14), 0,
      41, QMetaType::UInt, 0x00015103, uint(3), 0,
      42, QMetaType::UInt, 0x00015103, uint(4), 0,
      43, QMetaType::UInt, 0x00015103, uint(5), 0,
      44, QMetaType::UInt, 0x00015103, uint(10), 0,
      45, QMetaType::UInt, 0x00015103, uint(11), 0,
      46, QMetaType::UInt, 0x00015103, uint(9), 0,
      47, QMetaType::UInt, 0x00015103, uint(8), 0,
      48, QMetaType::UInt, 0x00015103, uint(7), 0,
      49, QMetaType::Bool, 0x00015103, uint(6), 0,
      50, QMetaType::UInt, 0x00015103, uint(17), 0,
      51, QMetaType::UInt, 0x00015103, uint(16), 0,
      52, QMetaType::UInt, 0x00015103, uint(18), 0,
      53, QMetaType::UInt, 0x00015103, uint(19), 0,
      54, QMetaType::Float, 0x00015103, uint(20), 0,
      55, QMetaType::Float, 0x00015103, uint(21), 0,
      56, QMetaType::Float, 0x00015103, uint(22), 0,
      57, 0x80000000 | 58, 0x0001510b, uint(23), 0,

       0        // eod
};

Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_CLASSQmlMqttClientENDCLASS[] = {
    QMetaObject::SuperData::link<QMqttClient::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QmlMqttClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QMqttClient::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmlMqttClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmlMqttClientENDCLASS,
    qt_static_metacall,
    qt_meta_extradata_CLASSQmlMqttClientENDCLASS,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t,
        // property 'carSpeed'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'batLevel'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'batTemp'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'lmotorTemp'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'rmotorTemp'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'lmotorSpeed'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'rmotorSpeed'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'throPos'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'gearMode'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'carMode'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'carDistance'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'brakeTravel'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'mcu1Temp'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'mcu2Temp'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'batVol'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'batAlarm'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'lmotortorq'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'rmotortorq'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'angle'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'LbatAlr'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'acc_x'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'acc_y'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'acc_z'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'state'
        QtPrivate::TypeAndForceComplete<QMqttClient::ClientState, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QmlMqttClient, std::true_type>,
        // method 'carSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'batLevelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'batTempChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'throPosChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gearModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'carModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'batAlarmChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'batVolChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mcu2TempChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mcu1TempChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'carDistanceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'brakeTravelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rmotorTempChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lmotorTempChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rmotorSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lmotorSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rmotortorqChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lmotortorqChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'angleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LbatAlrChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'acc_xChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'acc_yChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'acc_zChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDataRec'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMqttMessage &, std::false_type>,
        // method 'connectToHost'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectFromHost'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'subscribe'
        QtPrivate::TypeAndForceComplete<QmlMqttSubscription *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void QmlMqttClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->carSpeedChanged(); break;
        case 1: _t->batLevelChanged(); break;
        case 2: _t->batTempChanged(); break;
        case 3: _t->throPosChanged(); break;
        case 4: _t->gearModeChanged(); break;
        case 5: _t->carModeChanged(); break;
        case 6: _t->batAlarmChanged(); break;
        case 7: _t->batVolChanged(); break;
        case 8: _t->mcu2TempChanged(); break;
        case 9: _t->mcu1TempChanged(); break;
        case 10: _t->carDistanceChanged(); break;
        case 11: _t->brakeTravelChanged(); break;
        case 12: _t->rmotorTempChanged(); break;
        case 13: _t->lmotorTempChanged(); break;
        case 14: _t->rmotorSpeedChanged(); break;
        case 15: _t->lmotorSpeedChanged(); break;
        case 16: _t->rmotortorqChanged(); break;
        case 17: _t->lmotortorqChanged(); break;
        case 18: _t->angleChanged(); break;
        case 19: _t->LbatAlrChanged(); break;
        case 20: _t->acc_xChanged(); break;
        case 21: _t->acc_yChanged(); break;
        case 22: _t->acc_zChanged(); break;
        case 23: _t->stateChanged(); break;
        case 24: _t->onDataRec((*reinterpret_cast< std::add_pointer_t<QMqttMessage>>(_a[1]))); break;
        case 25: _t->connectToHost(); break;
        case 26: _t->disconnectFromHost(); break;
        case 27: { QmlMqttSubscription* _r = _t->subscribe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QmlMqttSubscription**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMqttMessage >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::carSpeedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::batLevelChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::batTempChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::throPosChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::gearModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::carModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::batAlarmChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::batVolChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::mcu2TempChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::mcu1TempChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::carDistanceChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::brakeTravelChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::rmotorTempChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::lmotorTempChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::rmotorSpeedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::lmotorSpeedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::rmotortorqChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::lmotortorqChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::angleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::LbatAlrChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::acc_xChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::acc_yChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::acc_zChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttClient::ClientState >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->carSpeed(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->batLevel(); break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->batTemp(); break;
        case 3: *reinterpret_cast< uint*>(_v) = _t->lmotorTemp(); break;
        case 4: *reinterpret_cast< uint*>(_v) = _t->rmotorTemp(); break;
        case 5: *reinterpret_cast< uint*>(_v) = _t->lmotorSpeed(); break;
        case 6: *reinterpret_cast< uint*>(_v) = _t->rmotorSpeed(); break;
        case 7: *reinterpret_cast< uint*>(_v) = _t->throPos(); break;
        case 8: *reinterpret_cast< uint*>(_v) = _t->gearMode(); break;
        case 9: *reinterpret_cast< uint*>(_v) = _t->carMode(); break;
        case 10: *reinterpret_cast< uint*>(_v) = _t->carDistance(); break;
        case 11: *reinterpret_cast< uint*>(_v) = _t->brakeTravel(); break;
        case 12: *reinterpret_cast< uint*>(_v) = _t->mcu1Temp(); break;
        case 13: *reinterpret_cast< uint*>(_v) = _t->mcu2Temp(); break;
        case 14: *reinterpret_cast< uint*>(_v) = _t->batVol(); break;
        case 15: *reinterpret_cast< bool*>(_v) = _t->batAlarm(); break;
        case 16: *reinterpret_cast< uint*>(_v) = _t->lmotortorq(); break;
        case 17: *reinterpret_cast< uint*>(_v) = _t->rmotortorq(); break;
        case 18: *reinterpret_cast< uint*>(_v) = _t->angle(); break;
        case 19: *reinterpret_cast< uint*>(_v) = _t->LbatAlr(); break;
        case 20: *reinterpret_cast< float*>(_v) = _t->acc_x(); break;
        case 21: *reinterpret_cast< float*>(_v) = _t->acc_y(); break;
        case 22: *reinterpret_cast< float*>(_v) = _t->acc_z(); break;
        case 23: *reinterpret_cast< QMqttClient::ClientState*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCarSpeed(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setBatLevel(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setBatTemp(*reinterpret_cast< uint*>(_v)); break;
        case 3: _t->setLmotorTemp(*reinterpret_cast< uint*>(_v)); break;
        case 4: _t->setRmotorTemp(*reinterpret_cast< uint*>(_v)); break;
        case 5: _t->setLmotorSpeed(*reinterpret_cast< uint*>(_v)); break;
        case 6: _t->setRmotorSpeed(*reinterpret_cast< uint*>(_v)); break;
        case 7: _t->setThroPos(*reinterpret_cast< uint*>(_v)); break;
        case 8: _t->setGearMode(*reinterpret_cast< uint*>(_v)); break;
        case 9: _t->setCarMode(*reinterpret_cast< uint*>(_v)); break;
        case 10: _t->setCarDistance(*reinterpret_cast< uint*>(_v)); break;
        case 11: _t->setBrakeTravel(*reinterpret_cast< uint*>(_v)); break;
        case 12: _t->setMcu1Temp(*reinterpret_cast< uint*>(_v)); break;
        case 13: _t->setMcu2Temp(*reinterpret_cast< uint*>(_v)); break;
        case 14: _t->setBatVol(*reinterpret_cast< uint*>(_v)); break;
        case 15: _t->setBatAlarm(*reinterpret_cast< bool*>(_v)); break;
        case 16: _t->setLmotortorq(*reinterpret_cast< uint*>(_v)); break;
        case 17: _t->setRmotortorq(*reinterpret_cast< uint*>(_v)); break;
        case 18: _t->setAngle(*reinterpret_cast< uint*>(_v)); break;
        case 19: _t->setLbatAlr(*reinterpret_cast< uint*>(_v)); break;
        case 20: _t->setAcc_x(*reinterpret_cast< float*>(_v)); break;
        case 21: _t->setAcc_y(*reinterpret_cast< float*>(_v)); break;
        case 22: _t->setAcc_z(*reinterpret_cast< float*>(_v)); break;
        case 23: _t->setState(*reinterpret_cast< QMqttClient::ClientState*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QmlMqttClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmlMqttClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmlMqttClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMqttClient::qt_metacast(_clname);
}

int QmlMqttClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMqttClient::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void QmlMqttClient::carSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QmlMqttClient::batLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QmlMqttClient::batTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QmlMqttClient::throPosChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QmlMqttClient::gearModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QmlMqttClient::carModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QmlMqttClient::batAlarmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QmlMqttClient::batVolChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QmlMqttClient::mcu2TempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QmlMqttClient::mcu1TempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QmlMqttClient::carDistanceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QmlMqttClient::brakeTravelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void QmlMqttClient::rmotorTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void QmlMqttClient::lmotorTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void QmlMqttClient::rmotorSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void QmlMqttClient::lmotorSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void QmlMqttClient::rmotortorqChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void QmlMqttClient::lmotortorqChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void QmlMqttClient::angleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void QmlMqttClient::LbatAlrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void QmlMqttClient::acc_xChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void QmlMqttClient::acc_yChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void QmlMqttClient::acc_zChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void QmlMqttClient::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}
QT_WARNING_POP
