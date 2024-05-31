#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m, r;
int u, v;
vector<int> graph[100001];
queue<int> q;
bool visited[100001];
int dept[100001];

void bfs(int first){
    visited[first] = true;
    q.push(first);

    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(auto i: graph[num]){
            if(visited[i] == false){
                dept[i] = dept[num] + 1; // 깊이
                visited[i] = true;

                q.push(i);
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
        dept[i] = -1;
    }  

    dept[r] = 0;
    bfs(r);

    for(int i=1; i<=n; i++){
        cout << dept[i] << '\n';
    }
}