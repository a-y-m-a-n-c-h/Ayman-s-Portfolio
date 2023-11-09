#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;


int main(){
    
    ll t;
    cin >> t;
    
    while(t--){
        ll n , x;
        cin >> n;
        cin >> x;
        
        vector<ll> a(n,0);
        
        for(auto & x : a){
            cin >> x;
        }
        
        sort(a.begin(),a.end());
        
        vector<ll> cost(n-1,0);
        
        for(ll i = 0; i < n - 1; i++){
            cost[i] = (a[i + 1] - a[i])*(i+1);
        }
        
        ll h = 1;
        
        bool enter = false;
        
        for(ll i = 0; i < n - 1; i++){
            x = x - cost[i];
            if(x < 0){
                h = a[i];
                x = x + cost[i];
                ll added = x/(i + 1);
                h = h + added;
                enter = true;
                cout << h << endl;
                break;
            }
        }
        
        if(enter){
            continue;
        }else{
            h = a[n-1];
            ll addedwater = x/n;
            h = h + addedwater;
            cout << h << endl;
        }
    }
    
    
}
