#include <vector>
#include <functional> // For std::function
using namespace std;

class Solution {
public:
    vector<vector<int>> findSolution(function<int(int, int)> f, int z) {
        vector<vector<int>> result;
        int x = 1, y = 1000; // Start with the smallest x and largest y (within the constraints)
        
        while (x <= 1000 && y >= 1) {
            int value = f(x, y);
            if (value == z) {
                result.push_back({x, y}); // Store the pair (x, y)
                x++; // Move to the next x
                y--; // Move to the previous y
            } else if (value < z) {
                x++; // Increase x to increase f(x, y)
            } else {
                y--; // Decrease y to decrease f(x, y)
            }
        }
        
        return result;
    }
};
