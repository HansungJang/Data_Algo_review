/*
1. idea.


배열 만들기 
DP 문제 
0-1 knapsack 

row: 해당행의 index 값의 카드가 포함된 경우의 수 
col: n-1_C_2 = (n-1) * (n-2) / 2  
조합이 가능함을 표현하는 boolean table



카드 내림차순 정렬
최대값 저장 및 갱신 
합이 M초과 종료 

2. 시간복잡도: O(n^3)
>> n max: 100, 따라서 10^6 << 1억(10^8) 사용가능 

3. 자료구조 

*/

#include <iostream>
#include <vector>

using namespace std; 

int main()
{

    vector<vector<int>> card; 
    int win = 0; 
    int N, M; // N: card 갯수, M: target값 

    cin >> N >> M; 
    


    return 0; 
}