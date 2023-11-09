#include <iostream>
using namespace std;


bool f(int a, int b){
    
    if(a >= b - 1 and a <= 2*(b+1)){
        return 1;
    }
    return 0;
    
}




int main(){
    
    
    int g1, g2;
    cin >> g1;
    cin >> g2;
    
    int b1, b2;
    cin >> b1;
    cin >> b2;
    
    if(f(b1,g2) || f(b2,g1)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}
