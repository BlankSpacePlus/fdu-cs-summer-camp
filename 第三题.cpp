#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i : nums) {
        result ^= i;
    }
    return result;
}

int main() {
    vector<int>nums = {2, 3, 1, 3, 2};
    cout << singleNumber(nums) << endl;
}