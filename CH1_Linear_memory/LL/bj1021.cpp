// # 회전하는 큐 
// 3가지 기능 지원 
// #1. pop_front
// #2. move left (front -> back)
// #3. move right (back -> front)

//Goal,  특정 원소 뽑아내는데 2, 3함수를 이용하는 경우의 최소값 출력 
//문제의 point, 순서-1 번쨰의 index가 맨 앞에 오는데 드는 최소 비용을 계산하는 문제 
//맨앞 혹은 맨뒤의 원소로 부터 얼마나 멀리 있는가가 point 



#include <iostream>
#include <queue>

using namespace std; 

void moveLeft(queue<int>& list, int num)
{
    for(int i = 0; i < num; i++)
    {
        int move_elem = list.front(); 
        list.pop(); 
        list.push(move_elem);  
    }
}; 

void moveRight(queue<int>& list, int num)
{
    int index = 0; 
    int* temp = new int[list.size()]; 
    while(list.size() > 0)
    {
        temp[index++] = list.front();   
        list.pop(); 
    }

    // index-=1; 
    for(int i =  index - num; i < index; i++){list.push(temp[i]); }
    for(int i = 0; i < index - num; i++){list.push(temp[i]);}
    delete[] temp; 
}; 

void printOut(queue<int>& list)
{
    while(list.size() > 0){cout << list.front() << ", "; list.pop();}
}

int distance_right(int num, const queue<int> list)
{
    queue<int> trevers = list; 
    int distance = 1; 
    int index = 0; 

    int* temp = new int[trevers.size()]; 
    while(trevers.size() > 0)
    {
        temp[index++] = trevers.front();   
        trevers.pop();  
    }
    // cout << index << endl; 
    index-=1; 
    while(temp[index] != num)
    {
        if(distance > list.size() || index < 0) break; 
        distance++; 
        index--; 
    }

    delete[] temp;
    return distance; 
}

int distance_left(int num, const queue<int>& list)
{
    queue<int> trevers = list; 
    int distance = 0; 
    
    while(trevers.front() != num) 
    {
        distance++;
        trevers.pop(); 
    }
    return distance; 
}

int main()
{
    int N; // list size
    int M; // elemnt number
    int count = 0; 
    queue<int> queue_list; 
    queue<int> index_list; 

    cin >> N >> M; 
    for(int i = 0; i < N; i++){queue_list.push(i+1);}
    for(int i = 0; i < M; i++){int input; cin >> input; index_list.push(input);}

    while(index_list.size() > 0)
    {
        int target = index_list.front(); 
        index_list.pop(); 

        int left = distance_left(target, queue_list);
        int right = distance_right(target, queue_list);
        int min = (left < right) ? left : right; 
        if(min != 0)  
        {
            if(min == left){ moveLeft(queue_list, min); }
            else{ moveRight(queue_list, min); }
        } 

        count += min; 
        queue_list.pop(); 
    }
    // moveLeft(queue_list, 3); 
    // moveRight(queue_list, 4); 
    // printOut(queue_list);

    cout << count; 
    return 0;
}