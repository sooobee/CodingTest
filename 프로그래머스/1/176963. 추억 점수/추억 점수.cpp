#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
// name: 이름, yearning: 그리워하는 정도, photo: 그리워하는 사람 묶음
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int res = 0;

    for(int i=0; i<name.size(); i++){
        m.insert({name[i], yearning[i]});
    }

    for(int j=0; j<photo.size(); j++){
        
        res = 0;
        for(int k=0; k<photo[j].size(); k++){
            // m에 존재하는 경우
            if(m.find(photo[j][k]) != m.end()){
                res += m[photo[j][k]];
            }
        }
        answer.push_back(res);
    }

    return answer;
}