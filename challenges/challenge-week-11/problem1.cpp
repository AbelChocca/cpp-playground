#include <iostream>
#include <vector>


using namespace std;

int binarySearch(vector<int> temps, int target) {
    int left = 0;
    int right = temps.size()-1;
    int maxIndex = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (temps[mid] >= target) {
            maxIndex = mid;
            right = mid - 1;
        }
        else if (temps[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return maxIndex;
}

int main() {
    int n; cin >> n;
    vector<int> temperaturas(n);
    for (auto& n : temperaturas) cin >> n;
    int umbral; cin >> umbral;

    cout << binarySearch(temperaturas, umbral) << endl;
    
    return 0;
}