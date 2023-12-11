#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(ll tmp, vector<vector<ll>> &a){
    for(auto x: a){
        if(x[0] <= tmp and tmp <= x[1]){
            return tmp - x[0] + x[2];
        }
    }
    return tmp;
}

ll solve(ll seed, vector<vector<ll>> &s_s, vector<vector<ll>> &s_f, vector<vector<ll>> &f_w, vector<vector<ll>> &w_l, vector<vector<ll>> &l_t, vector<vector<ll>> &t_h, vector<vector<ll>> &h_l) {
    ll tmp = seed;
    tmp = helper(tmp, s_s);
    tmp = helper(tmp, s_f);
    tmp = helper(tmp, f_w);
    tmp = helper(tmp, w_l);
    tmp = helper(tmp, l_t);
    tmp = helper(tmp, t_h);
    tmp = helper(tmp, h_l);
    return tmp;
}

vector<ll> takeInput(string &str) {
    stringstream ss(str);
    string word;
    vector<ll> res;
    while(ss>>word)
        res.push_back(stoll(word));

    ll range = res[2];
    res[2] = res[0];
    res[0] = res[1];
    res[1] += range - 1;
    return res;
}

int main() {
    string tmp;
    int map = 0;
    vector<ll> seeds;
    vector<vector<ll>> s_s, s_f, f_w, w_l, l_t, t_h, h_l;
    while(getline(cin, tmp)) {
        if(map==0) {
            if(tmp == "seed-to-soil map:"){
                map=1;
                continue;
            }
            stringstream ss(tmp);
            string word;
            while(ss>>word){
                if(word == "seeds:") continue;
                seeds.push_back(stoll(word));
            }
        }else if(map==1){
            if(tmp == "soil-to-fertilizer map:") {
                map = 2;
                continue; 
            }
            if(tmp.size()>0)
                s_s.push_back(takeInput(tmp));
        }else if(map == 2) {
            if(tmp == "fertilizer-to-water map:") {
                map = 3;
                continue; 
            }
            if(tmp.size()>0)
                s_f.push_back(takeInput(tmp));
        }else if(map == 3) {
            if(tmp == "water-to-light map:") {
                map = 4;
                continue;
            }
            if(tmp.size()>0)
                f_w.push_back(takeInput(tmp));
        }else if(map == 4) {
            if(tmp == "light-to-temperature map:") {
                map = 5;
                continue; 
            }
            if(tmp.size()>0)
                w_l.push_back(takeInput(tmp));
        }else if(map == 5) {
            if(tmp == "temperature-to-humidity map:") {
                map = 6;
                continue; 
            }
            if(tmp.size()>0)
                l_t.push_back(takeInput(tmp));
        }else if(map == 6) {
            if(tmp == "humidity-to-location map:") {
                map = 7;
                continue; 
            }
            if(tmp.size()>0)
                t_h.push_back(takeInput(tmp));
        }else if(map == 7) {
            if(tmp.size()>0)
                h_l.push_back(takeInput(tmp));
        }

    }
    sort(s_s.begin(), s_s.end());
    sort(s_f.begin(), s_f.end());
    sort(f_w.begin(), f_w.end());
    sort(w_l.begin(), w_l.end());
    sort(l_t.begin(), l_t.end());
    sort(t_h.begin(), t_h.end());
    sort(h_l.begin(), h_l.end());

    /*
    ll min_location = LLONG_MAX;
    for(ll seed: seeds){
        long long res = solve(seed, s_s, s_f, f_w, w_l, l_t, t_h, h_l);
        min_location = min(min_location, res);
    }

    cout<<min_location;
    */
    
    vector<long> new_arr;
    for(auto x: s_s)
        new_arr.push_back(x[0]);

    ll min_location = LLONG_MAX;
    for(ll seed: new_arr){
        long long res = solve(seed, s_s, s_f, f_w, w_l, l_t, t_h, h_l);
        min_location = min(min_location, res);
    }
    /*
    ll min_location = LLONG_MAX;
    for(int i = 1; i < seeds.size(); i+=2) {
        for(int j = seeds[i-1]; j<seeds[i-1]+seeds[i]; ++j){
            ll res = solve(j, s_s, s_f, f_w, w_l, l_t, t_h, h_l);
            min_location = min(min_location, res);
        }
    }
    */
    cout<<min_location<<endl;
}
