#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
    
    int n;
    cin >> n;
    
    vector<pair<int,int>> intervals;
    
    for(int i = 0 ; i < n ; i++){
        int x , y;
        
        cin >> x; cin >> y;
        
        pair k(x,y);
        
        intervals.push_back(k);
    }
    
    sort(intervals.begin(),intervals.end());
    
    vector<int> counters;
    
    for(int i = 0; i < intervals.size(); i ++){
        int counter = 1;
        int finishTime = intervals[i].second;
        for(int j = i + 1; j < intervals.size(); j++){
            if(intervals[j].first <= finishTime){
                counter++;
            }else{
                counters.push_back(counter);
                break;
            }
        }
    }
    
    cout << *max_element(counters.begin(),counters.end());
    
    
}
