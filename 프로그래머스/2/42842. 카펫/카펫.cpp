#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> v;
    int height;
    int width;
    
    for(int height = 1; height <= sqrt(yellow); height++){
        // 나누어 떨어지는 수 쌍을 저장
        if(yellow % height == 0){
            width = yellow / height;
        }
        if((width + 2) * (height + 2) == brown + yellow){
            answer.push_back(width + 2);
            answer.push_back(height + 2);
        }
    }
   
    return answer;
}