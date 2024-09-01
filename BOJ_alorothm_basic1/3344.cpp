/*
N-Quuen 구현 문제 
해당 조건을 모두  만족시키는 quene의 자리 index 출력하면 됨. 

- N개의 말을 1개씩 삽입하는 풀이로 접근
- 순서는 첫번째 행에 임의 위치;
- 이후에 2번째 행부터 4가지 조건에 마는지 확인하며 맞다면 다음행으로 넘어감

2. 시간복잡도; O(N^2)
- 1 ~ (n-1)행 까지 for-loop으로 순회, 
- 0 ~ (n-1)번째의 colum이 <4가지 조건을 만족하면> 해당 인덱스 저장, 다음행으로 이동


3. 자료구조; GREEDY or DP 


condition
1. 모든 행에는 최소 1개의 queen이 있다.
2. 모든 행에 1개 초과하는 queen이 있으면 안된다.
3. 모든 열에 1개 초과하는 queen이 있으면 안된다. 
4. 대각선 위 (오른쪽) 1개 초과하는 queen이 있으면 안된다.
5. 대각선 위 (왼쪽) 1개 초과하는 queen이 있으면 안된다.

*/


#include <iostream>
#include <queue>
#include <ctime> // 실핼시간 마다 바뀌게 하기 위해서 
#include <cstdlib> // random 

using namespace std; 


bool condition1(bool** board, int size, int row, int col)
{
    bool check = true; 
    for(int i =0; i < size; i++)
    {
        if(board[row][i] == true){check = false; break;}
    }
    return check; 
}

bool condition2(bool** board, int size, int row, int col)
{
    bool check = true;

    for(int i = 0; i < size; i++)
    {
        if(board[i][col] == true) {check = false;  break;}
    }
    return check; 
}

bool condition3(bool** board, int size, int row, int col)
{
    bool check = true; 
    int crow = row -1; 
    int ccol = col +1; 

    while(crow >= 0 && ccol < size)
    {
        if(board[crow][ccol] == true){check = false; break;}
        crow -= 1; 
        ccol += 1; 
    }
    
    return check; 
}

bool condition4(bool** board, int size, int row, int col)
{
    bool check = true; 
    int crow = row -1; 
    int ccol = col -1; 
    
    while(crow >= 0 && ccol >= 0)
    {
        if(board[crow][ccol] == true){check = false; break;}
        crow -= 1; 
        ccol -= 1; 
    }
    
    return check; 
}


int queen_insert(bool** board, int size, int row)
{
    int index = 0; 
   

    for(int i = 0; i < size; i++)
    {
        bool con1 = condition1(board, size, row, i);
        bool con2 = condition2(board, size, row, i); 
        bool con3 = condition3(board, size, row, i);
        bool con4 = condition4(board, size, row, i);

        if(con1 && con2 && con3 && con4){index = i; break;}
    }

    return index; 
}


int main()
{

    srand((unsigned int)time(NULL)); 
    int size; 
    queue<int> queen_index; 
     
    cin >> size; 
    
    bool col_check[size] = {false, };
    bool board[size][size] = {false, }; 
    bool* boardptr[size]; 
    for(int i = 0; i < size; i++){boardptr[i] = board[i];}

    int first_colum_index = rand() % size; 
    queen_index.push(first_colum_index); 
    
    board[0][first_colum_index] = true; 
    for(int i = 1; i < size; i++)
    {
        int col = queen_insert(boardptr, size, i); 
        board[i][col] = true;  
        col_check[col] = true; 
        queen_index.push(col + 1);
       
    }

    while(queen_index.size() > 0)
    {
        cout << queen_index.front() <<endl; 
        queen_index.pop(); 
    }

    return 0; 
}