#include <iostream>
#include <unordered_map>
#include <list>
#include <sstream>
using namespace std;


int main(){
    
    string n;
    cin >> n;
    
    unordered_map<char, int> frequency;
    
    for(char &c : n){
        frequency[c] ++;
    }
    
    if (n.size() % 2 == 0){
        list<char> palindrome;
        for (auto& entry : frequency){
            
            if (entry.second % 2 != 0){
                cout << "NO SOLUTION";
                exit(0);
            }
            
            char c = entry.first;
            
            bool t = true;
            for(int i = 0; i < entry.second; i ++){
                if(t){
                    t = !t;
                    palindrome.push_back(c);
                }else{
                    palindrome.push_front(c);
                    t = !t;
                }
            }
        }
        
        stringstream ss;
        for (auto & entry : palindrome){
            ss << entry;
        }
        cout << ss.str();
    }else{
        
        int counter = 0;
        list<char> palindrome;
        char c;
        
        for (auto& entry : frequency){
            
            if (entry.second % 2 != 0){
                counter = counter + 1;
                c = entry.first;
                for (int i = 0; i < entry.second; i ++){
                    palindrome.push_back(c);
                }
            }
        }
        
        if (counter != 1){
            cout << "NO SOLUTION";
            exit(0);
        }
        
        for (auto& entry : frequency){
            
            if (entry.first == c){
                continue;
            }
            
            char c = entry.first;
            
            bool t = true;
            for(int i = 0; i < entry.second; i ++){
                if(t){
                    t = !t;
                    palindrome.push_back(c);
                }else{
                    palindrome.push_front(c);
                    t = !t;
                }
            }
        }
        
        stringstream ss;
        for (auto & entry : palindrome){
            ss << entry;
        }
        cout << ss.str();
    }
}
