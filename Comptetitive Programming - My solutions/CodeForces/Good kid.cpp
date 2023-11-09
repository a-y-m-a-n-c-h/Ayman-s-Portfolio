#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int> y(n,0);
        
        
        for(auto & x : y){
            cin >> x;
        }
        
        auto min = min_element(y.begin(), y.end());
        
        *min = *min + 1;
        
        ll product = 1;
        
        for(auto & x : y){
            product = product*x;
        }
        
        cout << product << endl;
        
    }
    
    
    
}
