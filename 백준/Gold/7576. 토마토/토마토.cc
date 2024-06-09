#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int m, n;
int visited[1001][1001];
int map[1001][1001];
int res; // 전체 걸리는 일수 저장
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool flag;
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //  이미 방문했거나, 범위를 넘어선 경우, 벽일 때
            if(visited[nx][ny] != 0 || nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == -1) continue;
            
            // 안 익은 토마토의 경우
            if(map[nx][ny] == 0){
                q.push({nx, ny});
                // 방문 순서 저장
                visited[nx][ny] = visited[x][y] + 1;
                res = visited[nx][ny];
            }
        }
    }
}

int main(){
    cin >> m >> n;

    // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                q.push({i, j}); // 1인 값을 큐에 넣음
                visited[i][j] = 1; // 방문 처리
            }
        }
    }

    bfs();
    
    // 익지 못한 토마토가 있는 경우 flag로 체크
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && visited[i][j] == false){
                flag = true; 
            }        
       }
    }

    // 토마토가 하나라도 익지 못한 상태
    if(flag){
        cout << "-1";
    // 저장 될 때부터 모든 토마토가 익은 경우
    } else if(res == 0){
        cout << "0";
    }
    // 시간이 지나 토마토가 모두 익은 경우
    else {
        cout << res-1; // 시작을 1에서 해줬으므로 빼줘야함
    }

    return 0;
}