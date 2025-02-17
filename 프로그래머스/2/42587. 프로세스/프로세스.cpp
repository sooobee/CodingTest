#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> v, int location) {
    int answer = 0; // 방문순서
    queue<pair<int, int>> q;
    
    for(int i = 0; i < v.size(); i++){
        q.push(make_pair(v[i], i)); // 우선순위, 원래 위치
    }
    
    // 오름차순 정렬
    sort(v.begin(), v.end(), greater<>());
    
    int num = 0;   
    while(!q.empty()){
        pair<int, int> front = q.front();
        int max = v[num]; // 우선순위 가장 큰 수
        q.pop();
        
        if(front.first == max){
            answer++; // 방문순서 + 1
            num++; // max값 update
            
            // 찾던 위치의 수인 경우
            if(front.second == location){
                break;
            }
            
        } else {
            q.push(front); // 우선순위가 작을 경우, 다시 넣음
        }
    }
    
    return answer;
}