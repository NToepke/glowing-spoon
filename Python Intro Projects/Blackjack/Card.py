#nst9fk
import random
class Card:
    __display_value = ""
    __value = 0
    __suit = ""

    def __init__(self):

        temp_value = random.randint(1,13)
        card_dict = {1: "Ace", 2: "Two", 3: "Three", 4: "Four",
                     5: "Five", 6: "Six", 7:"Seven", 8: "Eight",
                     9: "Nine", 10: "Ten", 11: "Jack", 12: "Queen",
                     13: "King"}
        self.__display_value = card_dict[temp_value]
        suit_dict = {1:"♥",2:"♠",3:"♣",4:"♦"}
        self.__suit = suit_dict[random.randint(1,4)]
        if temp_value > 10:
            self.__value = 10
        elif temp_value == 1:
            self.__value = 11
        else:
            self.__value = temp_value

    def __str__(self):
        return self.__display_value + " of " + self.__suit
        
    def get_value(self):
        return self.__value
    def get_face(self):
        return self.__display_value
    def get_suit(self):
        return self.__suit
