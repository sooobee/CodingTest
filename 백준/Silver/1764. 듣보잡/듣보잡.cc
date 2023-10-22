#include <iostream>
#include <string>
#include <algorithm>
#include<map>
using namespace std;

int main(){
    int N, M;
    string name;
    map<string, int> m;
    vector<string> result;
    
    cin >> N >> M;
    
    int sum = N+M;
    
    while(sum--){
        cin >> name;
        
        m[name]++; // key에 name을 저장하고 나온 횟수를 value로 카운트해줌
        
        // name이 2번 이상 나온 경우
        if(m[name] > 1){
            result.push_back(name);
        }
    }
    
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    
    for(int i=0; i< result.size(); i++){
        cout << result[i] << endl;
    }
}
