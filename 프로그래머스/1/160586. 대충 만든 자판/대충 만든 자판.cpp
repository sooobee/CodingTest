#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> m;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    // m 초기화
    for(int i = 0; i < keymap.size(); i++){
        // 각 string의 자리수
        for(int k = 0; k < keymap[i].size(); k++){
            if(m.find(keymap[i][k]) == m.end() || m[keymap[i][k]] > k + 1){
                m[keymap[i][k]] = k + 1;
            } 
        }
    }
    
    int cnt;
    for(int i = 0; i < targets.size(); i++){
        cnt = 0;
        bool flag = true;
        // 각 string의 자리수
        for(int k = 0; k < targets[i].size(); k++){
            
            // 이미 존재하는 경우 더 작은 수가 들어감
            if(m.find(targets[i][k]) != m.end()){
                cnt += m[targets[i][k]];
            } else {
                flag = false;
                break;
            }
        }
        if(flag){
            answer.push_back(cnt);
        }else {
            answer.push_back(-1);
        }
    }
    
    return answer;
}