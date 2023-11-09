#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef long long int ll;


vector<vector<ll>> powerset;
int counter = 0;


void createintegers(vector<ll> integers, vector<ll> building){
    
    
    if(integers.size() == 0){
        powerset.push_back(building);
        return;
    }

    vector<ll> copy = integers;
    ll x = copy[0];
    copy.erase(copy.begin());
    
    vector<ll> h = building;
    h.push_back(x);
    
    createintegers(copy,h);
    createintegers(copy,building);


    

}










int main(){
    
    
    
    
    
    int n;
    cin >> n;
    
    vector<ll> apples;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        apples.push_back(x);
    }
    
    vector<ll> building;
    
    createintegers(apples,building);
    
    vector<ll> subset;
    
    powerset.erase(powerset.begin());
    
    
    ll sum3 = 0;
    
    for(auto &x : apples){
        sum3 = sum3 + x;
    }
    
    ll toBePrinted = sum3;

    
    for(int i = 0; i < powerset.size(); i++){
        
        ll sum = 0;
        
        for(auto &x : powerset[i]){
            sum = sum + x;
        }
        
        ll x = abs(sum3 - sum - sum);
        
        if(x < toBePrinted ){
            toBePrinted = x;
        }
    }
    
    
    
    
    cout << toBePrinted;
    
    
    
    
    
    
}
