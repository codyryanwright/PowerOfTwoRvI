// Author: Cody Wright
// Lab: Lab 3 Bonus
// Purpose: Iterative/Recursive Timed Driver Comparison
// Date: 2/23/2018

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <math.h>

#include "PowerOfTwoRecursive.cpp"
#include "PowerOfTwoIterative.cpp"

using namespace std;

long double Power_of_two(int);
long double Power_of_2_I(int);

double timeIterative (int exponent=0, int iteration=0)
{  
  cout << fixed << showpoint << setprecision (5);
  double start = double(clock()) / CLOCKS_PER_SEC;
  
  for (int i = 0; i<iteration; ++i)
    Power_of_2_I(exponent);
  
  double finish = double(clock()) / CLOCKS_PER_SEC;
  cout << fixed << showpoint << setprecision (5);
  double elapsed = finish - start; 
  
  return elapsed;
}

double timeRecursive(int exponent=0, int iteration=0)
{  
  cout << fixed << showpoint << setprecision (5);
  double start = double(clock()) / CLOCKS_PER_SEC;

  for (int i = 0; i<iteration; ++i)
    Power_of_two(exponent);
  
  double finish = double(clock()) / CLOCKS_PER_SEC;
  cout << fixed << showpoint << setprecision (5);
  double elapsed = finish - start; 
  
  return elapsed;
}

int main()
{
  const string filename = "comparison_results.csv";
  ofstream outFile(filename);
  
  // The best method of measuring difference is to step through increasing exponents
  // Increasing the iteration just gives a better comparison time
  // If you want to add more values for comparison, increase the max_exponent here
  // The time it takes to calculate 2^0 through 2^100 is negligible so test begins at 2^100
  const int max_exponent{1000};
  int iterations{100000};
  double recursiveElapsed{0};
  double iterativeElapsed{0};
    
  outFile<<"Exponent, Recursion Time,Iteration Time,Difference,Trial Runs = "<<iterations<<endl;
  
  cout<<"Now processing..."<<endl;  
  for(int exponent = 100; exponent<=max_exponent; exponent+=100) //exponent steps from 100 to 16000
  {
    recursiveElapsed = timeRecursive(exponent, iterations);
    iterativeElapsed = timeIterative(exponent, iterations);
    
    outFile<<exponent<<","<<recursiveElapsed<<","<<iterativeElapsed<<","
           <<fabs(recursiveElapsed-iterativeElapsed)<<endl;
  }
  outFile.close();
  
  cout<<"Finished, file written to "<<filename<<endl;
  
  return 0;
}
