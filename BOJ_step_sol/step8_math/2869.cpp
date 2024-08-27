/*
1. idea

[answer - idea]
- Loop를 사용하여 확인하는 방법은 프로그램에서 제시된 시간 복잡도 충족 X 
- 따라서, 관점을 바꾸어서 <(목표 거리 - 미끄러짐) / (이동거리 - 미끄러짐); 이동한 날짜>
이동한 날짜 * (1일 이동거리 | 목표거리 - 미끄러짐) + 미끄러짐 / 마지막 날은 미끄러짐 없으므로 >= (목표 거리) 


- 해당 문제 데이터 갯수가 10억이 아님. 
문제에 속지 말 것. 

- for loop 돌면서, 해당 값에 도달했는지 확인 
- 10억 이상 자료형 들어왔을 때, 처리가 가능한가


연산시간을 O(n) 미만으로 만들어야 함. 
O(log N) ? tree를 이용하는 문제? 

10억 이상 자료를 저장하는 자료형 (long long)



+ - goal 

-  2 1 5 , 4
-  

//연산 순서가 
day -> night 순으로 합산이 이루어져야함. 
순서 중요 
2 2 
1 1

2 3 
1 2

2 4 
1 3

2 5

2. 시간 복잡도 
>> O(n), n == 10억 >> 1억  따라서 
>>  늦출 필요가 있음. 

[answer idea] 
>> O(1)

3. 자료구조 
- maxheap 
>> 

[answer idea] - none, just variable


*/
#include <iostream>

using namespace std; 

int main()
{
    long long int A, B, V;
    // long long int counter = 0;
    // int result = 0; 

    cin >> A >> B >> V; 


// 1st - trial (wrong answer, timee over)
    // while(counter < V)
    // {
    //     result++; 
    //     counter += A; 
    //     if(counter >= V) break; 
    //     counter -= B; 
    // }

// 2nd trial 
    long long int result; 

    // result = (V - B) / (A - B); 

// 3rd -trial [final answer]
// 만약 다오르지 않는 나머지 값이 있을때 처리 조건 추가 

    result = ((V - B) % (A - B) != 0 ) ? ((V - B) / (A - B)) +1 : ((V - B) / (A - B)); 


    cout << result; 



    return 0; 
}
