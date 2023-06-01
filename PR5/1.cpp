#include <iostream>
#include <string>

std::string encrypt(const std::string& text, int key)
{
    std::string result = "";
    for (const auto& c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((c - base + key) % 26 + base);
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

    int key;
    std::cout << "Enter encryption key: ";
    std::cin >> key;

    std::string encryptedText = encrypt(text, key);
    std::cout << "Encrypted text: " << encryptedText << "\n";

    return 0;
