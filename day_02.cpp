#include<bits/stdc++.h>
#include<regex>

using namespace std;

vector<string> split(string inp, char del) {
    stringstream ss(inp);
    string word;
    vector<string> res;
    while(!ss.eof()) {
        getline(ss, word, del);
        res.push_back(word);
    }
    return res;
}

int solve(string &inp) {
    int id;
    
    regex game_id("Game\\s(\\d+):");
    smatch matches;

    if(regex_search(inp, matches, game_id)) {
        id = stoi(matches[1].str());
    }

    regex blue("(\\d+)\\sblue");
    regex green("(\\d+)\\sgreen");
    regex red("(\\d+)\\sred");
    
    vector<string> games = split(inp, ';');
//    for(string game: games) {
//        if(regex_search(game, matches, red)) if(stoi(matches[1].str()) > 12) return 0;
//        if(regex_search(game, matches, green)) if(stoi(matches[1].str()) > 13) return 0;
//        if(regex_search(game, matches, blue)) if(stoi(matches[1].str()) > 14) return 0;
//    }

//    return id;

    int blue_cnt = 0;
    int green_cnt = 0;
    int red_cnt = 0;
    for(string game: games) {
        if(regex_search(game, matches, red)) red_cnt = max(red_cnt, stoi(matches[1].str()));
        if(regex_search(game, matches, green)) green_cnt = max(green_cnt, stoi(matches[1].str()));
        if(regex_search(game, matches, blue)) blue_cnt = max(blue_cnt, stoi(matches[1].str()));
    }

    return blue_cnt * green_cnt * red_cnt;
}

int main() {
    string inp;
    int sum = 0;
    while(getline(cin, inp)) {
        sum += solve(inp);
    }
    cout<<sum<<endl;
}
