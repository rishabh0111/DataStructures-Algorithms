#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    //pre compute
    int hash[26] = {0}; // for lower case or upper case
    // int hash[256] = {0}; // for all case characters
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++; // hash[s[i] -'A'] for upper case
        // hash[s[i]] for all case characters
    }

    int q;
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        //fetch
        cout << hash[c-'a'] << endl;
    }
    

    return 0;
}