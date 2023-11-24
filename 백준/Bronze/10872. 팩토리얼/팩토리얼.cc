//
//  main.cpp
//  10872
//
//  Created by 김수비 on 11/25/23.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    int ans = 1;
    
    cin >> n;
    
    if(n== 0){
        ans = 1;
    }
    else {
        for(int i=1; i<=n; i++){
            ans *= i;
        }
    }
    
    cout << ans << endl;
}
