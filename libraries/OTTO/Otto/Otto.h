#ifndef Otto_h
#define Otto_h

#include <Servo.h>
#include "Oscillator.h"
#include <EEPROM.h>

#include "US.h"
#include "MaxMatrix.h"
#include "BatReader.h"

#include "Otto_mouths.h"
#include "Otto_sounds.h"
#include "Otto_gestures.h"
//#include "SoftSerialCommand.h"

//-- Constants
#define FORWARD     1
#define BACKWARD   -1
#define LEFT        1
#define RIGHT      -1
#define SMALL       5
#define MEDIUM     15
#define BIG        30

#define HIP_L   10       // connect Servo Hip left to D7
#define FOOT_L  12       // Connect Servo Foot Left to D8
#define HIP_R   11       // Connect Servo Hip right to D10
#define FOOT_R  13       // COnnect Servo Foot Right to D11

#define PIN_Buzzer  4
#define PIN_Trigger 3
#define PIN_Echo    5
#define PIN_NoiseSensor A0 // NONE

///define Bluetooth in SoftwareSerial 
#define BT_Rx   A4
#define BT_Tx   A5

//define Max7219 pins 
#define PIN_DIN    2   //max 7219
#define PIN_CS     6
#define PIN_CLK    9

//define Melody
#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978

class Otto
{
  public:
    //-- Otto initialization
    void init(int YL, int YR, int RL, int RR, bool load_calibration=true, int NoiseSensor=PIN_NoiseSensor, int Buzzer=PIN_Buzzer, int USTrigger=PIN_Trigger, int USEcho=PIN_Echo);

    //-- Attach & detach functions
    void attachServos();
    void detachServos();

    //-- Oscillator Trims
    void setTrims(int YL, int YR, int RL, int RR);
    void saveTrimsOnEEPROM();

    //-- Predetermined Motion Functions
    void _moveServos(int time, int  servo_target[]);
    void oscillateServos(int A[4], int O[4], int T, double phase_diff[4], float cycle);

    //-- HOME = Otto at rest position
    void home();
    bool getRestState();
    void setRestState(bool state);
    
    //-- Predetermined Motion Functions
    void jump(float steps=1, int T = 2000);
    void userServo(int s10, int s11, int s12, int s13, int T=300);    //사용자가 직적 서보모터를 제어하는 함수

    void walk(float steps=4, int T=1000, int dir = FORWARD);
    void turn(float steps=4, int T=2000, int dir = LEFT);
    void bend (int steps=1, int T=1400, int dir=LEFT);
    void shakeLeg (int steps=1, int T = 2000, int dir=RIGHT);

    void updown(float steps=1, int T=1000, int h = 20);
    void swing(float steps=1, int T=1000, int h=20);
    void tiptoeSwing(float steps=1, int T=900, int h=20);
    void jitter(float steps=1, int T=500, int h=20);
    void ascendingTurn(float steps=1, int T=900, int h=20);

    void moonwalker(float steps=1, int T=900, int h=20, int dir=LEFT);
    void crusaito(float steps=1, int T=900, int h=20, int dir=FORWARD);
    void flapping(float steps=1, int T=1000, int h=20, int dir=FORWARD);
    void move(int moveID,int time, int _moveSize);
    
    //-- Sensors functions
    float getDistance(); //US sensor
    int   getNoise();      //Noise Sensor

    //-- Battery
    double getBatteryLevel();
    double getBatteryVoltage();
    
    //-- Mouth & Animations
    void putMouth(unsigned long int mouth, bool predefined = true);
    void putAnimationMouth(unsigned long int anim, int index);
    void clearMouth();
 
    //-- Sounds
    void _tone (float noteFrequency, long noteDuration, int silentDuration);
    void _playNote(float noteFrequency, long noteDuration);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void sing(int songName);

    //-- Gestures
    void playGesture(int gesture);
	
	//-- Melody
	void melody(int mld, int meter);
    

 
  private:
    
    MaxMatrix ledmatrix=MaxMatrix(PIN_DIN,PIN_CS,PIN_CLK, 1);  // init Max7219 LED Matrix, 1 module

    BatReader battery;
    Oscillator servo[4];
    US us;

    int servo_pins[4];
    int servo_trim[4];
    int servo_position[4];

    int pinBuzzer;
    int pinNoiseSensor;
    
    unsigned long final_time;
    unsigned long partial_time;
    float increment[4];

    bool isOttoResting;

    unsigned long int getMouthShape(int number);
    unsigned long int getAnimShape(int anim, int index);
    void _execute(int A[4], int O[4], int T, double phase_diff[4], float steps);
};

#endif


