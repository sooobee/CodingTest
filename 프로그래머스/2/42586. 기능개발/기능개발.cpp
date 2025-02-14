#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> pro, vector<int> sp) {
    vector<int> answer;
    vector<int> rest; // 완료까지 걸리는 시간을 저장
    queue<int> q;
    
    for(int i = 0; i < pro.size(); i++){
        int time;
        int na = (100 - pro[i]) % sp[i];
        
        // 나머지가 0이 아닌 경우 +1을 해준 값을 rest에 저장
        if(na != 0){
            time = (100 - pro[i]) / sp[i] + 1;
            rest.push_back(time);
        } else {
            time = (100 - pro[i]) / sp[i];
            rest.push_back(time);
        }
    }

        for(int i = 0; i < rest.size(); i++){
            
            // 진행중인 기능이 없는 경우
            if(q.empty()){
                q.push(rest[i]);
                continue;
                
                // 이미 진행 중인 기능이 있는 경우
            } else { 
                // 뒷 기능이 앞 기능보다 더 오래 걸리는 경우
                // 그동안의 기능을 전부 pop
                // pop한 수를 answer에 저장
                if(rest[i] > q.front()){
                    int cnt = 0;
                    
                    while(!q.empty()){
                        q.pop();
                        cnt++;
                    }
                    answer.push_back(cnt);
                    q.push(rest[i]);

                    
                } else {
                    q.push(rest[i]);

                }
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            q.pop();
            cnt++;
        }
    answer.push_back(cnt);
    
    return answer;
}