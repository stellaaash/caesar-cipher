// This is basically like a caesar cipher, except the offset isn't static, but
// determined by a keyword repeated for the size of string to encode/decode.

#include <cassert>
#include <iostream>
#include <string>

char caesar_shift(char c, int offset) {
    assert(c >= 'a' && c <= 'z');

    char shifted;

    c += offset;
    if (c < 'a') {
        int difference = 'a' - c;
        shifted = 'z' - difference;
    } else if (c > 'z') {
        int difference = c - 'z';
        shifted = 'a' + difference;
    }

    return shifted;
}

std::string decode(std::string encoded, std::string keyword) {
    std::string key;

    size_t encoded_index = 0;
    size_t keyword_index = 0;
    while (encoded_index < encoded.length()) {
        if (encoded[encoded_index] >= 'a' && encoded[encoded_index] <= 'z') {
            key.push_back(keyword[keyword_index]);
            ++keyword_index;
            if (keyword_index >= keyword.length()) keyword_index = 0;
        } else {
            // If it's not alphabetical, we'll just push it through
            key.push_back(encoded[encoded_index]);
        }
        ++encoded_index;
    }

    std::cout << "[!] - Key created: " << key << std::endl;

    std::string decoded;

    size_t index = 0;
    while (index < encoded.length()) {
        if (encoded[index] >= 'a' && encoded[index] <= 'z') {
            const int alphabetical_index = key[index] - 'a';

            decoded.push_back(caesar_shift(encoded[index], alphabetical_index));
        } else {
            decoded.push_back(encoded[index]);
        }
        ++index;
    }

    return decoded;
}

int main(int argc, char** argv) {
    if (argc < 3) return 1;

    std::string encoded = argv[1];
    std::string keyword = argv[2];

    std::cout << decode(encoded, keyword);

    return 0;
}
