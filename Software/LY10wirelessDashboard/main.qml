import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import MqttClient
//import QtQuick.Extras 1.4
//import QtQuick.Controls.Styles 1.2
//import QtQuick.Extras.Private 1.0

Window {

    visible: true
    width: 1250
    height: 680
    color: "#666666"
    //    property alias rectangleX: rectangle.x
    title:  qsTr("LY10-WirelessDashboard")
    id: root

    //加载字体
    FontLoader {
        id: localFont
        source: "big-numbers.ttf"
    } //仪表数字显示使用字体

    //FontLoader {
    //    id: kfont
    //    source: "Cinzel-Regular.ttf"
    //} //版权声明处使用字体

    //FontLoader {
    //    id: wfont
    //    source: "PlayfairDisplaySC-Black.ttf"
    //} //Gear处使用字体
    FontLoader {
        id: ffont
        source: "FasterOne-Regular.ttf"
    } //Gear处使用字体

    FontLoader {
        id: ffzont
        source: "TTZhiHeiJ-W4.ttf"
    }

    property int rpm_test: 0
    property int count: 0
    //    property int m_port:1883
    //    property string m_topic: "hello"
    property int tempSubscription: 0
    MqttClient{
        id:carclient

        carSpeed: 0
        batLevel: 0
        batTemp: 0
        throPos: 0
        batVol: 0
        mcu1Temp: 0
        mcu2Temp: 0
        carDistance: 0
        brakeTravel: 0
        lmotorTemp: 0
        rmotorTemp: 0
        lmotorSpeed: 0
        rmotorSpeed: 0
        angle: 90
        acc_x: 7
        acc_y: 7
        acc_z: -10
       // onCarModeChanged: {
       //     if(carMode === 0)
       //     {
       //         modeStatus.active = false
       //     }
       //     else if(carMode === 1)
       //     {
       //         modeStatus.active = false
       //     }
       //     else if(carMode === 2)
       //     {
       //         modeStatus.active = true
       //     }
       // }
       // onGearModeChanged: {
       //     if(gearMode === 3)
       //         runStuatus.active = true
       //     else
       //         runStuatus.active = false

       // }
       // onBatAlarmChanged:{
       //     socAlarmFlag = batAlarm
       // }
    }

    //    ListModel {
    //        id: messageModel
    //    }
    //
    //    function addMessage(payload)
    //    {
    //        messageModel.insert(0, {"payload" : payload})
    //
    //        if (messageModel.count >= 100)
    //            messageModel.remove(99)
    //    }

    Image {
        id: logo
        source: "lingyun.png"
        x: 10; y:10
        width: sourceSize.width/10
        height: sourceSize.height/10
        Component.onCompleted: console.log(sourceSize);
        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked: {
                count++
                if (count == 10) {
                    borderImage.visible = true
                    //                   speedChart.visible = false
                    //                   rpmChart.visible = false
                }

                if (count == 1) {
                    $message({
                                 "message": '吃太饱了？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 2) {
                    $message({
                                 "message": '有病病？？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 3) {
                    $message({
                                 "message": '哪儿凉快哪儿呆着去！',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 4) {
                    $message({
                                 "message": '车修好了？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 5) {
                    $message({
                                 "message": '四六级都过了？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 6) {
                    $message({
                                 "message": '欸你这人怎么回事儿？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 7) {
                    $message({
                                 "message": '你再点一下试试？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 8) {
                    $message({
                                 "message": '没完了是吧？？？',
                                 "type": 'info',
                                 "show": true
                             })
                } else if (count == 9) {
                    $message({
                                 "message": '有点儿什么大病',
                                 "type": 'info',
                                 "show": true
                             })
                }
            }

        }
    }

    Item {
        id:mqttindicator
        x:1000; y:20
        Rectangle{
            id:connect
            width:25
            height: 25
            color:"#333333"
            radius: 100
        }

        Label{
            id:mqttlabel
            y:30
            width: 25
            height: 10
            color: "#99ccff"
            text: qsTr("MQTT")
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 6
        }
    }

    //    Item {
    //        id:subscribeindicator
    //        x:950; y:20
    //        Rectangle{
    //            id:sUbscribe
    //            width:25
    //            height: 25
    //            color:"#333333"
    //            radius: 100
    //        }
    //
    //        Label{
    //            id:subscribelabel
    //            y:30
    //            width: 25
    //            height: 10
    //            color: "#99ccff"
    //            text: qsTr("subscribe")
    //            horizontalAlignment: Text.AlignHCenter
    //            font.pointSize: 6
    //        }
    //    }

    Item {
        id: id_dashboard
        x:40; y:130
        width: 400
        height: 400
        //to creating data for demonstration purpose
        property int count: 0
        property int randNum: 0

        Rectangle {
            id:  id_speedArea
            anchors {
                horizontalCenter: parent.horizontalCenter
            }
            width: parent.width * 0.4
            height: width
            color: "black"
            radius: width/2

            Item {
                id: id_root
                property int value: 0
                anchors.fill: id_speedArea
                anchors.margins: id_speedArea.width * 0.025

                Rectangle {
                    id: id_speed

                    property int numberIndexs: 15
                    property int startAngle: 234
                    property int angleLength: 18
                    property int maxSpeed: 140


                    anchors.centerIn: parent
                    height: Math.min(id_root.width, id_root.height)
                    width: height
                    radius: width/2
                    color: "black"
                    border.color: "white"
                    border.width: id_speed.height * 0.02

                    Canvas {
                        id:canvas
                        anchors.fill: parent
                        contextType: "2d"
                        rotation: 145
                        antialiasing: true

                        onPaint: {
                            var context = canvas.getContext('2d');
                            context.strokeStyle = "blue";
                            context.lineWidth = id_speed.height * 0.05 / 2;
                            context.beginPath();
                            context.arc(id_speed.height / 2, id_speed.height / 2, id_speed.height / 2 - id_speed.height * 0.05, 0, Math.PI * 1.1, false);
                            context.stroke();

                            context.strokeStyle = "red";
                            context.lineWidth = id_speed.height * 0.05 / 2;
                            context.beginPath();
                            context.arc(id_speed.height / 2, id_speed.height / 2, id_speed.height / 2 - id_speed.height * 0.05, Math.PI * 1.1, Math.PI * 1.4, false);
                            context.stroke();
                        }
                    }

                    Repeater {
                        model: id_speed.numberIndexs

                        Item {
                            height: id_speed.height/2
                            transformOrigin: Item.Bottom
                            rotation: index * id_speed.angleLength + id_speed.startAngle
                            x: id_speed.width/2

                            Rectangle {
                                height: id_speed.height * 0.05
                                width: height / 2
                                color: "white"
                                antialiasing: true
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: id_speed.height * 0.03
                            }

                            Text {
                                anchors {
                                    horizontalCenter: parent.horizontalCenter
                                }
                                x: 0
                                y: id_speed.height * 0.09
                                color: "white"
                                rotation: 360 - (index * id_speed.angleLength + id_speed.startAngle)
                                text: index * (id_speed.maxSpeed / (id_speed.numberIndexs - 1))
                                font.pixelSize: id_speed.height * 0.05
                                font.family: "Comic Sans MS"
                            }
                        }
                    }
                }

                Rectangle {
                    id: id_center

                    anchors.centerIn: parent
                    height: id_speed.height*0.1
                    width: height
                    radius: width/2
                    color: "#333333"
                }

                Text {
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: id_speed.verticalCenter
                        topMargin: id_speed.height * 0.1
                    }
                    text: "Speed\n km/h"
                    color: "#99ccff"
                    font.pixelSize: id_speed.height * 0.1
                    font.family: "Comic Sans MS"
                }

                SpeedNeedle {
                    id: id_speedNeedle
                    anchors {
                        top: id_speed.top
                        bottom: id_speed.bottom
                        horizontalCenter: parent.horizontalCenter
                    }
                    value: carclient.carSpeed
                    startAngle: id_speed.startAngle
                    angleLength: id_speed.angleLength / (id_speed.maxSpeed / (id_speed.numberIndexs - 1))
                }
            }

        }

        Rectangle {
            id: id_lmotorspeedArea

            anchors {
                bottom: id_speedArea.bottom
            }
            x: parent.width / 20 -45
            width: parent.width * 0.35
            height: width
            color: "black"
            radius: width/2

            Item {
                id: id_lroot
                property int value: 0
                anchors.fill: id_lmotorspeedArea
                anchors.margins: id_lmotorspeedArea.width * 0.025
                Rectangle {
                    id: id_lmotorspeed

                    property int numberIndexs: 15
                    property int startAngle: 234
                    property int angleLength: 18
                    property int maxSpeed: 7


                    anchors.centerIn: parent
                    height: Math.min(id_lroot.width, id_lroot.height)
                    width: height
                    radius: width/2
                    color: "black"
                    border.color: "white"
                    border.width: id_lmotorspeed.height * 0.02

                    Canvas {
                        id:lcanvas
                        anchors.fill: parent
                        contextType: "2d"
                        rotation: 145
                        antialiasing: true

                        onPaint: {
                            var context = lcanvas.getContext('2d');
                            context.strokeStyle = "blue";
                            context.lineWidth = id_lmotorspeed.height * 0.05 / 2;
                            context.beginPath();
                            context.arc(id_lmotorspeed.height / 2, id_lmotorspeed.height / 2, id_lmotorspeed.height / 2 - id_lmotorspeed.height * 0.05, 0, Math.PI * 1.1, false);
                            context.stroke();

                            context.strokeStyle = "red";
                            context.lineWidth = id_lmotorspeed.height * 0.05 / 2;
                            context.beginPath();
                            context.arc(id_lmotorspeed.height / 2, id_lmotorspeed.height / 2, id_lmotorspeed.height / 2 - id_lmotorspeed.height * 0.05, Math.PI * 1.1, Math.PI * 1.4, false);
                            context.stroke();
                        }
                    }

                    Repeater {
                        model: id_lmotorspeed.numberIndexs

                        Item {
                            height: id_lmotorspeed.height/2
                            transformOrigin: Item.Bottom
                            rotation: index * id_lmotorspeed.angleLength + id_lmotorspeed.startAngle
                            x: id_lmotorspeed.width/2

                            Rectangle {
                                height: id_lmotorspeed.height * 0.05
                                width: height / 2
                                color: "white"
                                antialiasing: true
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: id_lmotorspeed.height * 0.03
                            }

                            Text {
                                anchors {
                                    horizontalCenter: parent.horizontalCenter
                                }
                                x: 0
                                y: id_lmotorspeed.height * 0.09
                                color: "white"
                                rotation: 360 - (index * id_lmotorspeed.angleLength + id_lmotorspeed.startAngle)
                                text: index * (id_lmotorspeed.maxSpeed / (id_lmotorspeed.numberIndexs - 1))
                                font.pixelSize: id_lmotorspeed.height * 0.05
                                font.family: "Comic Sans MS"
                            }
                        }
                    }
                }

                Rectangle {
                    id: id_lcenter

                    anchors.centerIn: parent
                    height: id_lmotorspeed.height*0.1
                    width: height
                    radius: width/2
                    color: "#333333"
                }

                Text {
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: id_lmotorspeed.verticalCenter
                        topMargin: id_lmotorspeed.height * 0.1
                    }
                    text: "RPM"
                    color: "#99ccff"
                    font.pixelSize: id_lmotorspeed.height * 0.1
                    font.family: "Comic Sans MS"
                }

                SpeedNeedle {
                    id: id_lmotorspeedNeedle
                    anchors {
                        top: id_lmotorspeed.top
                        bottom: id_lmotorspeed.bottom
                        horizontalCenter: parent.horizontalCenter
                    }
                    value: carclient.lmotorSpeed/1000
                    startAngle: id_lmotorspeed.startAngle
                    angleLength: id_lmotorspeed.angleLength / (id_lmotorspeed.maxSpeed / (id_lmotorspeed.numberIndexs - 1))
                }
            }


        }

        Rectangle {
            id: id_rmotorspeedArea

            anchors {
                bottom: id_speedArea.bottom
            }
            x: parent.width - parent.width / 2.5 +45
            width: parent.width * 0.35
            height: width
            color: "black"
            radius: width/2

            Item {
                id: id_rroot
                property int value: 0
                anchors.fill: id_rmotorspeedArea
                anchors.margins: id_rmotorspeedArea.width * 0.025
                Rectangle {
                    id: id_rmotorspeed

                    property int numberIndexs: 15
                    property int startAngle: 234
                    property int angleLength: 18
                    property int maxSpeed: 7

                    anchors.centerIn: parent
                    height: Math.min(id_rroot.width, id_rroot.height)
                    width: height
                    radius: width/2
                    color: "black"
                    border.color: "white"
                    border.width: id_rmotorspeed.height * 0.02

                    Canvas {
                        id:rcanvas
                        anchors.fill: parent
                        contextType: "2d"
                        rotation: 145
                        antialiasing: true

                        onPaint: {
                            var context = rcanvas.getContext('2d');
                            context.strokeStyle = "blue";
                            context.lineWidth = id_rmotorspeed.height * 0.05 / 2;
                            context.beginPath();
                            context.arc(id_rmotorspeed.height / 2, id_rmotorspeed.height / 2, id_rmotorspeed.height / 2 - id_rmotorspeed.height * 0.05, 0, Math.PI * 1.1, false);
                            context.stroke();

                            context.strokeStyle = "red";
                            context.lineWidth = id_rmotorspeed.height * 0.05 / 2;
                            context.beginPath();
                            context.arc(id_rmotorspeed.height / 2, id_rmotorspeed.height / 2, id_rmotorspeed.height / 2 - id_rmotorspeed.height * 0.05, Math.PI * 1.1, Math.PI * 1.4, false);
                            context.stroke();
                        }
                    }

                    Repeater {
                        model: id_rmotorspeed.numberIndexs

                        Item {
                            height: id_rmotorspeed.height/2
                            transformOrigin: Item.Bottom
                            rotation: index * id_rmotorspeed.angleLength + id_rmotorspeed.startAngle
                            x: id_rmotorspeed.width/2

                            Rectangle {
                                height: id_rmotorspeed.height * 0.05
                                width: height / 2
                                color: "white"
                                antialiasing: true
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: id_rmotorspeed.height * 0.03
                            }

                            Text {
                                anchors {
                                    horizontalCenter: parent.horizontalCenter
                                }
                                x: 0
                                y: id_rmotorspeed.height * 0.09
                                color: "white"
                                rotation: 360 - (index * id_rmotorspeed.angleLength + id_rmotorspeed.startAngle)
                                text: index * (id_rmotorspeed.maxSpeed / (id_rmotorspeed.numberIndexs - 1))
                                font.pixelSize: id_rmotorspeed.height * 0.05
                                font.family: "Comic Sans MS"
                            }
                        }
                    }
                }

                Rectangle {
                    id: id_rcenter

                    anchors.centerIn: parent
                    height: id_rmotorspeed.height*0.1
                    width: height
                    radius: width/2
                    color: "#333333"
                }

                Text {
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: id_rmotorspeed.verticalCenter
                        topMargin: id_rmotorspeed.height * 0.1
                    }
                    text: "RPM"
                    color: "#99ccff"
                    font.pixelSize: id_rmotorspeed.height * 0.1
                    font.family: "Comic Sans MS"
                }

                SpeedNeedle {
                    id: id_rmotorspeedNeedle
                    anchors {
                        top: id_rmotorspeed.top
                        bottom: id_rmotorspeed.bottom
                        horizontalCenter: parent.horizontalCenter
                    }
                    value: carclient.lmotorSpeed/1000
                    startAngle: id_rmotorspeed.startAngle
                    angleLength: id_rmotorspeed.angleLength / (id_rmotorspeed.maxSpeed / (id_rmotorspeed.numberIndexs - 1))
                }
            }

        }

    }



    ProgressBar{
        id: brake_travel
        x:900; y:450
        from:0.0
        to:100
        value:carclient.brakeTravel;
        width: 350
        height:25
        rotation: -90.0
        transformOrigin: Item.TopLeft
        //     anchors.centerIn: parent
        background: Rectangle{
            implicitWidth: brake_travel.width
            implicitHeight: brake_travel.height
            color:"#333333"
            radius:5
        }
        contentItem: Item{
            Rectangle{
                width: brake_travel.visualPosition * brake_travel.width
                height: brake_travel.height
                radius: 3
                color:"green"
            }
        }
    }


    ProgressBar{
        id: padelh_travel
        x:950; y:450
        from:0.0
        to:100.0
        value:carclient.throPos
        width: 350
        height:25
        rotation: -90.0
        transformOrigin: Item.TopLeft
        //       anchors.centerIn: parent
       background: Rectangle{
           implicitWidth: padelh_travel.width
           implicitHeight: padelh_travel.height
           color:"#333333"
           radius:5
       }
        contentItem: Item{
            Rectangle{
                width: padelh_travel.visualPosition * padelh_travel.width
                height: padelh_travel.height
                radius: 3
                color:"red"
            }
        }
    }

    Label{
        id:brake_label
        x:900; y:450
        width: brake_travel.height
        height: 20
        color: "#99ccff"
        text: qsTr("brake")
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 6
    }

    Label{
        id:padelh_label
        x:950; y:450
        width: padelh_travel.height
        height: 20
        color: "#99ccff"
        text: qsTr("throttle")
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 6
    }




    Item {
        id: batVolLabel
        x: 30
        y: 300
        width: 100
        height: 100
        Text {
            id: batVol_100
            x: 15
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.batVol / 100 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: batVol_10
            x: 39
            y: 5
            width: 45
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.batVol / 10 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: batVol_1
            x: 70
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.batVol / 1 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: batVol
            x: 31
            y: 61
            color: "#b4cfe5"
            text: qsTr("电池电压")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }

    Item{
        id:carSpeed_label
        x:30
        y:400
        width:100
        height:100
        Text {
            id: carspeed_100
            x: 15
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.carSpeed / 100 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:carSpeed_10
            x:39; y:5
            width:45
            height: 62
            color:"#99ccff"
            text:parseInt(carclient.carSpeed /10 %10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:carSpeed_1
            x:70; y:5
            width: 38
            height: 62
            color:"#99ccff"
            text: carclient.carSpeed % 10
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            id: carSpeed
            x: 31
            y: 61
            color: "#b4cfe5"
            text: qsTr("carspeed")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }

    Item{
        id:lmotorspeed_label
        x:140
        y:300
        width:100
        height:200
        Text{
            id:lmotorspeed_1000
            x:15; y:5
            width:38
            height: 62
            color:"#99ccff"
            text:parseInt(carclient.lmotorSpeed /1000 %10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:lmotorspeed_100
            x:39; y:5
            width: 45
            height: 62
            color:"#99ccff"
            text: carclient.lmotorSpeed % 100 %10
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:lmotorspeed_10
            x:67; y:5
            width:45
            height: 62
            color:"#99ccff"
            text:parseInt(carclient.lmotorSpeed /10 %10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:lmotorspeed_1
            x:94; y:5
            width: 45
            height: 62
            color:"#99ccff"
            text: carclient.lmotorSpeed % 10
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            id: lmotorspeed
            x: 41
            y: 61
            color: "#b4cfe5"
            text: qsTr("lmotspeed")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }

    Item{
        id:rmotorspeed_label
        x:140
        y:400
        width:100
        height:200
        Text{
            id:rmotorspeed_1000
            x:15; y:5
            width:38
            height: 62
            color:"#99ccff"
            text:parseInt(carclient.rmotorSpeed /1000 %10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:rmotorspeed_100
            x:39; y:5
            width: 45
            height: 62
            color:"#99ccff"
            text: carclient.rmotorSpeed % 100 %10
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:rmotorspeed_10
            x:67; y:5
            width:45
            height: 62
            color:"#99ccff"
            text:parseInt(carclient.rmotorSpeed /10 %10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:rmotorspeed_1
            x:94; y:5
            width: 45
            height: 62
            color:"#99ccff"
            text: carclient.rmotorSpeed % 10
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            id: rmotorspeed
            x: 41
            y: 61
            color: "#b4cfe5"
            text: qsTr("rmotspeed")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }

    Item {
        id: mcu1TempLabel
        x: 250
        y: 300
        width: 100
        height: 100

        Text {
            id: mcu1Temp_10
            x: 39
            y: 5
            width: 45
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.mcu1Temp / 10 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: mcu1Temp_1
            x: 70
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.mcu1Temp / 1 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: mcu1Temp
            x: 41
            y: 61
            color: "#b4cfe5"
            text: qsTr("MCU1Temp")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }
    Item {
        id: mcu2TempLabel
        x: 330
        y: 300
        width: 100
        height: 100

        Text {
            id: mcu2Temp_10
            x: 39
            y: 5
            width: 45
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.mcu2Temp / 10 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: mcu2Temp_1
            x: 70
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.mcu2Temp / 1 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: mcu2Temp
            x: 41
            y: 61
            color: "#b4cfe5"
            text: qsTr("MCU2Temp")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }
    Item {
        id:lmoTempLabel
        x: 250
        y: 400
        width: 100
        height: 100

        Text {
            id: lmoTemp_10
            x: 39
            y: 5
            width: 45
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.lmotorTemp / 10 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: lmoTemp_1
            x: 70
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.lmotorTemp / 1 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: lmoTemp
            x: 41
            y: 61
            color: "#b4cfe5"
            text: qsTr("lmoTemp")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }
    Item {
        id: rmoTempLabel
        x: 330
        y: 400
        width: 100
        height: 100

        Text {
            id: rmoTemp_10
            x: 39
            y: 5
            width: 45
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.rmotorTemp / 10 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: rmoTemp_1
            x: 70
            y: 5
            width: 38
            height: 62
            color: "#99ccff"
            text: parseInt(carclient.rmotorTemp / 1 % 10)
            horizontalAlignment: Text.AlignHCenter
            font.family: "big-numbers"
            font.pixelSize: 35
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: rmoTemp
            x: 41
            y: 61
            color: "#b4cfe5"
            text: qsTr("rmoTemp")
            font.family: "Tensentype ZhiHeiJ-W4"
            font.pixelSize: 15
        }
    }

    //加速度仪表
    Item {
        id:accelarate
        x:500; y:250
        width: 180
        height: 180

        Rectangle{
            id:accelaratedash
            width: parent.width
            height: parent.height
            color:"#333333"
            anchors.centerIn: parent
            anchors.topMargin: 30
            anchors.leftMargin: 30
            radius: width/2
            Rectangle{
                anchors.centerIn: parent
                width: parent.width-10
                height: parent.height-10
                radius: width/2
                color: "#333333"
                border.color: "white"
                border.width: 2
            }
        }

        Canvas{
            id:accelaratecanvas
            anchors.fill: parent
            contextType: "2d"
            onPaint: {
                var cav = getContext("2d");
                cav.strokeStyle = "white"
                cav.lineWidth = 0.5

                cav.moveTo(parent.width/2, parent.width/2)
                cav.beginPath()
                cav.arc(parent.width/2,parent.width/2,60,0,Math.PI * 2,true)
                cav.stroke()

                cav.beginPath()
                cav.arc(parent.width/2,parent.width/2,40,0,Math.PI * 2,true)
                cav.stroke()

                cav.beginPath()
                cav.arc(parent.width/2,parent.width/2,20,0,Math.PI *2,true)
                cav.stroke()
            }
        }
        Rectangle{
            id:indicator
            width: 9
            height: width
            x:-10-width/2+carclient.acc_x/20*100; y:-10-height/2+carclient.acc_y/20*100
            color:"red"
            radius: width/2
            opacity: 0.8
        }

        Item  {
            id:acczbash
            x:240
            width: parent.width/10
            height: parent.height
            Rectangle{
                id:acczbashl
                y:10
                width:parent.width
                height: parent.width
                color:"#333333"
                radius: width/2
            }
            Rectangle{
                id:acczbashb
                y:parent.width/2+10
                width: parent.width
                height: parent.height-30
                color:"#333333"
            }
            Rectangle{
                id:acczbashr
                y:parent.height-20
                width:parent.width
                height: parent.width
                color:"#333333"
                radius: width/2
            }

        }

        Item {
            id:acczindicator
            x:240; y:160-(carclient.acc_z/20)*(parent.height-30); z:1
            width: acczbash.width
            Rectangle{
                id:acczcircle
                width:parent.width
                height: parent.width
                color:"#99ccff"
                radius: 100
    //           Text {
    //                id: acczdisp
    //                text: Math.abs(anglesensor.value - 90)
    //                anchors.centerIn: parent
    //                color: "#99ccff"
    //                font.pixelSize: 12
    //                font.family: "Tensentype ZhiHeiJ-W4"
    //            }
            }
            Behavior on x {
                SmoothedAnimation { velocity: 1000 }
            }
        }
    }

    Item {
        id: angle
        x:470; y:440
        Label{
            text: "steering wheel angle"
            font.pixelSize: 10
            font.family: "Tensentype ZhiHeiJ-W4"
            color: "#99ccff"
        }

        Anglesensor{
            y:angle.parent.y + 15
            width: 350
            height: 25
            z:1
            value: carclient.angle
        }
    }


    Item{                                                           //时间控件
        x:50; y:500
        width: 10
        height: 50
        Text {
            id: time
            font.pointSize: 20
            color:"#99ccff"
        }
        Timer{
            id:timer
            interval: 1000; running: true; repeat: true
            onTriggered: time.text = Qt.formatDateTime(new Date(),"hh-mm-ss")
        }
        Component.onCompleted: {
            timer.start()
        }
    }

    Button{
        id:connectbut
        x:800; y:500
        width: 80
        height: 20
        flat: false
        text: carclient.state === MqttClient.Connected ? "Disconnect" : "Connect"
        onClicked: {
            if(carclient.state === MqttClient.Connected){
                carclient.disconnectFromHost()
                connect.color = "#333333"
            }
            else{
                carclient.connectToHost()
                connect.color = "#99ccff"
                subscribebut.enabled = true
            }
        }
    }
    Button{
        id: subscribebut
        x:900; y:500
        width: 80
        height: 20
        flat: false
        text: "subscribe"
        enabled: false
        onClicked: {
            carclient.subscribe("mqtt")
            subscribebut.enabled = false
        }
    }

    BorderImage {
        id: borderImage
        x: 5
        y: 20
        width: sourceSize.width
        height: sourceSize.height
        visible: false
        source: "1.jpg"
    }
    Message {
        id: message
        z: 3
    }
    //彩蛋对话框提示函数
    function $message(data) {
        if (data && data.show) {
            message.show = data.show
        }
        if (data && data.message) {
            message.text = data.message
        }

        if (data && data.type) {
            message.type = data.type
        }

        if (data && data.type && data.type !== 'success'
                && data.type !== 'error' && data.type !== 'info') {
            return false
        }

        message.openTimer() //调用Message组件下定时器方法
    }
}

