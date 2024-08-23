// // DUMMY 게임 규칙 
// // intial: start: [0][0] index, 길이: 1 
// // size : N * N 
// // 맵에 사과, 길이 +1 
// // 처음 이동은 오른쪽 
// // 벽에 닿거나 자기자신에게 닿으면 over 


// #include <iostream>
// #include <queue>
// #include <algorithm>
// //#include <utility>

// using namespace std; 

// typedef struct 
// {
//     int y; 
//     int x;
// } snake_elem; 

// // 뱀의 이동
// // [][+1] : r,  [+1][]: down , [][-1] : l, [-1][]: up : 시계방향  
// // D: 시계방향 L: 반시계방향 


// typedef struct 
// {
//     int time; 
//     char rotate;
// } move_rotate; 


// class snake
// {
//     private: 
//         queue<snake_elem> body; 
//         int size;
//         char move; 

//     public: 
//     snake()
//     {
//         snake_elem intial; 
//         intial.x = intial.y = 0; 
//         body.push(intial);

//         size = 1; 
//         move = 'r'; 
//     }
//     void movesnake(int **gamefield) // [y][x] 뱀이 한칸 이동하는 함수 
//     {
//         snake_elem move_elem; 

//         if(move == 'r')
//         {
//             move_elem.x = body.back().x + 1;
//             move_elem.y = body.back().y; 
//         }
//         else if(move == 'u')
//         {
//             move_elem.x = body.back().x;
//             move_elem.y = body.back().y -1; 
//         } 
//         else if(move == 'l')
//         {
//             move_elem.x = body.back().x -1;
//             move_elem.y = body.back().y; 
//         }
//         else 
//         {
//             move_elem.x = body.back().x;
//             move_elem.y = body.back().y +1; 
//         }

//         body.push(move_elem);
//         if(gamefield[move_elem.y][move_elem.x] != 1) body.pop(); 
//     }; 

//     bool gameover()
//     {
//         bool result = false; 
//         // head: back()의 정보를 통해서 알 수 있음
//         // #1. head가 tail 겹치는 순간 
//         // #2. 벽을 통과한 순간 

//         snake_elem head = body.back();  
//         snake_elem tail = body.front(); 

//         result = find(body.front(), body.back(), head); 



//         // if(head.x)



//     }; 

//     void insertBody(){}; 
//     void setmove(){}; 
 
// }; 


// int main()
// { 
//     queue<snake_elem> snake;
//     // snake_elem* apple_position; 
//     queue<move_rotate> move_point; 

//     char snake_move = 'r'; // 뱀의 이동 방향 
//     int size = 1; 
//     int apples; 
//     int rotate_num; 
//     int count = 0 ; // 게임 종료 시간 확인

//     int** gamefield; 

// // #1. 게임 field 크기 설정 입력받기 
//     cin >> size; 
//     gamefield = new int*[size];
//     for(int i = 0; i < size; i++){gamefield[i] = new int[size];}
//     for(int i = 0; i < size; i++) // 초기화 
//     {
//         for(int j =0; j < size; j++)
//         {
//             gamefield[i][j] = 0; 
//         }
//     }

//     cin >> apples; 
//    // apple_position = new snake_elem[apples]; 
//     for(int i =0; i < apples; i++)
//     {
//         int x, y; 
//         cin >> x >> y; 
//         x -=1; y-=1;
//         gamefield[x][y] = 1; // 1: apple 의미 
//     }

//     cin >> rotate_num; 

//     for(int i =0; i < rotate_num; i++)
//     {
//         move_rotate minfo; 
//         int move_time; 
//         char movepoint; 

//         cin >> move_time >> movepoint; 
//         minfo.time = move_time; 
//         minfo.rotate = movepoint;

//         move_point.push(minfo);  
//     }


// // #2. 게임 




//     for(int i = 0; i < size; i++){delete[] gamefield[i];}
//     delete gamefield; 
//     return 0; 
// }

// [참조] https://hagisilecoding.tistory.com/82
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, t1, t2 , k;
    int map[102][102] = {0};
    bool visit[102][102] = {false};
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> t1 >> t2;
        map[t1 - 1][t2 - 1] = 1;
    } // 문제에서 원점을 1,1을 기준으로 하고 있고 나는 0,0을 원점으로 하기위해서 -1해줌.
 
    int cnt = 0;
    char t3;
 
    int dx[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상
    int dy[4] = {0, 1, 0, -1};
    int dir = 0;
    int x = 0;
    int y = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int bt1 = 0;
    int l;
    cin >> l;
    for (int i = 0; i < l;i++){
        cin >> t1 >> t3;
        
        while(cnt < t1 || i == l-1){ 
            // 마지막 입력까지 게임이 끝나지 않을 경우 뱀을 끝날때까지 보내줘야함.
            cnt++;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
 
            if(nx >=0 && ny >=0 && nx<n && ny<n && !visit[ny][nx]){
                // 게임이 끝나지 않을 조건
                if(map[ny][nx] == 1){ // 사과를 먹었을 때
                    map[ny][nx] = 0; // 사과 없애주고
                    q.push(make_pair(nx, ny)); // 몸 좌표에 추가
                    visit[ny][nx] = true; // 몸 있다는걸 좌표 표시
                }else{// 사과 없을 때
                    q.push(make_pair(nx, ny)); 
                    visit[ny][nx] = true; 
                    visit[q.front().second][q.front().first] = false;
                    // 꼬리 부분없애주기
                    q.pop();
                }
            }else{
                cout << cnt;
                return 0;
            }        
            x = nx;
            y = ny;
            if(cnt == t1){
                if(t3 == 'D'){ // 우측 회전
                    dir = (dir + 1) % 4; 
                }else{ // 좌측 회전
                    dir = (dir + 3) % 4;
                }
            }
        }
    }
    return 0;
} // 1h