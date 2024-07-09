#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long int n;
int t[1500001];
int p[1500001];
int dp[1500001]; // dp[i]: i일에 시작했을 때의 최대 수익

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }

    for(int i=n; i>=1; i--){

        // 퇴사 일을 안 넘을 때만
        if(i + t[i] <= n+1){
            // i일에 상담하지 않는 것과 하는 것 중 더 큰 값을 dp에 저장
            dp[i] = max(dp[i+1], dp[i+t[i]]+p[i]);
        }

        // 퇴사 일을 넘을 경우 상담을 하지 않음
        else dp[i] = dp[i+1]; 
    }
    cout << dp[1];

}