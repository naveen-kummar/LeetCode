#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> left, right;

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        left.resize(n);
        right.resize(n);
        
        findSmallerLeft(heights);
        findSmallerRight(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        return maxArea;
    }   

private:
    void findSmallerLeft(vector<int>& arr) {
        stack<pair<int, int>> st; // (index, value)
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && st.top().second >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top().first;
            st.push({i, arr[i]});
        }
    }

    void findSmallerRight(vector<int>& arr) {
        stack<pair<int, int>> st; // (index, value)
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? arr.size() : st.top().first;
            st.push({i, arr[i]});
        }
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}