#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;


int main(){
    
    int q;
    cin >> q;
    
    
    
    for(int i = 0; i < q; i ++){
        
        ll x;
        cin >> x;
        
        if (x < 10){
            cout << x << endl;
            continue;
        }
        
        int numberOfDigits = 1;
        
        ll difference = x;
        
        ll number = 1;
        
        ll l = 0;
        
        ll actualValue = 1;
        
        while(difference >= 0){
            
            ll y = 9*pow(10,l)*(l+1);
            
            number = number + y;
            
            difference = x - number;
            
            if(difference < 0){
                number = number - y;
                difference = x - number;
                break;
            }
            
            numberOfDigits = numberOfDigits + 1;
            
            actualValue = actualValue + 9*pow(10,l);
            
            l++;
        }
        
        actualValue = actualValue + difference/numberOfDigits;
        
        string av = to_string(actualValue);
        
        cout << av[difference%numberOfDigits] << endl;
        
        
    }
    
    
}
