
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char table[SIZE][SIZE];
char *text2;
char coba;
char decrypted[100];

// Membuat tabel Playfair Cipher dari kunci
void createTable(const char *key) {
    int used[26] = {0};
    int row = 0, col = 0;

    while (*key != '\0') {
        if (!used[tolower(*key) - 'a'] && *key != 'j') {
            table[row][col++] = tolower(*key);
            used[tolower(*key) - 'a'] = 1;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
        key++;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (!used[ch - 'a'] && ch != 'j') {
            table[row][col++] = ch;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
}

// Mendapatkan koordinat karakter dalam tabel
void getCharPosition(char ch, int *row, int *col) {
    if (ch == 'j') ch = 'i';

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (table[*row][*col] == ch)
                return;
        }
    }
}

// Enkripsi teks dengan aturan Playfair Cipher
void encrypt(const char *text) {
    char ch1, ch2;
    int row1, col1, row2, col2;

    for (int i = 0; text[i] != '\0'; i += 2) {
        ch1 = tolower(text[i]);
        ch2 = (text[i + 1] != '\0') ? tolower(text[i + 1]) : 'x';

        getCharPosition(ch1, &row1, &col1);
        getCharPosition(ch2, &row2, &col2);

        if (row1 == row2) {
            printf("%c%c ", table[row1][(col1 + 1) % SIZE], table[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2) {
            printf("%c%c ", table[(row1 + 1) % SIZE][col1], table[(row2 + 1) % SIZE][col2]);
        } else {
            
            printf("%c%c ", table[row1][col2], table[row2][col1]);
            //printf("bingo\n");
        }
    }
}

void decrypt(const char *text) {
    char ch1, ch2;
    int row1, col1, row2, col2;
    int index = 0;

    for (int i = 0; text[i] != '\0'; i += 2) {
        ch1 = tolower(text[i]);
        ch2 = (text[i + 1] != '\0') ? tolower(text[i + 1]) : 'x';

        getCharPosition(ch1, &row1, &col1);
        getCharPosition(ch2, &row2, &col2);

        if (row1 == row2) {
            decrypted[index++] = table[row1][(col1 + SIZE - 1) % SIZE];
            decrypted[index++] = table[row2][(col2 + SIZE - 1) % SIZE];
        } else if (col1 == col2) {
            decrypted[index++] = table[(row1 + SIZE - 1) % SIZE][col1];
            decrypted[index++] = table[(row2 + SIZE - 1) % SIZE][col2];
        } else {
            decrypted[index++] = table[row1][col2];
            decrypted[index++] = table[row2][col1];
        }
    }
    decrypted[index] = '\0'; // Menambahkan null-terminator pada akhir string
}


int main() {
    char key[50];
    char text[100];
    

    printf("Masukkan kunci: ");
    scanf("%s", key);

    printf("Masukkan teks untuk dienkripsi (huruf kecil tanpa spasi): ");
    scanf("%s", text);

    createTable(key);
    printf("Teks terenkripsi: ");
    encrypt(text);
    printf("\nTeks terdekripsi: ");
    decrypt(text);
    text2 = &decrypted;
    decrypt(text2);
    printf("%s\n", decrypted);
    
    //printf("%c ", *text2);

    return 0;
}