#nst9fk
print("Object Position Calculator")
repeat_program = True
while(repeat_program):
    #initial Position
    while(True):
        try:
            x_init = float(input("\n\nWhat is the object's initial position? "))
        except ValueError:
            print("The value you entered is invalid. Only numerical values are valid.")
        else:
            break
    #initial Velocity
    while(True):
        try:
            v_init = float(input("What is the object's initial velocity? "))
        except ValueError:
            print("The value you entered is invalid. Only numerical values are valid.")
        else:
            break
    #Acceleration
    while(True):
        try:
            accel = float(input("What is the object's acceleration? "))
        except ValueError:
            print("The value you entered is invalid. Only numerical values are valid.")
        else:
                break
    #Time in motion
    while(True):
        try:
            time = float(input("How long has the object been in motion? "))
            #check for negative
            if(time<0):
                 print("Negative time values are not allowed.")
                 continue
        except ValueError:
             print("The value you entered is invalid. Only numerical values are valid.")
        else:
             break
    #Xfinal = x0 + vt +1/2at^2
    xfinal = x_init + (v_init * time) + (.5 * accel * time ** 2)

    print("The final position of the object is",xfinal,"meters.")
    another_calculation = input("Do you want to perform another calculation? (y/n): ")
    if(another_calculation != 'y'):
        repeat_program = False
