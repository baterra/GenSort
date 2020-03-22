#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

struct People { // data type for people
  char  Name [50];
  int Age;

} ;



int cmpfunc (const void * a, const void * b) { // compare function between int
   return ( *(int*)a - *(int*)b );
}

int cmpfuncDoub (const void * a, const void * b) { // compare function between double
   return ( *(double*)a - *(double*)b );
}

int cmpfuncPeopleName (const void * a, const void * b) {  // compare function between People by name

  struct People aa = *(struct People*)a; // cast argumemnts into People
  struct People bb = *(struct People*)b;


   return ( strcmp(aa.Name, bb.Name)  == 0)? aa.Age - bb.Age : strcmp(aa.Name, bb.Name) ;
}

int cmpfuncPeopleAge (const void * a, const void * b) { // compare function between People by age

  struct People aa = *(struct People*)a; // cast argumemnts into People
  struct People bb = *(struct People*)b;

   return ( aa.Age - bb.Age == 0)? strcmp(aa.Name, bb.Name) : aa.Age - bb.Age ;
}

//////////////////////////////////////////////////

int cmpfuncPeopleNameReverse (const void * a, const void * b) { // compare function between People by name but reverse

  struct People bb = *(struct People*)a; // cast argumemnts into People
  struct People aa = *(struct People*)b; //variables a and b are swapped with each other to do the compare reverse

    return ( strcmp(aa.Name, bb.Name)  == 0)? aa.Age - bb.Age : strcmp(aa.Name, bb.Name) ;
}

int cmpfuncPeopleAgeReverse (const void * a, const void * b) {  // compare function between People by age but reverse

  struct People bb = *(struct People*)a; // cast argumemnts into People; 
  struct People aa = *(struct People*)b; //variables a and b are swapped with each other to do the compare reverse

   return ( aa.Age - bb.Age == 0)? strcmp(aa.Name, bb.Name) : aa.Age - bb.Age ;
}


int cmpfuncReverse (const void * a, const void * b) {  // compare function between int but reverse
   return ( *(int*)b - *(int*)a );
}


int cmpfuncDoubReverse (const void * a, const void * b) {  // compare function between double but reverse
   return ( *(double*)b - *(double*)a );
}


// generic sort, with byAge argument decides whether to order a array of People by age, and rev argument controls ascending vs descending ordering
void genSort(void * arr, int eleSize, int dataSize, bool byAge, bool rev )
{

  if(dataSize == sizeof(struct People) ) // apply people sort if array is of type people
  {
    if(byAge) // apply people sort by age
    {
          if(rev) // descending ordering
        {
            qsort(arr, eleSize, dataSize, cmpfuncPeopleAgeReverse);
        }
        else // ascending ordering
        {
          qsort(arr, eleSize, dataSize, cmpfuncPeopleAge);
        }
    }
    else // apply people sort by name
    {
        if(rev) // descending ordering
        {
            qsort(arr, eleSize, dataSize, cmpfuncPeopleNameReverse);
        }
        else // ascending ordering
        {
          qsort(arr, eleSize, dataSize, cmpfuncPeopleName );
        }
    }
      
      
  }
  else{
       if(dataSize == sizeof(int)) // apply people sort if array is of type int
       {
              if(rev) // descending ordering
              {
                  qsort(arr, eleSize, dataSize, cmpfuncReverse);
              }
              else // ascending ordering
              {
                qsort(arr, eleSize, dataSize, cmpfunc);
              } 
       }



       if(dataSize == sizeof(double)) // apply double sort if array is of type double
       {
              if(rev) // descending ordering
              {
                  qsort(arr, eleSize, dataSize, cmpfuncDoubReverse);
              }
              else // ascending ordering
              { 
                qsort(arr, eleSize, dataSize, cmpfuncDoub);
              } 
       }
  }


    
    
}



int main(void) {

  //Test to sort Int array
  printf("Sort ints \n");
  int a[] = { -1, 44, 3, -10, 1, 50, 32 };
  genSort(a, 7, sizeof(int) , false , false);
  
  for( int i = 0 ; i < 7; i++ ) {
      printf("%d ", a[i]);
   }



  //Test to sort double array
  printf("\n\n\n Sort double \n");
  double b [] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
  genSort(b, 12, sizeof(double) , false , false);
  
  for( int i = 0 ; i < 12; i++ ) {
      printf("%f ", b[i]);
   }


  //Test to sort people array by age in descending order
  printf("\n\n\n Sort People by age in descending order\n"); 
  struct People peops []= {  { "Hal", 20 },
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


  genSort(peops, 17 ,sizeof(struct People),  true , true );
  for( int i = 0 ; i < 17; i++ ) {
      printf("%s %d, ", peops[i].Name, peops[i].Age);
   }



     //Test to sort people array by name in ascending order
  printf("\n\n\n Sort People by name in ascending order\n"); 
  struct People peops2 []= {  { "Hal", 20 },
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


  genSort(peops2, 17 ,sizeof(struct People),  false , false );
  for( int i = 0 ; i < 17; i++ ) {
      printf("%s %d, ", peops2[i].Name, peops[i].Age);
   }




  return 0;
}