#include<iostream>
#include<algorithm>
using namespace std;

int n, m, r;
int u, v;
int cnt = -1;
vector<vector<int>> graph;
int visited[100001];

void dfs(int num){

     for(auto i: graph[num]){
        if(visited[i] == -1){
            visited[i] = visited[num]+1;
            dfs(i);
        }
    } 
}

int main(){
    cin >> n >> m >> r;

    graph.resize(n+1);

    // 모두 -1로 채움
    fill_n(visited, n+1, -1);

    for(int i=0; i<m; i++){
        cin >> u >> v; 

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<n+1; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    visited[r] = 0;
    dfs(r);

    for(int i=1; i<n+1; i++){
        cout << visited[i] << '\n';
    }
   
    return 0;
}