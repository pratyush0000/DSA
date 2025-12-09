#include <bits/stdc++.h>
using namespace std;


bool isAnagram(string s, string t){
    if(s.length()!=t.length()){
        return false;
    }
    
    unordered_map<char,int> mpp;
    for(char c : s){
        mpp[c]++;
    }

    for(char c : t){
        mpp[c]--;
    }

    for(auto it : mpp){
        if(it.second!=0){
            return false;
        }
    }

    return true;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    bool hello=isAnagram(s1,s2);
    
    cout << (hello ? "Yes" : "No") << endl;
    
    return 0;
}