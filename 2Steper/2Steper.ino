#include <AccelStepper.h>
//此lib库文件在程序包中，需要先复制到arduiino的\libraries文件夹下。
//方法1： 复制到 我的文档\Arduino\libraries 中
//方法2： 在arduino IDE的菜单中选择 项目->加载库->管理库 中搜索AccelStepper，自动安装

#define FULLSTEP 4
#define HALFSTEP 8
//接线方法 
//电机1的接法
#define motorPin1  2     //  28BYJ48 pin 1 接 arduino的2#口
#define motorPin2  3     //  28BYJ48 pin 2 接 3#
#define motorPin3  5     //  28BYJ48 pin 3 接 5#  ！注意，4#口预留sd读卡器
#define motorPin4  6     //  28BYJ48 pin 4 接 6#

//电机2的接法
#define motorPin5  7     //  28BYJ48 pin 1 接 7#
#define motorPin6  8     //  28BYJ48 pin 2 接 8#
#define motorPin7  9     //  28BYJ48 pin 3 接 9#
#define motorPin8  10    //  28BYJ48 pin 4 接 10#


AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

void setup() 
{
  Serial.begin(9600);
  stepper1.setMaxSpeed(1000.0);     //最大速度，过高扭矩变小，超过256容易丢步
  stepper1.setAcceleration(256.0);  //加速度，试稳定程序可以调节。
  stepper1.setSpeed(256);           //速度
  //视 FULLSTEP 或 HALFSTEP， 1024 或 512 步进电机转一周   
  //设置电机1的旋转步数 可调节（数字越大，图形尺寸越大）
  stepper1.moveTo(790);
  
  stepper2.setMaxSpeed(1000.0);
  stepper2.setAcceleration(256.0);
  stepper2.setSpeed(256);
  //同stepper1
  stepper2.moveTo(1226);  
  
}
void loop()  
{
  if(stepper1.distanceToGo() == 0)
    stepper1.moveTo(-stepper1.currentPosition());
  if(stepper2.distanceToGo() == 0)
    stepper2.moveTo(-stepper2.currentPosition());
    
  stepper1.run();
  stepper2.run();
    
}
