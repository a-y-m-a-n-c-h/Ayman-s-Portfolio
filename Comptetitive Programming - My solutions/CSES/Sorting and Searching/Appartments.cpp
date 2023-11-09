#include <iostream>
#include <vector>
using namespace std;


bool binarySearch(vector<int> & actualSizes, int k, int desiredSize, vector<int> & occupied){
    
    int low = 0;
    int high = actualSizes.size();
    
    int mid = 0;
    
    while(low <=high){
        mid = (low + high)/2;
        
        if((abs(desiredSize - actualSizes[mid]) <= k)&&(occupied[mid] != 1)){
            if(low == high){
                occupied[low]++;
                return 1;
            }
            high = mid;
        }else if(abs(desiredSize - actualSizes[mid]) <= k){
            low = mid + 1;
        }else{
            if(desiredSize - actualSizes[mid] < 0){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    return 0;
    
}







int main(){
    
    
    int n;
    int m;
    int k;
    
    cin >> n;
    cin >> m;
    cin >> k;
    
    vector<int> desiredSizes(n);
    vector<int> actualSizes(m);
    vector<int> occupied(m,0);
    
    
    for(auto & x : desiredSizes){
        cin >> x;
    }
    
    for(auto & x : actualSizes){
        cin >> x;
    }
    
    sort(actualSizes.begin(),actualSizes.end());
    sort(desiredSizes.begin(),desiredSizes.end());
    
    int counter = 0;
    
    for(auto & x : desiredSizes){
        
        if(binarySearch(actualSizes, k, x, occupied)){
            
            counter++;
            
        }
    }
    
    cout << counter;
    
}
