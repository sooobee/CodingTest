#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int t, n, m;
bool visitt[1001];
vector<vector<int>> v;

int cnt = 0; 

void dfs(int x){
    // 노드의 개수를 셈
    cnt++;

    visitt[x] = true; // 방문 처리

    // 연결된 노드를 하나씩 돔
    for(auto i : v[x]){

        // 방문하지 않았다면 dfs 실행
        if(!visitt[i]) dfs(i);
    }
}

int main(){
    cin >> t;

    for(int i=0; i<t; i++){
        int f1, f2;
        cin >> n >> m;

        // 그래프 초기화
        v.clear();
        v.resize(n+1);

        for(int j=0; j<m; j++){

            cin >> f1 >> f2;

            // 그래프 초기화
            v[f1].push_back(f2);
            v[f2].push_back(f1);
            
            // 방문 기록 초기화
            memset(visitt, false, sizeof(visitt));
        }
        
        cnt = 0;

        dfs(1);

        // 비행기의 수 = 간선의 길이
        cout << cnt-1 << endl;
    }    
}