#include <makerEdu_lib.h>

/****************************************************************************************************
  motor함수로 모터제어하기
*****************************************************************************************************
  본 예제코드는 메이크에듀보드의 전용 모터드라이버회로를 이용한 모터 제어 예제코드입니다.
  메이커에듀보드는 2개의 모터를 동시에 개별적으로 제어하는 전용 모터드라이버를 사용하며
  모터를 사용하지 않을때는 드라이버보드를 제거하고 디지털핀으로 사용할 수 있습니다.

  사용함수는 motor(M1속도,M2속도,동작시간); 입니다. wheel함수는 단독으로 사용했을 때 작동하지 않지만,
  motor함수는 동작시간을 인자값으로 주면 지정된 시간만큼 동작한 후 정지합니다.
  다만 동작시간이 0이라면 wheel함수와 같은 동작을 합니다.

  모터의 속도는 -200 ~ 200이고 속도값이 0이면 모터를 정지 시킵니다. 인자값이 음수로 표현되면 회전방향이 변합니다.
  M1모터를 왼쪽이라 할 때 양수는 전진방향 음수는 후진방향을 표시합니다.

  또한 모터 드라이버는 메이크에듀보드의 입력전원을 그대로 모터에 전달하므로 메이크에듀보드의 입력전압이 클수록
  모터의 힘과 속도가 증가하게 됩니다. 메이크에듀보드는 최대 12V까지 사용할 수 있습니다.
  motor함수가 사용하는 아두이노의 핀은 PWM출력 핀3,5,6,9번입니다.
  예제코드를 보드에 올려서 모터의 회전을 확인해 보세요.
********************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{ // put your setup code here, to run once:
  start();                       // 고정핀 셋업(D2 ~ D13의 디지털핀 출력으로 셋업, A0~A5의 아날로그핀 입력으로 셋업멜로디연주속도 4)
  start_servo(0);                // 사용할 서보모터 개수 초기화
  start_ultraSonic(OFF, 7, 8);   // 초음파센서 초기화 (사용유무, trig핀번호, echo핀번호)
  start_led(13, 4);              // 사용할 RGBled 개수와 연결핀 초기화 (연결핀 - D13, 기본사용개수 4개)
  delay(1000);
}

void loop()
{ // put your main code here, to run repeatedly:
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  motor(100, 100, 1000);     //1초동안 속도 100으로 전진 후 정지
  motor(-100, -100, 1000);   //1초동안 속도 100으로 후진 후 정지
  motor(-100, 100, 1000);    //1초동안 속도 100으로 제자리 좌회전 후 정지
  motor(100, -100, 1000);    //1초동안속도 100으로 제자리 우회전 후 정지
  delay(1000);               //1초동안속도 양쪽모터 정지

  motor(100, 100, 1000);     //1초동안 속도 100으로 전진 후 정지
  delay(1000);               //1초동안속도 양쪽모터 정지
  motor(-100, -100, 1000);   //1초동안 속도 100으로 후진 후 정지
  delay(1000);               //1초동안속도 양쪽모터 정지
  motor(-100, 100, 1000);    //1초동안 속도 100으로 제자리 좌회전 후 정지
  delay(1000);               //1초동안속도 양쪽모터 정지
  motor(100, -100, 1000);    //1초동안속도 100으로 제자리 우회전 후 정지
  delay(1000);               //1초동안속도 양쪽모터 정지

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();
}
