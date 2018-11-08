#include "kict_lib.h"

/**************************************************************
서보모터제어하기
*****************************************************************************************************
본 예제코드는 메이크에듀보드를 이용하여 서보모터를 사용하는 기본 예제입니다.
아두이노에서는 확장 라이브러리를 통해 기본적인 서보모터라이브러리를 제공합니다. 
메이크에듀보드에서는 아두이노에서 제공하는 서보모터라이브러리를 활용하여 
아두이노의 문법체계를 지키면서 보다 쉽게 서보모터를 제어할 수 있는 자체 함수를 제공합니다. 

메이크에듀보드에서 제공하는 서보모터관련 함수는 다음과 같습니다. 
default_Servoinit(사용할서보개수); - 사용하고자 하는 서보모터의 갯수를 초기화합니다.
                                     10번핀부터 시작하여 사용개수만큼 디지털핀을 사용합니다.(1개-10번핀,2개-10,11번핀...)
                                     모두 4개의 서보모터를 사용할 수 있습니다. 
servoX.write(각도);                - 해당X핀에 연결된 서보모터의 각도를 제어합니다.
servo(서보핀번호,ON/OFF);          - 원하는 서보모터를 사용하기 위해 켜거나 사용을 중지할 수 있습니다.
                                     OFF된 서보모터는 토크가 해제됩니다.(철자는 대문자로 써야합니다) 

메이크에듀보드에서 제공하는 서보모터관련 함수는 D10 ~ D13번핀에서 순차적으로 사용할 수 있습니다. 
그러나 아두이노에서 제공하는 확장라이브러리의 문법을 모두 사용할 줄 알면 메이크에듀보드의 모든 디지털핀에 
서보모터를 사용할 수 있습니다. 
예제코드를 보드에 올려서 모터의 회전을 확인해 보세요.
********************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int val;    // 아날로그 입력핀의 값이 저장되는 변수를 정수형으로 선언

void setup() 
{// put your setup code here, to run once:
  default_Servoinit(1);  //사용할 서보모터 개수 초기화
  makeInit(4);           //고정핀 셋업(버저핀4,왼쪽모터 6,9, 오른쪽모터 3,5 멜로디 템포 4)
  delay(1000);
}

void loop() 
{// put your main code here, to run repeatedly:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while(1)                               // 무한반복 시작하겠음
{                                      // 중괄호 시작    
  val = analogRead(0);                 // 아날로그입력 0번핀으로 입력되는 가변저항값을 변수 val에 저장함.(0~1023)
  val = map(val, 0, 1023, 0, 180);     // 변수val에 입력되는 가변저항값의 범위(0~1023)를 서보모터의 각도변화량인 0~180의 값으로
                                       // 균등환산하여 다시 변수 val에 저장
  servo10.write(val);                  // D10번핀에 연결된 서보모터의 각도값을 변수 val로 정함
  delay(15);                           // 0.015초 대기
}                                      // 중괄호 끝. 중괄호 시작으로 다시 돌아감.


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  finish();                 
}
