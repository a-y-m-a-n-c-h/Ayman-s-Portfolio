#include <iostream>
#include <vector>
#include <cmath>
using namespace std;




int main(){
    
    int n;
    cin >> n;
    
    vector<int> xCo;
    vector<int> yCo;
    vector<double> perimiterSpot;
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < 3 ; j++){
            int x,y;
            cin >> x;
            cin >> y;
            
            xCo.push_back(x);
            yCo.push_back(y);
        }
            
        int x1 = xCo[i];
        int y1 = yCo[i];
        
        int x2 = xCo[i + 1];
        int y2 = yCo[i + 1];
        
        int x3 = xCo[i + 2];
        int y3 = yCo[i + 2];
        
        double d1 = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
        
        double d2 = sqrt(pow(x3 - x2,2) + pow(y3 - y2,2));
        
        double d3 = sqrt(pow(x3 - x1,2) + pow(y3 - y1,2));
        
        double peri = d1 + d2 + d3;
        
        perimiterSpot.push_back(peri);
            
        
        
    }
    
    double total = 0;
    
    for(auto & x : perimiterSpot){
        total += x;
    }
    
    cout << total;
    
}
