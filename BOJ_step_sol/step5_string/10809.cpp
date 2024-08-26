/*
sol idea.
https://cplusplus.com/reference/string/string/find_first_of/
find_first_of 함수 사용
*/

#include <iostream>
#include <string>
#include <cstddef>

using namespace std; 

int main()
{
    string in; 
    int alp[26]; 
    for(int i =0; i < 26; i++) alp[i] = -1; 

    getline(cin, in); 
    for(int i = 97; i < 123; i++)
    {
        char alph = i; 
        size_t first = in.find_first_of(alph); 
        if(first != string::npos)
        {
            alp[i - 97] = first;  
        } 
    }


    for(int i = 0; i < 26; i++){ cout << alp[i] << " "; }
    return 0; 
}