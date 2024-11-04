#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int T;
    
	cin>>T;
    
    for(int i = 0; i < T; i++){
    	int a, b, n;
       int res = 0;
        
        cin >> a >> b >> n;
        
		if(a > n || b > n){
            cout << "0" << endl;
			continue;
        }
        
        while(a <= n && b <= n){
        	if(a > b)
                b += a;
            else 
                a += b;
            
            res++;
      }
        cout << res << endl;
    }
	return 0;
}