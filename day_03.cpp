#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int extractNum(vector<string> &inp, int row, int col) {
    if(row < 0 or col < 0 or row >= inp.size() or col >= inp[row].size() or !isdigit(inp[row][col])) return 0;
    int num = 0;
    int tmp = col;
    int ten = 1;
    while(tmp<inp[row].size() and isdigit(inp[row][tmp])){
        num = num*10 + (inp[row][tmp] - '0');
        inp[row][tmp] = '.';
        ++tmp;
        ten *= 10;
    }
    tmp = col-1;
    while(tmp>=0 and isdigit(inp[row][tmp])){
        num += (inp[row][tmp] - '0') * ten;
        inp[row][tmp] = '.';
        --tmp;
        ten *= 10;
    }
    return num;
}

int move(vector<string> &inp, int row, int col) {
    int sum = 0;
    int arr[3] = {-1, 0, +1};
    for(int i = 0; i < 3; ++i){ 
        for(int j=0; j < 3; ++j){
            if(arr[i] == 0 and arr[j] == 0) continue;
            sum += extractNum(inp, row+arr[i], col+arr[j]);
        }
    }
    return sum;
}

int movePart2(vector<string> &inp, int row, int col) {
    vector<int> nums;
    int arr[3] = {-1, 0, +1};
    for(int i = 0; i < 3; ++i){ 
        for(int j=0; j < 3; ++j){
            if(arr[i] == 0 and arr[j] == 0) continue;
            int tmp = extractNum(inp, row+arr[i], col+arr[j]);
            if(tmp!=0)
            nums.push_back(tmp);
        }
    }
    if(nums.size()==2) return nums[0] * nums[1];
    return 0;
}

int solve(vector<string> &inp) {
    int sum = 0;
    for(int i = 0; i < inp.size(); ++i) {
        for(int j = 0; j < inp[i].size(); ++j) {
            char c = inp[i][j];
            //if(isdigit(c) or c == '.') continue;
            //sum += move(inp, i, j);
            if(c=='*'){
                sum += movePart2(inp, i, j);
            }
        }
    }
    return sum;
}

int main() {
    vector<string> inp;
    string tmp;
    while(getline(cin, tmp)) {
        inp.push_back(tmp);
    }
    cout<<solve(inp);
}
