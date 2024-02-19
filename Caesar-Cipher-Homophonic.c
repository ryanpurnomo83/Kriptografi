#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encryptHomophonic(char plaintext[], char ciphertext[100], char key[][3]) {
    
    int i, a;
    int simpan[100];
    for (i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        if (c >= 'A' && c <= 'z') {
            //printf("%d", c);
            //srand(time(NULL))
            switch(c){
                //int index = c - c;
                int b = 0;
                int index;
                
                case 'A' : index = rand() % 7;strcat(ciphertext, key[index]); break;
                case 'B' : a = 7;strcat(ciphertext, key[a]); break;
                case 'C' : a = rand() % 3 + 8;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'D' : a = rand() % 4 + 11; 
                           simpan[b++] = a;
                           index = a;  
                           strcat(ciphertext, key[index]); break;
                case 'E' : a = rand() % 13 + 15;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'F' : a = rand() % 3 + 28;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'G' : a = rand() % 2 + 31;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'H' : a = rand() % 3 + 33;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'I' : a = rand() % 8 + 36;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'J' : strcat(ciphertext, key[44]); break;
                case 'K' : strcat(ciphertext, key[45]); break;
                case 'L' : a = rand() % 4 + 46;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'M' : a = rand() % 3 + 50;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'N' : a = rand() % 8 + 53;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'O' : a = rand() % 7 + 61;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'P' : a = rand() % 3 + 68;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'Q' : strcat(ciphertext, key[71]); break;
                case 'R' : a = rand() % 8 + 72;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'S' : a = rand() % 6 + 80;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'T' : a = rand() % 9 + 86;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'U' : a = rand() % 3 + 95;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'V' : strcat(ciphertext, key[98]); break;
                case 'W' : strcat(ciphertext, key[99]); break;
                case 'X' : strcat(ciphertext, key[100]); break;
                case 'Y' : a = rand() % 2 + 101;
                           simpan[b++] = a;
                           index = a;
                           strcat(ciphertext, key[index]); break;
                case 'Z' : strcat(ciphertext, key[103]); break;

            }
            //printf("%d", index);
        } else {
            strncat(ciphertext, &c, 1); // Tambahkan karakter tanpa enkripsi
        }
    }
}

