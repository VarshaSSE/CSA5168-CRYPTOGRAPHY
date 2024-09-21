#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateKeyTable(char key[], char keyTable[5][5]);
void prepareText(char str[], char preparedText[]);
void decryptPlayfair(char digraph[], char keyTable[5][5], char decryptedDigraph[]);
void findPosition(char letter, char keyTable[5][5], int *row, int *col);
void playfairDecrypt(char ciphertext[], char key[], char decryptedText[]);
int main() {
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONECUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char key[] = "JFK";
    char decryptedText[256];  
    playfairDecrypt(ciphertext, key, decryptedText);
    printf("Decrypted message: %s\n", decryptedText);
    return 0;
}
void generateKeyTable(char key[], char keyTable[5][5]) {
    int used[26] = {0};
    int row = 0, col = 0;
    used['J' - 'A'] = 1;
    for (int i = 0; key[i] != '\0'; i++) {
        if (!used[toupper(key[i]) - 'A']) {
            keyTable[row][col++] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            keyTable[row][col++] = ch;
            used[ch - 'A'] = 1;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }
}
void prepareText(char str[], char preparedText[]) {
    int len = strlen(str), index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            preparedText[index++] = toupper(str[i]);
        }
    }
    preparedText[index] = '\0'; 
}
void decryptPlayfair(char digraph[], char keyTable[5][5], char decryptedDigraph[]) {
    int row1, col1, row2, col2;
    findPosition(digraph[0], keyTable, &row1, &col1);
    findPosition(digraph[1], keyTable, &row2, &col2);
    if (row1 == row2) {
        decryptedDigraph[0] = keyTable[row1][(col1 + 4) % 5];
        decryptedDigraph[1] = keyTable[row2][(col2 + 4) % 5];
    } else if (col1 == col2) {
        decryptedDigraph[0] = keyTable[(row1 + 4) % 5][col1];
        decryptedDigraph[1] = keyTable[(row2 + 4) % 5][col2];
    } else {
        decryptedDigraph[0] = keyTable[row1][col2];
        decryptedDigraph[1] = keyTable[row2][col1];
    }
}
void findPosition(char letter, char keyTable[5][5], int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyTable[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void playfairDecrypt(char ciphertext[], char key[], char decryptedText[]) {
    char keyTable[5][5];
    char preparedCiphertext[256], digraph[3], decryptedDigraph[3];
    int len, index = 0;
    generateKeyTable(key, keyTable);
    prepareText(ciphertext, preparedCiphertext);
    len = strlen(preparedCiphertext);
    for (int i = 0; i < len; i += 2) {
        digraph[0] = preparedCiphertext[i];
        digraph[1] = preparedCiphertext[i + 1];
        digraph[2] = '\0';
        decryptPlayfair(digraph, keyTable, decryptedDigraph);
        decryptedText[index++] = decryptedDigraph[0];
        decryptedText[index++] = decryptedDigraph[1];
    }
    decryptedText[index] = '\0'; 
}
