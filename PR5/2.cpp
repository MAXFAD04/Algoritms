#include <iostream>
#include <string>
#include <unordered_map>

std::string readFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return text;
}

std::unordered_map<char, int> countChars(const std::string& str)
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
    
    return charCounts;
}

int findKey(const std::string& text)
{
    std::unordered_map<char, int> charFreq = countChars(text);

    // The most frequent letter in Russian language is "о"
    // We compute the distance from the most frequent letter to "о",
    // and use that as our initial guess for the encryption key
    int initialGuess = (charFreq.begin()->first - 'о' + 32) % 32;

    // Try all possible keys and count the number of valid words
    int maxValidWords = 0;
    int bestKey = 0;
    for (int key = 0; key < 32; ++key) {
        std::string decryptedText = encrypt(text, key);
        int numValidWords = countValidWords(decryptedText);
        if (numValidWords > maxValidWords) {
            maxValidWords = numValidWords;
            bestKey = key;
        }
    }

    return bestKey;
}

int main()
{
    std::string filename = "text.txt";
    std::string text = readFile(filename);

    int key = findKey(text);

    std::cout << "The encryption key is: " << key << "\n";

    return 0;
}
