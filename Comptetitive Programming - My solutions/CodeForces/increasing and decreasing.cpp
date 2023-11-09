#include <iostream>
#include <cmath>
using namespace std;





int main(){

    int t;
    cin >> t;
    
    
    while(t--){
        
        
        int x,y,n;
        cin >> x;
        cin >> y;
        cin >> n;
        
        int distance = y - x;
        
        if(distance == 2){
            cout << -1 << endl;
            continue;
        }
        
        if(n > 1 + ceil(log2(distance))){
            cout << -1 << endl;
        }else{
            n = n - 2;
            cout << x << " ";
            while(distance != 2){
                
                
                if(n == 1){
                    break;
                }
                
                int halve = ceil((double)distance/2);
                int remainingDistance = distance - halve;
                
                x = x + halve;
                
                cout << x << " ";
                
                distance = remainingDistance;
                n--;
            }
            
            cout << y - 1 << " " << y << endl;
        }
    }
    
}
