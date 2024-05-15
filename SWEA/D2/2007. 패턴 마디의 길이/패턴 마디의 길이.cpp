#include<iostream>
using namespace std;

int main(){
    int T;

    cin >> T;

    // T만큼 반복
    for(int i=1; i<=T; i++){
        string str;
        string tmp;
        int cnt = 1;
        cin >> str;

        tmp += str[0];
        for(int k=1; k <= str.size(); k++){
            if(tmp != str.substr(tmp.size(), k)){
                tmp += str[k];
                cnt++;
            }
            else {
                break;
            }
        }

        cout << "#" << i << " " << cnt << endl;

    }
}