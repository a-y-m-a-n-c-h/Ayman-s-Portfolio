#include <iostream>
using namespace std;




int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        string x;
        cin >> x;
        if(x == "bac"| x == "cba"| x == "acb" | x == "abc"){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    
}
