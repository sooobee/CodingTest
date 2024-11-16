#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int num;
        cin >> num;

        v.push_back(num);    
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        cout << v[i] << '\n';
    }
}