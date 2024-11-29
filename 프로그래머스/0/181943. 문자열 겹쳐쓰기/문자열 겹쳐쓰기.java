class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String answer = my_string;
        int ol = overwrite_string.length(); // 바꿀 길이
        int ml = my_string.length();
        
        answer = my_string.substring(0, s) + overwrite_string
            + my_string.substring(s + ol, ml);
        
        return answer;
    }
}