#include <iostream>
using namespace std;



/*int main(){
    string n;
    cin >> n;
    int counter = 0;
    int maxcounter = 0;
    for(int i = 0; i<n.length() - 1; i++){
        if (n[i] == n[i + 1]){
            counter = counter + 1;
        }else{
            if (counter > maxcounter){
                maxcounter = counter;
            }
            counter = 0;
        }
    }
    if (counter > maxcounter){
        maxcounter = counter;
    }
    cout << maxcounter + 1;
}
*/

int main() {
    string s; cin >> s; int n = (int)s.size();
    int i = 0, j = 0, res = 0;
    while (j != n) {
        if (s[j] == s[i]) { j++; continue; }
        res = max(res, j - i); i = j;
    }
    cout << max(res, j - i) << '\n';
}
