#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main(){
    
    ll t;
    cin >> t;
    
    while(t--){
        
        int n,m;
        cin >> n;
        cin >> m;
        
        vector<ll> a(n);
        vector<ll> b(m);
        
        for(auto &x : a){
            cin >> x;
        }
        vector<ll> copy(a);
        for(auto &x : b){
            cin >> x;
        }
        
        ll bigNum = 0;
        
        for(auto & x : b){
            bigNum = bigNum | x;
        }
        
        if(n%2 == 0){
            for(auto & x : a){
                x = x | bigNum;
            }
            ll min = 0;
            ll max = 0;
            for(auto & x : a){
                min = min xor x;
            }
            for(auto & x : copy){
                max = max xor x;
            }
            cout << min << " " << max << endl;
        }else{
            for(auto & x : a){
                x = x | bigNum;
            }
            ll max = 0;
            ll min = 0;
            for(auto & x : a){
                max = max xor x;
            }
            for(auto & x : copy){
                min = min xor x;
            }
            cout << min << " " << max << endl;
        }
    }
    
   
        
        
}
