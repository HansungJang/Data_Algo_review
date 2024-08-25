/*
아이디어,   / 10  switch 문으로 점수 분할 출력 
TC O(N)
자료구조 - 
*/

 #include <iostream>

 using namespace std; 

 int main()
 {
    int score; 
    cin >> score; 
    switch(score / 10)
    {
        case 10:
        case 9: cout << 'A' << endl; break; 
        case 8: cout << 'B' << endl; break; 
        case 7: cout << 'C' << endl; break;
        case 6: cout << 'D' << endl; break; 
        default: cout << 'F' <<endl; break; 
    }

    return 0; 
 }