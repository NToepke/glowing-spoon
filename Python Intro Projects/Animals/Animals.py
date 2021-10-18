#nst9fk
import random
class Animal:
        #variable declaration
        __animal_type = ""
        __name = ""
        __mood = ""

        def __init__(self, animal, name):
                #variable initialization
                self.__animal_type = animal
                self.__name = name
                #generate random number for mood (1-3 inclusive)
                moodint = random.randint(1,3)
                #set mood variable based on random number
                if moodint == 1:
                        self.__mood = "happy"
                elif moodint == 2:
                        self.__mood = "hungry"
                else:
                        self.__mood = "sleepy"
        #accessor functions to access private/hidden values
        def get_animal_type(self):
            return self.__animal_type
        def get_name(self):
            return self.__name
        def check_mood(self):
            return self.__mood
            

        
        
