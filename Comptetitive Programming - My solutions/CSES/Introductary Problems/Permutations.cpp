#include <iostream>
#include <list>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    if (n == 1){
        cout << 1;
        exit(0);
    }
    
    if (n <= 3){
        cout << "NO SOLUTION";
    }else{
        list<int> numbers;
        numbers.push_back(2);
        numbers.push_back(4);
        numbers.push_back(1);
        numbers.push_back(3);
        
        bool flip = true;
        
        for (int i = 5; i <= n; i ++){
            if (flip){
                numbers.push_back(i);
                flip = !flip;
            }else{
                numbers.push_front(i);
                flip = !flip;
            }
        }
        
        for (auto it = numbers.begin(); it != numbers.end(); it++){
            cout << *it << " ";
        }
    }
}


