#include <iostream>
#include <string>
#include <unordered_map>

std::string generateCipherAlphabet(const std::string& key)
{
    std::string result = "";
    std::unordered_map<char, bool> usedChars;

    // Append the characters in the key to the result string in order
    for (const auto& c : key) {
        if (!usedChars[c]) {
            result += c;
            usedChars[c] = true;
        }
    }

    // Append the remaining letters of the alphabet to the result string
    for (char c = 'а'; c <= 'я'; ++c) {
        if (!usedChars[c]) {
            result += c;
            usedChars[c] = true;
        }
    }

    return result;
}

std::string encrypt(const std::string& text, const std::string& cipherAlphabet)
{
    std::string result = "";

    for (const auto& c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'А' : 'а';
            result += cipherAlphabet[c - base];
        }
        else {
            result += c;
        }
    }

    return result;
}

int main()
{
    std::string text;
    std::cout << "Enter text to encrypt: ";
    std::getline(std::cin, text);

    std::string key = "пароль";
    std::string cipherAlphabet = generateCipherAlphabet(key);

    std::string encryptedText = encrypt(text, cipherAlphabet);
    std::cout << "Encrypted text: " << encryptedText << "\n";

    return 0;
}
