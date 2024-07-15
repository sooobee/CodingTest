#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a[51];
    int b[51];
    int sum = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a + n); // 오름차순 정렬
    sort(b, b + n, greater<int>()); // 내림차순 정렬

    for(int i = 0; i < n; i++){
        sum = sum + a[i] * b[i];
    }
    cout << sum;
}