#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
bool visited[1000001];
int dept[1000001];

void bfs(int n){
    queue<int> q;
    
    q.push(n);
    visited[n] = true;

    while(!q.empty()){
        int num = q.front();
        q.pop();

// -------1, 2, 3 경우를 다 queue에다 넣음
        if(num % 3 == 0){
            int nxt = num / 3;

            if(!visited[nxt]){
                q.push(nxt);
                visited[nxt] = true;
                dept[nxt] = dept[num]+1;
            }
        }

        if(num % 2 == 0){
            int nxt = num / 2;

            if(!visited[nxt]){
                q.push(nxt);
                visited[nxt] = true;
                dept[nxt] = dept[num]+1;
            }
        }

        if(num-1 > 0 && !visited[num-1]){
            q.push(num-1);
            visited[num-1] = true;
            dept[num-1] = dept[num]+1;
        }
    }
}

int main(){
    cin >> n;

    bfs(n);

    if(visited[1]) cout << dept[1];

    return 0;
}