#include <iostream>
using namespace std;
#include <numeric>
#include <vector>
#include <algorithm>
#include <climits>


int main(){
    
    int n;
    int x;
    
    cin >> n;
    cin >> x;
    
    
    vector<int> input;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        input.push_back(x);
    }
    
    int gcd = input[0];
    
    for(auto y : input){
        gcd = std :: gcd(gcd, y);
    }
    
    vector<int> dp(x + 1,-1);
    
    dp[0] = 0;
    
    bool exists = false;
    
    if(x%gcd != 0){
        cout << -1 << endl;
        exists = true;
    }else{
        for(int i = 1; i <= x; i++){
            vector<int> x;
            for(auto & y : input){
                if(i - y >=0){
                    if (dp[i - y] != -1){
                        x.push_back(dp[i - y]);
                    }
                }
            }
            if (x.empty()){
                continue;
            }
            dp[i] = *min_element(x.begin(), x.end()) + 1;
            vector<int> y;
            x = y;
        }
    }
    
    if(!exists){
        cout << dp[x];
    }
}
