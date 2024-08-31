/*
Goal, 가장 둘레의 길이가 큰 삼가형을 만드는 것 
1. 아이디어
- 삼각형의 성립 조건: 삼각형의 가장긴변 < 나머지 두변의 합.
-  Loop를 이용하여 가장긴변이 조건 성립하는지 확인
>> 조건 성립하면 stop

#필요함수 
3변중 최댓값을 찾는 함수 
두변의 합 > 긴변 조건 확인 

2. 시간복잡도
- O(N) // 가장 긴 변의 길이 조건
// N의 max값이 100 << 1억 
//사용가능  
3. 자료구조 
- vector, Linked List 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define tri 3 

using namespace std; 


int main()
{
    vector<int> sides; 
    int max, others; 

    for(int i =0; i < tri; i++)
    {
        int elem; 
        cin >> elem; 
        sides.push_back(elem); 
    }
    

    do
    {
        sort(sides.begin(), sides.end()); 
        max = sides.back(); 
        others =  sides[0] + sides[1];
        if(max >= others)
        {
            sides[2] = sides.back() - 1; 
        } 
    }while(max >= others); 

    int max_sum = 0; 
    for(int i = 0; i < tri; i++)
    {
        max_sum += sides[i]; 
    }

    cout << max_sum; 
    return 0; 
}