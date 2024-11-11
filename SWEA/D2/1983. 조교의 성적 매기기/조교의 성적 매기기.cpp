#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tc;
    int n, k;
    string grade[10] = {"A+", "A0", "A-", "B+", "B0", "C-", "C+", "C0", "C-", "D0"};
    string res;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        cin >> n >> k; // 학생수, 알고 싶은 학생 번호 입력

        vector<pair<double, int>> score; // 총점, 학생 번호 저장

        for(int j = 0; j < n; j++){
            int s1, s2, s3; // 중간, 기말, 과제 점수
            cin >> s1 >> s2 >> s3;

            score.push_back(make_pair((s1 * 0.35) + (s2 * 0.45) + (s3 * 0.2), j));
        }
        
        // 가장 큰 게 0번
        sort(score.begin(), score.end());
        reverse(score.begin(), score.end()); 
        

        // q: 등수, 전부 0에서 시작하므로 +1 신경 쓸거 x
        for(int q = 0; q < n; q++){
            if(score[q].second == k-1){
                res = grade[q * 10 / n];
                cout << "#" << i << " " << res << endl;
            }

        }
    }
}