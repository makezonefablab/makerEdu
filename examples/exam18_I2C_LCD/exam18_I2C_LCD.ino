#include <makerEdu_lib.h>              // 메이크에듀보드 라이브러리 호출

/*******************************************************************************************************************************
  확장 라이브러리 사용하기 - I2C통신용 LCD
********************************************************************************************************************************
  본 예제코드는 I2C통신용 LCD를 사용하기 위한 예제코드입니다.
  일반적으로 LCD를 제어하기 위해 아두이노는 lcd제어용 라이브러리를 사용자에게 제공합니다.
  아두이노 라이브러리 예제에서 LiquidCrystal 이라는 항목에는 lcd제어를 위한 다양한 예제코드가 준비되어 있습니다.
  그러나 아두이노가 제공하는 lcd제어 라이브러리는 디지털핀을 너무 많이 사용하므로 다양한 하드웨어와 동시에 사용하기 매우 불편합니다.
  본 예제에서는 lcd에 I2C통신용 확장보드를 연결하여 아두이노에서 2개의 특별한 아날로그 핀으로 lcd를 제어하는 코드를 제공합니다.
  그러나 이처럼 별도의 확장보드가 필요한 경우 아두이노는 확장보드를 제어하기 위한 별도의 라이브러리를 요구합니다.
  I2C통신용lcd 확장라이브러리는 메이크존 홈페이지나 gitHub을 통해 제공받을 수있습니다.
  다음의 예제코드를 올려서 lcd를 통해 문자출력을 확인해 보세요
*********************************************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Wire.h>                   // I2C통신을 위한 아두이노 라이브러리 호출
#include <LiquidCrystal_I2C.h>   // I2C모듈을 이용한 LCD라이브러리 호출

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD의 I2C주소를 0x27로 정하고 LCD사이즈를 1602로 정함
// I2C용 lcd를 사용하기 위한 객체선언은 setup 전에 해야 함.

void setup()
{ // put your setup code here, to run once:
  start();                       // 고정핀 셋업(D2 ~ D13의 디지털핀 출력으로 셋업, A0~A5의 아날로그핀 입력으로 셋업멜로디연주속도 4)
  start_servo(0);                // 사용할 서보모터 개수 초기화
  start_ultraSonic(OFF, 7, 8);   // 초음파센서 초기화 (사용유무, trig핀번호, echo핀번호)
  start_led(13, 4);              // 사용할 RGBled 개수와 연결핀 초기화 (연결핀 - D13, 기본사용개수 4개)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  lcd.begin();                  // lcd 초기화
  delay(1000);
}

void loop()
{ // put your main code here, to run repeatedly:
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // LCD에 영문자를 표현함.(한글은 아직 안됨)
  while (1)
  {
    lcd.backlight();                    // 백라이트 켜기
    lcd.setCursor(1, 0);                // 커서의 위치를 1번째 줄 2째칸에 위치시킴
    lcd.print("Hello, world!!");        // 1번째 줄 2째칸부터 Hello, world!를 출력
    lcd.setCursor(2, 1);                // 커서의 위치를 2번째 줄 3째칸에 위치시킴
    lcd.print("Makezone Edu");          // 2번째 줄 3째칸부터 Makezone Edu를 출력
    delay(3000);                        // 3초 기다리기
    lcd.clear();                        // LCD 화면 지우기
    delay(1000);                        // 1초 기다리기
    lcd.setCursor(0, 0);                // 커서의 위치를 1번째 줄 1째칸에 위치시킴
    lcd.print("makeEdu LCD 1602");      // 1번째 줄 1째칸부터 makeEdu LCD 1602를 출력
    delay(1000);                        // 1초 기다리기
    lcd.clear();                        // LCD 화면 지우기
    lcd.setCursor(4, 0);                // 커서의 위치를 1번째 줄 5째칸에 위치시킴
    lcd.print("Makezone");              // 1번째 줄 5째칸부터 Makezone을 출력
    delay(3000);                        // 3초 기다리기
    lcd.clear();                        // LCD 화면 지우기
    lcd.noBacklight();                  // 백라이트 끄기
    delay(1000);                        // 1초 기다리기
  }




  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();
}
