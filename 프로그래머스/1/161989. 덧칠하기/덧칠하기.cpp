#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int current_position = 0;

    sort(section.begin(), section.end()); // 색션 정렬
    
    for(int i = 0; i < section.size(); i++){
        if(section[i] > current_position){
            answer++;
            current_position = section[i] + m - 1;
        }
    }
    return answer;
}