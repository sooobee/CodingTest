#include<iostream>
#include<vector>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long int n;
        long long int res = 0;    
        vector<long long int> v;

        cin >> n;
        v.resize(n + 1);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        long long int max_value = -1;
        for(int i = n-1; i >= 0; i--){
            max_value = max(max_value, v[i]);
            res += max_value - v[i];
        }
        cout << res << '\n';
    }
}