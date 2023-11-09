#include <iostream>
using namespace std;


int main(){
    
    int t;
    cin >> t;
    
    
    while(t--){
        string x;
        cin >> x;
        
        
        for(int i = 0; i < x.size(); i++){
            if(x[i] == '1'){
                cout << 13 << endl;
                break;
            }
            if(x[i] == '3'){
                cout << 31 << endl;
                break;
            }
        }
    }
    
}
