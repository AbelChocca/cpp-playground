/*
    Intengrantes
        Abel Chocca
        Juan Tolentino
        Sebastian Gutierrez
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void swap(int& a, int& b){
    int c = b;
    b = a;
    a = c;
}

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }
}


int main()
{
    vector<int> nums;

    random_device rd;
    mt19937 gen(rd());

    // Números entre 1 y 1000
    uniform_int_distribution<> dist(1, 1000);

    for (int i = 0; i < 200; i++)
    {
        nums.push_back(dist(gen));
    }

    cout << "VECTOR ORIGINAL:\n";
    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << "\n\n";

    quickSort(nums, 0, nums.size() - 1);

    cout << "VECTOR ORDENADO:\n";
    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << '\n';

    return 0;
}