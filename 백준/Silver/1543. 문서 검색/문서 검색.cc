#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    string f;
    int res = 0;

    getline(cin, str);
    getline(cin, f);

    for(int i = 0; i < str.length(); i++){
        // 탐색할 문자가 f보다 길이가 작은 경우 break
        if(str.length() - i < f.length()) 
            break;
            
        // i부터 f의 길이 만큼 자름
        string temp = str.substr(i, f.length());

        // 찾았으면 그 후부터 탐색
        if(temp == f){
            res++;
            i += f.length() -1;
        }
    }

    cout << res;

}