#include <string>
#include <vector>
#include <stack>
using namespace std;

bool visited[201];

void dfs(int cur, int n, vector<vector<int>>& com){
    visited[cur] = true; // 방문처리

    for(int i = 0; i < n; i++){
        if(!visited[i] && com[cur][i] == 1){
            dfs(i, n, com);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}