import QtQuick 2.8

Item {
    id: id_root
    property int value: 0

    Rectangle {
        id: id_rmotorspeed

        property int numberIndexs: 15
        property int startAngle: 234
        property int angleLength: 18
        property int maxSpeed: 280

        anchors.centerIn: parent
        height: Math.min(id_root.width, id_root.height)
        width: height
        radius: width/2
        color: "black"
        border.color: "white"
        border.width: id_rmotorspeed.height * 0.02

        Canvas {
            id:canvas
            anchors.fill: parent
            contextType: "2d"
            rotation: 145
            antialiasing: true

            onPaint: {
                var context = canvas.getContext('2d');
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
        id: id_center

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
        text: "Speed\n km/h"
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
        value: id_root.value
        startAngle: id_rmotorspeed.startAngle
        angleLength: id_rmotorspeed.angleLength / (id_rmotorspeed.maxSpeed / (id_rmotorspeed.numberIndexs - 1))
    }
}
