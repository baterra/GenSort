

#Generic sort function that sorts different data types
#and chooses in which order. If sorting people, gives option
# to sort by age instead of name

# a is a list,  byAge is a bool, and reverse is a bool
def generic_sort( a, byAge, reverse):
 
  if byAge: 

    for x in a:  # switch places between name and age if sort by age
        x.reverse()

    if reverse:
      a.sort(reverse=True) # sort decending order
    else:
      a.sort() # sort ascending order

  else: 
    # not sort by age
    if reverse: 
      a.sort(reverse=True) # sort decending order
    else: 
      a.sort() # sort ascending order



print(" ")

#Test list of ints
print("Sort list of ints")
a = [-1, 43, 8, 34, -10, 3 , 2, 4, 5, 1]
generic_sort(a, False, False)
print(a)
print(" ")


#Test list of floats
print("Sort list of floats")
numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]

generic_sort(numbers , False, False)
print(numbers)
print(" ")



#Test list of people 
print("Sort list of people ")
people = [["Hal", 20] , ["Susann", 31], ["Dwight", 19], ["Kassandra", 21], ["Lawrence", 25], ["Cindy", 22], ["Cory", 27], ["Mac", 19], ["Romana", 27], ["Doretha", 32], ["Danna", 20], ["Zara", 23], ["Rosalyn", 26], ["Risa", 24], ["Benny", 28], ["Juan", 33], ["Natalie", 25]]

generic_sort(people , False, False)
print(people)
print(" ")



#Test list of people in descending order by age
print("Sort list of people in descending order by age")
people = [["Hal", 20] , ["Susann", 31], ["Dwight", 19], ["Kassandra", 21], ["Lawrence", 25], ["Cindy", 22], ["Cory", 27], ["Mac", 19], ["Romana", 27], ["Doretha", 32], ["Danna", 20], ["Zara", 23], ["Rosalyn", 26], ["Risa", 24], ["Benny", 28], ["Juan", 33], ["Natalie", 25]]

generic_sort(people , True, True)
print(people)
print(" ")
