#include <iostream>
using namespace std;



int main(){
    
    int target;
    cin >> target;
    
    for(int i = 0; i < target; i++){
        int a;
        int b;
        cin >> a;
        cin >> b;
        
        
        if (a > b){
            int k = 2*b - a;
            if(k >= 0 && k%3 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            int k = 2*a - b;
            if(k >= 0 && k%3 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    
    
}
