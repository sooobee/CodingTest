#include<string>
#include<iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<int> st;
    
    for(int i = 0; i < s.length(); i++){
        // '('일 때는 무조건 push
        if(s[i] == '(') st.push(s[i]);
        else {
            // ')'일 때
            // 스택이 비어있으면 바로 false
            if(st.empty()) return false;
            else {
                // 스택이 비어있지않을 때
                // '(' 인 경우 pop
                if(st.top() == '('){
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
    }
    
    if(st.empty()){
        answer = true;
    }
    
    return answer;
}