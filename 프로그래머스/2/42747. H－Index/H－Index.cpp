#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    // 최대 인용 수 ~ 1까지 돌며 h값을 찾음
    for(int i = citations[0]; i > 0; i--){
        int h = i;
        int countB = 0;
        int countS = 0;
        
        for(int j = 0; j < citations.size(); j++){
            // 전체수에서 h보다 큰 수의 개수, 작은 수의 개수를 체크
            // h: 큰 수의 개수보다 크거나/같, 작은 수의 개수보다 작거나/같
            if(citations[j] >= h) countB++;
            else if(citations[j] <= h) countS++;
        }
        
        if(countB >= h && countS <= h){
            answer = h;
            break;
        }
    }
    return answer;
}