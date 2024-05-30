#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, r;
int u, v;
vector<int> graph[100001];
bool visited[100001];
queue<int> q;
int cnt=1;
int res[100001];

void bfs(int first){
    visited[first] = true;
    q.push(first);
    res[first] = cnt;

    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(auto i: graph[num]){
            if(visited[i] == false){
                visited[i] = true; // 방문 처리
                q.push(i);

                // 방문 순서 저장
                cnt++;
                res[i] = cnt;
            }
        }
    }
}

int main(){
    cin >> n >> m >> r;

    for(int i=0; i<m; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        // 내림차순
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    bfs(r);

    for(int i=1; i<=n; i++){
        cout << res[i] << '\n';
    }
    return 0;
}