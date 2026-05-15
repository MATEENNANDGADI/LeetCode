#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int min_diff = INT_MAX;
        vector<vector<int>> result;
        
        for (size_t i = 1; i < arr.size(); ++i) {
            int current_diff = arr[i] - arr[i-1];
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
        
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i-1] == min_diff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        return result;
    }
};