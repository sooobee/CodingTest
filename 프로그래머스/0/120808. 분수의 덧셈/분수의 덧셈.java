class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int[] answer = new int [2];
        int max = 1; // 최대공약수
        int limit;
        
        int u = numer1 * denom2 + numer2 * denom1; // 분자
        int d = denom1 * denom2; // 분모
        
        if(u > d) limit = d;
        else limit = u;
        
        // 최대공약수를 지정
        for(int i = 1; i <= limit; i++){
            if(u % i == 0 && d % i == 0)
                max = i;
        }
        
        answer[0] = u / max;
        answer[1] = d / max;
       
        
        return answer;
    }
}