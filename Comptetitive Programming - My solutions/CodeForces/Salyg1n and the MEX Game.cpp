#include <iostream>
#include <vector>
#include <set>
using namespace std;



int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        set<int> integers;
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            integers.insert(x);
        }
        
        if(*integers.begin() != 0){
            cout << 0 << endl;
            cout.flush();
            int y;
            cin >> y;
            if(y == -2){
                exit(1);
            }
        }else{
            auto it = integers.begin();
            int k = 0;
            while(k != integers.size() && *it == k){
                it++;
                k++;
            }
            cout << k << endl;
            cout.flush();
            int y;
            cin >> y;
            
            if(y == -2){
                exit(1);
            }
            
            while(y!=-1){
                cout << y << endl;
                cout.flush();
                cin >> y;
                if(y == -2){
                    exit(1);
                }
            }
        }
    }
}
