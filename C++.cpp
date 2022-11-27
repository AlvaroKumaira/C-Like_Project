#include <iostream>
using namespace std;

void encoder(){

  char message[500], point;
  int key;

  cout<<"Type the sentence you want to encrypt: ";
  cin>>message;
  cout<<"Now, type the key you want to use (Number): ";
  cin>>key;

  for(int i=0; message[i]!='\0'; i++){

    point = message[i];

    if (islower(point)){
      point = (point - 'a' + key) % 26 + 'a';
    }
    if (isupper(point)){
      point = (point - 'A' + key) % 26 + 'A';
    }
    if (isdigit(point)){
      point = (point - '0' + key) % 10 + '0';
    }

    message[i]=point;
}

  cout<<"The encrypted message is:\n";
  cout<<message;

}
void decoder(){

  char message[500], point;
  int key;

  cout<<"Type the sentence you want to decrypt: ";
  cin>>message;
  cout<<"Now, type the key that was used (Number): ";
  cin>>key;

  for(int i=0; message[i]!='\0'; i++){

    point = message[i];

    if (islower(point)){
      point = (point - 'a' - key) % 26 + 'a';
    }
    if (isupper(point)){
      point = (point - 'a' - key) % 26 + 'A';
    }
    if (isdigit(point)){
      point = (point - 'a' - key) % 10 + '0';
    }

    message[i]=point;
}

  cout<<"The encrypted message was:\n";
  cout<<message;
}

int main() {
  int opc;

  do{
    cout<<"[1] Encrypt a message\n";
    cout<<"[2] Decrypt a message\n";
    cout<<"[0] Exit\n";
    cin>>opc;

    switch(opc){
      case 1:
        encoder();
        break;
      case 2:
        decoder();
        break;
      case 0:
        cout<<"Bye!\n";
        break;
      default:
        cout<<"Invalid Option!\n";
        break;
    }
  }
  while(opc!=0);
  

  return 0;
}
