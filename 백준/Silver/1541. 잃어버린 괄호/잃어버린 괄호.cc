
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string num = ""; // 수를 한번 저장해주는 역할
    int result = 0;
    bool isMinus = false;
    
    cin >> str;
    
    for(int i=0; i<str.size()+1; i++){
        
        // 연산자이거나 마지막 수일 때
        if(str[i] == '+' || str[i] == '-' || i == str.size()){
            
           // 이미 마이너스가 나온 경우
            if(isMinus){
                result -= stoi(num); // 마이너스 후의 값을 뺌
                num = "";
            }
            // 첫번째 마이너스거나, 플러스거나, 마지막일때
            else{
                result += stoi(num); // 연산자가 나오기 전 숫자를 result에 업로드
                num = "";
            }
            
        }
        // 수인 경우
        else {
            num += str[i]; // 수를 string으로 저장
        }
        
        if(str[i] == '-')
            isMinus = true;
    }
    cout << result << endl;
}
