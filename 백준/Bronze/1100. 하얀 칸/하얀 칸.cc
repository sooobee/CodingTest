#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int res = 0;
    char pan[8][9];

    for(int i = 0; i < 8; i++){
        cin >> pan[i];
    }

    for(int i=0; i<8; i++){
        for(int j = i % 2; j < 8; j += 2){
            if(pan[i][j] == 'F'){
                res++;
            }
        }
    }
    cout << res << endl;
}