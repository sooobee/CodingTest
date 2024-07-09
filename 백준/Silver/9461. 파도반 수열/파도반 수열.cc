#include<iostream>
using namespace std;

int main(){
    int T;
    long long int dp[101];
    cin >> T;
    
    while(T--){
        int n;

        cin >> n;

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;

        for(int i=6; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-5];
        }
        cout << dp[n] << '\n';
    }
}