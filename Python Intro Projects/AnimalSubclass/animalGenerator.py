#nst9fk
import Animal

#initialize variables
animal_list=list()

print("Welcome to the animal generator!\nThis program creates Animal objects.")

#add multiple animals loop
while (True):

    print("Would you like to create a mammal or bird? (Default Bird)")
    print("1. Mammal")
    print("2. Bird")
    choice = input("Which would you like to create? ")

    #gather member field data
    if choice == '1':
        animal_type = input("\nWhat type of mammal would you like to create? ")
        name = input("What is the mammal's name? ")
        color = input("What color is the mammal's hair? ")
        animal = Animal.Mammal(animal_type,name,color)
    else:
        animal_type = input("\nWhat type of bird would you like to create? ")
        name = input("What is the bird's name? ")
        flight = input("Can the bird fly? ")
        animal = Animal.Bird(animal_type,name,flight)
    animal_list.append(animal)
    #repeat program
    calculate_again = input("\nWould you like to enter another animal? (y/n) ")
    if (calculate_again != "y"):
        break

print("\nAnimal List:")

#loop through list and print all pertinent information
for x in animal_list:
    print(x.get_name() + " the " + x.get_animal_type() + " is " + x.check_mood())

