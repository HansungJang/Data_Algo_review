// 원형 자료구조; index 값의 범위를 활용하는 문제 
// 바퀴에 같은 글자는 두 번 이상 등장하지 않는다.
// 또, 바퀴는 시계방향으로만 돌아간다. 


// 문제 해석;  "화살표가 가리키는 글자가 변한 숫자" 조건에 대해서 해석하는데 시간이 올래걸림. 
// 1 trial 오답이유. "같은 글자가 2번 이상 등장하지 않는다" 조건 무시... (입력 조건에는 적용이 되어 있지 않으므로 구현이 필요!)

#include <iostream>
#include <algorithm> // find 함수 사용 (중복 조건 확인)
#include <queue>

using namespace std; 


int reIndex(int curr_index, int num, int N)
{
    int result = curr_index + num; 
    // if(result > (N -1)) result -= N;
    if(result > (N -1)) result %= N; // 1 trial에서 error가 발생한 이유
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

        curr_index = reIndex(curr_index, num, N); 
        if(output[curr_index] != '?' && output[curr_index] != alp){curr_index = -1; break;}
        // else if(dup_check != output + N && dup_check != output + curr_index) {curr_index = -1; break;}
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

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// int N, K;
// void setpan(vector<char> &pan) {
// 	for (int i = 0; i < N; i++) {
// 		pan[i] = '?';
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false); 
//     //C++ 표준 스트림들이 C표준 스트림들과 각각의 입출력 연산 후에 동기화 여부 설정
//     //c / c++ 입출력 형식의 혼용하여 사용하는 것을 허용할 것인지 확인하는 문법
//     //[reference] https://hegosumluxmundij.tistory.com/54  
// 	cin.tie(0); cout.tie(0);
// 	cin >> N >> K;
// 	vector<char> pan(N);
// 	setpan(pan);
// 	int index;
// 	for (int i = 0; i < K; i++) {
// 		int count; char tmpc;
// 		cin >> count >> tmpc;
// 		if (i == 0) { pan[0] = tmpc; index = 0; continue; }
// 		index = (count + index) % N;
// 		//돌렸을 때 같은문자(같은 자리)는 나올 수 있다. 그것마저 아니면 틀린 원판
// 		if (pan[index] != '?'&& pan[index] != tmpc) { cout << "!"; return 0; }
// 		else {
// 			pan[index] = tmpc;
// 		}
// 	}
// 	//중복체크
// 	for (int i = 0; i < N; i++) {
// 		for (int j = i + 1; j < N; j++) {
// 			if(pan[i]!='?' &&pan[i]==pan[j]) { cout << "!"; return 0; }
// 		}
// 	}
// 	for (int i = 0; i < N; i++) {
// 		cout << pan[index];
// 		index--;
// 		if (index == -1) index = N - 1;
// 	}
// 	return 0;
// }