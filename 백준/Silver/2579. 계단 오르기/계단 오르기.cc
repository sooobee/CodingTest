#include<iostream>
using namespace std;

int main(){
    int n;
    int num[301] = {0, };
    int dp[301] = {0, };
    
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> num[i];
    }

    dp[0] = 0;
    dp[1] = num[1];
    dp[2] = num[1]+num[2];

    for(int i=3; i<=n; i++){
        dp[i] = max(num[i]+dp[i-2], num[i]+num[i-1]+dp[i-3]);
    }

    cout << dp[n];
}