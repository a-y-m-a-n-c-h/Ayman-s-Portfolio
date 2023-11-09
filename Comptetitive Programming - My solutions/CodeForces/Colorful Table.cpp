#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;




int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n,k;
        
        cin >> n;
        cin >> k;
        
        vector<int> numbers(n);
        unordered_map<int, bool> present;
        
        for(int i = 0; i < k; i++){
            present[i] = 0;
        }
        
        for(auto &x : numbers){
            cin >> x;
        }
        
        vector<int> leftMost(k,0);
        vector<int> rightMost(k,0);
        
        int j = 0;
        
        for(int i = 0; i < n ; i ++){
            present[numbers[i]] = 1;
            int h = j;
            for(; h < numbers[i]; h++){
                leftMost[h] = i + 1;
            }
            j = max(h,numbers[i]);
        }
        
        j = 0;
        
        for(int i = n-1; i > -1; i --){
            int h = j;
            for(; h < numbers[i]; h++){
                rightMost[h] = i + 1;
            }
            j = max(h,numbers[i]);
        }
        vector<int> answer(k,0);
        
        for(int i = 0; i < k; i ++){
            
            if(present[i + 1]){
                answer[i] = 2*(rightMost[i] - leftMost[i] + 1);
            }
            
        }
        
        for(auto&x : answer){
            cout << x << " ";
        }
        cout << endl;
    }
    
}
