#include <iostream>
#include <random>
#include <cmath>

using namespace std;

// Function to calculate greatest common divisor
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to generate a random prime number
int generate_prime() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(2, 100);
    
    int num = dis(gen);
    while (true) {
        bool is_prime = true;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            return num;
        num = dis(gen);
    }
}

// Function to generate public and private keys
void generate_keys(int& n, int& e, int& d) {
    // Generate two random prime numbers
    int p = generate_prime();
    int q = generate_prime();

    // Calculate n and phi(n)
    n = p * q;
    int phi_n = (p-1) * (q-1);

    // Choose e such that 1 < e < phi(n) and e is coprime to phi(n)
    do {
        e = rand() % phi_n + 1;
    } while (gcd(e, phi_n) != 1);

    // Calculate d such that d*e mod phi(n) = 1
    int k = 1;
    while (true) {
        d = (k*phi_n + 1) / e;
        if ((d*e) % phi_n == 1)
            return;
        k++;
    }
}

// Function to encrypt a message
int encrypt(int m, int e, int n) {
    // Calculate c = m^e mod n
    int c = 1;
    for (int i = 0; i < e; i++) {
        c = (c*m) % n;
    }
    return c;
}

// Function to decrypt a message
int decrypt(int c, int d, int n) {
    // Calculate m = c^d mod n
    int m = 1;
    for (int i = 0; i < d; i++) {
        m = (m*c) % n;
    }
    return m;
}

int main() {
    // Generate public and private keys
    int n, e, d;
    generate_keys(n, e, d);

    // Encrypt and decrypt a message
    int m = 123;
    cout << "Original message: " << m << endl;

    int c = encrypt(m, e, n);
    cout << "Encrypted message: " << c << endl;

    int decrypted_m = decrypt(c, d, n);
    cout << "Decrypted message: " << decrypted_m << endl;

    return 0;
}
