#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rot = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                rot = i;
                break; // Stop once we find the rotation point
            }
        }

        vector<int> subVector1(nums.begin(), nums.begin() + rot + 1);
        vector<int> subVector2(nums.begin() + rot + 1, nums.end());

        int k = searchSubArray(subVector1, target);
        int l = searchSubArray(subVector2, target);

        if (k != -1) return k;
        else if (l != -1) return rot + 1 + l;
        return -1;
    }

    int searchSubArray(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Rotated sorted array
    int target = 0;

    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}