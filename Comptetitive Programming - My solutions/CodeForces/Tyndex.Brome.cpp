#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(){
    
    ll n,k;
    cin >> n;
    cin >> k;
    
    unordered_map<ll, vector<ll>> map;
    
    vector<char> userinsert;
    
    for(ll i = 0; i <k; i ++){
        char c;
        cin >> c;
        
        userinsert.push_back(c);
        map[c].push_back(i);
    }
    
    vector<string> potentialAdresses;
    
    for(ll i = 0; i < n; i++){
        string x;
        cin >> x;
        potentialAdresses.push_back(x);
    }
    
    vector<ll> F(n,0);
    
    for(ll i = 0; i < n; i++){
        string x = potentialAdresses[i];
        for(ll j = 0; j < x.size(); j++){
            if(map[x[j]].empty()){
                F[i] += x.size();
            }else{
                ll minn = abs(j - map[x[j]][0]);
                for(auto &x : map[x[j]]){
                    minn = min(minn,abs(j - x));
                }
                F[i] += minn;
            }
        }
    }
    
    for(auto & x : F){
        cout << x << endl;
    }
}
