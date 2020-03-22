#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;


struct People { // data type for people
  string Name;
  int Age;
  
} ;



// sorts arrays of normal data types
// has rev argument used to change the ordering to
//descending order
// byAge arument is used to order by age if array is of type people
// which is used mainly in the next function
template <class T>

void genSort (T x[], int size,  bool byAge, bool rev )
{

	std::sort(x, x + size);

  if(rev){
    reverse(x, x + size);
  }



}

// overloaded sorting function for type people
void genSort (People x[], int size, bool byAge, bool rev )
{

	if(byAge) // this nested if order the array by age
  {
       for(int i = 0; i < size ; i++) // this loop checks each element to see if they are in the right postion
    {
      for(int j = i; j < size; j++) // this loop checks if the current element being checked is greater than the next element being checked and if so swap them
      {
        if(x[i].Age == x[j].Age){ // check name if age are ==
            if(x[i].Name > x[j].Name)
          {
            People temp = x[i]; //swapping
            x[i] = x[j];
            x[j] = temp;
          }
        }
        else{
            if(x[i].Age > x[j].Age) // checks age
          {
            People temp = x[i]; // swapping
            x[i] = x[j];
            x[j] = temp;
          }
        }
          
      }
    }
  }
  else{ // this nest orders the array by name
    for(int i = 0; i < size ; i++) // this loop checks each element to see if they are in the right postion
    {
      for(int j = i; j < size; j++) // this loop checks if the current element being checked is greater than the next element being checked and if so swap them
      {
          if(x[i].Name == x[j].Name){ // check age if name are ==
            if(x[i].Age > x[j].Age)
          {
            People temp = x[i]; // swap
            x[i] = x[j];
            x[j] = temp;
          }
        }
        else{
            if(x[i].Name > x[j].Name) // check if name are ==
          {
            People temp = x[i]; // swap
            x[i] = x[j];
            x[j] = temp;
          }
        }
      }
    }
  }
  


if(rev){ // make array into descending order if true
    reverse(x, x + size);
  }

 

}


int main() {
 
 //Test sorting of ints
  std::cout << "Sorting ints \n";
  int a [] = {5,2,-1, 10, -40, 38};
  genSort(a, 6, false, false);
   for(int i = 0; i < 6; i++)
  {
    std::cout << a[i] << " , ";
  }
 std::cout << "\n\n\n";
  

//Test sorting of double
 std::cout << "Sorting double \n";
      double b [] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
        genSort(b, 12,false, false);
      for(int i = 0; i < 12; i++)
      {
        std::cout << b[i] << " , ";
      }
 std::cout << "\n\n\n";



//Test sorting of people by age in reverse
 std::cout << "Sorting people by age in decsending order \n";
People peops []= {  { "Hal", 20 },
                   { "Susann", 31 },
                    { "Dwight", 19 },
                   { "Kassandra", 21 },
                    {"Lawrence", 25 },
                    { "Cindy", 22 },
                    { "Cory", 27 },
                    { "Mac",19 },
                    { "Romana", 27 },
                    { "Doretha", 32 },
                    { "Danna",20 },
                    { "Zara",23 },
                    { "Rosalyn", 26 },
                   { "Risa", 24 },
                    { "Benny", 28 },
                    { "Juan", 33 },
                    {"Natalie", 25 } };

  genSort(peops, 17 ,true, true);


       for(int i = 0; i < 17; i++)
      {
        std::cout << peops[i].Name << " "<< peops[i].Age << " , ";
      }
 std::cout << "\n\n\n";



//Test sorting of People by name

 std::cout << "Sorting people by name in ascending order \n";
People peops2 []= {  { "Hal", 20 },
                   { "Susann", 31 },
                    { "Dwight", 19 },
                   { "Kassandra", 21 },
                    {"Lawrence", 25 },
                    { "Cindy", 22 },
                    { "Cory", 27 },
                    { "Mac",19 },
                    { "Romana", 27 },
                    { "Doretha", 32 },
                    { "Danna",20 },
                    { "Zara",23 },
                    { "Rosalyn", 26 },
                   { "Risa", 24 },
                    { "Benny", 28 },
                    { "Juan", 33 },
                    {"Natalie", 25 } };

  genSort(peops2, 17 ,false, false);


       for(int i = 0; i < 17; i++)
      {
        std::cout << peops2[i].Name << " "<< peops2[i].Age << " , ";
      }
 std::cout << "\n\n\n";


}