#include <iostream>
#include <vector>
using namespace std;

int counter = 0;

string input;

vector<vector<bool>> matrix(7,vector<bool>(7));

vector<string> moves;


void countThePaths(int i,int j,int counter3){
    
    bool left = 1, right = 1, up = 1, down = 1, upperRight = 1, upperLeft = 1, lowerRight = 1, lowerLeft = 1;
    
    if(j > 0){
        left = matrix[i][j-1];
    }
    if(j < 6){
        right = matrix[i][j+1];
    }
    if(i > 0){
        up = matrix[i-1][j];
    }
    if(i < 6){
        down = matrix[i+1][j];
    }
    
    bool canGoUp = 1, canGoDown = 1, canGoRight = 1, canGoLeft = 1;
    
    if(i > 0 && j < 6){
        upperRight = matrix[i-1][j+1];
    }else{
        upperRight = 0;
    }
    if(upperRight&&!up&&!right){
        canGoUp = 0;
        canGoRight = 0;
    }
    
    if(i > 0 && j > 0){
        upperLeft = matrix[i-1][j-1];
    }else{
        upperLeft = 0;
    }
    if(upperLeft&&!up&&!left){
        canGoUp = 0;
        canGoLeft = 0;
    }
    
    if(i < 6 && j < 6){
        lowerRight = matrix[i+1][j+1];
    }else{
        lowerRight = 0;
    }
    if(lowerRight&&!down&&!right){
        canGoDown = 0;
        canGoRight = 0;
    }
    
    if(i < 6 && j > 0){
        lowerLeft = matrix[i+1][j-1];
    }else{
        lowerLeft = 0;
    }
    if(lowerLeft&&!down&&!left){
        canGoDown = 0;
        canGoLeft = 0;
    }
    
    
    if(left&&right&&!up&&!down){
        return;
    }
    if(up&&down&&!left&&!right){
        return;
    }
    
    
    if(counter3 != 48 && matrix[6][0] == 1){
        return;
    }
    
    
//    if(48 - counter3 < (6 - i + j)){
//        return;
//    }
    
    if (counter3 == 48 && (i == 6 && j == 0)){
        counter = counter + 1;
        //cout << counter << endl;
        return;
    }
    
//    if (counter3 == 48){
//        return;
//    }
    matrix[i][j] = 1;
    
    
    
    if(input[counter3] == 'D'){
        if((i + 1 < 7)&&(matrix[i + 1][j] == 0)){ // down
            moves.push_back("down");
            countThePaths(i+1,j,counter3 + 1);
            matrix[i+1][j] = 0;
            moves.pop_back();
        }
    }
    
    if(input[counter3] == 'R'){
        
        if((j + 1 < 7)&&(matrix[i][j + 1] == 0)){ // right
            moves.push_back("right");
            countThePaths(i,j+1,counter3 + 1);
            matrix[i][j+1] = 0;
            moves.pop_back();
        }
        
    }
    
    if(input[counter3] == 'U'){
        
        if((i - 1 > -1)&&(matrix[i - 1][j] == 0)){ // up
            moves.push_back("up");
            countThePaths(i-1,j,counter3 + 1);
            matrix[i-1][j] = 0;
            moves.pop_back();
        }
        
    }
    
    
    if(input[counter3] == 'L'){
        if((j - 1 > -1)&&(matrix[i][j - 1] == 0)){ // left
            moves.push_back("left");
            countThePaths(i,j - 1,counter3 + 1);
            matrix[i][j-1] = 0;
            moves.pop_back();
        }
    }
    
    
    if(input[counter3] == '?'){
        
        bool down = 0, up = 0 , left = 0, right = 0;
        
        if(canGoDown){
            if((i + 1 < 7)&&(matrix[i + 1][j] == 0)){ // down
                
                moves.push_back("down");
                down = 1;
                countThePaths(i+1,j, counter3 + 1);
                matrix[i+1][j] = 0;
                moves.pop_back();
                
            }
        }
        if(canGoRight){
            if((j + 1 < 7)&&(matrix[i][j + 1] == 0)){ // right
                
                moves.push_back("right");
                right = 1;
                countThePaths(i,j+1, counter3 + 1);
                matrix[i][j+1] = 0;
                moves.pop_back();
                
            }
        }
        if(canGoUp){
            if((i - 1 > -1)&&(matrix[i - 1][j] == 0)){ // up
                
                moves.push_back("up");
                up = 1;
                countThePaths(i-1,j, counter3 + 1);
                matrix[i-1][j] = 0;
                moves.pop_back();
                
            }
        }
        if(canGoLeft){
            if((j - 1 > -1)&&(matrix[i][j - 1] == 0)){ // left
                
                moves.push_back("left");
                left = 1;
                countThePaths(i,j - 1, counter3 + 1);
                matrix[i][j-1] = 0;
                moves.pop_back();
                
            }
        }
    }
    
}



int main(){
    
    cin >> input;
    
    countThePaths(0,0,0);
    
    cout << counter;
    
}
