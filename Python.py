def encrypt():
  
  message = input("Type the message you want to encrypt: ")
  key = int(input("Now type the key you want to use: "))
  message_list = list(message)

  for i in range(len(message)):
    point = message_list[i]

    if(point.islower()):
      point = chr((ord(point) - ord('a') + key) % 26 + ord('a'));
    if(point.isupper()):
      point = chr((ord(point) - ord('A') + key) % 26 + ord('A'));
    if(point.isdigit()):
      point = chr((ord(point) - ord('0') + key) % 26 + ord('0'));

    message_list[i] = point

  encry_message = ''.join(message_list)
  print("The encrypted message is: ")
  print(encry_message)

def decrypt():
  
  message = input("Type the message you want to decrypt: ")
  key = int(input("Now type the key that was used: "))
  message_list = list(message)

  for i in range(len(message)):
    point = message_list[i]

    if(point.islower()):
      point = chr((ord(point) - ord('a') - key) % 26 + ord('a'));
    if(point.isupper()):
      point = chr((ord(point) - ord('A') - key) % 26 + ord('A'));
    if(point.isdigit()):
      point = chr((ord(point) - ord('0') - key) % 26 + ord('0'));

    message_list[i] = point

  decryp_message = ''.join(message_list)
  print("The decrypted message is: ")
  print(decryp_message)

def menu():

  opt = 5

  while opt != 0:

    print("[1] Encoder")
    print("[2] Decoder")
    print("[0] Exit")
    opt = int(input("Select: "))

    if (opt==1):
      encrypt()
    elif (opt==2):
      decrypt()
    elif (opt==3):
      print("Bye!")
    else:
      print("Invalid Option!")

menu()