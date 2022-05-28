/*********makezone_Shield_libraries V1.82*********/
/*V1.1
//모터함수 속도 버그해결
//beat 정의에 테누토 계산 수정
/*V1.2
//아두이노 표준 서보라이브러리 포함 초기화 함수 생성
/*V1.25
//탬포 함수의 인자가 0일때 note를 버저로 사용할 수 있도록 수정
//버저함수 추가 - buzzer(onTime, offtime) : 버저음은 가온음 '라'
/*V1.3
// finish()함수 적용
/*V1.4
// 초음파센서값을 얻기 위한 getDistance()함수 추가 - Cm단위로 감지거리값을 반환함
// 초음파센서 초기화 함수 start_ultraSonic(사용여부, trig핀번호, echo핀번호)추가
// servoXn.write()함수를 servo함수에 통합 
// start()함수에서 출력으로 초기화 하는 디지털핀을 시리얼핀을 제외한 모든 핀으로 확대
// music Constants의 note정의 중 오타수정
/*V1.5
// 조종기를 위한 라이브러리 추가
/*V1.6
// note함수에서 tone함수에 직접 접근할 수 있도록 변경(tempo를 1로함)
*/
/*V1.7
// ws2812b 네오픽셀 제어함수 추가
// tempo값이 1이고 음계가 쉼표일때 때 note함수는 noTone함수를 호출함 
*/
/*V1.72
// start_led함수의 제어핀 셋업인자값 추가
// 스트립led의 밝기 제어 함수명 수정 brightControl -> ledBright 
*/
/*V1.73
// 라이브러리 헤더이름을 kict_lib에서 makeEdu_lib로 변경
*/
/*V1.8
// led스트립 제어함수 7종 추가
// ledSpeed(), ledShow(), ledWipe(),ledTheaterChase(), 
// ledRainbow(), ledRainbowCycle(), ledTheaterChaseRainbow() 추가
*/
/*V1.82
// led_start()함수 수정
// led 인스터스명 수정. strip->strip0(다중 인스턴스 사용) memo
*/

/************************************************
 * servo Constants
 ************************************************/
#include <Servo.h>
#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel strip0;  //ws2812b 스트립led의 인스턴스 선언
Servo servo10;            //10번핀에 사용할 서보모터 이름
Servo servo11;            //11번핀에 사용할 서보모터 이름
Servo servo12;            //12번핀에 사용할 서보모터 이름
Servo servo13;            //13번핀에 사용할 서보모터 이름

#define sv1 servo10
#define sv2 servo11
#define sv3 servo12
#define sv4 servo13

#define ON -1
#define OFF -2

/************************************************
 * ultarSonar Constants
 ************************************************/

#define distance getDistance()

/*************************************************
 * music Constants
 *************************************************/

#define NOTE_0  0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440      //조율 기준음 가온음 '라'
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

