#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
vector<int>graph[101];
bool visited[101];

void dfs(int num){
    // num 노드에서 갈 수 있는 모든 노드를 방문 표시
    for(auto i: graph[num]){
        if(visited[i] == false){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int check;
            cin >> check;
            
            if(check == 1){
                // 연결된 간선 저장
                graph[i].push_back(j);
            }
        }
    }

    for(int i=0; i<n; i++){
        memset(visited, 0, sizeof(visited)); // 방문 표시 전부 0으로 초기화 
        dfs(i); // i 노드에서 갈 수 있는 모든 노드를 방문(1로 표시)

        // 방문할 수 있는 노드를 출력
        for(int j=0; j<n; j++){
            cout << visited[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}