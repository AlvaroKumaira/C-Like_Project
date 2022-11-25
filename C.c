#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

void encoder(){

    char message[500], point; //variable point is used to store the switch
    int key;

    printf("Type the sentence you want to encrypt: ");
    scanf("%[^\n]", &message);
    fflush(stdin);
    printf("Now, type the key you want to use (Number): ");
    scanf("%d", &key);
    fflush(stdin);

    for(int i=0; message[i]!='\0';i++){ //for is used to run through the sentence written by the user

        point=message[i];
        
        /*
        the operation is the same for every case, but since ASCII are diferents for upper, 
        lower and digits, three if's are needed to check the char.
        */

        if (islower(point)) {
            point = (point - 'a' + key) % 26 + 'a'; //mod 26 is used for letters since there are 26 letters in the alphabet
        }
        if (isupper(point)) {
            point = (point - 'A' + key) % 26 + 'A';
        }
        if (isdigit(point)) {
            point = (point - '0' + key) % 10 + '0'; //mod 10 is used for digits (0-9)
        }

        message[i]=point; //assing messsage[i] the new value
    }

    printf("The encrypted message is:\n");
    printf("%s\n", message);

}

/*
The decoder works the same way the encoder does, with the difference that instead of adding the key the function subtracts it
*/
void decoder(){

    char message[500], point;
    int key;

    printf("Type the sentence you want to decrypt: ");
    scanf("%[^\n]", &message);
    fflush(stdin);
    printf("Now, type the key that was used (Number): ");
    scanf("%d", &key);
    fflush(stdin);

    for(int i=0; message[i]!='\0';i++){

        point=message[i];

        if (islower(point)) {
            point = (point - 'a' - key) % 26 + 'a';
        }
        if (isupper(point)) {
            point = (point - 'A' - key) % 26 + 'A';
        }
        if (isdigit(point)) {
            point = (point - '0' - key) % 10 + '0';
        }

        message[i]=point;
    }

    printf("The decrypted message is:\n");
    printf("%s\n", message);

}
int main(){

    int opc;

    do{
        printf("[1] Encrypt a message\n");
        printf("[2] Decrypt a message\n");
        printf("[0] Exit\n");
        printf("Select: ");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc){
        case 1:
            encoder();
            break;
        case 2:
            decoder();
            break;
        case 0:
            printf("Bye!\n");
        default:
            printf("Invalid Option!\n");
            break;
        }
    }
    while(opc!=0);

    system("pause");

    return 0;
}