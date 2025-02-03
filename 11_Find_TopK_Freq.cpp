#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        std::sort(nums.begin(), nums.end());

      //  cout << "The input sz = " << nums.size() << std::endl;

        vector<std::pair<int, int>> topK{};
        //topK.resize(k);
        

        int elem = nums[0];
       // int prevElem = nums[0];
        int freq = 1;
        bool firstElem = true;
        
        bool isAllProcessed = false;
        int totalProcessed = 0;

        for(int i : nums)
        {
            ++totalProcessed;
            if(firstElem)
            {
                firstElem = false;
                continue;
            }
            if(elem != i)
            {
               // if(freq >= k)
                {
                    topK.push_back(std::make_pair(freq, elem));
                    if(totalProcessed == nums.size())
                    {
                        isAllProcessed = true;
                    }
                }
                elem = i;
                freq = 1;
            }
            else
            {
                ++freq;
            }
        }

        if(!isAllProcessed)
        {
           // if(freq >= k)
            {
                topK.push_back(std::make_pair(freq, nums[nums.size() - 1]));
            }
        }

        std::sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return (a.first > b.first);
        });

        vector<int> result;
        int iter = 0;
        for(auto topFreq : topK)
        {
            result.push_back(topFreq.second);
            ++iter;
            if(iter == k)
            {
                break;
            }
        }
        return result;
    }
};


int main() {

    Solution sol{};
    std::vector<int> input = {1,2,2,3,3,3};
    std::vector<int> s = sol.topKFrequent(input, 2);
    //::vector<int> s = {3, 1, 4, 1, 5, 9};

    sort(s.begin(), s.end(), [](int a, int b) {
    return a > b;});

};

  