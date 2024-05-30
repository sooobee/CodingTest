#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define LLI long long int


int n, m, r;
int u, v;

vector<LLI> graph[100001]; 
bool visited[100001];
LLI t[100001]; // 방문 순서
LLI d[100001]; // 깊이
LLI cnt;
LLI res;

void dfs(int num){
    visited[num] = true;
    cnt++;
    t[num] = cnt;

    for(auto i: graph[num]){
        if(visited[i] == false){
            d[i] = d[num]+1;
            dfs(i);
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
        sort(graph[i].begin(), graph[i].end(), greater<LLI>());
        t[i] = 0; // 방문 순서 전부 0으로 초기화
    }

    d[r] = 0;
    dfs(r);

    for(int i=1; i<=n; i++){
        res += d[i]*t[i];
    }
    cout << res;

    return 0;
}