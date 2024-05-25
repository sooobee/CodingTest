#include<iostream>
#include<algorithm>
using namespace std;

int n, m, r;
vector<vector<int>> s;
int cnt;

int* res;

bool visitt[100001];

void dfs(int num){
    if(visitt[num] == false){
        // 방문 표시
        visitt[num] = true;
        cnt++;
        res[num] = cnt;

        for(auto k: s[num]){
            if(visitt[k] == false) dfs(k);
        }
    }
}

int main(){
    cin >> n >> m >> r;

    s.resize(n+1);
    // 크기 동적할당
    res = new int[n+1];


    for(int i=0; i<m; i++){
        int u, v;

        cin >> u >> v;

        s[u].push_back(v);
        s[v].push_back(u);
    }

    // 내림차순 정렬(오름차순일 때는 less 함수를 넣음)
    for(int i=1; i<=n; i++){
        sort(s[i].begin(), s[i].end(), greater<int>());
    }

    dfs(r);

    for(int i=1; i<=n; i++){
        cout << res[i] << '\n';
    }

    if(res){
        delete [] res;
    }
    

    return 0;
}