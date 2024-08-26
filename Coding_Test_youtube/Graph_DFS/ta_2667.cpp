// https://nanyoungkim.tistory.com/62

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
int map[25][25];
int visited[25][25];
vector<int> cntVec;
 
//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int N;
int cnt;
 
void dfs(int r, int c){
 
    for(int i = 0; i<4; i++){
        
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr>=N || nr<0 || nc>=N || nc<0) continue;
        
        if(visited[nr][nc]==0 && map[nr][nc]==1){   //방문 안했고 집이 있으면
            visited[nr][nc] = 1;                    //방문했다고 표시하고
            cnt+=1;                                 //집 개수 세기
            dfs(nr,nc);
        }
    }
 
}
 
 
int main(){
    
    int res=0;
    
    cin >> N;
    string str;
    
    for(int i = 0; i<N; i++){
        cin >> str;
        for(int j = 0; j<str.length(); j++){            //입력 주의
            visited[i][j] = 0;
            
            if(str[j] == '1'){
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }
    
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if(map[i][j]==1 && visited[i][j]==0){
                visited[i][j] = 1;
                cnt = 1;                        //처음은 시작점 포함하므로 1로 초기화
                dfs(i,j);
                cntVec.push_back(cnt);
                res++;                          //단지 그룹 1개 탐색 끝남
            }
        }
    }
    
    sort(cntVec.begin(), cntVec.end());
    cout << res << "\n";
    
    for(int i = 0; i<cntVec.size(); i++){
        cout << cntVec[i] << "\n";
    }
 
    return 0;
}