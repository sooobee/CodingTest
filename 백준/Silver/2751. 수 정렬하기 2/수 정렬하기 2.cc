#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;

    
    
    while(n--){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());

    
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    
}