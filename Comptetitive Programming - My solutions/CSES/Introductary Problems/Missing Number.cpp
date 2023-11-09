#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
int main(){
    int n;
    cin >> n;
    
    vector<int> numbers;
    
    for (int i = 0; i < n - 1; i ++){
        int k;
        cin >> k;
        numbers.push_back(k);
    }
    sort(numbers.begin(),numbers.end());
    
    int j = 1;
    
    bool entered = false;
    
    for (int i = 0; i < n - 1; i ++){
        if (numbers[i] != j){
            entered = true;
            cout << j;
            break;
        }
        j = j + 1;
    }
    
    if(!entered){
        cout << j;
    }
}
*/
int main() {
    int n; cin >> n; int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x; res ^= x ^ (i + 1); // ^= : bitwise xor
    }
    cout << (res ^ n) << '\n';
}
