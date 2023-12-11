#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <string>
using namespace std;

//int findCalibrationValue(string inp) {
//    string second_digit = " ";
//    string first_digit = " "; 

//    for(char x: inp) {
//        if(!isdigit(x)) continue;
//        if(first_digit == " ") {
//            first_digit = x;
//            break;
//        }     
//    }

//    reverse(inp.begin(), inp.end());
//    for(char x: inp) {
//        if(!isdigit(x)) continue;
//        if(second_digit == " ") {
//            second_digit = x;
//            break;
//        }     
//    }

//    string num = first_digit + second_digit;
//    return stoi(num);
//}

int findLast(string str, string sub) {
    int i = -1;
    int find;
    while((find = str.find(sub, i+1)) != string::npos) {
        i = find;
    }

    return i;
}

int findCalibrationValue(string inp) {
    vector<string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> nums = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int first_idx = INT_MAX;
    int second_idx = INT_MIN;
    int first_digit, second_digit;

    for(int i = 0; i < 9; ++i) {
        string s = digits[i];
        int it = inp.find(s);
        if(it != string::npos) {
            int idx = it;
            if(idx < first_idx) {
                first_idx = idx;
                first_digit = i + 1;
            }
            
        }
        it = findLast(inp, s);
        if(it != -1) {
            if(it > second_idx) {
                second_idx = it; 
                second_digit = i + 1;
            }
        }

    }

    for(int i = 0; i < 9; ++i) {
        string s = nums[i];
        int it = inp.find(s);
        if(it != string::npos) {
            int idx = it;
            if(idx < first_idx) {
                first_idx = idx;
                first_digit = i + 1;
            }
            
        }
        it = findLast(inp, s);
        if(it != -1) {
            if(it > second_idx) {
                second_idx = it; 
                second_digit = i + 1;
            }
        }

    }

    return first_digit*10 + second_digit;
}

int main() {
    string str;
    int sum = 0;
    while(cin>>str){
        sum += findCalibrationValue(str);
    }
    cout<<sum;
}
