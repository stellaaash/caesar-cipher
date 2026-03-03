#include <unistd.h>

#define OFFSET 10

// Minus to encode
char encode(char c) {
    // Ignore all non lowercase characters
    if (c < 'a' || c > 'z') return c;

    char encoded = c - 10;

    char difference = 'a' - encoded - 1;
    if (difference > 0) {
        encoded = 'z' - difference;
    }

    return encoded;
}

// Plus to decode
char decode(char c) {
    // Ignore all non lowercase characters
    if (c < 'a' || c > 'z') return c;

    char decoded = c + 10;

    char difference = decoded - 'z';
    if (difference > 0) {
        decoded = 'a' + difference - 1;
    }

    return decoded;
}

// Only lowercase characters
int main(int argc, char** argv) {
    if (argc < 2) return 1;

    int i = 0;
    char* encoded = argv[1];

    while (encoded[i]) {
        char decoded = decode(encoded[i]);
        write(1, &decoded, 1);
        ++i;
    }
    write(1, "\n", 1);
}
