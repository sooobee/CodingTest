#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> v, int location) {
    int answer = 0;
    vector<int> m = v;
    int num = 0;
    queue<pair<int, int>> q; // value, index 저장
    int cnt = 0;
    int res[101] = {0, };
    
    sort(m.begin(), m.end(), greater<int>());
    
    for(int i = 0; i < v.size(); i++){
        q.push({v[i], i});
    }
    
    while(!q.empty()){
        // 우선순위가 작을 경우 뒤에 다시 넣음
        auto current = q.front();
        q.pop();
        
        // 가장 큰 값인 경우
        if(current.first == m[num]){
            cnt++; // 방문순서 +1
            num++;
            
            // 탐색중인 index이면 break
            if(current.second == location){
                answer = cnt;
                break;
            }
        } 
        // 우선 순위가 밀릴 때 다시 큐에 집어넣음
        else {
            q.push(current);
        }

    }

    return answer;
}