import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack <Character> st = new Stack<>();
        
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i); // 하나 하나씩 선택
            
            if(c == '('){
                st.push(c);
            } else {
                // ')' 일 때 비어있지 않으면
                if(!st.isEmpty()){
                    if(st.peek() == '('){
                        st.pop();
                    } else {
                        st.push(c);
                    }
                } else {
                    // 비어있으면 바로 false
                    answer = false;
                    break;
                }
            }
        }
        
        if(!st.isEmpty()){
            answer = false;
        }

        return answer;
    }
}