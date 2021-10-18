#nst9fk

repeat_program = True
while(repeat_program):

    #file management
    file_name = 'numbers.txt'
    try:
        f = open(file_name, "r")
        #opening variable declarations to allow loop to run
        first_value = int(f.readline())
        maximum = first_value
        minimum = first_value
        total_sum = first_value
        total_count = 1
        for x in f:
            #typecast to integer to allow math to work
            x = int(x)
            total_count+=1
            total_sum += x
            #check if minimum
            if x < minimum:
                minimum = x
            #Check if maximum
            if x > maximum:
                maximum = x
        f.close()
    except :
        #with any isssues, kick back an error
            print("Error Reading File")
    else:
            #calculate average and range
            average = int(total_sum) / float(total_count)
            range_total = maximum - minimum
            #print output
            print("File Name: ",file_name)
            print("Sum: ",total_sum)
            print("Count: ",total_count)
            print("Average: ",average)
            print("Maximum: ",maximum)
            print("Minimum: ",minimum)
            print("Range: ",range_total)
    #program repeat check
    another_calculation = input("Would you like to evaluate another file? (y/n): ")
    if(another_calculation != 'y'):
        repeat_program = False
