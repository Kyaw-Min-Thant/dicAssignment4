#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

char arr[10000];
char toFind[]="winhtut";
int count = 0;
char  w[100];
int arrLength=4739;
int i=0;
int j=0;

void gotoNextWord();

int main(){
    FILE *fptr;
    fptr = fopen("words.txt","r");
    for (int i=0;i<5000;i++){
        char c = fgetc(fptr);
        arr[i]=c;
    }

    printf("Enter words: ");
    gets(w);

    int wLen;
    wLen = strlen(w);
    i = j = count = 0;
    while (i<arrLength){
        if(arr[i]==w[0]){
            for (j = 0; j < wLen; j++) {
                if(arr[i+j] != w[j]){
                    gotoNextWord();
                    break;
                }
            }
            if(j == wLen){
                if(isspace(arr[i+j])|| ispunct(arr[i+j])||arr[i+j]=='\0'){
                    count++;
                    i += j;
                }
            }
        } else{
            gotoNextWord();
        }
        i++;
    }
    printf("Found %d%c%s\n",count ,' ', w);
    fclose(fptr);
    return 0;
}

void gotoNextWord(){
    while (isspace(arr[i])== 0 && ispunct(arr[i])== 0 && arr[i] != '\0'){
        i++;
    }

}
#pragma clang diagnostic pop