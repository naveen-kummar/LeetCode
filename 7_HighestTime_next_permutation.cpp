#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string largestTimeFromDigits(vector<int>& arr) {
    string latest = "";
    int maxTime = -1;
    
    // Generate all permutations of the array
    sort(arr.begin(), arr.end());
    do {
        int hours = arr[0] * 10 + arr[1];
        int minutes = arr[2] * 10 + arr[3];
        
        // Check if it's a valid time
        if (hours < 24 && minutes < 60) {
            int totalMinutes = hours * 60 + minutes;
            if (totalMinutes > maxTime) {
                maxTime = totalMinutes;
                latest = to_string(arr[0]) + to_string(arr[1]) + ":" + to_string(arr[2]) + to_string(arr[3]);
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
    
    return latest;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {5, 5, 5, 5};
    
    cout << "Latest Time (1,2,3,4): " << largestTimeFromDigits(arr1) << endl;
    cout << "Latest Time (5,5,5,5): " << largestTimeFromDigits(arr2) << endl;

    std::string s = "321";

    std::sort(s.begin(), s.end());

    do
    {
        std::cout << s << '\n';
    }
    while (std::next_permutation(s.begin(), s.end()));
 
    std::cout << s << '\n';
    
    return 0;
}
