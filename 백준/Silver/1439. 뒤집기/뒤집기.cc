#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int zero = 0;
    int one = 0;
    int res = 0;

    cin >> str;
    
    for(int i = 0; i < str.length(); i++)
    {   
        // 0 뒤집을 때
        if(str[i] == '0'){
            if (str[i] != str[i + 1]) one++;
        }
        // 1 뒤집을 때
        else{
            if(str[i] != str[i + 1]) zero++;
        }
    }
    // 더 작게 뒤집는 수 출력
    res = min(one, zero);

    cout << res;
    return 0;
}