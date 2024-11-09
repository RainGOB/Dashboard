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
    "batcurChanged",
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
    "yawChanged",
    "rollChanged",
    "pitchChanged",
    "lmcudccurChanged",
    "rmcudccurChanged",
    "lmcuaccurChanged",
    "rmcuaccurChanged",
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
    "batcur",
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
    "yaw",
    "roll",
    "pitch",
    "lmcudccur",
    "rmcudccur",
    "lmcuaccur",
    "rmcuaccur",
    "state",
    "QMqttClient::ClientState"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t {
    uint offsetsAndSizes[146];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[14];
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
    char stringdata25[11];
    char stringdata26[12];
    char stringdata27[13];
    char stringdata28[17];
    char stringdata29[17];
    char stringdata30[17];
    char stringdata31[17];
    char stringdata32[13];
    char stringdata33[10];
    char stringdata34[13];
    char stringdata35[5];
    char stringdata36[14];
    char stringdata37[19];
    char stringdata38[10];
    char stringdata39[21];
    char stringdata40[6];
    char stringdata41[9];
    char stringdata42[9];
    char stringdata43[7];
    char stringdata44[11];
    char stringdata45[11];
    char stringdata46[12];
    char stringdata47[12];
    char stringdata48[8];
    char stringdata49[9];
    char stringdata50[8];
    char stringdata51[12];
    char stringdata52[12];
    char stringdata53[9];
    char stringdata54[9];
    char stringdata55[7];
    char stringdata56[9];
    char stringdata57[11];
    char stringdata58[11];
    char stringdata59[6];
    char stringdata60[8];
    char stringdata61[6];
    char stringdata62[6];
    char stringdata63[6];
    char stringdata64[4];
    char stringdata65[5];
    char stringdata66[6];
    char stringdata67[10];
    char stringdata68[10];
    char stringdata69[10];
    char stringdata70[10];
    char stringdata71[6];
    char stringdata72[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t qt_meta_stringdata_CLASSQmlMqttClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QmlMqttClient"
        QT_MOC_LITERAL(14, 15),  // "carSpeedChanged"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 15),  // "batLevelChanged"
        QT_MOC_LITERAL(47, 13),  // "batcurChanged"
        QT_MOC_LITERAL(61, 14),  // "throPosChanged"
        QT_MOC_LITERAL(76, 15),  // "gearModeChanged"
        QT_MOC_LITERAL(92, 14),  // "carModeChanged"
        QT_MOC_LITERAL(107, 15),  // "batAlarmChanged"
        QT_MOC_LITERAL(123, 13),  // "batVolChanged"
        QT_MOC_LITERAL(137, 15),  // "mcu2TempChanged"
        QT_MOC_LITERAL(153, 15),  // "mcu1TempChanged"
        QT_MOC_LITERAL(169, 18),  // "carDistanceChanged"
        QT_MOC_LITERAL(188, 18),  // "brakeTravelChanged"
        QT_MOC_LITERAL(207, 17),  // "rmotorTempChanged"
        QT_MOC_LITERAL(225, 17),  // "lmotorTempChanged"
        QT_MOC_LITERAL(243, 18),  // "rmotorSpeedChanged"
        QT_MOC_LITERAL(262, 18),  // "lmotorSpeedChanged"
        QT_MOC_LITERAL(281, 17),  // "rmotortorqChanged"
        QT_MOC_LITERAL(299, 17),  // "lmotortorqChanged"
        QT_MOC_LITERAL(317, 12),  // "angleChanged"
        QT_MOC_LITERAL(330, 14),  // "LbatAlrChanged"
        QT_MOC_LITERAL(345, 12),  // "acc_xChanged"
        QT_MOC_LITERAL(358, 12),  // "acc_yChanged"
        QT_MOC_LITERAL(371, 12),  // "acc_zChanged"
        QT_MOC_LITERAL(384, 10),  // "yawChanged"
        QT_MOC_LITERAL(395, 11),  // "rollChanged"
        QT_MOC_LITERAL(407, 12),  // "pitchChanged"
        QT_MOC_LITERAL(420, 16),  // "lmcudccurChanged"
        QT_MOC_LITERAL(437, 16),  // "rmcudccurChanged"
        QT_MOC_LITERAL(454, 16),  // "lmcuaccurChanged"
        QT_MOC_LITERAL(471, 16),  // "rmcuaccurChanged"
        QT_MOC_LITERAL(488, 12),  // "stateChanged"
        QT_MOC_LITERAL(501, 9),  // "onDataRec"
        QT_MOC_LITERAL(511, 12),  // "QMqttMessage"
        QT_MOC_LITERAL(524, 4),  // "qmsg"
        QT_MOC_LITERAL(529, 13),  // "connectToHost"
        QT_MOC_LITERAL(543, 18),  // "disconnectFromHost"
        QT_MOC_LITERAL(562, 9),  // "subscribe"
        QT_MOC_LITERAL(572, 20),  // "QmlMqttSubscription*"
        QT_MOC_LITERAL(593, 5),  // "topic"
        QT_MOC_LITERAL(599, 8),  // "carSpeed"
        QT_MOC_LITERAL(608, 8),  // "batLevel"
        QT_MOC_LITERAL(617, 6),  // "batcur"
        QT_MOC_LITERAL(624, 10),  // "lmotorTemp"
        QT_MOC_LITERAL(635, 10),  // "rmotorTemp"
        QT_MOC_LITERAL(646, 11),  // "lmotorSpeed"
        QT_MOC_LITERAL(658, 11),  // "rmotorSpeed"
        QT_MOC_LITERAL(670, 7),  // "throPos"
        QT_MOC_LITERAL(678, 8),  // "gearMode"
        QT_MOC_LITERAL(687, 7),  // "carMode"
        QT_MOC_LITERAL(695, 11),  // "carDistance"
        QT_MOC_LITERAL(707, 11),  // "brakeTravel"
        QT_MOC_LITERAL(719, 8),  // "mcu1Temp"
        QT_MOC_LITERAL(728, 8),  // "mcu2Temp"
        QT_MOC_LITERAL(737, 6),  // "batVol"
        QT_MOC_LITERAL(744, 8),  // "batAlarm"
        QT_MOC_LITERAL(753, 10),  // "lmotortorq"
        QT_MOC_LITERAL(764, 10),  // "rmotortorq"
        QT_MOC_LITERAL(775, 5),  // "angle"
        QT_MOC_LITERAL(781, 7),  // "LbatAlr"
        QT_MOC_LITERAL(789, 5),  // "acc_x"
        QT_MOC_LITERAL(795, 5),  // "acc_y"
        QT_MOC_LITERAL(801, 5),  // "acc_z"
        QT_MOC_LITERAL(807, 3),  // "yaw"
        QT_MOC_LITERAL(811, 4),  // "roll"
        QT_MOC_LITERAL(816, 5),  // "pitch"
        QT_MOC_LITERAL(822, 9),  // "lmcudccur"
        QT_MOC_LITERAL(832, 9),  // "rmcudccur"
        QT_MOC_LITERAL(842, 9),  // "lmcuaccur"
        QT_MOC_LITERAL(852, 9),  // "rmcuaccur"
        QT_MOC_LITERAL(862, 5),  // "state"
        QT_MOC_LITERAL(868, 24)   // "QMqttClient::ClientState"
    },
    "QmlMqttClient",
    "carSpeedChanged",
    "",
    "batLevelChanged",
    "batcurChanged",
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
    "yawChanged",
    "rollChanged",
    "pitchChanged",
    "lmcudccurChanged",
    "rmcudccurChanged",
    "lmcuaccurChanged",
    "rmcuaccurChanged",
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
    "batcur",
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
    "yaw",
    "roll",
    "pitch",
    "lmcudccur",
    "rmcudccur",
    "lmcuaccur",
    "rmcuaccur",
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
      35,   14, // methods
      31,  263, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      31,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  224,    2, 0x06,   32 /* Public */,
       3,    0,  225,    2, 0x06,   33 /* Public */,
       4,    0,  226,    2, 0x06,   34 /* Public */,
       5,    0,  227,    2, 0x06,   35 /* Public */,
       6,    0,  228,    2, 0x06,   36 /* Public */,
       7,    0,  229,    2, 0x06,   37 /* Public */,
       8,    0,  230,    2, 0x06,   38 /* Public */,
       9,    0,  231,    2, 0x06,   39 /* Public */,
      10,    0,  232,    2, 0x06,   40 /* Public */,
      11,    0,  233,    2, 0x06,   41 /* Public */,
      12,    0,  234,    2, 0x06,   42 /* Public */,
      13,    0,  235,    2, 0x06,   43 /* Public */,
      14,    0,  236,    2, 0x06,   44 /* Public */,
      15,    0,  237,    2, 0x06,   45 /* Public */,
      16,    0,  238,    2, 0x06,   46 /* Public */,
      17,    0,  239,    2, 0x06,   47 /* Public */,
      18,    0,  240,    2, 0x06,   48 /* Public */,
      19,    0,  241,    2, 0x06,   49 /* Public */,
      20,    0,  242,    2, 0x06,   50 /* Public */,
      21,    0,  243,    2, 0x06,   51 /* Public */,
      22,    0,  244,    2, 0x06,   52 /* Public */,
      23,    0,  245,    2, 0x06,   53 /* Public */,
      24,    0,  246,    2, 0x06,   54 /* Public */,
      25,    0,  247,    2, 0x06,   55 /* Public */,
      26,    0,  248,    2, 0x06,   56 /* Public */,
      27,    0,  249,    2, 0x06,   57 /* Public */,
      28,    0,  250,    2, 0x06,   58 /* Public */,
      29,    0,  251,    2, 0x06,   59 /* Public */,
      30,    0,  252,    2, 0x06,   60 /* Public */,
      31,    0,  253,    2, 0x06,   61 /* Public */,
      32,    0,  254,    2, 0x06,   62 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      33,    1,  255,    2, 0x0a,   63 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      36,    0,  258,    2, 0x02,   65 /* Public */,
      37,    0,  259,    2, 0x02,   66 /* Public */,
      38,    1,  260,    2, 0x02,   67 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 34,   35,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 39, QMetaType::QString,   40,

 // properties: name, type, flags
      41, QMetaType::UInt, 0x00015103, uint(0), 0,
      42, QMetaType::UInt, 0x00015103, uint(1), 0,
      43, QMetaType::Float, 0x00015003, uint(2), 0,
      44, QMetaType::UInt, 0x00015103, uint(13), 0,
      45, QMetaType::UInt, 0x00015103, uint(12), 0,
      46, QMetaType::UInt, 0x00015103, uint(15), 0,
      47, QMetaType::UInt, 0x00015103, uint(14), 0,
      48, QMetaType::UInt, 0x00015103, uint(3), 0,
      49, QMetaType::UInt, 0x00015103, uint(4), 0,
      50, QMetaType::UInt, 0x00015103, uint(5), 0,
      51, QMetaType::UInt, 0x00015103, uint(10), 0,
      52, QMetaType::UInt, 0x00015103, uint(11), 0,
      53, QMetaType::UInt, 0x00015103, uint(9), 0,
      54, QMetaType::UInt, 0x00015103, uint(8), 0,
      55, QMetaType::UInt, 0x00015103, uint(7), 0,
      56, QMetaType::Bool, 0x00015103, uint(6), 0,
      57, QMetaType::UInt, 0x00015103, uint(17), 0,
      58, QMetaType::UInt, 0x00015103, uint(16), 0,
      59, QMetaType::UInt, 0x00015103, uint(18), 0,
      60, QMetaType::UInt, 0x00015103, uint(19), 0,
      61, QMetaType::Float, 0x00015103, uint(20), 0,
      62, QMetaType::Float, 0x00015103, uint(21), 0,
      63, QMetaType::Float, 0x00015103, uint(22), 0,
      64, QMetaType::Float, 0x00015003, uint(23), 0,
      65, QMetaType::Float, 0x00015103, uint(24), 0,
      66, QMetaType::Float, 0x00015103, uint(25), 0,
      67, QMetaType::UInt, 0x00015103, uint(26), 0,
      68, QMetaType::UInt, 0x00015103, uint(27), 0,
      69, QMetaType::UInt, 0x00015103, uint(28), 0,
      70, QMetaType::UInt, 0x00015903, uint(29), 0,
      71, 0x80000000 | 72, 0x0001510b, uint(30), 0,

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
        // property 'batcur'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
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
        // property 'yaw'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'roll'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'pitch'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'lmcudccur'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'rmcudccur'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'lmcuaccur'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'rmcuaccur'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'state'
        QtPrivate::TypeAndForceComplete<QMqttClient::ClientState, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QmlMqttClient, std::true_type>,
        // method 'carSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'batLevelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'batcurChanged'
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
        // method 'yawChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rollChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pitchChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lmcudccurChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rmcudccurChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lmcuaccurChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rmcuaccurChanged'
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
        case 2: _t->batcurChanged(); break;
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
        case 23: _t->yawChanged(); break;
        case 24: _t->rollChanged(); break;
        case 25: _t->pitchChanged(); break;
        case 26: _t->lmcudccurChanged(); break;
        case 27: _t->rmcudccurChanged(); break;
        case 28: _t->lmcuaccurChanged(); break;
        case 29: _t->rmcuaccurChanged(); break;
        case 30: _t->stateChanged(); break;
        case 31: _t->onDataRec((*reinterpret_cast< std::add_pointer_t<QMqttMessage>>(_a[1]))); break;
        case 32: _t->connectToHost(); break;
        case 33: _t->disconnectFromHost(); break;
        case 34: { QmlMqttSubscription* _r = _t->subscribe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QmlMqttSubscription**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 31:
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
            if (_t _q_method = &QmlMqttClient::batcurChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
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
            if (_t _q_method = &QmlMqttClient::yawChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::rollChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::pitchChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::lmcudccurChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::rmcudccurChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::lmcuaccurChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::rmcuaccurChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 30:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttClient::ClientState >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->carSpeed(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->batLevel(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->batcur(); break;
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
        case 23: *reinterpret_cast< float*>(_v) = _t->yaw(); break;
        case 24: *reinterpret_cast< float*>(_v) = _t->roll(); break;
        case 25: *reinterpret_cast< float*>(_v) = _t->pitch(); break;
        case 26: *reinterpret_cast< uint*>(_v) = _t->lmcudccur(); break;
        case 27: *reinterpret_cast< uint*>(_v) = _t->rmcudccur(); break;
        case 28: *reinterpret_cast< uint*>(_v) = _t->lmcuaccur(); break;
        case 29: *reinterpret_cast< uint*>(_v) = _t->rmcuaccur(); break;
        case 30: *reinterpret_cast< QMqttClient::ClientState*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCarSpeed(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setBatLevel(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setbatcur(*reinterpret_cast< float*>(_v)); break;
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
        case 23: _t->setYaw(*reinterpret_cast< float*>(_v)); break;
        case 24: _t->setRoll(*reinterpret_cast< float*>(_v)); break;
        case 25: _t->setPitch(*reinterpret_cast< float*>(_v)); break;
        case 26: _t->setLmcudccur(*reinterpret_cast< uint*>(_v)); break;
        case 27: _t->setRmcudccur(*reinterpret_cast< uint*>(_v)); break;
        case 28: _t->setLmcuaccur(*reinterpret_cast< uint*>(_v)); break;
        case 29: _t->setRmcuaccur(*reinterpret_cast< uint*>(_v)); break;
        case 30: _t->setState(*reinterpret_cast< QMqttClient::ClientState*>(_v)); break;
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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
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
void QmlMqttClient::batcurChanged()
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
void QmlMqttClient::yawChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void QmlMqttClient::rollChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void QmlMqttClient::pitchChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void QmlMqttClient::lmcudccurChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void QmlMqttClient::rmcudccurChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void QmlMqttClient::lmcuaccurChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void QmlMqttClient::rmcuaccurChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void QmlMqttClient::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}
QT_WARNING_POP
