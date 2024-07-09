#include<iostream>
#include<algorithm>
using namespace std;

int n;
int num[1001];
int dp[1001];
int big = 1;

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> num[i];
        dp[i] = 1;
    }

    dp[1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            // 뒤에 오는 수가 더 클 경우에만
            if(num[i] > num[j]){
                dp[i] = max(dp[i], dp[j]+1); 
            }
        }
        if(dp[i] > big) big = dp[i];
    }
    cout << big;
}