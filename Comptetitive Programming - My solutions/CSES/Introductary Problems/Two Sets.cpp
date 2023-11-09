#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> setss;

bool findSubsetSum(vector<int> package, int target){ // given a package chack if there is a subset that
                                                     // sums to target
    
    if (target <0){
        return 0;
    }else if(target == 0){
        return 1;
    }
    
    if (package.size() == 0){
        return 0;
    }
    
    for (auto &x : package){
        vector<int> copy = package;
        copy.erase(remove(copy.begin(),copy.end(),x),copy.end()); // remove x
        
        if (!findSubsetSum(copy,target - x)){
            continue;
        }else{
            setss.push_back(x);
            return 1;
        }
    }
    return 0;
}





int main(){
    
    /* // exponential way
    int n;
    cin >> n;
    
    int sum = n*(n+1)/2;
    
    vector<int> package;
    
    for(int i = 1; i <= n; i ++){
        package.push_back(i);
    }
    
    if (sum%2 == 0){
        int value = sum/2;
        
        if (findSubsetSum(package,value)){
            cout << "YES" << endl;
            cout << setss.size() << endl;
            vector<int> sets2;
            for(int i = 0;i < setss.size(); i ++){
                cout << setss[i] << " ";
            }
            cout << endl;
            cout << n - setss.size() << endl;
            for(int i = 1; i <= n; i ++){
                if (find(setss.begin(),setss.end(),i) == setss.end()){
                    cout << i << " ";
                }
            }
        }
    }else{
        cout << "NO";
    }
    */
    
    
    
    int n;
    cin >> n;
    
    int sum = n*(n+1)/2;
    
    vector<int> package;
    
    for(int i = 1; i <= n; i ++){
        package.push_back(i);
    }
    
    if (sum%2 == 0){ // always works since I always have more n + 1' s than I need
        int value = sum/2;
        
        vector<int> set;
        
        if(n%2 == 0){
            int k = 0;
            int numberofnplus1sIneed = n/4;
            for(int i = 0; i < numberofnplus1sIneed; i++){
                set.push_back(package[i]);
                set.push_back(package[n-1-i]);
                k = i;
            }
            k = k + 1;
            cout << "YES" << endl;
            cout << set.size() << endl;
            for(int i = 0; i < set.size(); i++){
                cout << set[i] << " ";
            }
            
            cout << endl;
            
            cout << package.size() - set.size() << endl;
            
            int size = package.size() - set.size() + k;
            
            for(;k < size; k++){
                cout << package[k] << " ";
            }
        }else{
            int k = 0;
            int numberofnsIneed = (n + 1)/4;
            
            for(int i = 0; i < numberofnsIneed; i++){
                set.push_back(package[i]);
                set.push_back(package[n-2-i]);
                k = i;
            }
            k = k + 1;
            cout << "YES" << endl;
            cout << set.size() << endl;
            for(int i = 0; i < set.size(); i++){
                cout << set[i] << " ";
            }
            
            cout << endl;
            
            cout << package.size() - set.size() << endl;
            
            int size = package.size() - set.size() + k;
            
            for(;k < size - 1; k++){
                cout << package[k] << " ";
            }
            
            cout << package[n-1];
        }
        
        
    }else{
        cout << "NO";
    }
    
    
}

