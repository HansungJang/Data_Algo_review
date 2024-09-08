/*
- 모든 경우의 수 확인 
- 깊이가 달라질 때, for-loop 으로는 구현 불가능

[Youtube - 아이디어]

1. 아이디어 
- 백트래킹 재귀함수 안에서, fot 돌면서 숫자 선택(이때 방문여부 확인)
- 재귀함수 M개를 선택경우프린트 ㄴ

- 1부터 N중에 하나를 선택한 뒤
- 다음 1부터 N까지 선택할 때 이미 선택한 값이 아닌 경우 선택 
- M개를 선택할 경우 프린트 

2. 시간복잡도
- 중복이 가능 case, O(N^N) << 1억 (N < 8)
- 중복이 불가능 case, O(N!) << 1억 ( N < 10)

현 문제; 중복 불가 Max: 8 
-> O(N!) 사용가능 

3. 자료구조 
- bool [] 중복 체크 
- int [] 선택한 값 저장 


issue Note 
- 1 trial, 시간초과
>> sol 비트마스킹, 출력 버퍼 사용(I/O 최적화), reference operator사용, .... 
-> 비트마스킹, (30 ~ 31 경우의 수) 작은 크기 해당하는 sol, 우리문제의 경우 적합하지 않음.  
-> 

- 2 trial, fixed 방법 
>> 입출력 동기화를 줄임으로서 연산속도를 개선시킴.   
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> elem; 

void backtrack(bool check[], int N, int M)
{
    if(elem.size() == M) 
    {
        for(int i : elem) cout << i << " ";
        cout << endl; 
        return;  
    }

    for(int i = 1; i <= N; i++)
    {
        if(check[i] == false)
        {
            check[i] = true; 
            elem.push_back(i); 
            backtrack(check, N, M); 
            check[i] = false; 
            elem.pop_back(); 
        }

    }
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; 
    cin >> N >> M; 
    
    bool check[N+1] = {false, }; 
    backtrack(check, N, M);


    return 0; 
}