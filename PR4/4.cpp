#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> findIndices(const std::vector<int>& arr, int target)
{
    std::unordered_map<int, int> numMap;  // Key: array element, Value: index of element
    std::vector<int> result;

    for (int i = 0; i < arr.size(); ++i) {
        int complement = target - arr[i];
        if (numMap.find(complement) != numMap.end()) {
            // We found a pair that adds up to the target
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }
        numMap[arr[i]] = i;
    }

    // If we reach here, no pair was found
    return result;
}

int main()
{
    std::vector<int> arr = {-1, 2, 3, 4, 7};
    int target = 5;

    std::vector<int> indices = findIndices(arr, target);
    if (indices.empty()) {
        std::cout << "No pair found\n";
    }
    else {
        std::cout << "Pair found at indices " << indices[0] << " and " << indices[1] << "\n";
    }

    return 0;
}
