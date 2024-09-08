#include<string>
#include<iostream>
#include<queue>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    queue<char> q;

    for(int i=0; i<s.length(); i++){
        if(s[i] == ')'){
            if(!q.empty()){
                q.pop();
            } else {
                q.push(s[i]);
                answer = 0; // )가 가장 많이 들어오는 경우 바로 false
                break;
            }
        }else {
            q.push(s[i]);
        }
    }

    if(q.empty()) answer = 1;


    return answer;
}