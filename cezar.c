#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 1000

//(str[i] - 'a') + shift) %26 + 'a' 

char* cezar_cipher(char* str, int key){
    int lenght = (strlen(str));
    char* cipher = (char*) malloc (sizeof(char)*(lenght+1));
    for(int i=0; i<lenght; i++){
        if(str[i] >= 'a' && str[i] <='z')
        {
            cipher[i] = ((str[i]- 'a')+key) %26 +'a';
        }
        else
        {
            cipher[i] = str[i];
        }
    }
    cipher[lenght] = '\0';
    return cipher;
}

int main()
{
    char str[MAXN];
    scanf("%s",str);

    int key;
    scanf("%d",&key);

    char* cipher = cezar_cipher(str, key);
    printf("%s",cipher);
    return EXIT_SUCCESS;
}/*  */






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char *cezar_decipher(char *cipher, int key)
{
    int length = strlen(cipher);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++)
    {

        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if (cipher[i] >= '0' && cipher[i] <= '9')
        {
            str[i] = (cipher[i] - '0' - key + 10) % 10 + '0';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    str[length] = '\0';
    return str;
}

int read_cipher(char *filename, char *cipher)
{

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }
    if (fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.\n");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
int write_text(char *plaintext)
{
    char *filename = "plain.txt";
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s", plaintext);
    fclose(fp);
}
int main()
{

    // char filename[MAXN];
    // printf("Enter filename: \n");
    // scanf("%s", filename);
    char cipher[MAXN];
    fgets(cipher, MAXN, stdin);
    int key;
    printf("Enter key:\n");
    scanf("%d", &key);
    char *text = cezar_decipher(cipher, key);
    printf("%s", text);
    free(text);
    return EXIT_SUCCESS;
}