import java.util.*;

class Solution {
    static boolean[] visited; // 전역 변수 선언
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++){
            // 현재 위치, 전체 크기, 배열
            if(!visited[i]){
                dfs(i, computers);
                answer++;
            }
        }
        
        return answer;
    }
    
    public void dfs(int cur, int[][] arr){
        visited[cur] = true; // 방문 처리

        for(int i = 0; i < arr[cur].length; i++){
            // 만약 둘이 연결되어 있고, 방문하지 않은 경우 dfs 실행
            if(arr[cur][i] == 1 && !visited[i]){
                dfs(i, arr);
            }
        }
    }
}