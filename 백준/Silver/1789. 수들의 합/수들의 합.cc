#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int S;
    long long int sum = 0;
    long long int res = 0;
    cin >> S;

    for(long long int i = 0; i <= 400000; i++){
        // i가 짝수일 때
        if(i % 2 == 0){
            sum = (1 + i) * (i / 2);
        } else {
            sum = (1 + i) * (i / 2) + (i / 2 + 1);
        }

        if(sum > S){
            res = i;
            break;
        }
    }
    cout << res - 1; 
}