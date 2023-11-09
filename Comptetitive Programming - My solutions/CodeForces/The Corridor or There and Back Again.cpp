#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<pair<int,int>> input;
        
        for(int i = 0; i < n; i ++){
            int d, s;
            cin >> d;
            cin >> s;
            
            
            pair<int,int> a(d,s);
            input.push_back(a);
            
        }
        
        
        auto first = input[0];
        
        int k = ceil((double)first.second/2) - 1;
        int limiter = first.first + k;
        
        for(auto & x : input){
            k =ceil((double)x.second/2) - 1;
            int l = x.first + k;
            
            if(l < limiter){
                limiter = l;
            }
        }
        
        cout << limiter << endl;
        
    }
    
}