/*************************************************************
easy working!!! (for korean) 
**************************************************************/
#define rest   NOTE_0  
#define si0    NOTE_B0  
#define do1    NOTE_C1  
#define dos1   NOTE_CS1 
#define re1    NOTE_D1  
#define res1   NOTE_DS1 
#define mi1    NOTE_E1  
#define pa1    NOTE_F1  
#define pas1   NOTE_FS1 
#define sol1   NOTE_G1  
#define sols1  NOTE_GS1 
#define ra1    NOTE_A1  
#define ras1   NOTE_AS1 
#define si1    NOTE_B1  
#define do2    NOTE_C2  
#define dos2   NOTE_CS2 
#define re2    NOTE_D2  
#define res2   NOTE_DS2 
#define mi2    NOTE_E2  
#define pa2    NOTE_F2  
#define pas2   NOTE_FS2 
#define sol2   NOTE_G2  
#define sols2  NOTE_GS2 
#define ra2    NOTE_A2  
#define ras2   NOTE_AS2 
#define si2    NOTE_B2  
#define do3    NOTE_C3  
#define dos3   NOTE_CS3 
#define re3    NOTE_D3  
#define res3   NOTE_DS3 
#define mi3    NOTE_E3  
#define pa3    NOTE_F3  
#define pas3   NOTE_FS3 
#define sol3   NOTE_G3  
#define sols3  NOTE_GS3 
#define ra3    NOTE_A3  
#define ras3   NOTE_AS3 
#define si3    NOTE_B3  
#define do4    NOTE_C4  
#define dos4   NOTE_CS4 
#define re4    NOTE_D4  
#define res4   NOTE_DS4 
#define mi4    NOTE_E4  
#define pa4    NOTE_F4  
#define pas4   NOTE_FS4 
#define sol4   NOTE_G4  
#define sols4  NOTE_GS4 
#define ra4    NOTE_A4  
#define ras4   NOTE_AS4 
#define si4    NOTE_B4  
#define do5    NOTE_C5 
#define dos5   NOTE_CS5 
#define re5    NOTE_D5 
#define res5   NOTE_DS5 
#define mi5    NOTE_E5 
#define pa5    NOTE_F5  
#define pas5   NOTE_FS5 
#define sol5   NOTE_G5  
#define sols5  NOTE_GS5 
#define ra5    NOTE_A5  
#define ras5   NOTE_AS5 
#define si5    NOTE_B5  
#define do6    NOTE_C6  
#define dos6   NOTE_CS6 
#define re6    NOTE_D6  
#define res6   NOTE_DS6 
#define mi6    NOTE_E6  
#define pa6    NOTE_F6  
#define pas6   NOTE_FS6 
#define sol6   NOTE_G6  
#define sols6  NOTE_GS6 
#define ra6    NOTE_A6  
#define ras6   NOTE_AS6 
#define si6    NOTE_B6  
#define do7    NOTE_C7  
#define dos7   NOTE_CS7 
#define re7    NOTE_D7  
#define res7   NOTE_DS7 
#define mi7    NOTE_E7  
#define pa7    NOTE_F7  
#define pas7   NOTE_FS7 
#define sol7   NOTE_G7  
#define sols7  NOTE_GS7 
#define ra7    NOTE_A7  
#define ras7   NOTE_AS7 
#define si7    NOTE_B7  
#define do8    NOTE_C8  
#define dos8   NOTE_CS8 
#define re8    NOTE_D8  
#define res8   NOTE_DS8 

/*********************************************************
beat define
**********************************************************/

#define n32   1*3*4   // 3
#define n16   2*3*4   // 6
#define n16d  3*3*4   // 9 (점음표 표현)
#define n16t  2*4*4   // 8 (테누토 표현)
#define n8    4*3*4   // 12
#define n8d   6*3*4   // 18
#define n8t   4*4*4   // 16
#define n4    8*3*4   // 24
#define n4d   12*3*4  // 36
#define n4t   8*4*4   // 32
#define n2    16*3*4  // 48
#define n2d   24*3*4  // 72
#define n2t   16*4*4  // 64
#define n1    32*3*4  // 96


/*********************************************************
ps2 define
**********************************************************/
/*
#define BRAKE 0
#define brake BRAKE
#define STOP 1
#define HEADER_HIGH     0xaa
#define HEADER_LOW      0x55
//Option Button
#define PS2_SELECT      (conData[0]&0x01)
#define PS2_L_SW        (conData[0]&0x02)
#define PS2_R_SW        (conData[0]&0x04)
#define PS2_START       (conData[0]&0x08)

//Left Side Button
#define PS2_L_FF        (conData[0]&0x10)
#define PS2_L_RR        (conData[0]&0x20)
#define PS2_L_BB        (conData[0]&0x40)
#define PS2_L_LL        (conData[0]&0x80)

//Right Side Button
#define PS2_R_FF        (conData[1]&0x10)
#define PS2_R_RR        (conData[1]&0x20)
#define PS2_R_BB        (conData[1]&0x40)
#define PS2_R_LL        (conData[1]&0x80) 

//Front Side Button
#define PS2_L_2         (conData[1]&0x01)
#define PS2_R_2         (conData[1]&0x02)
#define PS2_L_1         (conData[1]&0x04)
#define PS2_R_1         (conData[1]&0x08)

//Left Side Analog Joy Stick
#define PS2_AL_FF       (conData[2]&0x10)
#define PS2_AL_RR       (conData[2]&0x20)
#define PS2_AL_BB       (conData[2]&0x40)
#define PS2_AL_LL       (conData[2]&0x80)

//Right Side Analog Joy Stick
#define PS2_AR_FF       (conData[2]&0x01)
#define PS2_AR_RR       (conData[2]&0x02)
#define PS2_AR_BB       (conData[2]&0x04)
#define PS2_AR_LL       (conData[2]&0x08)

int conData[3];
int rx_data[4];
int rx_cnt;
unsigned char buf;
unsigned char check_sum = 0;
unsigned char rxmode = 0;
*/


