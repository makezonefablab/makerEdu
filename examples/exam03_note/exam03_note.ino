#include <makerEdu_lib.h>

/*****************************************************************************************************
  멜로디 함수로 음악 연주하기
******************************************************************************************************
  본 예제코드는 메이크에듀보드의 내장 수동 부저를 이용하여 멜로디를 연주하는 예제코드입니다.
  하나의 멜로디 함수는 하나의 음표에 대응합니다.
  사용함수는 note(음계,박자); 입니다.
  음계는 7음계음에 옥타브표시를 붙여 "4옥타브 도"는 "do4"로 표시합니다. 반음은 음이름 뒤에 s를
  붙여 사용합니다. "4옥타브 도#"과 "4옥타브 레b"은 같은음이라 항상 올림음으로 표시하고 "dos4"로 적습니다.
  음계에 rest를 적으면 소리가 나지않으므로 박자만큼 쉬게 됩니다.
  tempo()함수는 연주속도를 빠르기를 조절합니다. 기본값은 4로 실수단위로 사용하고 숫자가 작아지면 빨라지고
  커지면 느려집니다.
  start()함수에는 기본 tempo가 4로 설정되어 있으므로 별다른 tempo설정없이 멜로디함수를 호출하면 연주속도는
  tempo(4) 로 연주합니다.
  메이커에듀보드에 내장된 부저는 D4번핀에 연결되어 있습니다.
  예제코드를 보드에 올려서 1도화음인 "도미솔"음을 확인해 보세요.
*******************************************************************************************************/
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

  note(do4, n4);    //4옥타브 "도"음을 4분음표길이로 연주
  note(mi4, n4);
  note(sol4, n4);
  note(rest, n4);   //4분쉼표
  tempo(5);           //템포를 5로 느리게(안단테)
  note(do4, n4);
  note(mi4, n4);
  note(sol4, n4);
  note(rest, n4);   //4분쉼표
  tempo(1.5);         //템포를 1.5로 빠르게(비바치시모)
  note(do4, n4);
  note(mi4, n4);
  note(sol4, n4);
  note(rest, n4);   //4분쉼표
  tempo(4);           //템포를 기본값 4인 보통 빠르기로(모데라토)
  note(do4, n4);
  note(mi4, n4);
  note(sol4, n4);
  note(rest, n4);   //4분쉼표
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();
}
