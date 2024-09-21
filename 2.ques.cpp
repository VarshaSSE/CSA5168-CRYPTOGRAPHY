#include <stdio.h>
#include <string.h>
int main() {
    char plaintext[100], ciphertext[100];
    char key[27] = "QWERTYUIOPLKJHGFDSAZXCVBNM";  
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    int i, j;
    printf("Enter a message to encrypt(uppercase): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (plaintext[i] == alphabet[j]) {
                    ciphertext[i] = key[j];  
                    break;
                }
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
    printf("Encrypted message: %s", ciphertext);
    return 0;
}
