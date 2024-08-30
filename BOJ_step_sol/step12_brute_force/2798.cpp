/*

# 1-trial: 
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

# 2-trial; 
1. 아이디어: 조합수 만큼 3중 for-loop 

- n_C_3; 전체 가능한 카드의 조합 / 횟수 
- 3중 for-loop으로 1번째(0 ~ n-2), 2번째 (i+1 ~ n-1), 3번째(j+1 ~ n)
// 각 loop의 구조는 안의 인덱스는 무조건 앞의 인덱스보다 커야함. 
- sort 함수를 통해서 찾은값, 내림차순으로 정렬 
- for loop 돌면서 Max값 확인 

2. 시간복잡도: 
- TC(N^3)
카드의 수에 의해서 TC 결정 (MAX: 100)
100_C_3 = (98 * 99 * 100) / (2 * 3) = 161,700  << 1억 
>> 3중 Loop 사용가능

3. 자료구조 
- vector: 
- 3중 for-loop 
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort 
#define card_fac 6 // card factorial value 


using namespace std; 

int SIZE(int size)
{
    int result = 1;
    for(int i = (size -2); i <= size; i++){result *= i;}
    result /= card_fac;  
    return result; 
}

int main()
{
    int size; 
    vector<int> card; 
    vector<int> sum_list; 
    int max = 0; 
    int N, M; // N: card 갯수, M: target값 

    cin >> N >> M; 
    size = SIZE(N); 

    for(int i = 0; i < N; i++)
    {
        int elem; 
        cin >> elem; 
        card.push_back(elem); 
    }

    sort(card.begin(), card.end()); 

    for(int i = 0; i < N -2; i++)
    {
        for(int j = i+1; j < N-1; j++)
        {
            for(int k = j+1; k < N; k++)
            {
                int elem = card[i] + card[j] + card[k]; 
                if(elem > M){break;} 
                sum_list.push_back(elem); 
            }
        }
    }

    sort(sum_list.begin(), sum_list.end()); 

    cout << sum_list.back(); 

    return 0; 
}