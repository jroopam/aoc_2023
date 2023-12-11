#include <bits/stdc++.h>
using namespace std;

unordered_map<char, unordered_set<char>> direction;

int travel(vector<string> &pipes, int i, int j, char dir) {
    if(i<0 or j<0 or i>=pipes.size() or j>=pipes[i].size() or pipes[i][j] == '.' or direction[dir].find(pipes[i][j]) == direction[dir].end()) return 0;
    if(pipes[i][j] == 'S') return 1;

    char c = pipes[i][j];
    pipes[i][j] = '.';
    int ans = 0;

    if(direction['D'].find(c) != direction['D'].end())
        ans = max(ans, travel(pipes, i-1, j, 'U'));
    if(direction['U'].find(c) != direction['U'].end())
        ans = max(ans, travel(pipes, i+1, j, 'D'));
    if(direction['R'].find(c) != direction['R'].end())
        ans = max(ans, travel(pipes, i, j-1, 'L'));
    if(direction['L'].find(c) != direction['L'].end())
        ans = max(ans, travel(pipes, i, j+1, 'R'));
    
    return 1 + ans;
}

int solve(vector<string> &pipes) {
    int row, col;
    for(int i=0; i<pipes.size(); ++i){
        for(int j=0; j<pipes[i].size(); ++j){
            if(pipes[i][j] == 'S'){
                row = i, col = j;
                break;
            }
        }
    }

    return 1+max({travel(pipes, row-1, col, 'U'), travel(pipes, row + 1, col, 'D'), travel(pipes, row, col - 1, 'L'), travel(pipes, row, col + 1, 'R')});

}

int main() {
    vector<string> pipes;
    string tmp;
    while(cin>>tmp) {
        pipes.push_back(tmp);
    }
    vector<char> up = {'F', '7', '|'};
    vector<char> down = {'|', 'L', 'J'};
    vector<char> left = {'-', 'L', 'F'};
    vector<char> right = {'7', 'J', '-'};
    direction['U'] = unordered_set(up.begin(), up.end());
    direction['D'] = unordered_set(down.begin(), down.end());
    direction['L'] = unordered_set(left.begin(), left.end());
    direction['R'] = unordered_set(right.begin(), right.end());
    cout<<solve(pipes)/2<<endl;
}
