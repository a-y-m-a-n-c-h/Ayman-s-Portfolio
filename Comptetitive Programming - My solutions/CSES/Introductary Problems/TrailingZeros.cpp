#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    int x = n/5;
    int counter = 0;
    
    int p = 5;
    
    for(int i = 0; i < x; i++){
        int n = p;
        while (n%5 == 0){
            n = n/5;
            counter = counter + 1;
        }
        p = p + 5;
    }
    cout << counter;
    
}
