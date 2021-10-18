#nst9fk
import random
import math
import Card
import sys

def play_a_game(data):
    hand_number = data[2] + data[3] + data[4] + 1
    print("\n\nHand %d:" % hand_number)

    #   Take bet
    bet = -1
    while bet > data[1] or bet <= 0:
        try:
            print("You have %d chips." % data[1])
            bet = int(input("How many chips to bet for this hand? "))
        except ValueError:
            print("Please enter a valid number of chips to bet!")
            bet = -1
        else:
            if bet>data[1]:
                print("You cannot bet more chips than you have!")
            elif bet==0:
                print("You cannot bet zero chips!")
            elif bet<0:
                print("You cannot bet negative chips!")
    data[5] = bet
    #   Deal Player Cards
    print("Dealing Cards...\n")
    number_aces=0
    total=0
    #   check for aces
    new_card1 = Card.Card()
    if new_card1.get_value() == 11:
        number_aces = 1
    new_card2 = Card.Card()
    if new_card2.get_value() == 11:
        if number_aces == 1:
            number_aces = 1
    total = new_card1.get_value() + new_card2.get_value()
    #   if you draw two aces, total goes to 12
    if total == 22:
        total = 12
    hand = [new_card1,new_card2]

    #   Deal Dealer's Cards
    dealer_aces=0
    dealer_total = 0
    dealer_card1 = Card.Card()
    if dealer_card1.get_value() == 11:
        dealer_aces = 1
    dealer_card2 = Card.Card()
    if dealer_card2.get_value() == 11:
        dealer_aces = 1
    dealer_total = dealer_card1.get_value() + dealer_card2.get_value()
    #   if you draw two aces, total goes to 12
    if dealer_total == 22:
        dealer_total = 12
    dealer_hand = [dealer_card1,dealer_card2]

    #   print hands
    print("Your hand:")
    for x in hand:
        print(x)
    print("\nDealer's shown card:")
    print(dealer_hand[0])

    #   check for blackjacks
    if total == 21:
        print("\nBLACKJACK!")
        data[5] = math.floor(data[5]*1.5)
        win(data)
    elif dealer_total == 21:
        print(dealer_hand[1])
        print("\nDealer has Blackjack!")
        loss(data)

        
    #   player hit or stand
    while True:
        choice = input("\nEnter '1' to hit, anything else to stand: ")
        if choice == "1":
            #   deal card
            new_card = Card.Card()
            print("Card Drawn: " + str(new_card))
            if new_card.get_value() == 11:
                number_aces +=1
            total += new_card.get_value()
            #   player busts, check for aces
            if total > 21:
                if number_aces > 0:
                    total -= 10
                    number_aces -= 1
                else:
                    print("BUST")
                    print("Your total: %d" % total)
                    loss(data)
            #   player did not bust, add card to hand
            hand.append(new_card)
            print("\nYour hand:")
            for x in hand:
                print(x)
            print("\nDealer's shown card:")
            print(dealer_hand[0])
            #   repeat until user does not hit
        else:
            break

    #   User has stood
    #   Show dealer hand
    print("\nDealer's hand:")
    for x in dealer_hand:
        print(x)
    #   if the dealer is at or above 17, do not print totals
    #   print is covered after the while loop
    if dealer_total >= 17:
        print("\nDealer total: %d" % dealer_total)
        print("Your total: %d" % total)
    #   dealer already has a better hand
    if dealer_total>total:
        loss(data)
    #   dealers hand is not better
    while dealer_total<17 and dealer_total<total:
        #   deal card
        new_card = Card.Card()
        print("\nCard Drawn: " + str(new_card))
        if new_card.get_value() == 11:
            dealer_aces +=1
        dealer_total += new_card.get_value()
        #   dealer busts, check for aces
        if dealer_total > 21:
            if dealer_aces > 0:
                dealer_total -= 10
                dealer_aces -= 1
            else:
                print("New Dealer Total: %d" % dealer_total)
                print("DEALER BUST\n")
                win(data)
        print("New Dealer Total: %d\n" % dealer_total)
        #   dealer did not bust, add card to hand
        dealer_hand.append(new_card)
            
        #   repeat until dealer hits or passes 17 or wins
    #   if no-one busted, determine outcome
    if(dealer_total<22 and total<22):
        print("Dealer total: %d" % dealer_total)
        print("Your total: %d" % total)
        if dealer_total > total:
            loss(data)
        elif dealer_total < total:
            win(data)
        else:
            tie(data)

