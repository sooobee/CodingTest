#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        int h1, m1, h2, m2; // 시작 시, 분, 끝 시, 분
        int resh;
        int resm;

        cin >>  h1 >> m1 >> h2 >> m2;

        // 더한 값
        resh = h1 + h2;
        resm = m1 + m2;

        if(resm >= 60){
            resh += 1; // 60이 넘는 경우 시간 +1
            resm -= 60;
        }
        
        // 오후인 경우 12를 뺌
        if(resh > 12){
            resh -= 12;
        } 
        cout << "#" << i << " " << resh << " " << resm << endl;
        
    } 
}
