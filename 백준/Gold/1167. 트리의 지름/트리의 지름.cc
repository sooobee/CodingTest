#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// int 순서쌍을 edge라는 별칭으로 선언
typedef pair<int, int> edge;

// int 순서쌍을 가지는 배열
vector<vector<edge>> graph;
bool visited[100001];
int dis[100001];
int v;

void bfs(int first){
    queue<int> q;
    q.push(first);
    visited[first] = true; // 방문처리 

    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(edge i : graph[num]){
            if(visited[i.first] == false){
                visited[i.first] = true; // 방문처리
                q.push(i.first); // q에 넣음
                dis[i.first] = dis[num] + i.second; // 가중치를 더해서 dis 배열에 저장
            }
        }
    }
}

int main(){
    int s, e, w;
    cin >> v;

    graph.resize(v+1); // 벡터 크기 동적할당

    for(int i=0; i<v; i++){
        cin >> s;
        while(true){
            cin >> e;
            if(e == -1) break;
            cin >> w;
            // s노드와 연결된 e노드, 그에 대한 가중치를 저장
            graph[s].push_back(edge(e, w));

        }        
    }
    bfs(1);

    int max = -1;
    int index;
    for(int i = 1; i<=v; i++){
        if(max < dis[i]){
          max = dis[i]; // 가장 먼 거리 저장
          index = i; // 가장 거리가 먼 노드를 index에 저장
        }
    }

    // 초기화
    for(int i=1; i<=v; i++){
        visited[i] = false;
        dis[i] = 0;
    }
    bfs(index);

    // max값을 비교
    for(int i = 1; i<=v; i++){
        if(max < dis[i]){
          max = dis[i]; // 가장 먼 거리 저장
        }
    }
    cout << max << '\n';
}

