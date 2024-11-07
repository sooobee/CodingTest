#include<iostream>
using namespace std;

int main(){
	int l, u, tc;
    
    cin >> tc;
    
    for(int i = 1; i <= tc; i++){
    	int time;
        
        cin >> l >> u >> time;
        
        // 운동을 최소 시간보다 적게 한 경우
        if(time < l){
            cout << "#" << i << " " << l - time << endl;
            continue;
    	} 
        // 최대 시간 보다 많이 한 경우
        else if (time > u){
       	 	cout << "#" << i << " " << "-1" << endl;
            continue;
        }
        // 그 사이에 들어갈 경우
        else {
            cout << "#" << i << " " << "0" << endl;
            continue;
        }
    }
}
