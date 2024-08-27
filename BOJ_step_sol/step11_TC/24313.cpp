/*
1. 아이디어 
- 부등호가 성립하는지 아닌지만 판별하면 됨. 
- for-loop(1차원) 순회하며 주어진 (n0)값에 대하여 부등식을 판별. 
2. 시간복잡도 
- O(1) // for-loop가 있지만 해당 변수의 크기임 size에 비례한 상수의 영역 
사용가능  
3. 자료구조 
- none 
*/


#include <iostream>
#define size 2 


using namespace std; 

int main()
{

    // 1 trial - issue a값들이 음수인 경우 고려하지 않음. 
    // (0 ≤ |ai| ≤ 100)
    int a[size]; 
    int c, n0; 

    cin >> a[1] >> a[0]; 
    cin >> c;
    cin >> n0; 

//  ((a[1] * n0 + a[0] ) <= (c * n0)) ? cout << 1 : cout << 0;

    // 2nd-trial (양수로 전환)
    // for(int i = 0; i < size; i++)
    // {
    //     if(a[i] < 0) a[i] *= (-1); 
    // }

    // 3rd - trial 
    // 예외 case 1 , 4n - 3 ≤ 3n (n ≥ 1) 
    // > sol, n항을 한고으로 모으는 것 안전하게 풀이할 수 있음.
    // -> 반례를 찾을때까지 순회 O(n), 무한루프 위험 ... 
    // 해당 접근은 오류가 있음..  

    // > 참조 답안 idea, a1 <= c 조건 추가하면 됨 -> O(1) 

    ((a[1] * n0 + a[0] ) <= (c * n0) && a[1] <= c) ? cout << 1 : cout << 0;

    return 0; 
}
