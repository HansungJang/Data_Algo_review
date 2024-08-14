// # remove_if 함수 구현 (특정 조건에 해당하는 형식 삭제)

#include <string>
#include <iostream>
#include <forward_list>


using namespace std; 


struct citizen
{
    string name; 
    int age; 
}; 

ostream &operator<<(std::ostream &os, const citizen &c)
{
    return (os << "[" << c.name << ", " << c.age << "]"); 
}


void print_citizen(forward_list<citizen> citizens)
{
    for(const auto &c : citizens)
        cout << c << " ";
    cout << endl; 
}

int main()
{
    forward_list<citizen> citizens = {{"kim", 22}, {"Cim", 16}, {"aim", 28},{"dim", 14}}; 
    auto citizens_copy = citizens; 

    cout << "Total citizen: "; 
    print_citizen(citizens); 
    // for(const auto &c : citizens)
    //     cout << c << " ";
    // cout << endl; 

    
    // #1. remove_if 적용 
    // 투표권이 없는 시민 (age < 19) 이하인 시민 제거 
    // remove_if는 조건을 만족하는 member를 삭제함. 

    citizens.remove_if([](const citizen &c)
    {
        return (c.age < 19); 
    });  
    print_citizen(citizens);

    // #2. 청소년 출력
    citizens_copy.remove_if([](const citizen &c)
    {
        return (c.age > 19); 
    });  
    print_citizen(citizens_copy);

    return 0; 
}