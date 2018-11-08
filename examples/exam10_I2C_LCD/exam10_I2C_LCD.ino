#include "kict_lib.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD의 I2C주소를 0x27로 정하고 LCD사이즈를 1602로 정함

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() 
{// put your setup code here, to run once:
  default_Servoinit(0);  //사용할 서보모터 개수 초기화
  makeInit(4);           //고정핀 셋업(버저핀4,왼쪽모터 6,9, 오른쪽모터 3,5 멜로디 템포 4)
  lcd.begin();            // lcd 초기화
  delay(1000);
}

void loop() 
{// put your main code here, to run repeatedly:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // LCD에 영문자를 표현함.(한글은 아직 안됨)
while(1)
{  
  lcd.backlight();                    // 백라이트 켜기
  lcd.setCursor(1,0);                 // 커서의 위치를 0번째 줄 3째칸에 위치시킴
  lcd.print("Hello, world!!");         // 0번째 줄 3째칸에 Hello, world!를 출력
  lcd.setCursor(2,1);                 // 커서의 위치를 1번째 줄 2째칸에 위치시킴
  lcd.print("Makezone Edu");          // 1번째 줄 2째칸에 Makezone Edu를 출력
  delay(3000);                        // 3초 기다리기
  lcd.clear();                        // LCD 화면 지우기
  delay(1000);                        // 1초 기다리기
  lcd.setCursor(0,0);                 // 커서의 위치를 0번째 줄 0째칸에 위치시킴
  lcd.print("makeEdu LCD 1602");
  lcd.setCursor(4,1);                 // 커서의 위치를 1번째 줄 4째칸에 위치시킴
  lcd.print("Makezone");
  delay(3000);                        // 3초 기다리기
  lcd.clear();                        // LCD 화면 지우기
  lcd.noBacklight();                  // 백라이트 끄기  
  delay(1000);                        // 1초 기다리기
}


 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();                 
}
