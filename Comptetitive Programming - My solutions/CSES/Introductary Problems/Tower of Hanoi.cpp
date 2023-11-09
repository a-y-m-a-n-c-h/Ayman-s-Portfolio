#include <iostream>
#include <sstream>
using namespace std;

stringstream moves;

int counter = 0;

void towerOfHanoi(int n, int start, int middle, int end){
    
    if(n == 0){
        return;
    }
    
    towerOfHanoi(n-1,start,end,middle);
    
    moves << start << " " << end << "\n";
    counter = counter + 1;
    
    towerOfHanoi(n-1,middle,start,end);
    
}





int main(){
    
    int n;
    cin >> n;
    
    towerOfHanoi(n,1,2,3);
    
    cout << counter << endl;
    
    cout << moves.str();
    
}
