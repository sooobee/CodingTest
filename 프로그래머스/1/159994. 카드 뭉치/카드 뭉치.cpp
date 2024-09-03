#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int current_c1 = 0;
    int current_c2 = 0;
    int cnt = 0;

    for(int i=0; i<goal.size(); i++){
        if(goal[i] == cards1[current_c1]){
            current_c1++;
            cnt++;
        }
        else if(goal[i] == cards2[current_c2]){
            current_c2++;
            cnt++;
        }
    }

    if(cnt == goal.size()) answer = "Yes";
    else answer = "No";

    return answer;
}