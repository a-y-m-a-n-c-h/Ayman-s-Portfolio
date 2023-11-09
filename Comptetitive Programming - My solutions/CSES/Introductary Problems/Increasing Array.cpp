#include <iostream>
#include <vector>
using namespace std;

/*
int main(){
   int n;
    cin >> n;
    
    vector<int> numbers;
    
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    long long int counter = 0;
    
    for (int i = 1; i < numbers.size(); i ++){
        int a = numbers[i - 1];
        if (numbers[i] >= a){
            continue;
        }else{
            counter = counter + (a - numbers[i]);
            numbers[i] = a;
        }
    }
    cout << counter;
}
*/

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n; vector<int> v(n);
    for (auto &x : v) { cin >> x; }
    int cur = 0; ll res = 0;

    for (auto &x : v) { cur = max(cur, x);
        res += cur - x;
        
    }
    cout << res << '\n';
}


