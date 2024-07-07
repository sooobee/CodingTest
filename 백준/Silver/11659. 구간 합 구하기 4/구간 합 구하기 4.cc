#include<iostream>
using namespace std;

int main(){
    int n, m;
    long long int num[100001];
    long long int dp[100001];

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    // 100000번
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }

    dp[0] = 0;
    dp[1] = num[1];
    dp[2] = num[1]+num[2];

    // 100000-3번
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+num[i]; 
    }

    // 100000번
    for(int w=0; w<m; w++){
        int i, j;

        cin >> i >> j;

        cout << dp[j] - dp[i-1] << "\n";
    }
}