#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0; // 현재 차량 idx
    int sum = 0; // 현재 다리에 올라와있는 차량 무게 총합
    queue<int> q;
    
    while(1){
        // 마지막 트럭일 때
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        answer++;
        int now_weight = truck_weights[idx]; // 현재 차 무게
        
        // 차가 다리를 다 건넜을 경우
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        
        // 다리에 다음 차가 진입할 수 있다면
        if(sum + now_weight <= weight){
            sum += now_weight;
            q.push(now_weight);
            idx++;
        } else {
            q.push(0); // 진입할 수 없다면 0을 푸시해서 시간초 계산
        }
    }
    
    return answer;
}