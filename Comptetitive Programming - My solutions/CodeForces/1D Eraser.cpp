#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n,k;
        cin >> n;
        cin >> k;
        
        string x;
        cin >> x;
        
        vector<int> digits;
        
        for(auto & y : x){
            if (y == 'W'){
                digits.push_back(0);
            }else{
                digits.push_back(1);
            }
        }
        
        int min = 0;
        
        for(int i = 0; i < n; i++){
            if(digits[i] == 1){
                i = i + k - 1;
                min = min + 1;
                if(i >=n){
                    break;
                }
            }
        }
        
        
        cout << min << endl;
    }
    
}
