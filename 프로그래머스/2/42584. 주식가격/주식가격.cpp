#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer; 
    
    for(int i = 0; i < prices.size(); i++){
        int cnt = 0;
        
        // 마지막 가격인 경우 0 넣고 break
        if(i == prices.size() - 1){
            answer.push_back(0);
            break;
        }
        
        for(int j = i+1; j < prices.size(); j++){
            
            // 더작은 수가 뒤에 오는 경우 
            // 카운트 종료
            if(prices[i] > prices[j]){
                cnt++;
                answer.push_back(cnt);
                break;
                // 같거나 큰 수가 뒤에 오는 경우
                // 카운트를 더해줌
            } else {
                cnt++;
            }
            
            // 탐색 끝난 경우 push
            if(j == prices.size() - 1){
                answer.push_back(cnt);
            }
        }
    }
    
    return answer;
}