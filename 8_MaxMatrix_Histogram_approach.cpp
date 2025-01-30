#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    int row = mat.size(), col = mat[0].size();
    vector<int> heights(col, 0);
    int total = 0;

    for (int i = 0; i < row; ++i) {
        // Update histogram heights
        for (int j = 0; j < col; ++j) {
            heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
        }

        // Count submatrices ending at row `i` using monotonic stack
        stack<pair<int, int>> st;  // Stores (height, count of valid submatrices)
        int sum = 0;

        for (int j = 0; j < col; ++j) {
            int count = 1;
            while (!st.empty() && st.top().first >= heights[j]) {
                auto [h, c] = st.top();
                st.pop();
                count += c;
                sum -= h * c;
            }
            st.push({heights[j], count});
            sum += heights[j] * count;
            total += sum;
        }
    }

    return total;
}

int main() {
    vector<vector<int>> mat1 = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << "Output: " << numSubmat(mat1) << endl;  // Expected: 13

    vector<vector<int>> mat2 = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    cout << "Output: " << numSubmat(mat2) << endl;  // Expected: 24

    return 0;
}
