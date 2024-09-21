#include <stdio.h>
#include <ctype.h>
int main() {
    char text[100];
    int shift, i = 0;
    char ch;
    printf("Enter a message to encrypt: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 0) {
        shift = 26 + (shift % 26);
    }
    shift = shift % 26;
    while (text[i] != '\0') {
        ch = text[i];
        if (isupper(ch)) {
            ch = (ch - 'A' + shift) % 26 + 'A';
            text[i] = ch;
        }
        else if (islower(ch)) {
            ch = (ch - 'a' + shift) % 26 + 'a';
            text[i] = ch;
        }
        i++;
    }
    printf("Encrypted message: %s", text);
    return 0;
}
