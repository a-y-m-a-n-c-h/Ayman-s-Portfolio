#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;



int main(){
    
    
    int t;
    cin >> t;
    
    while(t--){
        int n,k;
        cin >> n;
        cin >> k;
        
        vector<int> fruits(n,0);
        
        for(auto& x : fruits){
            cin >> x;
        }
        vector<int> heights(n,0);
        
        for(auto& x : heights){
            cin >> x;
        }
        
        int min = 0;
        int a = 0;
        int b = 0;
        int differ = b - a;
        int maxSum = heights[0];
        int sum = heights[0];
        
        for(int i = 0; i < n - 1; i ++){
            if(heights[i + 1] % heights[i] != 0){
                if (b - a > differ && (k - sum) > 0){
                    maxSum = sum;
                    differ =
                }
            }else{
                sum = sum + fruits[i];
                b = i;
            }
        }
        
    }
    
}