void decryptHomophonic(char ciphertext[], char decryptedtext[], char key[][3]) {
    int i;
    for (i = 0; i < strlen(ciphertext); i += 2) {
        //int jmlh = strlen(ciphertext);
        //printf("%d", jmlh);
        char symbol[3] = {ciphertext[i], ciphertext[i + 1], '\0'};
        int j;
        for (j = 0; j < 105; j++) {
            if (strcmp(key[j], symbol) == 0) {
                int decryptedIndex = j;
                //printf("%d", key[j]);
                if (decryptedIndex >= 0 && decryptedIndex <= 6) {
                    /*decryptedIndex >= 0 && decryptedIndex <= 7*/
                    printf("%d\n", decryptedIndex);
                    strncat(decryptedtext, "A", 1);
                } else if(decryptedIndex == 7){
                    strncat(decryptedtext, "B", 1);
                }else if(decryptedIndex >= 8 && decryptedIndex <= 10){
                    strncat(decryptedtext, "C", 1);
                }else if(decryptedIndex >= 11 && decryptedIndex <= 14){
                    strncat(decryptedtext, "D", 1);
                }
                else if(decryptedIndex >= 15 && decryptedIndex <= 27){
                    strncat(decryptedtext, "E", 1);
                }
                else if(decryptedIndex >= 28 && decryptedIndex <= 30){
                    strncat(decryptedtext, "F", 1);
                }else if(decryptedIndex >= 31 && decryptedIndex <= 32){
                    strncat(decryptedtext, "G", 1);
                }else if(decryptedIndex >= 33 && decryptedIndex <= 35){
                    strncat(decryptedtext, "H", 1);
                }else if(decryptedIndex >= 36 && decryptedIndex <= 43){
                    strncat(decryptedtext, "I", 1);
                }else if(decryptedIndex == 44){
                    strncat(decryptedtext, "J", 1);
                }else if(decryptedIndex == 45){
                    strncat(decryptedtext, "K", 1);
                }else if(decryptedIndex >= 46 && decryptedIndex <= 49){
                    strncat(decryptedtext, "L", 1);
                }else if(decryptedIndex >= 50 && decryptedIndex <= 52){
                    strncat(decryptedtext, "M", 1);
                }else if(decryptedIndex >= 53 && decryptedIndex <= 60){
                    strncat(decryptedtext, "N", 1);
                }else if(decryptedIndex >= 61 && decryptedIndex <= 67){
                    strncat(decryptedtext, "O", 1);
                }else if(decryptedIndex >= 68 && decryptedIndex <= 70){
                    strncat(decryptedtext, "P", 1);
                }else if(decryptedIndex == 71){
                    strncat(decryptedtext, "Q", 1);
                }else if(decryptedIndex >= 72 && decryptedIndex <= 79){
                    strncat(decryptedtext, "R", 1);
                }else if(decryptedIndex >= 80 && decryptedIndex <= 85){
                    strncat(decryptedtext, "S", 1);
                }else if(decryptedIndex >= 86 && decryptedIndex <= 94){
                    strncat(decryptedtext, "T", 1);
                }else if(decryptedIndex >= 95 && decryptedIndex <= 97){
                    strncat(decryptedtext, "U", 1);
                }else if(decryptedIndex == 98){
                    strncat(decryptedtext, "V", 1);
                }else if(decryptedIndex == 99){
                    strncat(decryptedtext, "W", 1);
                }else if(decryptedIndex == 100){
                    strncat(decryptedtext, "X", 1);
                }else if(decryptedIndex >= 101 && decryptedIndex <= 102){
                    strncat(decryptedtext, "Y", 1);
                }else if(decryptedIndex == 103){
                    strncat(decryptedtext, "Z", 1);
                }
                else{
                    // Jika tidak, tentukan karakter sesuai dengan indeks
                    char decryptedChar = 'A' + j;
                    strncat(decryptedtext, &decryptedChar, 1);
                }
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    char plaintext[100];
    char ciphertext[200] = "";
    char decryptedtext[100] = "";

    char key[105][3] = {
        "BU", "CP", "AV", "AH", "BT", "BS", "CQ", 
        "AT",
        "DL", "BK", "AU",
        "BV", "DY", "DM", "AI",
        "DK", "CO", "AW", "BL", "AA", "CR", "BM", "CS", "AF", "AG", "BO", "BN", "BE",
        "BW", "CM", "CN",
        "DN", "BJ",
        "AS", "CL", "CK",
        "DJ", "BI", "AX", "CJ", "AB", "BP", "CU", "CT",
        "BX",
        "DI",
        "AR", "BH", "CI", "AJ",
        "DH", "BG", "AY",
        "BY", "DG", "DF", "CH", "AC", "BR", "DU", "DT",
        "DZ", "BF", "DX", "AK", "CG", "BQ", "DR",
        "BZ", "DE", "AZ", 
        "DD",
        "AQ", "DC", "DQ", "AL", "CE", "CF", "CV", "DS",
        "AP", "AN", "AO", "CD", "DW", "DV",
        "CB", "DB", "DP", "CC", "AD", "CY", "CW", "CX", "AE", 
        "CA", "AM", "BA",
        "BB",
        "CZ",
        "BD",
        "DO", "DA",
        "BC"
    };

    printf("Masukkan teks yang ingin dienkripsi: ");
    scanf("%s", &plaintext);

    encryptHomophonic(plaintext, ciphertext, key);
    printf("\nTeks Terenkripsi: %s\n", ciphertext);

    decryptHomophonic(ciphertext, decryptedtext, key);
    printf("Teks Terdekripsi: %s\n", decryptedtext);

    return 0;
}