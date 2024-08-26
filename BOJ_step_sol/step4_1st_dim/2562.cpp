/*
9개 입력 정수 중에서 최대값, 해당 값의 index 출력 
algorithm, find 를 사용할수도 있지만 해당 부분 실행시간 상수배 만큼 증가 

big-o notaion
O(3*n) 시간, 
그냥 입력시에 해당 값을 비교한다면 O(n) 시간에 끝낼수 있는 작업; 
단 해당비교를 위해서 별도의 변수 : maxnum, max_index 를 위한 공간이 추가로 필요하다는 부분이 있지만 
TC >> SC보다 의미있다고 판단하여 

for-loop를 이용한 풀이로 진행 
 */

#include <iostream>
#define size 9

using namespace std; 
int main()
{
    int number[size] = {0,}; 
    int maxnum = 0, maxindex = 0; 

    for(int i = 0; i < size; i++)
    {
        cin >> number[i]; 
        if(number[i] > maxnum)
        {
            maxnum = number[i];
            maxindex = i; 
        }
    }

    cout << maxnum << endl << (maxindex + 1) << endl; 

    return 0; 
}