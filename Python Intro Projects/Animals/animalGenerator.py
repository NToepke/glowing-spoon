#nst9fk
from Animals import Animal

#initialize variables
animal_list=[]

print("Welcome to the animal generator!\nThis program creates Animal objects.")

#add multiple animals loop
while (True):

    #gather member  variable data
    animal_type = input("\nWhat type of animal would you like to create? ")
    name = input("What is the animal's name? ")

    #create object and add it to the list
    animal = Animal(animal_type,name) 
    animal_list.append(animal)
    #repeat program
    calculate_again = input("\nWould you like to enter another animal? (y/n) ")
    if (calculate_again != "y"):
        break

print("\nAnimal List:")

#loop through list and print all pertinent information
for x in animal_list:
    print(x.get_name() + " the " + x.get_animal_type() + " is " + x.check_mood())

temperature = 74.5
print('temperature')
a= [1,2,3,4,5]
print(a[:])
print(a[0:])
print(a[:100])
print(a[-1:])
