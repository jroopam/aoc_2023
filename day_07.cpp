#include<bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;


unordered_map<char, int> strength;

int type(string s) {
    unordered_map<char, int> t;
    //for(auto c: s) ++t[c];
    //Part 2
    int j_cnt = 0;
    for(auto c: s){
        if(c=='J'){
            ++j_cnt;
            continue;
        } 
        ++t[c];
    } 

    auto it = t.begin();

    vector<int> cnt;
    while(it != t.end()) cnt.push_back((it++)->second);
    sort(cnt.begin(), cnt.end(), greater<int>());
    int idx = 0;

    // Part 2
    if(cnt.empty()) cnt.push_back(0);
    cnt[idx] += j_cnt;

    if(cnt[idx] == 5) {
        return 7;
    } else if(cnt[idx] == 4) {
        return 6;
    } else if(cnt[idx] == 3) {
        ++idx;
        int val = cnt[idx];
        if(val == 2) return 5;
        else if(val == 1) return 4;
    } else if(cnt[idx] == 2) {
        ++idx;
        int val = cnt[idx];
        if(val == 2) return 3;
        else if(val == 1) return 2;
    } else {
        return 1;
    }
}

bool comp(const pair<string, int> &fir, const pair<string, int> &sec) {
    string a = fir.first;
    string b = sec.first;
    int type_a = type(a);
    int type_b = type(b);
    if(type_a != type_b) return type_a < type_b; 

    for(int i=0; i<a.size(); ++i) {
        if(a[i] != b[i]) return strength[a[i]] < strength[b[i]];
    }
}

int main() {
    strength['A'] = 13;
    strength['K'] = 12;
    strength['Q'] = 11;
    strength['J'] = 10;
    strength['T'] = 9;
    strength['9'] = 8;
    strength['8'] = 7;
    strength['7'] = 6;
    strength['6'] = 5;
    strength['5'] = 4;
    strength['4'] = 3;
    strength['3'] = 2;
    strength['2'] = 1;

    //Part 2
    strength['J'] = 0;
    
    string tmp;
    vector<pair<string, int>> inp;
    while(getline(cin, tmp)){
        pair<string, int> insert;
        stringstream ss(tmp);
        ss>>insert.first;
        string cnt;
        ss>>cnt;
        insert.second = stoi(cnt);
        inp.push_back(insert);
    }
    sort(inp.begin(), inp.end(), comp);
    int ans = 0;
    for(int i=0; i<inp.size(); ++i) {
        ans += (i+1) * inp[i].second;
    }
    cout<<ans<<endl;
}