/********************************************KICT_makeShield_libraries*************************************************************/

float beatDuration, Tempo;                          //피에조버저를 사용하기 위한 광역변수
unsigned char svCount, trigPin, echoPin, _flag;            //서보모터와 초음파센서를 사용하기 위한 광역변수

void ledBright(unsigned char bright);              // ws2812b 밝기 조절
void finish(void);
void tempo(float spd);                              //멜로디 연주 속도를 정하는 함수(기본값 4)
void duration(float beat);
void note(int pitch, float beat);                  //피에조버저를 이용해 음계를 연주하는 함수(블럭에서는 NOTE_A3 ~ NOTE_C6까지만)
void start(void);                                   //쉴드 초기화 함수(모터 포트와 버저포트를 셋업하고 멜로디연주속도를 지정함)
float getDistance(void);
void start_led(uint16_t _pin, uint16_t count);           //led 초기화 
void start_ultraSonic(char use, unsigned char trig, unsigned char echo);  //초음파센서 초기화 함수(사용유무, trig핀번호, echo핀번호);
void start_servo(char num);                         //사용할 servo모터의 개수 초기화
void buzzer(int onTime, int offTime);
void servo(char num, int state);                    //servo(서보모터핀번호, 각도값); 각도값인자에 ON,OFF인자를 통해 토크사용을 결정
void lMotor(int spd);                               //왼쪽모터 구동을 위한 내부함수. 속도값 45 ~ 200 사이에서 정수단위로 지정(M1포트)
void rMotor(int spd);                               //오른쪽쪽모터 구동을 위한 내부함수. 속도값 45 ~ 200 사이에서 정수단위로 지정(M2포트)
void wheel(int lspd, int rspd);                     //시간값이 지정되지 않고 각 모터의 속도와 방향만 정함
void motor(int lspd, int rspd, unsigned int timer); //시간값을 정하면 지정된 시간만큼 모터를 동작하고 시간값을 0으로 두면 wheel과 같음
bool boolanalogRead(char Pin, unsigned int value);  //아날로그입력핀값을 기준값 value와 비교하여 bool값을 반환하는 함수
void remocon(void);                                 //리모컨 사용을 위한 함수 
void led(uint16_t n, int r, int g, int b);          //ws2812b 모듈 개별 제어 함수
void ledWipe(int r, int g, int b, unsigned int t);
void ledTheaterChase(int r, int g, int b, unsigned int t);
void ledRainbow(unsigned int t);
void ledRainbowCycle(unsigned int t);
void ledRainbowTheaterChase(unsigned int t);
void ledShow(void);
void ledSpeed(unsigned char flag);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tempo(float playTempo)
{
  Tempo = playTempo;
}

void ledSpeed(unsigned char flag)
{
  _flag = flag;
}

void ledBright(unsigned char bright)
{
  strip0.setBrightness(bright);
}

void led(uint16_t n, int r, int g, int b)
{
  if(_flag == 0) strip0.showSinglePixel(n, strip0.Color(r, g, b));    // lowspeed single pixel control (include "show()")
  else if(_flag == 1) strip0.setPixelColor(n, strip0.Color(r, g, b)); // highspeed single pixel control (Use "show()" individually)
}
void ledShow(void)
{
  strip0.show(); //Update
}

