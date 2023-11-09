#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll f(ll x, ll y){
    return x + y;
}


int main(){
    
    ll t;
    cin >> t;
    
    while(t--){
        
        ll n,k,a,b;
        cin >> n; // cities
        cin >> k; //major cities
        cin >> a; // begin
        cin >> b; // end
        
        vector<pair<ll, ll>> majorCities;
        
        for(ll i = 0; i < k; i++){
            ll x,y;
            cin >> x;
            cin >> y;
            pair<ll,ll> p(x,y);
            majorCities.push_back(p);
        }
        vector<pair<ll, ll>> remainingCities;
        
        for(ll i = 0; i < n-k; i++){
            ll x,y;
            cin >> x;
            cin >> y;
            pair<ll,ll> p(x,y);
            remainingCities.push_back(p);
        }
        
        if(majorCities.size() == 0){ // no major cities
            pair<ll,ll> p1 =remainingCities[a-1];
            pair<ll,ll> p2 =remainingCities[b-1];
            
            cout << f(abs(p1.first-p2.first),abs(p1.second-p2.second)) << endl;
        }else{
            if(a <= k){ // i am a major city
                if(b<=k){
                    cout << 0 << endl;
                }else{
                    pair<ll,ll> bp = remainingCities[b-k-1];
                    vector<ll> x;
                    
                    for(ll i = 0; i < majorCities.size(); i ++){
                        x.push_back(f(abs(majorCities[i].first-bp.first),abs(majorCities[i].second-bp.second)));
                    }
                    cout << *min_element(x.begin(),x.end()) << endl;
                }
            }else{ // i am not a major city but major cities exist
                
                vector<ll> x;
                
                pair<ll,ll> ap = remainingCities[a-k-1];
                if(b<=k){
                    pair<ll,ll> bp = remainingCities[b-1];
                    
                    vector<ll> x;
                    
                    for(ll i = 0; i < majorCities.size(); i ++){
                        x.push_back(f(abs(majorCities[i].first-ap.first),abs(majorCities[i].second-ap.second)));
                    }
                    cout << *min_element(x.begin(),x.end()) << endl;
                }else{
                    pair<ll,ll> bp = remainingCities[b-k-1];
                    ll h = f(abs(ap.first - bp.first), abs(ap.second -bp.second));
                    
                    ll q;
                    vector<ll> x;
                    
                    for(ll i = 0; i < majorCities.size(); i ++){
                        x.push_back(f(abs(majorCities[i].first-ap.first),abs(majorCities[i].second-ap.second)));
                    }
                    q = *min_element(x.begin(), x.end());
                    
                    vector<ll> y;
                    
                    for(ll i = 0; i < majorCities.size(); i ++){
                        y.push_back(f(abs(majorCities[i].first-bp.first),abs(majorCities[i].second-bp.second)));
                    }
                    ll s = *min_element(y.begin(), y.end());
                    
                    if(h < q + s){
                        cout << h << endl;
                    }else{
                        cout << q + s << endl;
                    }
                }
            }
        }
    }
}
