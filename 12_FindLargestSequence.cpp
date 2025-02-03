#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
    
    std::set<int> uniqueElems{nums.begin(), nums.end()};

    int currentLength = 0;
    int maxLength = 0;
    for(int i : nums)
    {
            if(uniqueElems.find(i-1) == uniqueElems.end())
            {
                currentLength = 0;
                while(uniqueElems.find(i+currentLength) != uniqueElems.end())
                {
                    ++currentLength;
                }

                maxLength = std::max(currentLength, maxLength);
            }
    }

    return maxLength;

    };
};


int main() {

    Solution sol{};
    std::vector<int> input = {3, 4, 4, 6, 100, 2, 200, 5, 5,5, 5, 5,5,5 };
    int s = sol.longestConsecutive(input);
    //::vector<int> s = {3, 1, 4, 1, 5, 9};
    std::cout << s << endl;


};

  