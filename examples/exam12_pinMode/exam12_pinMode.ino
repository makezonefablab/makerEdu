#include <makerEdu_lib.h>

/*******************************************************************************************************************************
  pinMode 사용하기
********************************************************************************************************************************
  본 예제코드는 아두이노의 pinMode 명령어를 사용하여 디지털 핀이나 아날로그 핀의 사용용도를 바꾸는 예제입니다.
  pinMode를 통해 핀의 입출력을 결정하지 않고 maker Edu보드의 기본 라이브러리를 사용하면, 디지털핀은 모두 출력으로 설정되고,
  아날로그 핀은 모두 입력으로 설정됩니다.
  maker Edu의 기본 라이브러리의 start()함수는 pinMode를 세팅해 주는 함수입니다.
  때문에 별도로 pinMode를 통해 핀의 입출력을 재설정하려면 반드시 setup()함수 안에서 start()함수를 호출한 후,
  pinMode 명령어를 호출해야 합니다.
  pinMode()명령어는
  pinMode(변경할 핀 번호, INPUT/OUTPUT)으로 사용합니다. 이때 입출력표시인자값은 반드시 대문자로 써야 합니다.
  pinMode()명령어를 이용해 기본적으로 입력으로 설정된 아날로그 핀을 출력으로 설정할 수도 있습니다. 아날로그 핀을 출력으로 설정하면
  디지털 신호를 출력하게 됩니다. 따라서 일반적인 디지털 핀 사용법대로 아날로그 핀을 출력으로 사용할 수 있습니다.
  다만 아날로그 핀은 pinMode를 설정할 때 셋업할 핀번호가 디지털핀번호와 구분되도록 핀번호숫자앞에 A라는 문자를 표기합니다.
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
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  while (1)                                 // 무한 반복
  { // 중괄호 시작부터
    if (digitalRead(7) == 0)                // 7번핀에 입력되는 값이 0과 같으면
    {
      digitalWrite(A0, HIGH);               // A0핀에 HIGH값 출력
    }
    else                                    // 아니면
    {
      digitalWrite(A0, LOW);                // A0핀에 LOW값 출력
    }
  }                                        // 무한반복 중괄호 마침


  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();
}
