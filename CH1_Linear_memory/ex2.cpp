// 다양한 타입의 연산자를 공통된 형신의 데이터 타입으로 변형하여 저장 및 출력 
// Goal, 전체 원소를 빠르게 순회하는 것. 

#include <array>
#include <iostream>
#include <type_traits>

using namespace std; 

template<typename ...Args>
//array<?,?> build_array(Args&& ...args); 

auto build_array(Args&&... args) -> array<typename common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename common_type<Args...>::type; 
    return {forward<commonType>((Args&&)args)...}; 
} 

int main()
{
    auto data = build_array(1, 0u, 'A', 3.2f, true); 

    for(auto i : data)
    {
        cout << i << " "; 
    }
    cout << endl;;     

    return 0; 
}
