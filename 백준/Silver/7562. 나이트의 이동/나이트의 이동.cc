#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int tc;
int l;
bool visited[301][301];
int res[301][301]; // 깊이 저장

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int s1, int s2, int e1, int e2){
    queue<pair<int, int>> s;

    s.push({s1, s2});
    visited[s1][s2] = true; // 첫 값 방문 표시

    while(!s.empty()){
        int x = s.front().first;
        int y = s.front().second;
        s.pop();

        if(x == e1 && y == e2) break; // 목적지에 도달하면 종료

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 판의 범위를 넘어서는 경우
            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;

            // 이미 방문한 경우
            if(visited[nx][ny] == true) continue;

            // 연결된 자식에서 다시 탐색
            s.push({nx, ny});  
            visited[nx][ny] = true; // 방문 표시
            res[nx][ny] = res[x][y] + 1; // 깊이 저장
                
           
        }
    }
}

int main(){
    cin >> tc;

    for(int i=0; i<tc; i++){

        cin >> l;

        // 값을 입력 받음(시작점과 끝점)
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;

        // 초기화(방문, 깊이)
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                visited[i][j] = false;
                res[i][j] = 0;
            }
        }

        res[s1][s2] = 0;
        bfs(s1, s2, e1, e2);

        cout << res[e1][e2] << "\n";
    }    
}