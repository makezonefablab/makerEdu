#include <makerEdu_lib.h>

/*******************************************************************************************************************************
  토글방식에서 바운스 제거하기_02
********************************************************************************************************************************
  본 예제코드는 아두이노에서 토글방식으로 스위치를 제어할때 바운스를 제거하는 디바운스 예제코드입니다.
  전자회로를 구성하는 기계식 스위치에서 bounce라는 것은 스위치를 작동시킬 때,전자적으로 사람이 느끼지 못할만큼 빠르게 스위치가
  개폐를 반복하는 것을 말합니다. 때문에 사람은 한번 스위치를 작동시켰다고 생각하지만 아두이노는 여러번 스위치를 작동시켰다고 인식하여
  물리적인 동작구현에 오류가 발생합니다. 예제11의 토글코드에서 바운스제거를 위한 지연시간을 0으로 두면 동작오류를 볼 수 있습니다.
  디바운스(Debounce)코드는 이러한 바운싱현상을 제거하기 위한 프로그래밍적 기법을 말합니다.
  이번 예제에서는 millis()함수를 이용하여 delay함수를 사용하지 않는 디바운스코드입니다.
  다음 예제를 통해 사용법을 확인해 보세요
*********************************************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{ // put your setup code here, to run once:
  start();                       // 고정핀 셋업(D2 ~ D13의 디지털핀 출력으로 셋업, A0~A5의 아날로그핀 입력으로 셋업멜로디연주속도 4)
  start_servo(0);                // 사용할 서보모터 개수 초기화
  start_ultraSonic(OFF, 7, 8);   // 초음파센서 초기화 (사용유무, trig핀번호, echo핀번호)
  start_led(13, 4);              // 사용할 RGBled 개수와 연결핀 초기화 (연결핀 - D13, 기본사용개수 4개)

  /**********pinMode는 반드시 설정함수를 먼저 호출한 후 그 다음에 호출한다.***************************/
  pinMode(A0, OUTPUT);        // 아날로그 A0핀 출력으로 설정
  pinMode(7, INPUT);          // 디지털 7핀 입력으로 설정
  delay(1000);
}

void loop()
{ // put your main code here, to run repeatedly:
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int ledState = LOW;         // LED가 연결된 A0핀의 현재 상태를 표시하는 변수(LOW로 초기화함)
  int buttonState;            // 입력으로 설정된 D7번핀의 현재 버튼작동상태를 저장하는 변수
  int lastButtonState = HIGH; // 입력으로 설정된 D7번핀의 마지막 동작상태를 저장하는 변수(HIGH로 초기화함)
  long lastDebounceTime = 0;  // A0핀에 연결된 스위치가 작동했을 때까지의 마지막 시간값을 저장하는 변수.
  // 밀리초로 작동하는 millis()함수를 저장하게 되므로 int형이 저장할 수있는 수의 범위를
  // 빠르게 넘어서므로long형으로 선언함


  while (1)                                   // 무한 반복
  { // 중괄호 시작부터
    if (digitalRead(7) != lastButtonState)    // D7의 현재 스위치값이 lastButtonState값과 다르다면
    {
      lastDebounceTime = millis();            // lastDebounceTime에 현재의 millis값을 저장한 후,
    }
    if ((millis() - lastDebounceTime) > 50)   // 현재 millis의 시간값과 lastDebounceTime에 저장된 시간값의 차가 50보다 크고
    {
      if (digitalRead(7) != buttonState)      // D7번핀 값과 buttonState값이 다르면,
      {
        buttonState = digitalRead(7);         // buttonState값에 현재 D7번핀 값을 저장한 후,
        if (buttonState == HIGH)              // buttonState값이 HIGH라면
        {
          ledState = !ledState;               // ledState값을 반전시킨다.
        }
      }
    }
    digitalWrite(A0, ledState);               // A0번에 연결된 led를 ledState값으로 표현하고,
    lastButtonState = digitalRead(7);         // lastButtonState변수에 D7번 핀값을 저장하시오
  }                                             // 무한반복 중괄호 마침 다시 while(1)로 gogo!!

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();
}
