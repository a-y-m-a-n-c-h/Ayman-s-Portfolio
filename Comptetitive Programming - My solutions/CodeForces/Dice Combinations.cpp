#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int ll;



int main(){
    
    int n;
    
    cin >> n;
    
    vector<ll> dp(n+1,0);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    ll m = pow(10,9) + 7;
    
    for(int j = 3; j < n + 1; j++){
        ll sum = 0;
        int k = j - 1;
        int i = 0;
        while(i != 6 && k >= 0){
            sum = (sum + dp[k])%m;
            i++;
            k--;
        }
        dp[j] = sum;
    }
    
    
    
    cout << dp[n];
    
    
}
