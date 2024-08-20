// 원형 자료구조; index 값의 범위를 활용하는 문제 
// 문제 해석;  "화살표가 가리키는 글자가 변한 숫자" 조건에 대해서 해석하는데 시간이 올래걸림. 
// 1 trial 오답이유. "같은 글자가 2번 이상 등장하지 않는다" 조건 무시... (입력 조건에는 적용이 되어 있지 않으므로 구현이 필요!)

#include <iostream>
#include <algorithm> // find 함수 사용 (중복 조건 확인)
// #include <queue>

using namespace std; 


int reIndex(int curr_index, int num, int N)
{
    int result = curr_index + num; 
    if(result > (N -1)) result -= N;
    return result;  
}

void printStr(char* result, int N, int curr_index)
{
    for(int i = curr_index; i >= 0; i--) cout << result[i];
    for(int i = N-1; i > curr_index; i--) cout << result[i];
}


int main()
{
    int N, K; // N: size, K: rotate number
    // queue<int> chage_num; 
    // queue<char> alpha; 
    int curr_index = 0; 
    char* output; 

    cin >> N >> K; 
// #1. 문자열 초기화 
    output = new char[N]; 
    for(int i = 0; i < N; i++) output[i] = '?'; 

// #2. 입력 삽입 
    for(int i = 0; i < K; i++)
    {
        int num; 
        char alp; 
        cin >> num >> alp; 
        // chage_num.push(num);
        char* dup_check = find(output, output + N, alp); 

        curr_index = reIndex(curr_index,num, N); 
        if(output[curr_index] != '?' && output[curr_index] != alp){curr_index = -1; break;}
        else if(output[curr_index] != alp && dup_check != output + N) {curr_index = -1; break;}
        else
        {
            output[curr_index] = alp; 
        } 
    }

// #3. 출력 
    if(curr_index < 0) cout << "!"; 
    else
    {
        printStr(output, N, curr_index);
    }

    delete output; 
    return 0; 
}