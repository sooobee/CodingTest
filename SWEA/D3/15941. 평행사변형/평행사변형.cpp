#include<iostream>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    
    for(int i = 1; i <= tc; i++){
    	int n; 
        cin >> n;
        
        cout << "#" << i << " " << n * n << endl;
    }
}