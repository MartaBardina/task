//
//  Task1.cpp
//  tskt
//
//  Created by Marta Bardina on 17.12.2024.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> anagrams(vector<string>& words) {
    unordered_map<string, vector<string>> groups;

    for (const auto& word : words) {
        array<int, 26> count = {0};
        for (char c : word) count[c - 'a']++;

        string key;
        for (int n : count) key += n + '0';

        groups[key].push_back(word);
    }

    vector<vector<string>> result;
    result.reserve(groups.size());
    for (auto&& group : groups)
        result.push_back(std::move(group.second));

    return result;
}

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = anagrams(words);

    for (const auto& group : result) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i] << (i < group.size() - 1 ? " " : "");
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
