/*
참고 : https://st-lab.tistory.com/212
[reference] https://cplusplus.com/reference/ios/fixed/
*/


#include <iostream>

using namespace std; 

int main()
{
    long double a, b; 
    cin >> a >> b; 
    cout.precision(12); // 출력할 자릿수 설정 
    cout << fixed; // 부돟소수점의 자릿수를 precision에서 설정한 크기만큼 출력하겠다는 의미 
    cout << (a / b) << endl; 
    return 0; 
}  