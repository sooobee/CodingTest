#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long int num[1001]; // 입력 받은 수 저장
long long int dp[1001]; // dp[i]: i번째까지 증가하는 수열의 합
long long int big;

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> num[i];
    }

    for(int i=1; i<=n; i++){
        dp[i] = num[i];
    }

    big = dp[1];

    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){

            // 뒤에 오는 수가 더 작은 경우
            if(num[i] <= num[j]) continue;

            else {
                dp[i] = max(dp[i], dp[j] + num[i]);

                if(dp[i] > big) big = dp[i];
            }
        }
    }
    
    cout << big;
}