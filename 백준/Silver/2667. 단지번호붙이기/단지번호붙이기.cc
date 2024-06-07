#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[25][25];
bool visited[25][25];
vector<int> res;
int cnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    visited[x][y] = true; 

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 이미 방문한 경우
        if(visited[nx][ny] == true) continue;

        // 좌표를 넘어선 경우
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        // 0인 경우
        if(map[nx][ny] == 0) continue;

        cnt += 1;  // cnt는 방문한 칸의 개수
        dfs(nx, ny);
    }
}

int main(){
    cin >> n;

    // 입력 받음
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == true) continue;
            if(map[i][j] == 0) continue;
            else {
                cnt = 1;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    
    for(int i: res){
        cout << i << '\n';
    }
    return 0;

}