import Data.List
import Data.Foldable
import Data.Bool



data People = People String Int deriving (Show, Eq) -- define people datatype as a string (name) and Int (age)



name :: People -> String
name   (People n a ) = n ------ this function returns the  name of the People 

age :: People -> Int
age   (People n a ) = a ------ this function returns the age of the People 


--- function that compares two people by name
nameSortHelp (People n a) (People n2 a2 )  | n > n2 = GT
                                           | n < n2 = LT
                                           | n == n2 = compare a a2

--- function that compares two people by age
ageSortHelp (People n a) (People n2 a2 )   | a > a2 = GT
                                           | a < a2 = LT
                                           | a == a2 = compare n n2


-- function that sorts any type, rev argument reverses ordering if True, and f argument is that type of comparison being done to the list, which for this assignment dictates the list's type

genericSort (a:as) f   rev     | (rev == False) = sortBy f (a:as)
                               | (rev == True) = reverse (sortBy f (a:as))




main = do
-- Testing int sort
  print("Order by ints")
  print(genericSort [5,3,8,7] compare False)
  print(" ")

-- Testing float sort
  print("Order by floats")
  print(genericSort [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26] compare False)
  print(" ")


-- Testing People by age in descending order sort
  print("Order People by age in descending order")
  print(genericSort [People "Hal" 20 , People "Susann" 31 , People "Dwight" 19 , People "Kassandra" 21 , People "Lawrence" 25 , People "Cindy" 22 , People "Cory" 27 , People "Mac" 19 , People "Romana" 27 , People "Doretha" 32 , People "Danna" 20 , People "Zara" 23 , People "Rosalyn" 26 , People "Risa" 24 , People "Benny" 28 , People "Juan" 33 , People "Natalie" 25 ]  ageSortHelp True  )
  print(" ")



-- Testing People by name in ascending order sort
  print("Order People by age in ascending order")
  print(genericSort [People "Hal" 20 , People "Susann" 31 , People "Dwight" 19 , People "Kassandra" 21 , People "Lawrence" 25 , People "Cindy" 22 , People "Cory" 27 , People "Mac" 19 , People "Romana" 27 , People "Doretha" 32 , People "Danna" 20 , People "Zara" 23 , People "Rosalyn" 26 , People "Risa" 24 , People "Benny" 28 , People "Juan" 33 , People "Natalie" 25 ]  nameSortHelp False  )
  print(" ")







