#include<iostream>
#include<algorithm>
using namespace std;

int n;
int num[100001];
int dp[100001];
int big = -1001;

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> num[i];
    }

    dp[0] = 0;

    for(int i=1; i<=n; i++){
        dp[i] = max(num[i], num[i] + dp[i-1]);

        if(dp[i] > big) big = dp[i];
    }

    cout << big;
}