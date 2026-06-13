#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> fruits(n);
    for (auto& n : fruits) cin >> n;

    unordered_map<string, int> countFruits;

    for (auto& f : fruits) {
        countFruits[f]++;
    }

    pair<string, int> repeatedFruit = {"", 0};
    for (const auto& [key, value] : countFruits) {
        if (value > repeatedFruit.second) {
            repeatedFruit = {key, value};
        }
    }
    cout << repeatedFruit.first;

    return 0;
}