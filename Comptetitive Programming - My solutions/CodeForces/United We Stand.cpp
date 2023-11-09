#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    int t;
    cin >> t;
    
    
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int> numbers;
        
        int p;
        cin >> p;
        numbers.push_back(p);
        
        bool isDistinct = false;
        
        for(int i = 0; i < n - 1; i++){
            int x;
            cin >> x;
            
            if(x != p){
                isDistinct = true;
            }
            
            numbers.push_back(x);
        }
        
        if(!isDistinct){
            cout << -1 << endl;
            continue;
        }else{
            int max = *max_element(numbers.begin(),numbers.end());
            
            vector<int> b;
            vector<int> c;
            
            for(auto &x : numbers){
                if(x == max){
                    c.push_back(max);
                }else{
                    b.push_back(x);
                }
            }
            
            cout << b.size() << " " << c.size() << endl;
            
            for(auto &x : b){
                cout << x << " ";
            }
            cout << endl;
            
            for(auto &x : c){
                cout << x << " ";
            }
            cout << endl;
            
        }
        
    }
    
    
    
    
    
    
}
