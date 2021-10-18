#cipher.py
#nst9fk

codex = "0123456789!@#$%^&*()-+<>?="
alphabet = "abcdefghijklmnopqrstuvwxyz"

def encode():
    text = input("\nEnter a message to encode: ")
    encoder = text.maketrans(alphabet,codex)
    print("Encoded message: "+text.translate(encoder)+"\n")
def decode():
    text = input("\nEnter a message to decode: ")
    decoder = text.maketrans(codex,alphabet)
    print("Decoded message: "+text.translate(decoder)+"\n")
    print()
def main():

    while(True):

        print("Welcome to the Secret Message Encoder/Decoder")
        print("1. Encode a message\n2. Decode a message\n3. Exit")
        choice = input("\nWhat would you like to do? ")
        try:
            if(int(choice) == 1):
                encode()
            elif(int(choice) == 2):
                decode()
            elif(int(choice) == 3):
                return
            else:
                raise ValueError
        except ValueError:
            print(choice+" is not a valid choice.")
        else:
            continue
main()
