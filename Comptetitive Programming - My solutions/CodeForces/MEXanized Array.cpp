#include <iostream>
using namespace std;
typedef long long int ll;


int main(){
    
    ll t;
    cin >> t;
    
    
    while(t--){
        
        ll n,k,x;
        cin >> n;
        cin >> k;
        cin >> x;
        
        if(n < k){
            cout << -1 << endl;
            continue;
        }
        if(x < k - 1){
            cout << -1 << endl;
            continue;
        }
        
        ll sum = ((k-1)*(k))/2;
        
        if(x >= k + 1){
            sum = sum + (n-k)*x;
        }else{
            sum = sum + (n-k)*(k-1);
        }
        cout << sum << endl;
    }
    
    
}
