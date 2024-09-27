#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), greater());

    
    for(int i = 0; i < n; i++){
        // 인용 수
        int h = citations[i];
        
        // h보다 더 많이 인용된 논문의 수
        int num = i+1;
        
        answer = max(answer, min(h, num));
    
    }
    return answer;
}