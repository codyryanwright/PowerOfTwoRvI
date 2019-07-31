// Author: Cody Wright
// Lab: Lab 3 Part 2
// Purpose: Demonstrate "Power of 2" Iteratively
// Date: 2/23/2018

// REAL WORLD APPLICATION : Since memory is allotted in binary increments, it's growth can be modeled as a "Power of 2"
//                          Therefore, you could keep track of a data members size by calling the function, for example
//                          how the size of a vector increases it doubles everytime it resizes.
//                          Generically, it can be used anytime something is similarly growing at a rate of 200%
//                          The iterative candidate performs faster than its recursive counterpart and would not
//                          eat up the application stack, so it would be the preferred deployment.

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// As unsigned long long has a limit of k=63
// As long double has a limit of k=16383
long double Power_of_2_I(int k)
{
  long double result{1};
  
  if (k>0)
  {
    for (int i=0; i<k; ++i)
      result = result*2;
  }
  else if (k<0)
  {
    k=-k;
    for (int i=0; i<k; ++i)
      result = result*2;
    result=(1/result);
  }
  
  return result;
}

//int main()
//{
//  cout << "This program calculates a power of two iteratively..."<<endl;
//  
//  string str_exponent{""}; // use a string for validation
//  int int_exponent{0};  // after validation convert to int for calculation
//  bool good_exponent{false};
//  
//  while (true)
//  {
//    while(!good_exponent) // input validation
//    {
//      cout << "\nEnter the exponent: ";
//      cin>>str_exponent;
//      try
//      {
//        int_exponent=stoi(str_exponent);
//        good_exponent=true;
//      }
//      catch (exception& e)
//       cout<<"  Invalid Entry"<<endl; 
//    }
//    
//    cout << "  2^" << int_exponent << " = " << Power_of_2_I(int_exponent)<<endl;
//    
//    string choice{""};
//  
//    while(true)
//    {
//      cout<<"\nWould you like to enter another? (Y/N) ";
//      cin>>choice;
//            
//      if ((toupper(choice[0])!='Y' && toupper(choice[0])!='N') || choice.length()>1)
//        cout<<"  Invalid Entry"<<endl;
//      else break;
//    }
//    
//    if (toupper(choice[0])=='N') break; // exit program
//    else good_exponent=false; // reset for new entry
//  }
//  
//  return 0;
//}

/* Test output:
This program calculates a power of two iteratively...

Enter the exponent: a
  Invalid Entry

Enter the exponent: 0
  2^0= 1

Would you like to enter another? (Y/N) a
  Invalid Entry

Would you like to enter another? (Y/N) y

Enter the exponent: 1
  2^1= 2

Would you like to enter another? (Y/N) y

Enter the exponent: 2
  2^2= 4

Would you like to enter another? (Y/N) y

Enter the exponent: 10
  2^10= 1024

Would you like to enter another? (Y/N) y

Enter the exponent: 16383
  2^16383= 5.94866e+4931

Would you like to enter another? (Y/N) y

Enter the exponent: 16384
  2^16384= inf

Would you like to enter another? (Y/N) y

Enter the exponent: -1
  2^-1= 0.5

Would you like to enter another? (Y/N) y

Enter the exponent: -2
  2^-2= 0.25

Would you like to enter another? (Y/N) n

--------------------------------
Process exited after 89.07 seconds with return value 0
Press any key to continue . . .
*/
