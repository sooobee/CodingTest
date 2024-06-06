#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, m;
int u, v;
vector<int> graph[2001];
bool visited[2001];
int cnt[2001];
bool flag;

void dfs(int num){
    // 5개의 노드가 연결되어 있을 경우 빠져나옴
    if(cnt[num] == 5){
        flag = true;
        return;
    }

    // 연결된 노드 탐색
    for(int i: graph[num]){
        if(visited[i] == false){
            visited[i] = true; // 방문 처리
            cnt[i] = cnt[num] + 1; // 깊이 저장
            dfs(i);
        }

    }
    // 연결된 노드 전부 방문했을 때 본인을 방문처리 초기화 시켜준다.!!!!
    visited[num] = false;
}


int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 노드 탐색
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            visited[i] = true; // 첫노드 방문 표시
            cnt[i] = 1;
            dfs(i);
        }

        // 하나라도 만족하는 경우 바로 종료
        if(flag){
            cout << "1";
            return 0;
        }
    }
    cout << "0";
    return 0;    
}