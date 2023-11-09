#include <iostream>
#include <vector>
using namespace std;


int main(){
    
    int t;
    cin >> t;
    
    
    while(t--){
        
        vector<string> matrix(10);
        
        for(auto &x : matrix){
            cin >> x;
        }
        
        vector<string> matrix2;
        
        for(int i = 9 ; i >= 5; i--){
            matrix2.push_back(matrix[i]);
        }
        
        int sum = 0;
        for(int i = 0; i < 5; i ++){
            for(int j = 0; j < 10; j++){
                if(matrix[i][j] == 'X'){
                    if(j >= i && j <= 9 - i){
                        sum = sum + i + 1;
                    }else if(j < i){
                        sum = sum + j + 1;
                    }else{
                        sum = sum + 9 - j + 1;
                    }
                }
            }
        }
        
        for(int i = 0; i < 5; i ++){
            for(int j = 0; j < 10; j++){
                if(matrix2[i][j] == 'X'){
                    if(j >= i && j <= 9 - i){
                        sum = sum + i + 1;
                    }else if(j < i){
                        sum = sum + j + 1;
                    }else{
                        sum = sum + 9 - j + 1;
                    }
                }
            }
        }
        
        cout << sum << endl;
        
    }
    
    
    
}
