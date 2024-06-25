#include<iostream>
using namespace std;

int main(){
    int T;
    int arr[41][2];

    cin >> T;

    while(T--){
        int n;
        cin >> n;

        arr[0][0] = 1;
        arr[0][1] = 0;
        arr[1][0] = 0;
        arr[1][1] = 1;

        // 호출 값 저장
        for(int i=2; i<n+1; i++){
            arr[i][0] = arr[i-2][0] + arr[i-1][0];
            arr[i][1] = arr[i-2][1] + arr[i-1][1];
        }

        cout << arr[n][0] << " " << arr[n][1] << "\n";
    }
}