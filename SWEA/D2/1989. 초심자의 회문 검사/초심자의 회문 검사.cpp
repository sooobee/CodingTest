#include <iostream>
using namespace std;

int main(){
    int T; 
    int res;

    cin >> T;

    // T만큼 반복
    for(int i=1; i<=T; i++){
        string str;
        int cnt= 0;
        cin >> str;
        
        for(int k=0; k<=str.length()/2; k++){
            if(str[k] == str[str.length()-1-k]){
                cnt++;
            }
        }

        if(cnt > str.length()/2){
            cout << "#" << i << " 1" << endl;
        } else {
            cout << "#" << i << " 0" << endl;
        }
    }
}