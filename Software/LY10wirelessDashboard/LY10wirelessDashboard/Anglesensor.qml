import QtQuick 2.8

Item {
    id:anglesensor
    width: 350
    height: 25
    property int value: 0

    Item  {
        id:anglebash
        width: parent.width
        height: parent.height
        Rectangle{
            id:anglebashl
            width:parent.height
            height: parent.height
            color:"#333333"
            radius: 100
        }
        Rectangle{
            id:anglebashb
            x:parent.height/2
            width:parent.width
            height: parent.height
            color:"#333333"
        }
        Rectangle{
            id:anglebashr
            x:parent.width
            width:parent.height
            height: parent.height
            color:"#333333"
            radius: 100
        }
    }

    Item {
        id:angleindicator
        x:parent.width/180*parent.value; y:1;z:1
        height: parent.height
        Rectangle{
            id:anglecircle
            width:parent.height -2
            height: parent.height -2
            color:"#99ccff"
            radius: 100
            Text {
                id: angle_disp
                text: Math.abs(anglesensor.value - 90)
                anchors.centerIn: parent
                color: "#99ccff"
                font.pixelSize: 12
                font.family: "Tensentype ZhiHeiJ-W4"
            }
        }
        Behavior on x {
            SmoothedAnimation { velocity: 1000 }
        }
    }
}
