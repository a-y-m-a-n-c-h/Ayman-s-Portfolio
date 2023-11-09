#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

typedef long long int ll;


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        ll n, x, y;
        cin >> n;
        cin >> x;
        cin >> y;
       
        ll counter1 = n/x;
        ll counter2 = n/y;
        ll lcm1 = lcm(x,y);
        
        ll counter3 = n/lcm1;
        
        
        counter1 = counter1 - counter3;
        counter2 = counter2 - counter3;
        
        ll h = n;
        ll s = 1;
        ll sum1 = 0;
        ll sum2 = 0;

        
        sum1 = n*counter1 - (counter1*(counter1 - 1))/2;
        sum2 = (counter2*(counter2 + 1))/2;
        
        
//        for(int i = 0; i < counter1; i++){
//            sum1 = sum1 + h;
//            h--;
//        }
//        for(int i = 0; i < counter2; i++){
//            sum2 = sum2 + s;
//            s++;
//        }

        cout << sum1 - sum2 << endl;
        
    }
}
