/*
단어 뒤집기 
- 단어의 순서 유지 / queue 
- 단어의 반전 / vector 

1. 아이디어 
- for-loop 돌면서 문자열 저장 queue 
- 저장한 문자열 공백 기준으로 substr, find, vector  
- 좌우반전 / return string 으로 받고  ( swap / vector.push_pop() 원리 이용)
- queue.front() 문자열을  문자 단위로 vector에 저장, vector.size() > 0 반복 

2. 시간복잡도 
- O (n)
// 전체 문장의 수(n) * maximum 단어의 수 << 500  
// 따라서, TC << T(500 * n) 이므로 
// 문장이 1억께 미민인 경우 연산이 가능 

3. 자료구조 
- 선형자료구조 (queue, stack)
- queue, vector 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std; 


void swapWord(string word)
{
    vector<char> copy;
    for(int i = 0; i < word.length(); i++)
    {
        copy.push_back(word[i]); 
    }  

   while(copy.size() > 0)
    {
        cout << copy.back();
        copy.pop_back();  
    }
}


int main()
{
    int size; 
    queue<string> str_list; 

    cin >> size; 
    cin.ignore(); 
    for(int i = 0; i < size; i++)
    {
        string elem; 
        getline(cin, elem); 
        str_list.push(elem);
    }


    while(str_list.size() > 0)
    {
        string str1 = str_list.front(); 
        str_list.pop(); 

        while(str1.length() > 0)
        {
            size_t pos = str1.find_first_of(" ");
            string word = str1.substr(0, pos);
            str1 = str1.substr(pos + 1);

// 단어 반대로 
            swapWord(word); 
            cout << " ";  

            if(pos == str1.length())
            {
                swapWord(str1);
                break;
            }  // 문자열내 공백이 없는 경우 마지막 단어
        }
        if(str_list.size() > 0) cout << endl; 
    }
    return 0; 
}