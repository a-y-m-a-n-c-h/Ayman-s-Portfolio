#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main(){
    
    int n;
    int m;
    
    cin >> n;
    cin >> m;
    
    multiset<int> actualPrices;
    vector<int> requestedPrices(m,0);
    
    for (int i = 0; i < n; i++){
        int y;
        cin >> y;
        actualPrices.insert(y);
    }
    
    for (auto & y : requestedPrices){
        cin >> y;
    }
    
    for (auto & z : requestedPrices){
        
        auto l = actualPrices.lower_bound(z);
        if (l == actualPrices.end()){
            if(actualPrices.size() != 0){
                l--;
            }else{
                cout << -1 << endl;
                continue;
            }
        }
        int x = *l;
        
        if(x == z){
            cout << z << endl;
            actualPrices.erase(l);
        }else{
            bool k = false;
            while(*l > z){
                if(l != actualPrices.begin()){
                    l--;
                }else{
                    k = true;
                    cout << -1 << endl;
                    break;
                }
                if (l == actualPrices.end()){
                    break;
                }
            }
            if(k){
                continue;
            }
            if (l == actualPrices.end()){
                cout << -1 << endl;
            }else{
                cout << *l << endl;
                actualPrices.erase(l);
            }
        }
    }
}
