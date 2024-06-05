#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int w, h;
int x, y;
int graph[51][51];
int visited[51][51];
int res;

// 상하좌우, 대각선 4개
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1 };
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1 };

void dfs(int a, int b){
    stack<pair<int, int>> s;
    s.push({a, b});

    visited[a][b] = true;

    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;

        s.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 1이 아니면 나감
            if(graph[nx][ny] != 1) continue;

            // 좌표 범위를 벗어나는 경우
            if( nx < 0 || nx >= h || ny < 0 || ny >= w) continue; 
            
            // 방문 안한 경우(1이고, 좌표 범위를 벗어나지 않았고, 방문도 안한 경우)
            if(visited[nx][ny] == false){
                visited[nx][ny] = true; // 방문표시

                s.push({x, y});
                s.push({nx, ny});
                break;
            }
        }
    }
    res += 1;
}

int main(){
    while(1){
        cin >> w >> h;
        
        if(w == 0 && h == 0) break;
        // 초기화
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                visited[i][j] = 0;
                graph[i][j] = 0;
            }
        }
        res = 0;

        // 맵을 입력 받음
        for(int i=0; i < h; i++){
            for(int j=0; j < w; j++){
                cin >> graph[i][j];
            }
        }

        for(int i=0; i < h; i++){
            for(int j=0; j < w; j++){
                
                // 방문하지 않았고, 1인 칸에 대해 dfs를 실행
                if(graph[i][j] == 1 && visited[i][j] == false){
                    dfs(i, j);
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
