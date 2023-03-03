// Given a large text and a pattern where text >> pattern.
// Find indices for the matching pattern in the text.

// Rolling hash method: O(n) time, O(1) space

/**
 * @brief Rolling hash method
 * hash(pattern) = 
 * hash(pattern[0..m-1]) = (pattern[0]*d^(m-1) + pattern[1]*d^(m-2) + ... + pattern[m-1]) mod q
 * Also, First character of the pattern is the most significant character hence it's mutiplied by d^(m-1)
 * 
 * 
 * Formula for Rehashing text in O(1) operation given hash of previous window:
 * hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
 * 
 * NOTE: 
 * d: Number of characters in the alphabet 
 * q: A prime number 
 * h: d^(m-1) mod q
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int findModuloPower(int a, int b, int q) {
    int result = 1;
    while( b > 0) {
        if (b & 1) {
            result = (result * a) % q;
        }
        b = b >> 1;
        a = (a * a) % q;
    }
    return result%q;
}

// Find hash of any string
int findStringHash(int d, int h,int q, string str) {
    int strHash = 0;
    for (int i = 0; i < str.size(); i++) {
        strHash = (d * strHash + str[i]) % q;
    }
    return strHash;
}


vector<int> findMatches(string text, string pattern) {
    int d = 256; // Number of characters in the alphabet
    int q = 10007; // A prime number

    int n = text.size();
    int m = pattern.size();

    int h = findModuloPower(d, m-1, q);  // d^(m-1) mod q

    int patternHash = findStringHash(d, h, q, pattern);
    int textHash;

    vector<int> startIndicesOfMatches;

    for (int i = 0; i <= n - m; i++) {
        // Don't need to rehash the pattern
        if(i == 0) 
            textHash = findStringHash(d, h, q, text.substr(0, m));
        else // Rehash the text
            textHash = (d * (textHash - text[i - 1] * h) + text[i + m - 1]) % q;

        // In case of negative hash, make it positive
        if (textHash < 0) 
            textHash = textHash + q;
        

        if (patternHash == textHash) {
            bool isMatch = true;
            // In case of collision, check if the strings are actually equal
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                startIndicesOfMatches.push_back(i);
            }
        }
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";


    auto startIndicesOfMatches = findMatches(text, pattern);

    cout << "Indices of matches: ";
    for (auto index : startIndicesOfMatches) {
        cout << index << " ";
    }
}
