#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main(){
    
    int n , x;
    
    cin >> n;
    cin >> x;
    
    vector<int> weights;
    
    
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        weights.push_back(x);
    }
    
    sort(weights.begin() , weights.end());
    
    int counter = 0;
    
    int i = 0;
    int j = weights.size() - 1;
    
    while(i < j){
        if(weights[i] + weights[j] > x){
            j = j - 1;
            counter = counter + 1;
        }else{
            i = i + 1;
            j = j - 1;
            counter = counter + 1;
        }
    }
    if(i == j){
        counter = counter + 1;
    }
    
    cout << counter;
}
