#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    int n;
    
    cin >> n;
    
    vector<int> input;
    
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        
        input.push_back(x);
        
    }
    
    sort(input.begin(),input.end());
    
    int counter = 0;
    
    for(int i = 0; i < input.size() - 1; i++){
        
        if (input[i] != input[i+1]){
            counter++;
        }
        
    }
    
    
    cout << counter + 1<< endl;
    
}
