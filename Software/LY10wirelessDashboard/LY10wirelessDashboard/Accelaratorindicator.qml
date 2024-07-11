import QtQuick 2.8

Item {
    id:accelarate
    width: 180
    height: 180
    property int acc_x: 0
    property int acc_y: 0
    property int acc_z: 0
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
        x:90-width/2+acc_x; y:90-height/2+acc_y
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
        x:240; y:parent.height/10*parent.acc_z+10;z:1
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
