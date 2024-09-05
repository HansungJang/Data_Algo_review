/*
가장 많이 사용된 단어 갯수 출력 

1. 아이디어
- 문자열 ascii 코드 변환
- index값 count, 최대 번호 인덱스 출력

2. 시간복잡도 
- O(N) , 입력받은 문자열의 길이, 알파벳 순서 
max N << 1억 사용가능 

3. 자료구조 
- 배열 

*/

#include <iostream>
#define alpsize 26 

using namespace std; 

void Convert(string& str1)
{
    for(int i = 0; i < str1.length(); i++)
    {
        char elem = str1[i];
        if(elem >= 97 && elem < 123) // 소문자의 경우
        {
            elem -= 32;
            str1[i] = elem; 
        }
    }
}

int* Countalp(string& str1)
{
    int alp[alpsize] = {0, }; 
    int* alpptr = alp; 

    for(int i = 0; i < str1.length(); i++)
    {
        int elem_index = str1[i] - 65; 
        alp[elem_index]++; 
    }

    return alpptr; 
}


char Findmax(int* alp)
{
    int max = 0; 
    int multi = 0; 
    char max_char; 

    for(int i = 0; i< alpsize; i++)
    {
        if(max < alp[i])
        {
            multi = 0; 
            max = alp[i]; 
            max_char = i + 65; 
        }

        else if(max == alp[i] && max > 0)
        {
            multi = 1; 
            max_char = '?'; 
        }
    }

    return max_char; 
} 

int main()
{
    string input; 
    char max; 
    int* alplist; 

    getline(cin, input); 
    Convert(input); 
    alplist = Countalp(input);
    max = Findmax(alplist); 

    cout << max; 
    return 0; 
}