#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> value_to_indices;
        for (int i = 0; i < n; i++) {
            value_to_indices[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) return steps;
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
 }
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                if (value_to_indices.count(arr[curr])) {
                    for (int next_idx : value_to_indices[arr[curr]]) {
                        if (!visited[next_idx]) {
                            visited[next_idx] = true;
                            q.push(next_idx);
                        }
                    }
                    value_to_indices.erase(arr[curr]);
                }
            }
            steps++;
        }
        return -1;
    }
};