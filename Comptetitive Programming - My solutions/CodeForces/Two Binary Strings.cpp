#include <iostream>
using namespace std;

int main(){
    
    int t;
    
    cin >> t;
    
    while(t--){
        
        string x;
        string y;
        
        cin >> x;
        cin >> y;
        
        bool entered = false;
        
        for(int i = 0; i < x.size() - 1; i++){
            if(x[i] == '0' && x[i + 1] == '1'){
                if(y[i] == '0' && y[i + 1] == '1'){
                    cout << "YES" << endl;
                    entered = true;
                    break;
                }
            }
        }
        
        if(!entered){
            cout << "NO" << endl;
        }
    }
    
    
}
