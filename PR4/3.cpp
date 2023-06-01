#include <iostream>
#include <string>
#include <unordered_map>

void countChars(const std::string& str)
{
    std::unordered_map<char, int> charCounts;
    
    for (const auto& c : str) {
        if (charCounts.find(c) == charCounts.end()) {
            charCounts[c] = 1;
        }
        else {
            charCounts[c]++;
        }
    }
    
    for (const auto& p : charCounts) {
        std::cout << "'" << p.first << "' occurs " << p.second << " time(s)\n";
    }
}

int main()
{
    std::string inputStr = "Hello, world!";
    countChars(inputStr);
    return 0;
}
