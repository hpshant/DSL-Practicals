#prashant holam
#SE-II (P)
#Roll No.: 20
#PRN: F23112022
'''
Write a python program to store first year percentage of students in an array.
Write function for sorting array of floating point numbers in ascending order using:
a) Selection Sort
b) Bubble Sort and display top five scores
'''

# Function for Selection Sort of elements
def Selection_Sort(marks):
    for i in range(len(marks)):
        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j
        marks[i], marks[min_idx] = marks[min_idx], marks[i]

    print("Marks of students after performing Selection Sort on the list : ")
    for i in range(len(marks)):
        print(marks[i])

# Function for Bubble Sort of elements
def Bubble_Sort(marks):
    n = len(marks)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Marks of students after performing Bubble Sort on the list :")
    for i in range(len(marks)):
        print(marks[i])

# Function for displaying top five marks
def top_five_marks(marks):
    print("Top 5 Marks are : ")
    print(*marks[-1:-6:-1], sep="\n")

# Main
marks=[]
n = int(input("Enter number of students whose marks are to be displayed : "))
print("Enter marks for",n,"students: ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)  # adding the element

print("The marks of",n,"students are : ")
print(marks)

flag=1;
while flag==1:
    print("\n---------------MENU---------------")
    print("1. Selection Sort of the marks")
    print("2. Bubble Sort of the marks")
    print("3. Exit")
    ch=int(input("\n\nEnter your choice (from 1 to 3) : "))

    if ch==1:
        Selection_Sort(marks)
        a=input("\nDo you want to display top marks from the list (y/n) : ")
        if a=='y':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag=0

    elif ch==2:
        Bubble_Sort(marks)
        a = input("\nDo you want to display top five marks from the list (y/n) : ")
        if a == 'y':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = 0

    elif ch==3:
        print("\nThanks for using this program!!")
        flag=0

    else:
        print("\nEnter a valid choice!!")
        print("\nThanks for using this program!!")
        flag=0

#Output:
'''
Enter number of students whose marks are to be displayed : 10
Enter marks for 10 students: 
23
4
26
25
16
19
24
23
29
28
The marks of 10 students are : 
[23, 4, 26, 25, 16, 19, 24, 23, 29, 28]

---------------MENU---------------
1. Selection Sort of the marks
2. Bubble Sort of the marks
3. Exit


Enter your choice (from 1 to 3) : 1
Marks of students after performing Selection Sort on the list :
4
16
19
23
23
24
25
26
28
29

Do you want to display top marks from the list (y/n) : y
Top 5 Marks are :
29
28
26
25
24

---------------MENU---------------
1. Selection Sort of the marks
2. Bubble Sort of the marks
3. Exit


Enter your choice (from 1 to 3) : 2
Marks of students after performing Bubble Sort on the list :
4
16
19
23
23
24
25
26
28
29

Do you want to display top five marks from the list (y/n) : y
Top 5 Marks are :
29
28
26
25
24

---------------MENU---------------
1. Selection Sort of the marks
2. Bubble Sort of the marks
3. Exit


Enter your choice (from 1 to 3) : 3

Thanks for using this program!!
'''