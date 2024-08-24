/*
전체 크기 100 100 
색종이 10, 정사각형 

가장 위변의 모서리 위치, 위변의 모서리 y + 10 위치 제공
겹치는 범위 구하여 제거하면 되는 문제 
-> sol 색종이가 다른 색종이의 영역에 있는지 판별하는 함수 
-> 겹치는 면의 시작점, 끝점 


2차원 배열
- 전체 도화지 크기 100 * 100; 
- 색칠된 부분면적 구하는 문제; 

- 주어진 index로부터 10 * 10 영역 색칠하는 함수 
- 색칠된 부분 count 
- 색칠한 부분인지 확인하는 함수 


O(n^2) // n: 100 100 * 100 < <1억> 따라서 사용가능 

*/

#include <iostream>
#define Size 100

using namespace std; 

void markarea(bool** board, int x, int y )
{
    int dx =  x; 
    int dy = (100 - y) - 10; 

    for(int i = 0; i < 10; i++)
    {
        for(int j =0; j < 10; j++)
        {
            if(board[dy + i][dx + j] == false)
            {
                board[dy + i][dx + j] = true; 
            }
        }
    }
}

int main()
{
    bool** board = new bool*[Size]; 
    for(int i = 0; i < Size; i++)
    {
        board[i] = new bool[Size]; 
    } 

    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            board[i][j] = false; 
        }
    }

    int color_p_num; 

    cin >> color_p_num; 
    for(int i = 0; i < color_p_num; i++)
    {
        int x, y; 
        cin >> x >> y; 
        markarea(board, x, y); 
    }


    int area = 0; 
    for(int i = 0; i < Size; i++)
    {
        for(int j =0; j < Size; j++)
        {
            if(board[i][j] == true) area++; 
        }
    }

    cout << area; 

    for(int i = 0; i < Size; i++)
    {
        delete board[i]; 
    } 
    delete[] board; 
    return 0; 
}