#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0], currentMin = nums[0], maxPro = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                // Swap current max and min
                int t = currentMax;
                currentMax = currentMin;
                currentMin = t;
            }
            // currentMax = max(nums[i], currentMax * nums[i])
            currentMax = max(nums[i], currentMax * nums[i]);
            // currentMin = min(nums[i], currentMin * nums[i])
            currentMin = min(nums[i], currentMin * nums[i]);
            // result = max(result, currentMax)
            maxPro = max(maxPro, currentMax);
        }
        return maxPro;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 3, -2, 4};
    std::cout << "Max Product (Test Case 1): " << solution.maxProduct(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {-2, 0, -1};
    std::cout << "Max Product (Test Case 2): " << solution.maxProduct(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {0, 2, -3, 4, -1};
    std::cout << "Max Product (Test Case 3): " << solution.maxProduct(nums3) << endl;

    return 0;
}
