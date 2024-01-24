//
//  main.cpp
//  2606
//
//  Created by 김수비 on 1/24/24.
//

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[101][101];
bool visitt[101];
int cnt;

void bfs(int v){
    queue<int> q;
    q.push(v);
    visitt[v] = true;

    while(!q.empty()){
        v = q.front();
        q.pop();
        cnt++;
        
        for(int i=1; i<=n; i++){
            // 간선이 있고, 방문하지 않은 곳
            if(arr[v][i] == 1 && !visitt[i]){
                visitt[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
    bfs(1);
    cout << cnt-1;
    
    return 0;
}
