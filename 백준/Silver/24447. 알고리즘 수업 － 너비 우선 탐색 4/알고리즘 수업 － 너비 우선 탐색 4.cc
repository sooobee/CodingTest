#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
typedef long long int LLI;
using namespace std;

int n, m, r;
int u, v;

vector<LLI> graph[100001];
bool visited[100001];
LLI d[100001];
LLI t[100001];
LLI res;
queue<LLI> q;
int cnt = 1;

void bfs(int first){
    visited[first] = true;
    q.push(first);

    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(auto i: graph[num]){
            if(visited[i] == false){
                d[i] = d[num]+1;

                visited[i] = true;
                q.push(i);

                cnt++;
                t[i] = cnt; // 방문 순서 
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
        sort(graph[i].begin(), graph[i].end());
        d[i]= -1; // 깊이 초기화
        t[i] = 0; // 방문 순서 초기화
    }
    
    d[r] = 0;
    t[r] = cnt;

    bfs(r);

    for(int i=1; i<=n; i++){
        res += d[i] * t[i];
    }

    cout << res;

    return 0;
}