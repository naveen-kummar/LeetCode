#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#include <algorithm>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;

        if(matrix.size() == 0 ||
        matrix[0].size() == 0)
        {
            return false;
        }

        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int topRow = 0;
        int bottomRow =  ROWS - 1;

        int row = 0;
        while (topRow <= bottomRow)
        {
            row = (topRow + bottomRow) / 2;
            if (target > matrix[row][COLS - 1])
            {
                topRow = row + 1;
            }
            else if(target < matrix[row][0])
            {
                bottomRow = row - 1;
            }
            else
            {
                break; //Target if at all present it ssould be at 'row'
            }
        }

        if(topRow > bottomRow)
        {
            return false; //Target is not in matrix
        }

        //Now we identified the row using BS. Now in same lets search column

        int leftCol = 0;
        int rightCol = COLS - 1;

        while(leftCol <= rightCol)
        {
            int col = (leftCol + rightCol)/2;
            if(target > matrix[row][col])
            {
                leftCol = col + 1;
            }
            else if(target < matrix[row][col])
            {
                rightCol = col - 1;
            }
            else
            {
                return true;//whoo we found the element
            }
        }
        return false; //We are here means we did not find the element
    }
};


int main() {

    Solution sol{};
    std::vector<vector<int>> input = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    bool retVal = sol.searchMatrix(input, 10);

    return 0;

};

  