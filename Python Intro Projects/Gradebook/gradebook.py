# gradebook.py
# Nathan Toepke NST9FK
# Display the average of each student's grade.
# Display tthe average for each assignment.

gradebook = [[61, 74, 69, 62, 72, 66, 73, 65, 60, 63, 69, 63, 62, 61, 64],
             [73, 80, 78, 76, 76, 79, 75, 73, 76, 74, 77, 79, 76, 78, 72],
             [90, 92, 93, 92, 88, 93, 90, 95, 100, 99, 100, 91, 95, 99, 96],
             [96, 89, 94, 88, 100, 96, 93, 92, 94, 98, 90, 90, 92, 91, 94],
             [76, 76, 82, 78, 82, 76, 84, 82, 80, 82, 76, 86, 82, 84, 78],
             [93, 92, 89, 84, 91, 86, 84, 90, 95, 86, 88, 95, 88, 84, 89],
             [63, 66, 55, 67, 66, 68, 66, 56, 55, 62, 59, 67, 60, 70, 67],
             [86, 92, 93, 88, 90, 90, 91, 94, 90, 86, 93, 89, 94, 94, 92],
             [89, 80, 81, 89, 86, 86, 85, 80, 79, 90, 83, 85, 90, 79, 80],
             [99, 73, 86, 77, 87, 99, 71, 96, 81, 83, 71, 75, 91, 74, 72]]
# gradebook = [[100, 100, 100, 96],[97, 87, 92, 88],[91, 90, 92, 91]]
# ^ other provided input with given output
number_assignments = len(gradebook[0])
number_students = len(gradebook)
# save number of assignments and students for later use
i = 0 # first iterator for various loops
# first deal with the averages for the students
student_average=0
student_averages=[]
# two variables are used so that the number can be stored in its final form
while (i < number_students ):
    # loop through all students and get the sum of all values in their list
    student_average = sum(gradebook[i])
    i+=1
    student_average/=number_assignments
    # divide by number of assignments and then save the finalized average to the list
    student_averages.append(student_average)

assignment_averages=[]
i=0
# reset iterator and declare the assignment avereages list
while(i < number_assignments):
    assignment_averages.append(0)
    i+=1
# above loop initializes all instances in the assignment averages list

i=0
# reset iterator and use nested loop to go through all values in the list
while ( i < number_assignments): # start with assignments as thats the number of indices in the average list
    j=0 # create iterator for nested loop
    while ( j < number_students): 
        assignment_averages[i] += gradebook[j][i] # index values may seem backwards, but j is tracking the student,
        # while i tracks the assignment. Because we want the assignment to be the same on the inside of the nested loop,
        # i is the second bracketed number
        j+=1 #increase iterator to prevent infinite loop
    i+=1 #increase iterator to prevent infinite loop
i=1 #reset iterators to work on following for loops to track which student/ assignment is being printed
j=1
print("Assignment Averages:")
for x in assignment_averages:
    x /= number_students #division of assignment averages is done here instead of in a separate loop, mostly for fun
    print("Assignment ",j,": %.2f" % x) #print formatting prints out each average with 2 decimal places
    j+=1
print("\nStudent Averages:")    
for x in student_averages:
    print("Student ",i,": %.2f" % x) #print formatting prints out each average with 2 decimal places
    i+=1

