#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int num[101];
    cin >> n;
    int res = 0;

    cin >> num[0];
    for(int i=1; i<n; i++){
        cin >> num[i];
    }

    for(int i = n-1; i > 0; i--){
        if(num[i] <= num[i-1]){
             res += num[i-1] - num[i] + 1;
            num[i-1] = num[i] - 1;
        }    
    }
    cout << res;
}