#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    

    // 돌아가면서 다른 것을 체크
    int i = 0;
    for(; i < completion.size(); i++){
        if(participant[i] != completion[i])
            break;
    }
    return participant[i];  
}