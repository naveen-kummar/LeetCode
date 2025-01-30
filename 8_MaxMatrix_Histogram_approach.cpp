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
        int subMatrixAtCurrentRow = 0;

        for (int j = 0; j < col; ++j) {
            int columnnWidth = 1;
            while (!st.empty() && 
            ((heights[j] == 0) ||(st.top().first >= heights[j]))) 
            {
                auto [prevHeight, prevColWidth] = st.top();
                st.pop();
                if(heights[j] != 0)
                {
                    columnnWidth += prevColWidth;
                }
 
               subMatrixAtCurrentRow -= prevHeight * prevColWidth;
            }

            if(heights[j] != 0)
            {
                st.push({heights[j], columnnWidth});
                subMatrixAtCurrentRow += heights[j] * columnnWidth;
                total += subMatrixAtCurrentRow;
            }
        }
    }

    return total;
}

int main() {
   // vector<vector<int>> mat1 = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
   // cout << "Output: " << numSubmat(mat1) << endl;  // Expected: 13

    vector<vector<int>> mat2 = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    cout << "Output: " << numSubmat(mat2) << endl;  // Expected: 24

    return 0;
}
