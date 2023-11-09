#include <iostream>
#include <vector>
using namespace std;



vector<string> recEnum(int n){
    if(n == 1){
        vector<string> base;
        base.push_back("0");
        base.push_back("1");
        return base;
    }
    
    vector<string> strings = recEnum(n - 1);
    
    vector<string> toBeReturned;
    
    for(int i = 0; i < strings.size(); i ++){
        string x = "0";
        x.append(strings[i]);
        toBeReturned.push_back(x);
    }
    
    for(int i = strings.size() - 1; i >= 0; i --){
        string x = "1";
        x.append(strings[i]);
        toBeReturned.push_back(x);
    }
    
    return toBeReturned;
}



int main(){
    
    int n;
    cin >> n;
    
    vector<string> GrayCode = recEnum(n);
    
    for(int i = 0; i < GrayCode.size(); i ++){
        cout << GrayCode[i] << endl;
    }
    
}
