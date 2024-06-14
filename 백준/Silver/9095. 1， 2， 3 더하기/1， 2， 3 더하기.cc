#include<iostream>
using namespace std;

int d[11]= {0, 1, 2, 4};
int main(){

    // 값을 설정
    for(int i=4; i<11; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int num;
        cin >> num;
        cout << d[num] << '\n';
    }
    return 0;
}
