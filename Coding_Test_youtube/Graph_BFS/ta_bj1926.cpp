/*
1. ���̵�� 
- 2�� For Loop => ��: 1, �湮 X  => BFS 
- BFS ���鼭 �׸� ���� +1, �ִ��� ���� 

2. �ð����⵵ 
[���� �����ڷ�] https://velog.io/@jiyaho/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%8B%9C%EA%B0%84-%EC%A0%9C%ED%95%9C%EA%B3%BC-%EC%8B%9C%EA%B0%84-%EB%B3%B5%EC%9E%A1%EB%8F%84

- BFS : O(V + E) 
// queue�� �ְ� ���� ����: O(2V) ~= O(V), Queue�� ���� ���� elemet�� Ȯ���ϴ� �۾� edge: O(E)
- V: row * col; 
- E: 4 * V (������ 4����(up, down, left, right))
- V + E: maximum value,  500(row) * 500(col) * 5 = 1,250,000 < 1�� (1�� CPU �ִ� ���� ����)
// ����, TC O(V + E) �˰����� ��밡�� 
// Data���� 500 ����, O(N ^ 3) ������ TC ��밡��

3. �ڷᱸ�� 
- �׷��� ��ü ���� : int [][]
- �湮 bool [][] 
- Queue(BFS) // �׸� Ž�� 

*/


// issue note, 
// 1. BFS Ž�� ���� if�� (�������� ����, Ž������) 2������ �����Ͽ� ������ �����Ϸ��� �ϴ� ���ǹ� ��� �ش� �������� ���� ���� �߻� 
// -> sol, ���� �� Ż�� �������� �������� ���
// 2. element Ž�� ���� 4���� �� visit �迭 (�ʱ�ȭ �κ�) -> �ʱ�ȭ�� false ����, �湮�� true�� ���� ǥ�� 
// 3. segemntation fault(���ǹ� && ���굵 ������ ����) �� access empty container(queue.empty() �� ��Ȳ���� �ش� elemnt �� �����Ϸ����ϴ� ���) run-time error�� �߻��ϴ� ���ǹ����� ����� ��.  

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std; 

int art_BFS(vector<vector<int>>& map, vector<vector<bool>>& map_visit, int  i, int j, int row, int col)
{
    int count = 1; 
    queue<pair<int, int>> art; 
    int dx[] = {1 , 0, -1, 0}; 
    int dy[] = {0, 1, 0, -1}; 


    art.push(make_pair(i, j)); 
    map_visit[i][j] = true; 
    while(art.size() > 0)
    {
        int x = art.front().second; 
        int y = art.front().first; 
        art.pop(); 

        for(int dir = 0; dir < 4; dir++)
        {

            int nx = x + dx[dir]; 
            int ny = y + dy[dir]; 

            if(nx < 0 || ny < 0 || nx >= col || ny >= row) continue; 
            
            if(map[ny][nx] == 1 && map_visit[ny][nx] == false)
                {
                    art.push(make_pair(ny, nx));
                    map_visit[ny][nx] = true; 
                    count++; 
                }
        }

    }

    return count; 
} 



int main()
{
    int row, col; 
    vector<vector<int>> map; 
    vector<vector<bool>> map_visit; 
    vector<int> art_size; 

    cin >> row >> col; 

    for(int i = 0; i < row; i++)
    {
        vector<int> elem_map; 
        vector<bool> elem_m_visit; 
        for(int j = 0; j < col; j++)
        {
            int elem; 
            cin >> elem; 
            elem_map.push_back(elem); 
            elem_m_visit.push_back(false);
        }

        map.push_back(elem_map); 
        map_visit.push_back(elem_m_visit); 
    }


    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(map[i][j] == 1 && map_visit[i][j] == false)
            {
                int size = art_BFS(map, map_visit, i, j, row, col);
                art_size.push_back(size);  
            }
        }
    }

    sort(art_size.begin(), art_size.end()); 
    cout << art_size.size() << endl; 
    if(!art_size.empty()) cout << art_size.back(); 
    else{cout << 0 ; }

    return 0; 
}