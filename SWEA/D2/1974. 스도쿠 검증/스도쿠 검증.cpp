#include<iostream>
using namespace std;

int map[9][9];
bool check[10]; // 방문 체크

void reset(){
    for(int i = 1; i <= 9; i++){
        check[i] = false;
    }
}

int main(){
    int tc;

    cin >> tc;

    for(int i = 1; i <= tc; i++){
        bool flag = false;
        
        // 각 정보를 입력 받음
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                cin >> map[j][k];
            }
        }
        
        // 세로 체크
        for(int q = 0; q < 9; q++){
            for(int z = 0; z < 9; z++){
                int num = map[q][z];
                                
                if(check[num] == false){
                    check[num] = true;
                } else { // 이미 방문한 것에 경우 true 처리
                    flag = true;
                }
            }
            reset();         
        }

        // 가로 체크
        for(int q = 0; q < 9; q++){
            if(flag) break;
            for(int z = 0; z < 9; z++){
                int num = map[z][q];
                                
                if(check[num] == false){
                    check[num] = true;
                } else { // 이미 방문한 것에 경우 true 처리
                    flag = true;
                }
            }
            reset(); 
        }        

        // 3*3 체크
        for(int a = 0; a < 3; a++){
            if(flag) break;

            for(int b = 0; b < 3; b++){

                for(int q = 0; q < 3; q++){
                    for(int z = 0; z < 3; z++){
                        int num = map[3 * a + q][3 * b + z];
                                        
                        if(check[num] == false){
                            check[num] = true;
                        } else { // 이미 방문한 것에 경우 true 처리
                            flag = true;
                        }
                    }
                }    
                reset();     
            }
        }
        

        if(flag == true){
            cout << "#" << i << " " << 0 << '\n';
        } else {
            cout << "#" << i << " " << 1 << '\n';
        }
    
    }
}