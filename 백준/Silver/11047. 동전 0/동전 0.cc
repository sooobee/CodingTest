#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int num[11];
int res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    for(int i= n-1; i >= 0; i--){

        if(k >= num[i]){
            int temp;
            temp = k / num[i];
            k %= num[i];
            res += temp;
        }
    }
    cout << res;
}