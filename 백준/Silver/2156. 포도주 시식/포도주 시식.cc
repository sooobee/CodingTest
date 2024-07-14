#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int num[10001];
    int dp[10001]; // dp[i]: i번째에 도달했을 때 먹을 수 있는 최대 포도주량(안먹는 경우도 포함)
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    dp[1] = num[1];
    dp[2] = num[1] + num[2];
    dp[3] = max({num[1] + num[2], num[2] + num[3], num[3] + num[1]});

    for(int i = 4; i <= n; i++){
        dp[i] = max({dp[i-1], num[i - 1] + dp[i - 3] + num[i], dp[i - 2] + num[i]});
    }

    cout << dp[n];
}