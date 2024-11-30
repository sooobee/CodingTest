import java.util.*;

public class Solution {
    public ArrayList <Integer> solution(int []arr) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        // 첫번째 원소는 무조건 추가
        if(arr.length > 0){
            answer.add(arr[0]);
        }
        
        // 뒤에 수와 같지 않을 때만 answer에 추가
        for(int i = 1; i < arr.length; i++){
    
            if(arr[i] != arr[i-1]){
                answer.add(arr[i]);
            }
        }
        return answer;
    }
}