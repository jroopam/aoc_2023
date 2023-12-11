#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    stringstream ss(s);
    string word;
    int i = 0;
    int cnt = 0;
unordered_set<int> st;
while(ss>>word){
    ++i;
    if(i<3) continue;
    if(word == "|") break;
    st.insert(stoi(word));
}
while(ss>>word){
    if(st.find(stoi(word)) != st.end()) ++cnt;
}
return cnt;
return pow(2, cnt-1);
}

int main() {
/*
string tmp;
int sum = 0;
while(getline(cin, tmp)) {
    sum += solve(tmp);
}
cout<<sum;
*/


string tmp;
int line = 1;
vector<int> instances_of_card(205, 1);
    while(getline(cin, tmp)) {
        int num = solve(tmp);
        ++line;
        for(int i=line; i<line+num; ++i) {
            instances_of_card[i] += instances_of_card[line-1];
        }
    }
    int res = 0;
    for(int i=1; i<line; ++i) {
        res += instances_of_card[i];
    }
    cout<<res;
}
