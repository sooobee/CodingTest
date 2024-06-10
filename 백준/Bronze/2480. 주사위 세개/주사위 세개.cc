#include<iostream>
using namespace std;

int n1, n2, n3;

int main(){
    cin >> n1 >> n2 >> n3;

    // 3개 다 같을 때 
    if(n1 == n2 && n2 == n3) cout << 10000 + n1*1000;

    // 2개만 같을 때 
    else if (n1 == n2) cout << 1000 + n2*100;
    else if (n2 == n3) cout << 1000 + n2*100;
    else if (n1 == n3) cout << 1000 + n3*100;

    else {
        int max = n1; 

        if(max < n2) max = n2;
        
        if(max < n3) max = n3;

        cout << max*100;
    }
}