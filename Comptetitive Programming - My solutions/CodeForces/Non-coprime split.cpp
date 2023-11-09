#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    if (n <= 3) {
        return true;  // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Numbers divisible by 2 or 3 are not prime
    }

    // Check for prime numbers using 6k +/- 1 rule
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int l,r;
        cin >> l;
        cin >> r;
        
        if((l <= 3)&&(r <=3)){
            cout << -1 << endl;
            continue;
        }
        
        if (l == r){
            if(isPrime(l)){
                cout << -1 << endl;
                continue;
            }else{
                for(int i = 2; i < l; i++){
                    if(l%i == 0){
                        int x = l/i;
                        cout << x*(i - 1) << " " << x << endl;
                        break;
                    }
                }
            }
        }else{
            if(r%2 == 0){
                cout << r/2 << " " << r/2 <<endl;
                continue;
            }
            if(l%2 == 0 && (l!=2)){
                cout << l/2 << " " << l/2 <<endl;
                continue;
            }
            cout << (r - 1)/2 << " " << (r - 1)/2 << endl;
        }
    }
    
    
    
}
