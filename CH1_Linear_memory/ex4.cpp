#include <iostream>
#include <forward_list>
#include <vector>

using namespace std; 

int main()
{
    // #1. vector을 사용하여 멤버에 접근, 접근시간 상수! 
    vector<string> winner = {
        "Max Verstappen",   // 2023
        "Max Verstappen",   // 2022
        "Esteban Ocon",     // 2021
        "Lewis Hamilton",   // 2020
        "Lewis Hamilton",   // 2019
        "Lewis Hamilton",   // 2018
        "Sebastian Vettel", // 2017
        "Lewis Hamilton",   // 2016
        "Sebastian Vettel", // 2015
        "Daniel Ricciardo"  // 2014
    };

    auto it = winner.begin(); // 상수시간 | 데이터에 접근하는데 걸리는 시간
    cout << "Current winner : " << *it << endl; 
    it += 8; // constant time, random access iterator 
    cout << "Last 8 years ago, winner : " <<  *it << endl; 
    advance(it, -3); 
    cout << "After 3 years later winner : " << *it <<endl;


    // #2. forward_list를 이용하여 멤버에 접근, 접근 시간 데멤버 순서에 선형! 
    forward_list<string> fwd(winner.begin(), winner.end()); 
    
    auto it1 = fwd.begin(); 
    cout << "Current winner : " << *it1 << endl;

    advance(it1, 5); // linear time, forward iterator 
    cout << "Last 5 years ago, winner : " <<  *it1 << endl;
 
    advance(it1, -3); // cannot access, forward iterator는 증가연산 밖에 안됨.  // with error! segementaiton error occur!  
    cout << "Last 3 years ago, winner : " <<  *it1 << endl;
    


    return 0; 
}