#include <stdio.h>
#include <ctype.h>
#include<string.h>
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
void encrypt(char plaintext[], int a, int b) {
    int i = 0;
    char ciphertext[100];
    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            char letter = toupper(plaintext[i]);
            ciphertext[i] = ((a * (letter - 'A') + b) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
        i++;
    }
    ciphertext[i] = '\0';
    printf("Encrypted message: %s\n", ciphertext);
}
void decrypt(char ciphertext[], int a, int b) {
    int i = 0;
    char decrypted[100];
    int a_inv = modInverse(a, 26);
    while (ciphertext[i] != '\0') {
        if (isalpha(ciphertext[i])) {
            char letter = toupper(ciphertext[i]);
            decrypted[i] = (a_inv * ((letter - 'A') - b + 26) % 26) + 'A';
        } else {
            decrypted[i] = ciphertext[i];
        }
        i++;
    }
    decrypted[i] = '\0';  
    printf("Decrypted message: %s\n", decrypted);
}
int main() {
    char plaintext[100], ciphertext[100];
    int a, b;
    printf("Enter the plaintext (uppercase letters only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  
    printf("Enter the value of a (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    encrypt(plaintext, a, b);
    printf("Enter the ciphertext to decrypt (uppercase letters only): ");
    scanf("%s", ciphertext);
    decrypt(ciphertext, a, b);
    return 0;
}
