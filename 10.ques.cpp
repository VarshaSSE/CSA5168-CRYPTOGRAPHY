#include <stdio.h>
#include <string.h>
#include <ctype.h>
char keyTable[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};
void prepareText(char input[], char preparedText[]);
void findPosition(char letter, int *row, int *col);
void encryptPlayfair(char digraph[], char encryptedDigraph[]);
void playfairEncrypt(char plaintext[], char encryptedText[]);

int main() {
    char plaintext[] = "Must see you over Cadogan West. Coming at once.";
    char encryptedText[256];
    playfairEncrypt(plaintext, encryptedText);
    printf("Encrypted message: %s\n", encryptedText);
    return 0;
}
void prepareText(char input[], char preparedText[]) {
    int len = strlen(input);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            char ch = toupper(input[i]);
            if (ch == 'J') {
                ch = 'I';
            }
            preparedText[index++] = ch;
        }
    }
    preparedText[index] = '\0';
}
void findPosition(char letter, int *row, int *col) {
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
void encryptPlayfair(char digraph[], char encryptedDigraph[]) {
    int row1, col1, row2, col2;
    findPosition(digraph[0], &row1, &col1);
    findPosition(digraph[1], &row2, &col2);
    if (row1 == row2) {
        encryptedDigraph[0] = keyTable[row1][(col1 + 1) % 5];
        encryptedDigraph[1] = keyTable[row2][(col2 + 1) % 5];
    } else if (col1 == col2) {
        encryptedDigraph[0] = keyTable[(row1 + 1) % 5][col1];
        encryptedDigraph[1] = keyTable[(row2 + 1) % 5][col2];
    } else {
        encryptedDigraph[0] = keyTable[row1][col2];
        encryptedDigraph[1] = keyTable[row2][col1];
    }
}
void playfairEncrypt(char plaintext[], char encryptedText[]) {
    char preparedText[256];
    char digraph[3], encryptedDigraph[3];
    int len, index = 0;
    prepareText(plaintext, preparedText);
    len = strlen(preparedText);
    for (int i = 0; i < len; i += 2) {
        digraph[0] = preparedText[i];
        if (i + 1 < len) {
            digraph[1] = preparedText[i + 1];
        } else {
            digraph[1] = 'X';
        }
        digraph[2] = '\0';
        encryptPlayfair(digraph, encryptedDigraph);
        encryptedText[index++] = encryptedDigraph[0];
        encryptedText[index++] = encryptedDigraph[1];
    }
    encryptedText[index] = '\0';
}
