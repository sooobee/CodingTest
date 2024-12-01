import java.util.*;

class Solution {
    public ArrayList <Integer> solution(int[] progresses, int[] speeds) {
        ArrayList <Integer> answer = new ArrayList<>();
        int [] time = new int [progresses.length];

        // 각자 남은 시간을 time에 저장
        for(int i = 0; i < progresses.length; i++){
            int num = (int) Math.ceil((100 - progresses[i]) / speeds[i]);
            
            // 나머지가 있으면 num에 +1
            if((100 - progresses[i]) % speeds[i] > 0){
                num += 1;
            }
            
            
            time[i] = num;
        }
        
        int max = time[0];
        int cnt = 0; 
        for(int i = 0; i < time.length; i++){
            
            // 뒤에 값이 max보다 작을 경우 스택에 푸시
            if(time[i] <= max){
                cnt++;
                
            } else {
                // cnt 넣어주고, max, cnt 변경
                answer.add(cnt);
                
                cnt = 0;
                max = time[i];
                cnt++;
            } 
        }

        if(cnt > 0){
            answer.add(cnt);
        }
        
        
        return answer;
    }
}