void ledWipe(int r, int g, int b, unsigned int t)
{
  strip0.colorWipe(strip0.Color(r, g, b), t);
}

void ledTheaterChase(int r, int g, int b, unsigned int t)
{
  strip0.theaterChase(strip0.Color(r, g, b), t);
}

void ledRainbow(unsigned int t)
{
  strip0.rainbow(t);
}

void ledRainbowCycle(unsigned int t)
{
  strip0.rainbowCycle(t);
}

void ledRainbowTheaterChase(unsigned int t)
{
  strip0.theaterChaseRainbow(t);
}

bool boolanalogRead(char Pin, unsigned int value)
{
  bool analogReadvalue = (analogRead(Pin) > value);
  return analogReadvalue;
}

float getDistance(void)
{
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    return pulseIn(echoPin,HIGH,30000)/58.2;
}

void start(void)
{
 // int analogPin[]={A0,A1,A2,A3,A4,A5};
 // for(int i = 0; i < 6; i++) pinMode(analogPin[i], INPUT);
  for(int i = 2; i < 14; i++) pinMode(i, OUTPUT);
  tempo(4);           // 곡의 전체적인 빠르기. 기본값은 4(실수로 표현가능) 숫자가 0에 수렴할수록 템포는 빨라짐
}
void start_led(uint16_t _pin, uint16_t count)
{
  if(count > 0){
    strip0 = Adafruit_NeoPixel(count, _pin, NEO_GRB + NEO_KHZ800);
    ledBright(50);
    strip0.begin();
    strip0.show();
    ledSpeed(0);
  }
  else if(count == 0) pinMode(13, OUTPUT);
}

void start_ultraSonic(char use, unsigned char trig, unsigned char echo)
{
  if(use == -1)
  {
    trigPin = trig;
    echoPin = echo;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }
  else if(use == -2)
  {
    pinMode(trig, OUTPUT);
    pinMode(echo, OUTPUT);
  }
}

void finish(void)
{
  noTone(4);
  for(int i = 10; i <=14; i++) {servo(i, OFF);}  
  for(int j = 2; j <14; j++)
  {
    pinMode(j, OUTPUT);
    digitalWrite(j, LOW);
  }
  while(1);
}

void duration(float beat)
{
  if(Tempo > 0) beatDuration = Tempo*(beat);
  else if(Tempo == 0) beatDuration = beat;
}

void note(int pitch, float beat)
{
  if(Tempo == 1 && pitch > 0) tone(4, pitch, beatDuration);
  else if (Tempo == 1 && pitch == 0) noTone(4);  
  else if(Tempo > 1)
  {
    duration(beat);
    for(int i = 0; i <= beatDuration; i++) tone(4, pitch, beatDuration);
    delay(beatDuration*1.15);
    noTone(4);
  }
  else if(Tempo == 0)
  {
    tone(4, pitch, 0);
    delay(beat);
    noTone(4);
    delay(beat);
  }
}

void buzzer(int onTime, int offTime)
{
  if(offTime > 0)
  {
    tone(4, 440,0);
    delay(onTime);
    noTone(4);
    delay(offTime);
  }
  else if(offTime == 0)
  {
    tone(4, 440,0);
    delay(onTime);
  }
}

void start_servo(char num)
{
  svCount = num;
  
  if(svCount > 0)
  {
    if(svCount >= 5) num = 4;
    switch(svCount)
    {
      case 1:
        servo10.write(0);
        servo10.attach(10);
        break;
        
      case 2:
        servo10.write(0);  
        servo11.write(0);   
        servo10.attach(10);
        servo11.attach(11);
        break;
        
      case 3:
        servo10.write(0);  
        servo11.write(0);   
        servo12.write(0);    
        servo10.attach(10);
        servo11.attach(11);
        servo12.attach(12);
        break;
        
      case 4:
        servo10.write(0);  
        servo11.write(0);   
        servo12.write(0);    
        servo13.write(0);         
        servo10.attach(10);
        servo11.attach(11);
        servo12.attach(12);
        servo13.attach(13);     
        break; 
    }
  }
  else
  {
    servo10.detach();
    servo11.detach();
    servo12.detach();
    servo13.detach(); 
  }
}

