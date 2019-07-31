#include<iostream>
using namespace std;


//Recursive Version
long double Power_of_two(int  k)
{
	if(k == 0)
		return 1; 
	else
		return 2* Power_of_two(k-1);
}

//main()
//{
//	int k;
//	cout << "Please input a natural number: " ;
//	cin >> k;
//	cout <<"\n Two to the " << k << " recursive is : "  << Power_of_two(k);
//}
