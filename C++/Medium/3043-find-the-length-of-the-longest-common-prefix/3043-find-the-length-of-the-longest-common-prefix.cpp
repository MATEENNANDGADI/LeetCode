#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        for (int x : arr1) {
            while (x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }
        int max_len = 0;
        
        for (int y : arr2) {
            while (y > 0) {
                if (prefixes.count(y)) {
                    int len = to_string(y).length();
                    max_len = max(max_len, len);
                    break;
                }
                y /= 10;
            }
        }
        
        return max_len;
    }
};