void servo(char num, int state)
{
  switch(svCount)
  {
    case 1:
      if((num == 10) && (state == -1)) servo10.attach(10);
      else if((num == 10) && (state == -2)) servo10.detach();
      else if((num == 10) && (state >= 0)) servo10.write(state);
      break;

    case 2:
      if((num == 10) && (state == -1)) servo10.attach(10);
      else if((num == 11) && (state == -1)) servo11.attach(11);
      else if((num == 10) && (state == -2)) servo10.detach();
      else if((num == 11) && (state == -2)) servo11.detach();
      
      else if((num == 10) && (state >= 0)) servo10.write(state);
      else if((num == 11) && (state >= 0)) servo11.write(state);
      break;

    case 3:
      if((num == 10) && (state == -1)) servo10.attach(10);
      else if((num == 11) && (state == -1)) servo11.attach(11);
      else if((num == 12) && (state == -1)) servo12.attach(12);
      else if((num == 10) && (state == -2)) servo10.detach();
      else if((num == 11) && (state == -2)) servo11.detach();
      else if((num == 12) && (state == -2)) servo12.detach();
    
      else if((num == 10) && (state >= 0)) servo10.write(state);
      else if((num == 11) && (state >= 0)) servo11.write(state);
      else if((num == 12) && (state >= 0)) servo12.write(state);
      break;
      
    case 4:
      if((num == 10) && (state == -1)) servo10.attach(10);
      else if((num == 11) && (state == -1)) servo11.attach(11);
      else if((num == 12) && (state == -1)) servo12.attach(12);
      else if((num == 13) && (state == -1)) servo13.attach(13);
      else if((num == 10) && (state == -2)) servo10.detach();
      else if((num == 11) && (state == -2)) servo11.detach();
      else if((num == 12) && (state == -2)) servo12.detach();
      else if((num == 13) && (state == -2)) servo13.detach();

      else if((num == 10) && (state >= 0)) servo10.write(state);
      else if((num == 11) && (state >= 0)) servo11.write(state);
      else if((num == 12) && (state >= 0)) servo12.write(state);
      else if((num == 13) && (state >= 0)) servo13.write(state);
      break;     
  }
}

void lMotor(int spd)
{
  if(spd >0)
  {
    if(spd > 200) spd=200;
    else if(spd < 45) spd=45;
    spd = 245-spd;        
    analogWrite(6,spd);
    digitalWrite(9,HIGH);      
  }
  else if(spd < 0)
  {
    if(abs(spd)>=200) spd=210;
    else if(abs(spd)<=45) spd=45;
    analogWrite(6,abs(spd));
    digitalWrite(9,0);    
  }
  else
  {
    digitalWrite(6,0);    
    digitalWrite(9,0);         
  }
}
void rMotor(int spd)
{
  if(spd >0)
  {
    if(spd > 200) spd=200;
    else if(spd < 45) spd=45;
    spd = 245-spd;        
    analogWrite(5,spd);
    digitalWrite(3,HIGH);
  }  
  else if(spd < 0)
  {
    if(abs(spd)>=200) spd=210;
    else if(abs(spd)<=45) spd=45;    
    analogWrite(5,abs(spd));
    digitalWrite(3,0);    
  }
  else
  {
    digitalWrite(3,0);    
    digitalWrite(5,0);     
  }
}

void wheel(int lspd, int rspd)
{
  lMotor(lspd);
  rMotor(rspd);  
}
void motor(int lspd, int rspd, unsigned int timer)
{
  if(timer > 0)
  {
    wheel(lspd,rspd);
    delay(timer);
    wheel(0,0);
  }
  else if(timer == 0) wheel(lspd,rspd);
}