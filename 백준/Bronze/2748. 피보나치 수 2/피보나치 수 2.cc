#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    long long int v[92];

    cin>> n;

    v[0] = 0;
    v[1] = 1;

    for(int i=2; i<n+1; i++){
        v[i] = v[i-1]+v[i-2];
    }

    cout << v[n];
}