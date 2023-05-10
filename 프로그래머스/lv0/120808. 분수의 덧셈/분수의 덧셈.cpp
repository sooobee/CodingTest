#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else 
        return gcd(b, a % b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
 
    int numer = numer1*denom2 + numer2*denom1; // 분자
    int denom = denom1*denom2; // 분모
    
    int div = gcd(numer, denom); // 최대공약수
    
    numer /= div;
    denom /= div;
    
    answer = {numer, denom};
    
    return answer;
}