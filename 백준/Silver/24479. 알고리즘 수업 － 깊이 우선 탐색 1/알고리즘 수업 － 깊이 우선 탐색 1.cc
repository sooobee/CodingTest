#include<iostream>
#include<algorithm>
using namespace std;

int n, m, r; // 정점, 간선, 시작 정점
int cnt; // 방문 순서
vector<vector<int>> v;
bool visitt[100001];
int visited_seq[100001];

void dfs(int num){
    visitt[num] = true;
    cnt++;
    visited_seq[num] = cnt;

    sort(v[num].begin(), v[num].end());
    for(auto i: v[num]){
        if(visitt[i] == false) dfs(i);
    }   
}

int main(){
    cin >> n >> m >> r;

    v.resize(n+1);
    
    for(int i=0; i<m; i++){
        int n1, n2;
        //간선의 정보
        cin >> n1 >> n2;

        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    
    dfs(r);

    for(int i=1; i<= n; i++){
        cout << visited_seq[i] << '\n';
    }
    return 0;
}