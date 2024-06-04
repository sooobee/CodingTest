#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, u, v;
vector<int> graph[100001];
bool visited[100001];
int parent[100001]; // 부모 노드 저장

void bfs(int first){
    queue<int> q;
    q.push(first);
    
    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(auto i: graph[num]){
            if(visited[i] == false){
                visited[i] = true;

                // i의 부모 num을 저장
                parent[i] = num;

                q.push(i);
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i=0; i<n-1; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 1 방문 표시
    visited[1] = true;
    
    bfs(1);

    // 부모 출력
    for(int i=2; i<=n; i++){
        cout << parent[i] << '\n';
    }
   return 0;
}