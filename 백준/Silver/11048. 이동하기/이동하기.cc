#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int num[1001][1001];
int dp[1001][1001];

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            cin >> num[i][j];

            // 초기화
            dp[i][j] = num[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1])) + num[i][j];
        }
    }
    cout << dp[n][m];
}