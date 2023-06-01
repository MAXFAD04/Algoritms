#include <iostream>
#include <list>
using namespace std;

template<typename K, typename V>
class HashTable {
private:
    const int SIZE = 10;
    list<pair<K, V>> table[10];
    int hashFunc(const K& key) const {
        return hash<K>{}(key) % SIZE;
    }
public:
    void insert(const K& key, const V& value) {
        int index = hashFunc(key);
        auto& bucket = table[index];
        for (auto& kv : bucket) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
    }
    list<V> find(const K& key) const {
        int index = hashFunc(key);
        const auto& bucket = table[index];
        list<V> values;
        for (const auto& kv : bucket) {
            if (kv.first == key) {
                values.push_back(kv.second);
            }
        }
        return values;
    }
    void erase(const K& key) {
        int index = hashFunc(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    HashTable<string, string> phoneBook;

    phoneBook.insert("Smith", "7 925-555-12-12");
    phoneBook.insert("Jones", "7 926-655-22-22");
    phoneBook.insert("Johnson", "7 927-755-32-32");
    phoneBook.insert("Smith", "7 928-855-42-42");

    cout << "Phone numbers for Smith: ";
    auto smithNumbers = phoneBook.find("Smith");
    for (const auto& number : smithNumbers) {
        cout << number << " ";
    }
    cout << endl;

    phoneBook.erase("Jones");

    cout << "Phone numbers for Jones: ";
    auto jonesNumbers = phoneBook.find("Jones");
    for (const auto& number : jonesNumbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
