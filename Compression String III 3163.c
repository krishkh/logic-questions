#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* compressedString(char* word) {
    char* newStr = (char*)malloc(sizeof(char)*4*strlen(word));
    char prev = word[0];
    int currentCounter = 1;
    int iteration = 0;
    for(int i = 1; word[i] != '\0'; i++){
        char current = word[i];
        if(current == prev && currentCounter < 9){
            currentCounter++;
            continue;
        }
        newStr[iteration++] = currentCounter+'0';
        newStr[iteration++] = prev;
        prev = current;
        currentCounter = 1;
    }
    newStr[iteration++] = currentCounter+'0';
    newStr[iteration++] = prev;
    newStr[iteration] = '\0';
    return newStr;
}

int main(){
    char* word = "aaaaaaaaaaaaaabb";
    printf("%s",compressedString(word));
}