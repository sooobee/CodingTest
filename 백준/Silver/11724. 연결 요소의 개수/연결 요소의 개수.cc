#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n, m;
int u, v;
vector<int> graph[1001];
bool visited[1001];
int res;

void dfs(int num){
    res += 1;

    if(visited[num] == true){
        res -= 1;
        return;
    }

    visited[num] = true;
    stack<int> s;
    
    s.push(num);
    
    while(!s.empty()){
        int cur_node = s.top();
        s.pop();

        for(auto i: graph[cur_node]){
            if(visited[i] == false){
                visited[i] = true; // 방문 처리
                
                int next_node = i; 
                s.push(cur_node); // 부모 먼저 넣고
                s.push(next_node); // 자식 넣음
                break;
            }
        }
    }
    return;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        dfs(i);
    }

    cout << res;
}