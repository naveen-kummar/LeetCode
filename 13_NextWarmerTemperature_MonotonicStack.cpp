#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#include <algorithm>

class Solution {
public:
    vector<int> NextWarmerTemperature(vector<int>& temperatures) {
        //30,38,30,36,35,40,28
        //0 ,1 ,2, 3, 4, 5, 6

        vector<int> result{};
        stack<pair<int, int>> st; // (index, value)
        for (int i = temperatures.size() - 1; i >= 0; i--) 
        {
            while (!st.empty() && st.top().second <= temperatures[i]) 
            {
                st.pop();
            }
            result[i] = st.empty() ? 0 : (i - st.top().first);
            st.push({i, temperatures[i]});
        }

        return result;
    }
};


int main() {

    Solution sol{};
    std::vector<int> input = {30,38,30,36,35,40,28};
    std::vector<int> s = sol.NextWarmerTemperature(input);
    //::vector<int> s = {3, 1, 4, 1, 5, 9};

    sort(s.begin(), s.end(), [](int a, int b) {
    return a > b;});

};

  