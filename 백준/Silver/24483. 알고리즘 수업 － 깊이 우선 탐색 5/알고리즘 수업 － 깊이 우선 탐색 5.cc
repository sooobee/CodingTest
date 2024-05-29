#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, r;
int u, v;
bool visited[100001]; // 방문 체크
long long int t[100001]; // 방문 순서
long long int d[100001]; // 깊이
int cnt;
long long int res;

vector<int> graph[100001];

void dfs(int num){
    visited[num] = true;
    cnt++;
    t[num] = cnt; // 방문 순서 저장

    for(auto i: graph[num]){
        // 방문하지 않은 노드의 경우
        if(visited[i] == false){
            // 깊이 저장
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

    // 오름차순 정렬
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
        
        // 모든 노드의 깊이를 -1로 초기화
        d[i] = -1;
    }

    d[r] = 0;
    dfs(r);

    for(int i=1; i<=n; i++){
        res += t[i]*d[i];
    }

    cout << res;

    return 0;
}