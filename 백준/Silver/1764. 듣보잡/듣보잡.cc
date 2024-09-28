#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int N, M;
    int sum;
    string str;
    map<string, int> m;
    vector<string> res;
    
    cin >> N >> M;
    sum = N + M;
    
    while(sum--){
        cin >> str;
        m[str]++;
        
        if(m[str] >= 2){
            res.push_back(str);
        }
    }
    
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
}