#include <iostream>
#include <cmath>
using namespace std;



int main(){
    
    int n;
    cin >> n;
    
    long long int x = pow(10,9) + 7;
    
    int result = 1;
    
    for (int i = 0; i < n; i++ ){
        result = result*2 % x;
    }
    cout << result;
    

    
}

