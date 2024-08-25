// BFS 문제, 
// 그림이 서로 연결 되어있는 정보를 출력 하는 문제 

// s 11 27 e 12 37 (1 - trial )

// idea. 

// 1.  1이 연결된, 우측 or 아래 방향 1이 있는지 확인. 
// 우측 값 [][+1], 아래 [+1][] (ptr + row크기 만큼 떨어져 있다는 것)


// 2. 이미 확인한 자료는 중복해서 확인하면 안됨. <how>
// 방문을 확인하는 값 대체 이미 방문한 elem에 대해서 1대신 2값 / 중복 방지 

// 3. 

// 1. 2중 for Loop 활용 (row * col) 탐색하면서 
// 2. 현재 elem == 1인 경우 (count ++; size ++;), 해당 elem = 2; 
// 연결 탐색을 BFS: queue를 이용하여 탐색 (value가 1인 ptr을 저장)
// curr_index + 1 == 1 or curr_index + row == 1  확인 
// 맞다면  size++; 해당 *index_elem = 2값 변경; 
// 3. 작품의 수, size가 가장큰 것 : algorithm sort함수 이용하여 가장 마지막 값, 크기 저장

// TC. O(N^2) 



// Data_strcture. queue, BFS 

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int row, col; 
    int** canvas; 
    vector<int> art; 


    cin >> row >> col; 
    canvas = new int*[row];
    for(int i = 0; i < row; i++) canvas[i] = new int[col];  

// 입력 
    for(int i =0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int elem; 
            cin >> elem; 
            canvas[i][j] = elem; 
        }
    }

// 그림찾기 
// queue front의 위치부터 (right, down 확인) 추가 
// 종료조건 row > , col > 


    for(int i = 0; i < row; i++)
    {
 
        for(int j =0; j < col; j++)
        {       
            queue<pair<int, int>> posit; 
            int size = 0; 
            if(canvas[i][j] == 1)
            {
                canvas[i][j] = 2; // 방문 check 
                size++; 
                posit.push(make_pair(i, j)); 
            //  탐색     
                while(posit.size() > 0)
                {
                    // if(*(posit.front() + 1) == 1 && (j+1) < col) {posit.push(&canvas[i][j + 1]); size++; canvas[i][j + 1] = 2;}// 우측부터 확인 
                    // if(*(posit.front() + col) == 1 && (i+1) < row) {posit.push(&canvas[i + 1][j]); size++; canvas[i + 1][j] = 2;}// 아래 확인 
                    int x = posit.front().second; 
                    int y = posit.front().first;
                    // if((x+1) < col && (y+1) < row)
                    // {
                    // 조건문 순서 탐색값이 달라짐
                        if((x+1) < col && canvas[y][x + 1] == 1 ) {posit.push(make_pair(y, x + 1)); size++; canvas[y][x + 1] = 2;}// 우측부터 확인 
                        if((y+1) < row && canvas[y + 1][x] == 1 ) {posit.push(make_pair(y + 1, x)); size++; canvas[y + 1][x] = 2;}// 아래 확인 
                        if((x-1) < col && (x-1) > 0  &&  canvas[y][x - 1] == 1 ) {posit.push(make_pair(y, x - 1)); size++; canvas[y][x - 1] = 2;}// 왼쪽 확인 
                        if((y-1) < row && (y-1) > 0  && canvas[y - 1][x] == 1 ) {posit.push(make_pair(y - 1, x)); size++; canvas[y - 1][x] = 2;}// 위 확인 

                    // } 
                    posit.pop(); 
                }

            } 
            if(size > 0) art.push_back(size); 
        }

    }


    sort(art.begin(), art.end());
    cout << art.size() << endl << art.back(); 


    for(int i = 0; i < row; i++) {delete canvas[i];}  
    delete[] canvas; 
    return 0; 
}