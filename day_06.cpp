#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<int> &t, vector<int> &d) {
    long long res = 1;
    for(int i = 0; i < t.size(); ++i) {
        int cnt = 0;
        for(int j = 1; j < t[i]; ++j) {
            if(j*(t[i]-j) > d[i]) ++cnt;
        }
        res *= cnt;
    }
    return res;
}

ll solve2(ll t, ll d) {
    ll cnt = 0;
    for(int j = 1; j < t; ++j) {
        if(j*(t-j) > d) ++cnt;
    }
    return cnt;
}

int main() {
    string tmp;
    vector<ll> time, d;
    while(getline(cin, tmp)) {
        stringstream ss(tmp);
        string word;
        while(ss>>word) {
            if(word=="Time:") continue;
            if(word=="Distance:") break;
            time.push_back(stoll(word));
        }
        while(ss>>word) {
            d.push_back(stoll(word));
        }
    }
    cout<<time[0]<<" "<<d[0]<<endl;
    cout<<solve2(time[0], d[0]);
}
