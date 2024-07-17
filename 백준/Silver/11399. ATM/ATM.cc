#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int num[1001];

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    sort(num, num+n);

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += num[i] * (n-i);
    }
    cout << sum;
}