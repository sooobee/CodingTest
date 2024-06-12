#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int f, s, g, u, d;
int cnt;
int dx[2];
int dept[1000001];
bool visited[1000001];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    // g->s가 될때 찾기
    while (!q.empty())
    {   
        int num = q.front();
    
        q.pop();

        // 다음에 들어갈 수
        for(int i=0; i<2; i++){
            int nxt = num + dx[i];

            // 1층~f층
            if( 0 < nxt && nxt <= f && visited[nxt] == false){
                q.push(nxt); // 스택이 아니므로 차례를 기다려야 함
                visited[nxt] = true;
                dept[nxt] = dept[num] + 1;
            }
        }
    }
}

int main(){
    cin >> f >> s >> g >> u >> d;
    
    dx[0] = u;
    dx[1] = -d;

    bfs(s);

    if(visited[g]) cout << dept[g];
    else cout << "use the stairs";

    return 0;
}