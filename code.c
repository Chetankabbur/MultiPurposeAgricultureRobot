#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 19200
#define REMOTEXY_WIFI_SSID "honor"
#define REMOTEXY_WIFI_PASSWORD "9538981779"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "df21b1103c17fd0f39b9d3630917890e"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 132 bytes
  { 255,9,0,0,0,125,0,17,0,0,0,31,1,200,126,1,1,9,0,10,
  4,5,30,30,112,4,26,31,70,0,31,10,30,41,30,30,112,4,26,31,
  83,0,31,10,60,4,30,30,112,4,26,31,66,0,31,10,5,77,30,30,
  112,4,26,31,82,0,31,10,63,79,30,30,112,4,26,31,76,0,31,10,
  116,8,30,30,112,4,26,31,80,0,31,10,166,6,30,30,112,4,26,31,
  83,100,0,31,10,167,52,30,30,112,4,26,31,80,108,0,31,10,120,53,
  30,30,48,4,26,31,72,0,31,80,108,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t pushSwitch_1; // =1 if state is ON, else =0
  uint8_t pushSwitch_2; // =1 if state is ON, else =0
  uint8_t pushSwitch_3; // =1 if state is ON, else =0
  uint8_t pushSwitch_4; // =1 if state is ON, else =0
  uint8_t pushSwitch_5; // =1 if state is ON, else =0
  uint8_t pushSwitch_6; // =1 if state is ON, else =0
  uint8_t pushSwitch_7; // =1 if state is ON, else =0
  uint8_t pushSwitch_8; // =1 if state is ON, else =0
  uint8_t pushSwitch_10; // =1 if state is ON, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
int m1=2;
int m2=3;
int m3=4;
int m4=5;
int s1=8;
int s2=9;
int pl1=10;
int pl2=11;
int p1=A0;
int p2=A1;
int h1=6;
int h2=7;
void left2(){

digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
delay(1000);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
  
}
void fward(){
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);

}
void bward(){
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);


}
void left1(){
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
delay(1000);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);


}
void right1(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
delay(1000);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);


}
void right2(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
delay(1000);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);

}
void stopm(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);


}
void son(){
  digitalWrite(s1,1);
  digitalWrite(s2,0);
}
void soff(){
  digitalWrite(s1,0);
  digitalWrite(s2,0);
}
void hon(){
  digitalWrite(h1,1);
  digitalWrite(h2,0);
}
void hoff(){
  digitalWrite(h1,0);
  digitalWrite(h2,0);
}
void pon(){
  digitalWrite(p1,1);
  digitalWrite(p2,0);
}
void poff(){
  digitalWrite(p1,0);
  digitalWrite(p2,0);
}
void plon(){
  digitalWrite(pl1,0);
  digitalWrite(pl2,1);
  delay(300);
 digitalWrite(pl1,0);
  digitalWrite(pl2,0);
}
void ploff(){
  digitalWrite(pl1,1);
  digitalWrite(pl2,0);
  delay(300);
   digitalWrite(pl1,0);
  digitalWrite(pl2,0);
}


void setup() 
{
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(pl1,OUTPUT);
  pinMode(pl2,OUTPUT);
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(h1,OUTPUT);
  pinMode(h2,OUTPUT);
  RemoteXY_Init (); 
   lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Multi Purpose ");
  lcd.setCursor(0,1);
  lcd.print("Agriculture Bot");
delay(500);  
}
int p=0;
int s=0;
int pl=0;
int h=0;
String sera="S";
void loop() 
{ 
  RemoteXY_Handler ();
 if(RemoteXY.pushSwitch_1 !=0 ){sera='F'; fward();}
 if(RemoteXY.pushSwitch_3 !=0 ){sera='B'; bward();}
 if(RemoteXY.pushSwitch_2 !=0 ){sera='S'; stopm();}
if(RemoteXY.pushSwitch_4 !=0 ) {sera='R';right1();}
if(RemoteXY.pushSwitch_5 !=0 ){sera='L'; left1();}
if(RemoteXY.pushSwitch_6 !=0  && p==0){ pon();
p=1;}
if(RemoteXY.pushSwitch_6 == 0 && p==1) {poff();p=0;}
if(RemoteXY.pushSwitch_7 !=0  && s==0){ son();
s=1;}
if(RemoteXY.pushSwitch_7 == 0  && s==1) {soff();s=0;}
if(RemoteXY.pushSwitch_8 !=0  && pl==0){ plon();
pl=1;}
if(RemoteXY.pushSwitch_8 ==0  && pl==1) {ploff();pl=0;}
if(RemoteXY.pushSwitch_10 !=0  && h==0){ hon();
h=1;}
if(RemoteXY.pushSwitch_10 ==0  && h==1) {hoff();h=0;}
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" M  P  S  PL H");
  lcd.setCursor(0,1);
  lcd.print(" "+sera+"  "+String(p)+"  "+String(s)+"  "+String(pl)+" "+String(h));
delay(500);
}