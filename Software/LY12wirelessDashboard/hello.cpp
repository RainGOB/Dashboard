// main.cpp

#include <QCoreApplication>
#include "qmlmqttclient.h"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

QXLSX_USE_NAMESPACE



int hello(QString TIMEdata)
{
    QXlsx::Document xlsx;
    xlsx.write("A1", "序号"); // write "cell head", it's shared string.
    xlsx.write("B1", "时间(s)");
    xlsx.write("C1", "车速(m/s)");
    xlsx.write("D1", "挡位");
    xlsx.write("E1", "左电机转速(RPM)");
    xlsx.write("F1", "右电机转速(RPM)");
    xlsx.write("G1", "左电机扭矩(Nm)");
    xlsx.write("H1", "右电机扭矩(Nm)");
    xlsx.write("I1", "左电机温度(℃)");
    xlsx.write("J1", "右电机温度(℃)");
    xlsx.write("K1", "油门");
    xlsx.write("L1", "刹车");
    xlsx.write("M1", "方向盘转角(℃)");
    xlsx.write("N1", "动力电池警告级别");
    xlsx.write("O1", "动力电池电流(A)");
    xlsx.write("P1", "动力电池电压(V)");
    xlsx.write("Q1", "动力电池电量(%)");
    xlsx.write("R1", "低压电池预警");
    xlsx.write("S1", "左电机控制器温度(℃)");
    xlsx.write("T1", "右电机控制器温度(℃)");
    xlsx.write("U1", "Acx(m/s^2)");
    xlsx.write("V1", "Acy(m/s^2)");
    xlsx.write("W1", "Acz(m/s^2)");
    xlsx.write("X1", "Yaw(°）");
    xlsx.write("Y1", "Pitch(°）");
    xlsx.write("Z1", "Roll(°）");
    xlsx.write("AA1","左电机直流电源（A）");
    xlsx.write("AB1","右电机直流电源（A）");
    xlsx.write("AC1","左电机交流电源（A)");
    xlsx.write("AD1","右电机交流电源（A）");
    xlsx.saveAs("LYdata"+TIMEdata+".xlsx"); // save the document as 'Test.xlsx'

    return 0;
    // return a.exec();
}

int attend_cell(QStringList& packStr,QString TIMEdata)
{
    static uint16_t row_num = 1;

    QXlsx::Document xlsx("LYdata"+TIMEdata+".xlsx");


/*
    switch(packStr[0].toInt()){
    case 1:

    case 2:
        break;
    }
*/
    if(packStr[0] == '1'){
        xlsx.write(row_num+1, 3 , packStr[1 ] .toInt());  //车速
        xlsx.write(row_num+1, 11, packStr[2 ] .toInt());  //油门
        xlsx.write(row_num+1, 14, packStr[3 ] .toInt());  //高压电池警告
        xlsx.write(row_num+1, 5 , packStr[4 ] .toInt());  //左电机转速
        xlsx.write(row_num+1, 6 , packStr[5 ] .toInt());  //右电机转速
        xlsx.write(row_num+1, 15, packStr[6 ] .toFloat());  //高压电池电流
        xlsx.write(row_num+1, 17, packStr[7 ] .toInt());  //电池电量
        xlsx.write(row_num+1, 4 , packStr[8 ] .toInt());  //挡位
        xlsx.write(row_num+1, 21, packStr[10] .toFloat());  //Acx
        xlsx.write(row_num+1, 22, packStr[11] .toFloat());  //Acy
        xlsx.write(row_num+1, 23, packStr[12] .toFloat());  //Acz
        xlsx.write(row_num+1, 25, packStr[13] .toFloat());
        xlsx.write(row_num+1, 27, packStr[14] .toInt()); //左电机控制器直流电流
        xlsx.write(row_num+1, 28 ,packStr[15] .toInt()); //右电机控制器直流电源
//        xlsx.write(row_num, 21, packStr[0] .toInt());  //编号
    }
    else{
        row_num++;

        xlsx.write(row_num, 1 , row_num-1);
        xlsx.write(row_num, 2 , QDateTime::currentDateTime().toString("HHmmss"));
        xlsx.write(row_num, 7 , packStr[1] .toInt());  //左电机扭矩
        xlsx.write(row_num, 8 , packStr[2] .toInt());  //右电机扭矩
        xlsx.write(row_num, 16, packStr[3] .toInt());  //高压电池电压
        xlsx.write(row_num, 19, packStr[5] .toInt());  //左电机控制器温度
        xlsx.write(row_num, 20, packStr[6] .toInt());  //右电机控制器温度
        xlsx.write(row_num, 9 , packStr[8] .toInt());  //左电机温度
        xlsx.write(row_num, 10, packStr[9] .toInt());  //右电机温度
        xlsx.write(row_num, 18, packStr[10].toInt()); //低压电池预警
        xlsx.write(row_num, 12, packStr[7] .toInt());  //油压
        xlsx.write(row_num, 13, packStr[11].toInt()); //方向盘转角
        xlsx.write(row_num, 24, packStr[12].toFloat()); //Yaw
        xlsx.write(row_num+1, 26, packStr[13] .toFloat());
        xlsx.write(row_num+1, 29, packStr[14] .toInt()); //左电机控制器交流电流
        xlsx.write(row_num+1, 30 ,packStr[15] .toInt()); //右电机控制器交流电源
//        xlsx.write(row_num, 21, packStr[0] .toInt());  //编号
    }

    qDebug()<<"save OK ";

    xlsx.save();

    return 0;
}
