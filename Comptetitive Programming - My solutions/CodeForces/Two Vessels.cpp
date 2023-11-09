#include <iostream>
#include <cmath>
using namespace std;






int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int a,b,c;
        
        cin >> a;
        cin >> b;
        cin >> c;
        
        if(a == b){
            cout << 0 << endl;
            continue;
        }else if(a < b){
            swap(a,b);
        }
        
        double k = ceil((double)(a - b)/(double)(2*c));
        
        cout << k << endl;
        
        
    }
    
    
    
}
