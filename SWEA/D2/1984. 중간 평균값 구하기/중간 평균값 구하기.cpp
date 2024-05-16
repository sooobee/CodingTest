#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=1; i<=T; i++){
        int arr[11]={0, };
        double sum=0;

        for(int i=0; i<10; i++){
            cin >> arr[i];
        }

        sort(arr, arr+10);

        for(int i=1; i<9; i++){
            sum += arr[i];
        }

        // 소수점 첫째자리에서 반올림해야 하므로 round 함수를 사용
        cout << "#" << i << " " << round(sum/8) << endl;

    }
}