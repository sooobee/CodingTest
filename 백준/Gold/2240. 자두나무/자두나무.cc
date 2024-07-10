#include<iostream>
#include<algorithm>
using namespace std;

int num[1005];
int dp[1005][35]; // dp[t][w]: 자두가 t시간에 떨어지고 w만큼 움직였을 때 얻을 수 있는 자두의 최댓값

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w;
    cin >> t >> w;

    for(int i=1; i<=t; i++) cin >> num[i];

    // 한번도 움직이지 않았을 때 얻을 수 있는 최대 자두 개수
    int cnt = 0;
    for(int i = 1; i <= t; i++){
        if(num[i] == 1) cnt++;
        dp[i][0] = cnt;
    }

    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= w; j++){
            // 이전 시간에 움직였을 때와 움직이지 않았을 때 비교
            // 현재 있는 나무에서 자두가 떨어지면 +1 그렇지 않으면 0 
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (1 + j % 2 == num[i]);
        }
    }
    cout << *max_element(dp[t], dp[t] + w + 1);
} 