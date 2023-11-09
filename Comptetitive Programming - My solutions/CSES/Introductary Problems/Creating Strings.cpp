#include <iostream>
#include <vector>
using namespace std;




vector<string> generate(string x){
    if (x.size() == 1){
        vector<string> b;
        b.push_back(x);
        return b;
    }
    vector<string> perm = generate(x.substr(1,x.size() - 1));
    
    vector<string> toBeReturned;
    
    char t = x[0];
    
    for(auto & x: perm){
        for(int i = 0; i < x.size() + 1 ; i ++){
            string y = x.substr(0,i) + t + x.substr(i ,x.size() - i);
            toBeReturned.push_back(y);
        }
    }
    return toBeReturned;
}



int main(){
    string n;
    cin >> n;
    
    vector<string> permutations = generate(n);
    
    sort(permutations.begin(), permutations.end());
    
    permutations.erase(unique(permutations.begin(), permutations.end()),permutations.end());
    
    cout << permutations.size() << endl;
    
    for (int i = 0; i < permutations.size(); i ++){
        cout << permutations[i] << endl;
    }
    
}































// inefficient method

//vector<string> permutations;
//int counter = 0;
//
//void createStrings(vector<string> characters, string x){
//
//    if(characters.size() == 0){
//        if((find(permutations.begin(),permutations.end(), x)) == permutations.end()){
//            permutations.push_back(x);
//            counter = counter + 1;
//        }
//        return;
//    }
//
//
//    for (auto & c : characters){
//
//        vector<string> characters2 = characters;
//
//        characters2.erase(find(characters2.begin(), characters2.end(), c));
//
//        createStrings(characters2,x + c);
//    }
//
//}
//
//
//
//
//
//int main(){
//
//    vector<string> characters;
//
//    string n;
//    cin >> n;
//
//    for(auto &x : n){
//        characters.push_back(string(1,x));
//    }
//
//    createStrings(characters,"");
//
//    cout << counter << endl;
//
//    for(auto& x : permutations){
//        cout << x << endl;
//    }
//
//}
