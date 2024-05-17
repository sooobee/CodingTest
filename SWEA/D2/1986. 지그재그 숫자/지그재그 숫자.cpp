#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    for(int testCase= 1; testCase<=T; testCase++){
        int num;
        int sum = 0;

        cin >> num;
        
        for(int i = 1; i <= num; i++){
            if(i % 2 == 0){
                sum -= i;
            } else {
                sum += i;
            }
        }

        cout << "#" << testCase << " " << sum << endl;
    }
}