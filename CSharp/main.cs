using System;
using System.Collections.Generic;
using System.Linq;
//April 15 midterm 2






class MainClass {

class People // definition for people type, consisting of name and age
{
    public string Name { get; set; }
    public int Age { get; set; }
}

 static void genSort<T>(T[] arr, bool reverse){ //generic sort for normal data types
     Array.Sort(arr); // sort array in ascending order

     if(reverse) // if reverse argument is true, array becomes orders in descending order
     {
       Array.Reverse(arr);
     }
}


// overloaded genSort functions for type People
// byAge argument lets users sort people by age if true
 static void genSort(People[] arr, bool reverse, bool byAge){
     People[] temp = new People[arr.Length]; // temporary array
     


     if(byAge)
     {
       temp = arr.OrderBy(p=> p.Age).ToArray(); // sort by age ascending order
     }

     else{
       temp = arr.OrderBy(p=> p.Name).ToArray(); // sort by name ascending order
     }


     if(reverse) // make temp array ordered in descending order
     {
       Array.Reverse(temp);
     }



     for(int x =0; x < temp.Length; x++) // loop that changes each element in the passed array with those of the new ordered array
     {
       arr.SetValue( temp[x], x );
     }





     
}


  public static void Main (string[] args) {


    // sort by int test
    Console.Write ("sorting int in ascending order:  ");

    int [] a = {5,2,-1, 10, -40, 38};
  
          genSort<int>(a, false); 
     for(int x = 0; x < a.Length; x++){
       Console.Write (a[x]);
       Console.Write (", ");

    }

    Console.WriteLine ("\n");
    Console.WriteLine ("\n");


     // sort by float test
    Console.WriteLine ("Sort floats in ascending order");

    double [] b = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
  
      genSort<double>(b, false); 
     for(int x = 0; x < b.Length; x++){
       Console.Write (b[x]);
       Console.Write (", ");

    }

   Console.WriteLine ("\n");
    Console.WriteLine ("\n");



  // sort by people via age and descending test
  Console.WriteLine ("Sort people in descending order by age");
  People[] peops = { new People { Name="Hal", Age=20 },
                   new People { Name="Susann", Age=31 },
                   new People { Name="Dwight", Age=19 },
                   new People { Name="Kassandra", Age=21 },
                   new People { Name="Lawrence", Age=25 },
                   new People { Name="Cindy", Age=22 },
                   new People { Name="Cory", Age=27 },
                   new People { Name="Mac", Age=19 },
                   new People { Name="Romana", Age=27 },
                   new People { Name="Doretha", Age=32 },
                   new People { Name="Danna", Age=20 },
                   new People { Name="Zara", Age=23 },
                   new People { Name="Rosalyn", Age=26 },
                   new People { Name="Risa", Age=24 },
                   new People { Name="Benny", Age=28 },
                   new People { Name="Juan", Age=33 },
                   new People { Name="Natalie", Age=25 } };
   




  genSort(peops, true, true);
  //People[] pep = peops.OrderBy(p=> p.Age).ToArray();

  for(int x = 0; x < peops.Length; x++){
       Console.Write (peops[x].Name + " "+ peops[x].Age );
      Console.Write (", ");
    }


 Console.WriteLine ("\n");
    Console.WriteLine ("\n");





// sort by people via name test

  Console.WriteLine ("");
    Console.WriteLine ("Sort people by name");  
   genSort(peops, false, false);
  //People[] pep = peops.OrderBy(p=> p.Age).ToArray();

  for(int x = 0; x < peops.Length; x++){
       Console.Write (peops[x].Name + " "+ peops[x].Age );
      Console.Write (", ");
    }


  }
}