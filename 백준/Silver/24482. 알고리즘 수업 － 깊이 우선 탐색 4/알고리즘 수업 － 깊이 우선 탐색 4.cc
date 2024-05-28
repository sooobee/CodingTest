#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, r; 
vector<int> graph[100001];
bool visited[100001];
int res[100001];

void dfs(int num){
    visited[num] = true;

    for(auto i: graph[num]){
        if(visited[i] == true) continue;

        res[i] = res[num]+1;
        dfs(i);
    }
}

int main(){
    cin >> n >> m >> r;

    for(int i=0; i<m; i++){
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 내림차순 정렬
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end(), greater<int>());
        res[i] = -1;
    }

    res[r] = 0;
    dfs(r);

    for(int i=1; i<=n; i++){
        cout << res[i] << '\n';
    }
    return 0;
}