#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int n;
int map[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dis[101];

void bfs(int a, int b, int k){
    queue<pair<int, int>> q;

    visited[a][b] = true;

    q.push({a, b});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 물에 잠기는 칸은 세지 않음
            if(map[nx][ny] <= k) continue;

            // 방문한 칸일 때
            if(visited[nx][ny] == true) continue;

            // 칸의 영역을 벗어난 경우   
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main(){
    cin >> n;

    // 맵 입력받음
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    // k= 0~100
    for(int k=0; k<=100; k++){
        int cnt = 0;

        for(int i=0; i<n; i++){
            fill_n(visited[i], n, false);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // 방문하지 않았고, 물에 잠기지 않는 칸에 대하여 bfs 실행
                if(visited[i][j] == false && map[i][j] > k){
                    bfs(i, j, k);
                    cnt += 1; // bfs 호출 개수가 영역의 개수
                }
            }
        }
        dis[k] = cnt;  
    }

    int max = 0;
    for(int i=0; i<=100; i++){
        if(dis[i] > max) max = dis[i];
    }

    cout << max;

}