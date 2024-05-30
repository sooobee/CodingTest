#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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

        // first와 연결되어 있는 모든 노드를 방문하고 큐에다 넣음    
        for(auto i: graph[num]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
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

    // 정렬
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(r);

    for(int i=1; i<=n; i++){
        cout << res[i] << '\n';
    }
    return 0;
}