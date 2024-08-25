// 오른쪽 기준 정렬  : flag 사용하는 문제 
/*
[reference]
- flag / https://cplusplus.com/reference/ios/ios_base/flags/
- setf / https://cplusplus.com/reference/ios/ios_base/setf/

flag 사용 예시 
 #include <iostream>     // std::cout, std::ios

int main () {
  std::cout.setf ( std::ios::right, std::ios::basefield );  // set hex as the basefield
  std::cout.setf ( std::ios::showbase );                  // activate showbase
  std::cout.width(10);
  std::cout << 100 << '\n';
  std::cout.unsetf ( std::ios::showbase );                // deactivate showbase
  std::cout << 100 << '\n';
  return 0;
}

[출력 결과] 
- 전체 크기 10 (오른쪽 정렬) 100
- 전체 크기 10 (왼쪽 정렬 : default) 100


cout의 flag를 사용할 떄, 
cout.setf(출력 방향(왼/오른/internal), 출력 진법, 부동소수점 표기) 선언을 할수 있음 
cout.setf
 */
#include <iostream>
using namespace std; 

int main()
{
    int num; 
    for(int i = 1; i < num; i++)
    {
        for(int num = 0; num < i; num++) printf
    }
    return 0; 
}