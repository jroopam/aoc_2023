#include<bits/stdc++.h>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;
typedef long long ll;

int steps(string start, string end, unordered_map<string, pair<string, string>> &network, string &path) {
    int res = 0;
    int i = 0;
    while(true) {
        i %= path.size();
        if(path[i]=='R') {
            start = network[start].second;
        } else {
            start = network[start].first;
        }
        //if(start == "ZZZ") return res + 1;
        //Part 2
        if(start[2] == 'Z') return res+1;
        ++i, ++res;
    }
    return -1;
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findLCM(vector<int> nums) {
    ll ans = nums.front();
    for(int x: nums) 
        ans = ((x*ans) / gcd(x, ans));
    return ans;
}

int steps2(vector<string> starts, string end, unordered_map<string, pair<string, string>> &network, string &path) {
    int res = 0;
    int i = 0;
    while(true) {
        i %= path.size();
        for(int j=0; j<starts.size(); ++j) {
            if(path[i]=='R') {
                starts[j] = network[starts[j]].second;
            } else {
                starts[j] = network[starts[j]].first;
            }
        }
        int cnt = 0;
        for(string start: starts) {
            if(start[2] == 'Z') ++cnt; 
        }
        if(cnt == starts.size()) return res + 1;
        cout<<res<<endl;
        ++i, ++res;
    }
    return -1;
}

int main() {
    string navigate;
    unordered_map<string, pair<string, string>> network;

    string tmp;
    int line = 0;
    while(getline(cin, tmp)) {
        if(line == 0) navigate = tmp;
        if(tmp.size()==0) continue;

        if(line > 0) {
            stringstream ss(tmp);
            string word;
            int w = 0;
            vector<string> inp;
            while (ss>>word) {
                if(word!="="){
                    inp.push_back(word);
                }
            }
            if(inp.size()==3)
            network[inp[0]] = make_pair(inp[1].substr(1, 3), inp[2].substr(0, 3));
        }
        ++line;
    }
    //cout<<steps("AAA", "ZZZ", network, navigate)<<endl;

    //Part 2
    vector<string> starts;
    vector<int> sol;
    for(auto x: network){
        if(x.first[2] == 'A'){
            cout<<x.first<<endl;
            sol.push_back(steps(x.first, "ZZZ", network, navigate));
        } 
    }
    //for(int res: sol) cout<<res<<endl;
    //The following lcm is not working correctly. I used an online calculator to find LCM
    cout<<findLCM(sol);
    //cout<<steps2(starts, "ZZZ", network, navigate)<<endl;
}
