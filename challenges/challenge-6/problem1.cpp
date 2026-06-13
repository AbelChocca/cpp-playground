#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
public:

    void heapify(vector<int>& arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }

    void buildHeap(vector<int>& arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();

        buildHeap(arr, n);

        for (int i = n - 1; i > 0; i--) {

            swap(arr[0], arr[i]);

            heapify(arr, i, 0);
        }
    }
};


int main() {
    int n; cin >> n;
    vector<int> nums(n);

    for (auto& n : nums) cin>>n;
    int k; cin >>k;
    
    HeapSort hs;

    hs.heapSort(nums);

    for (int i = 0; i < k; i++) {
        if (i == k-1) cout << nums[i];
    }

    return 0;
}