#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    int c = b;
    b = a;
    a = c;
}

void toShuffle(vector<int>& nums) {
    size_t n = nums.size();
    for (int i = n -1; i>0; i--) {
        int j = rand() % (i+1);
        swap(nums[i], nums[j]);
    }
}

int main() {
    srand(time(0));

    vector<int> nums = {4, 5, 1, 2, 7, 5, 9};
    toShuffle(nums);

    cout << "El estado inicial del arreglo shuffleado:\n";
    for (auto& n : nums) {
        cout << n << " ";
    }

    sort(nums.begin(), nums.end());
    cout << "El estado final del arreglo ordenado:\n";
    for (auto& n : nums) {
       cout << n << " ";
    }


    return 0;
}