#   add winnings to user, increase win stat
def win(data):
    print("You Win!")
    data[2] += 1
    data[1] += data[5]
    post_game_menu(data)

#   remove losses from user, increase loss stat
def loss(data):
    print("You Lose!")
    data[3] += 1
    data[1] -= data[5]
    post_game_menu(data)

#   increase tie stat
def tie(data):
    print("It's a Tie!")
    data[4] += 1
    post_game_menu(data)


def load_stats():
    #   get name to load file
    name = input("What is your name? ")
    try:
        #   try reading file of given name
        data = [name,0,0,0,0,0]
        f = open(name+".usr","r")
        data[0] = f.readline()
        data[1] = f.readline()
        data[2] = f.readline()
        data[3] = f.readline()
        data[4] = f.readline()
        f.close()
    except Exception as e:
        print("data unable to be loaded!")
        print(e)
        menu()
    else:
        data[0]=data[0].strip("\n")
        data[1]=int(data[1])
        data[2]=int(data[2])
        data[3]=int(data[3])
        data[4]=int(data[4])
        print("Welcome back %s, let's play!" % data[0])
        play_a_game(data)

def save_stats(data):
    try:
        #   try writing data of user to file
        f = open(data[0]+".usr","w")
        f.write(data[0]+"\n")
        f.write(str(data[1])+"\n")
        f.write(str(data[2])+"\n")
        f.write(str(data[3])+"\n")
        f.write(str(data[4])+"\n")
        f.close()
    except Exception as e:
        print("Sorry" + data[0] + ", your data was not able to be saved!")
        print(e)
    else:
        print(data[0] +", your data has been saved!")

def stats(data):
    print("\n"+ data[0]+", here are your game play statistics...")
    print("Chips: %d" % data[1])
    print("Wins: %d" % data[2])
    print("Losses: %d" % data[3])
    print("Ties: %d" % data[4])
    try:
        ratio = data[2] / data[3]
    except ZeroDivisionError:
        print("Win/loss ratio: INFINITE")
    else:
        print("Win/loss ratio: %.3f" % ratio)
    post_game_menu(data)
    
def post_game_menu(data):
    #   To prevent being stuck with no chips, players are given 100 more in case they lose all chips to continue play
    if data[1] == 0:
        print("You've run out of chips!\nHere is another 100 to get you going!\nGood Luck!")
        data[1] = 100
    print("\n1. Play again")
    print("2. View statistics")
    print("3. Quit")
    choice = input("\nEnter choice: ")
    if choice == '1':
        play_a_game(data)
    elif choice == '2':
        stats(data)
    elif choice == '3':
        save_stats(data)
        print("Bye!")
        sys.exit(0)
    else:
        print("Invalid choice!")
        post_game_menu(data)
    
def menu():
    print("Let's Play Blackjack!\n")
    print("1. Start a new player")
    print("2. Load a player")
    print("3. Quit")
    choices =["1", "2", "3"]
    choice = input("Enter choice: ")

    while choice not in choices:
        print(choice + " is not a valid choice!")
        choice = input("Enter a valid choice [1-3]: ")
    
    if choice == '1':
        name = input("\nWhat is your name? ")
        print("Hello "+name+". Let's play!")
        data = [name,100,0,0,0,0]
        print("You will start with "+str(data[1])+ " chips")
        play_a_game(data)
    if choice == '2':
        load_stats()
    if choice == '3':
        print("Bye!")
        sys.exit(0)
    

menu()
