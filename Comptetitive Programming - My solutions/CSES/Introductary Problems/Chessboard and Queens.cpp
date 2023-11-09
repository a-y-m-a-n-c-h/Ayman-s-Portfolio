#include <iostream>
#include <vector>
using namespace std;


int counter = 0;


vector<vector<char>> clear(vector<vector<char>> matrix, int i, int j){
    
    
//    for(int k = j; k<8; k++){ // right
//        if (matrix[i][k] == '.'){
//            matrix[i][k] = '*';
//        }
//    }
    
//    for(int k = j; k > -1; k--){ // left
//        if (matrix[i][k] == '.'){
//            matrix[i][k] = '*';
//        }
//    }
    
    for(int k = i; k < 8; k++){ // down
        if (matrix[k][j] == '.'){
            matrix[k][j] = '*';
        }
    }
    
//    for(int k = i; k > -1; k--){ // up
//        if (matrix[k][j] == '.'){
//            matrix[k][j] = '*';
//        }
//    }
    
    
    int k = i; int l = j;
    
    while(k < 8 && l < 8){ // down right
        if (matrix[k][l] == '.'){
            matrix[k][l] = '*';
        }
        k++;
        l++;
    }
    k = i; l = j;
    
//    while(k > -1 && l < 8){ // up right
//        if (matrix[k][l] == '.'){
//            matrix[k][l] = '*';
//        }
//        k--;
//        l++;
//    }
    
    k = i; l = j;
    
    while(k < 8 && l > -1){ // down left
        if (matrix[k][l] == '.'){
            matrix[k][l] = '*';
        }
        k++;
        l--;
    }
    
    k = i; l = j;
    
//    while(k > -1 && l > -1){ // up left
//        if (matrix[k][l] == '.'){
//            matrix[k][l] = '*';
//        }
//        k--;
//        l--;
//    }
    
    return matrix;
    
}



void placing(vector<vector<char>> matrix, int queen){
    
    if(queen == 8){
        counter = counter + 1;
    }
    
    for (int i = queen; i < 8; i++){
        
        if(i>queen){
            return;
        }
        
        bool entered = false;
        for(int j = 0; j < 8; j++){
            if (matrix[queen][j] == '*'){
                continue;
            }else{
                entered = true;
                vector<vector<char>> copy = clear(matrix,i,j);
                placing(copy,queen + 1);
            }
        }
        if(!entered){
            return;
        }
    }
    
}




int main(){
    
    vector<vector<char>> matrix;
    
    for(int i = 0; i < 8; i ++){
        vector<char> row;
        for (int j = 0; j < 8; j ++){
            
            char a;
            cin >> a;
            row.push_back(a);
            
        }
        matrix.push_back(row);
    }
    
    placing(matrix,0);
    
    cout << counter << endl;
    
}

