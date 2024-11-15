#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, v; // 정점, 간선, 시작점
int map[1001][1001];
bool visitted[1001]; // 방문 표시

// 방문 표시 초기화
void reset(){
    for(int i = 1; i <= n; i++){
        visitted[i] = false;
    }
}

void dfs(int v){
    // 방문 표시 후 출력
    visitted[v] = true;
    cout << v << " ";

    for(int i = 1; i <= n; i++){
        // 방문하지 않았고, 연결되어 있으면 dfs실행
        if(visitted[i] == false && map[v][i] == 1){
            dfs(i);
        }
    }
}

void bfs(int v){
    queue<int> q;

    q.push(v);
    visitted[v] = true;
    cout << v << " ";
    
    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(visitted[i] == false && map[num][i] == 1){
                q.push(i);
                visitted[i] = true;
                
                cout << i << " ";
            }
        }
    }
}

int main(){

   cin >> n >> m >> v;

   for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        map[a][b] = 1;
        map[b][a] = 1; // 각 점에 방문표시
   }
    dfs(v);
    reset();
    cout << endl;
    bfs(v);
}
