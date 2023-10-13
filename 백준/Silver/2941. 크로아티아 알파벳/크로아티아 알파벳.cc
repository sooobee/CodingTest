//
//  main.cpp
//  test2
//
//  Created by 김수비 on 2023/10/13.
//
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    string croatia[8]= {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int index;// 크로아티안 알파벳의 첫 index
    cin >> str;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<str.length(); j++){
            index = str.find(croatia[i]); // 문자의 첫번째 인덱스 값 반환
            // 같은 문자를 찾았을 경우
            if(index != string::npos){
                str.replace(index, croatia[i].length(), "#"); // 시작주소, 길이, 바꿀 문자
            }
        }
    }

    cout << str.size() << endl;
}
