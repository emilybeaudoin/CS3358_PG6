#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void populateArray(int *, int, int);
void displayArray(int *, int, int);
void tableOfSquares(int, int);
int powerFunction(int, int);
long long int sumOfSquares(int, int);
//minmax
void bubbleSort(int *, int);
bool isMember(int *, int, int);
void isItPrime(int, int);

int main()
{
	int size, 
		*array, 
		number; //holds the number to do operations on
	char choice = 0;
	srand(time(NULL));

	cout << "Thinking Recursively\n\n"
	     << "The function of this program is to\n"
	     << "use recursion to :-\n\n"
	     << "\t1.  Display squares of integers in ascending\n"
	     << "\t    order from 1 to the last element in the array\n"
	     << "\t2.  Raise the first number to a power 2\n"
	     << "\t3.  Return the sums of squares of the numbers\n"
	     << "\t    from 0 to a fifth element in the array\n" //instructions are not very clear about this either(which element)
	     << "\t4.  Search the array for the array's min and max values\n"
	     << "\t5.  Sort the array in descending order\n"
	     << "\t6.  Search the array for the first????? value in the array\n" //he said third, his intro says first, and his program runs the fourth
	     << "\t7.  Search the array for the number 600\n"
	     << "\t8.  Determine if a number is prime (processes all array values)\n";

	while(choice != 'x' && choice != 'X')
	{
		cout << "\nSelect from the following menu\n"
		     << "A.\tEnter Array Size that is > 4.\n"
		     << "x.\tTerminate The Program.     ";
		cin >> choice;
	
		switch(choice)
		{
			case 'A':
			case 'a': cout << "Enter Array Size: ";
					  cin >> size; //make loop to trap for incorrect sizes

					  array = new int [size];
					  populateArray(array, size, 0);

					  cout << "\nThe generated array is: ";
					  displayArray(array, size, 0);

					  number = array[size-1];
					  cout << "Table of square values 1 - " << number << "\n"
					       << "\nN \tN Squared\n";
					  tableOfSquares(number, 1);

					  number = array[0];
					  cout << "\nPower Function:\n";
					  cout << number << " raised to the 2nd power is: " //hardcoding the 2
					       << powerFunction(number,2); 

					  number = array[4]; //fifth number in array
					  cout << "\n\nSum of squares between 0 and " << number
					       << " is: " << sumOfSquares(number, 0);

					  //minmax call
					  cout << "\n\nSorted array\n";
					  bubbleSort(array,size);
					  displayArray(array, size, 0);

					  number = array[3]; //first, third, or fourth??
					  cout << "\n\nMember Functions:\n"
					       << "Does the array: "; 
					       displayArray(array, size, 0);
					  cout << "have the number " << number << "?\n";
					  if(isMember(array,size,number))
					  	 cout << "YES\n";
					  else 
					  	 cout << "NO\n";
					  //not member
					  
					  cout << "\n\nIs it prime:\n";
					  for(int i = 0; i < size; i++)
					  {
					  	 cout << "The number " << array[i] << " is ";
					  	 isItPrime(array[i], array[i]-1);
					  	 cout << " prime\n";
				   	  }


					  delete [] array; //so an array of a different size can be allocated on the next pass
			case 'x':
			case 'X':  break;
			default: cout << "\n***  Invalid Option ***\n";
		}//end of switch
	}//end of while

	cout << "\n\nCreated by Emily Beaudoin and Alex Olsen\n"
	     << "April 2017\n";

	return 0;
}//end of main

void populateArray(int * arr, int s, int index)
{
	if(index >= s) //base-case
		return;

	arr[index] = rand() % 476 + 25; //assigns a value between 1 and 500 to array

	populateArray(arr, s, index + 1); //recursion
}

void displayArray(int * arr, int s, int index)
{
	if(index >= s) //base case
		return;

	cout << arr[index] << " ";

	displayArray(arr, s, index + 1);
}

void tableOfSquares(int last, int index)
{
	if(index > last)
		return;

	cout << index << "\t" << index * index << endl;
	tableOfSquares(last, index + 1);
}

int powerFunction(int x, int power)
{
	if(power == 0) //base case 0
		return 1;
	else if (power == 1) //base case 1
		return x;
	else
		return( x * powerFunction(x, power - 1));
}

long long int sumOfSquares(int x, int index)
{	
	if(index > x) //base case
		return 0;
	else
		return( (index * index) + sumOfSquares(x, index + 1));
}

// void minmaxNumber(int *arr, int s, int &min, int &max)
// {	
// 	int min;
// 	if(size >= 1)
// 	{
// 		if(arr[size] < minmaxNumber(arr, size - 1))
// 			return arr[size];
// 		else
// 			return;
// 	}
// 	else


// }

void bubbleSort(int * arr, int s)
{
	if(s == 1) //base case
		return;

	for(int i = 0; i < (s-1); i++)
		if(arr[i] < arr[i+1])
			swap(arr[i], arr[i + 1]);

	bubbleSort(arr, s-1);
}

bool isMember(int *arr, int s, int val) //maybe void? all his functions appear to just output yes/no/whatever
{
	if(s == 0)
		return false;
 	else if(arr[s-1] == val) //base case
 		return true;
 	else 
 		return isMember(arr,s-1,val);
}

bool notMember(int *arr, int s, int val)
{
	int mid = s / 2;

	if(s == 0)
		return false;

}

void isItPrime(int val, int div)
{
	if(div == 1)
		return;
	else if(val % div == 0)
	{
		cout << "NOT";
	}
	else
		isItPrime(val, div - 1);
}


