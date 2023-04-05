#include <makerEdu_lib.h>

/****************************************************************************************************
  led함수로 스트립led 제어하기
*****************************************************************************************************
  본 예제코드는 메이크에듀보드에서 스트립led를 제어하는 예제코드입니다.
  메이커에듀보드는 1개의 스트립led를 사용할 수 있습니다.(여러개의 스트립led를 사용하려면 인스턴스를
  추가하여 네오픽셀 제어구문으로 사용하면 됩니다)

  초기화함수는 start_led(사용픽셀개수, 제어핀번호); 입니다. 
  초기화 기본값은 픽셀개수 4개, 제어핀 13번으로 제어핀은 아날로그핀으로 지정해도 됩니다.
  제어함수는 led(픽셀번호, R, G, B);로 RGB는 0~255까지 제어범위를 사용할 수 있습니다.
  스트립 전체의 밝기를 제어하려면 ledBright(밝기값); 함수를 사용합니다.
  RGB 개별적인 밝기는 led 함수를 통해 제어할 수 있지만 RGB값을 섞어서 다양한 색상을 표현하고 이에 대한
  밝기를 제어할 때 사용합니다.
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
  led(0, 255, 0, 0);      //0번 led 빨강
  delay(1000);
  led(0, 0, 255, 0);      //0번 led 초록
  delay(1000);
  led(0, 0, 0, 255);      //0번 led 파랑
  delay(1000);
  led(0, 255, 0, 255);    //0번 led 마젠타
  delay(1000);
  led(0, 255, 255, 0);    //0번 led 노랑
  delay(1000);
  led(0, 0, 255, 255);    //0번 led 사이안
  delay(1000);
  led(0, 255, 255, 255);  //0번 led 백색
  delay(1000);
  led(0, 0, 0, 0);        //0번 led 끄기
  delay(1000);



  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();
}
