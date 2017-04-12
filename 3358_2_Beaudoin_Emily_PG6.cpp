// Authors: Emily Beaudoin - 4, Alex Olsen - 30
// Due Date: 04/12/17
// Assignment Number: 6
// Spring - 2017 - CS 3358 - 2
// Instructor: Husain Gholoom
//
// This program prompts the user to enter an integer for the size of an array.
// Once an integer greater than 4 is entered, the program fills the array with
// randomly generated numbers ranging from 25-500. The filled array is then
// displayed for the user and proceeds to perform several operations involving
// the array values. The first operation finds the last number stored in the
// array and displays the square of each number beginning with 1 to the last
// number. The next operation takes the first number in the array and raises it
// to the second power and displays it to the screen. The program also sums the
// squares ranging from 0 to the second element in the array. The program finds
// the minimum and maximum number stored in the array. The program sorts and
// searches the array. The program determines whether or not each number in the
// array is prime.

// The user is able to re-run the program as desired before voluntarily exiting
// the program by entering an X.

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void populateArray(int *, int, int); //fills array with generated numbers
void displayArray(int *, int, int); //displays the filled array to the screen
void tableOfSquares(int, int); //finds the last number stored in the array and
// displays the square of each number beginning with 1 to that number
int powerFunction(int, int); //displays the value of the first number in the
// raised to the 2nd power
long long int sumOfSquares(int, int); //sums the squares ranging from 0 to the
// second element in the array
void minmaxNumber(int *, int, int &, int &); //finds the minimum and maximum
// value in the array
void bubbleSort(int *, int); //sorts the array in descending order
bool isMember(int *, int, int); //searches array for specific number
bool notMember(int *, int, int); //searches array for specific number
void isItPrime(int, int); //determines whether or not each number in the array
// is prime.

int main()
{
	int size, //takes the size of the array
		*array, //initialized array
		number, //holds the number to do operations on
		min, 
		max;
	char choice = 0; //holds user selection
	srand(time(NULL)); //enables random number generation

	cout << "Thinking Recursively\n\n"
	     << "The function of this program is to\n"
	     << "use recursion to :-\n\n"
	     << "\t1.  Display squares of integers in ascending\n"
	     << "\t    order from 1 to the last element in the array\n"
	     << "\t2.  Raise the first number to a power 2\n"
	     << "\t3.  Return the sums of squares of the numbers\n"
	     << "\t    from 0 to a fifth element in the array\n"
	     //instructions are not very clear about this either(which element)
	     << "\t4.  Search the array for the array's min and max values\n"
	     << "\t5.  Sort the array in descending order\n"
	     << "\t6.  Search the array for the first????? value in the array\n"
	      //he said third, his intro says first, and his program runs the fourth
	     << "\t7.  Search the array for the number 600\n"
	     << "\t8.  Determine if a number is prime (processes all array values)"
	     << "\n";

	while(choice != 'x' && choice != 'X') //terminates when user enters x or X
	{
		cout << "\nSelect from the following menu\n"
		     << "A.\tEnter Array Size that is > 4.\n"
		     << "x.\tTerminate The Program.     ";
		cin >> choice; //users answer

		switch(choice)
		{
			case 'A':
			case 'a': cout << "\nEnter Array Size: ";

					 while(!(cin >> size))
                      {
                            //loop to ensure correct data type
                        cout << "\n*** Invalid Array Size Value ***\n"
                             << "Enter an integer not a char: ";
                        cin.clear();
                        cin.ignore();
		              }

		              while(size < 4){
		              	if(!cin)
		              		cout << "\n*** Invalid Array Size Value ***\n"
					     << "Enter an integer not a char\n";
		              	else
                        		cout << "\n*** Invalid Array Size Value ***\n"
                             	 	     << "Enter Array Size That is > 4: ";
					cin.clear();
				        cin.ignore();
				        cin >> size;
                      }

					  array = new int [size];
					  populateArray(array, size, 0);
					  //fills array with generated numbers

					  cout << "\nThe generated array is: ";
					  displayArray(array, size, 0);
					  //displays the filled array to the screen

					  number = array[size-1];
					  cout << "\n\nTable of square values 1 - " << number << "\n"
					       << "\nN \tN Squared\n";
					  tableOfSquares(number, 1);
                      //displays the square of each number beginning with 1 to
                      // last number in array

					  number = array[0];
					  cout << "\nPower Function:\n";
					  cout << number << " raised to the 2nd power is: " //hardcoding the 2
					       << powerFunction(number,2);
					  //displays the value of the first number in the raised to
					  // the 2nd power

					  number = array[4]; //fifth number in array
					  cout << "\n\nSum of squares between 0 and " << number
					       << " is: " << sumOfSquares(number, 0);
					  //sums the squares ranging from 0 to the second element
					  // in the array

					  min = array[0]; //initialized to arbitary values
					  max = array[0]; //initialized to arbitary values
					  minmaxNumber(array, size, min, max);
				          //finds minimum and maximum values in the array
					  cout << "\n\nMin Number of "; 
					  displayArray(array, size, 0);
					  cout << " is : " << min;
					  cout << "\nMax Number of ";
					  displayArray(array, size, 0);
					  cout << " is : " << max;

					  cout << "\n\nSorted array\n";
					  bubbleSort(array,size);
					  //sorts the array in descending order
					  displayArray(array, size, 0);

					  number = array[3]; //first, third, or fourth??
					  cout << "\n\nMember Functions:\n"
					       << "Does the array: ";
                      displayArray(array, size, 0);
					  cout << "have the number\n" << number << "?";
					  if(isMember(array,size,number)) //searches the array
					  	 cout << "YES\n";
					  else
					  	 cout << "NO\n";

					  cout << "Does the array: ";
					       displayArray(array, size, 0);
					  cout << "have the number\n"
					       << "600?";
					  if(!notMember(array,size,600)) //searches the array
					  	 cout << "YES\n";
					  else
					  	 cout << "NO\n";


					  cout << "\n\nIs it prime:\n";
					  for(int i = 0; i < size; i++)
					  {
					  	 cout << "The number " << array[i] << " is ";
					  	 isItPrime(array[i], array[i]-1);
					  	 //determines which array values are prime
					  	 cout << "Prime\n";
				   	  }


					  delete [] array; //prepares new array size for next pass
			case 'x':
			case 'X':  break;
			default: cout << "\n***  Invalid Option ***\n";
		}//end of switch
	}//end of while

	cout << "\n\nCreated by Emily Beaudoin and Alex Olsen\n"
	     << "April 2017\n";

	return 0;
}//end of main

// *****************************************************************************
// populateArray function: creates an array of random integers.
//
// arr - represents the array name.
// s - represents the size of the list.
// index - represents the array position values are being stored.
//******************************************************************************

void populateArray(int * arr, int s, int index)
{
	if(index >= s) //base-case
		return;

	arr[index] = rand() % 476 + 25; //assigns a value between 1 and 500 to array

	populateArray(arr, s, index + 1); //recursion
}

// *****************************************************************************
// displayArray function: displays the array to the screen.
//
// arr - represents the array name.
// s - represents the size of the list.
// index - represents the array position values are stored.
//******************************************************************************

void displayArray(int * arr, int s, int index)
{
	if(index >= s) //base case
		return;

	cout << arr[index] << " ";

	displayArray(arr, s, index + 1); //increments index to traverse the array
}

// *****************************************************************************
// tableOfSquares function: performs square operation of 1 to the last number
//
// last - represents the value of the last number in the array.
// index - represents the array position values are stored.
//******************************************************************************

void tableOfSquares(int last, int index)
{
	if(index > last)
		return;

	cout << index << "\t" << index * index << endl;
	//performs square operation of 1 to the last array number
	tableOfSquares(last, index + 1); //increments index to traverse the array
}

// *****************************************************************************
// powerFunction function: performs power operation on selected array number
//
// x - represents the value of the number used for power operation.
// power - represents the specific power the number is raised to.
// returns value of array number to the 2nd power.
//******************************************************************************

int powerFunction(int x, int power)
{
	if(power == 0) //base case 0
		return 1;
	else if (power == 1) //base case 1
		return x;
	else
		return( x * powerFunction(x, power - 1));
		//performs power operation on array number
}

// *****************************************************************************
// sumOfSquares function: performs summation of squares operation from 1 to
// selected array number.
//
// x - represents the value of the number used for square summation operation.
// index - represents the number 1, the beginning of the square summation.
// returns value of square summation.
//******************************************************************************

long long int sumOfSquares(int x, int index)
{
	if(index > x) //base case
		return 0;
	else
		return( (index * index) + sumOfSquares(x, index + 1));
		//performs square summation operation
}

// *****************************************************************************
// minmaxNumber function: searches for the minimum and maximum values stored in
// the array.
//
// arr - represents the array name.
// s - represents the size of the list.
// min - represents the minimum value found in the array.
// max - represents the maximum value found in the array.
//******************************************************************************

void minmaxNumber(int *arr, int s, int &min, int &max)
{	
	if(s < 1) //base case
		return;
	else if(arr[s-1] < min)
		min = arr[s-1]; //resets minimum value found in the array

	minmaxNumber(arr, s-1, min, max);
	//decrements the position in the array for traversal

	if(arr[s-1] > max)
		max = arr[s-1]; //resets maximum value found in the array
}

// *****************************************************************************
// bubbleSort function: sorts the array in descending order.
//
// arr - represents the array name.
// s - represents the size of the list.
//******************************************************************************

void bubbleSort(int * arr, int s)
{
	if(s == 1) //base case
		return;

	for(int i = 0; i < (s-1); i++)
		if(arr[i] < arr[i+1]) //loop finds greater than values
			swap(arr[i], arr[i + 1]); //swaps the larger numbers to the front

	bubbleSort(arr, s-1); //traverses the array
}

// *****************************************************************************
// isMember function: searches array for specific value.
//
// arr - represents the array name.
// s - represents the size of the list.
// val - represents the value being searched for.
// returns true if value found or false if otherwise.
//******************************************************************************

bool isMember(int *arr, int s, int val)
{
	if(s == 0)
		return false;
 	else if(arr[s-1] == val) //base case
 		return true;
 	else
 		return isMember(arr,s-1,val); //traverses array
}

// *****************************************************************************
// notMember function: searches array for specific value.
//
// arr - represents the array name.
// s - represents the size of the list.
// val - represents the value being searched for.
// returns true if value is not found or false if otherwise.
//******************************************************************************

bool notMember(int *arr, int s, int val)
{
	int mid = (s / 2) - 1,//mid index
	    subSize; //size of new split array
	int *subArray; //new array to hold search portion of original array
	bool notFlag; //flag found or not

	if(s < 1)
		return true; //returns true if not found
	else if(s == 1)
	{
		if(arr[0] != val) //compares last array value to number being searched
			return true; //returns true if not found
	}
	else if(arr[mid] == val) //determines middle array position
	{
		return false; //returns false if middle number is equal to search value
	}
	else if(arr[mid] < val) //determines array portion to search next
	{
		if(mid == 0) //array is empty returns true when value wasnt found
			return true;
		subSize = mid; //creates new middle position
		subArray = new int [subSize];
		for (int i = 0; i < subSize; i++) //fills new array with portion of old
		{
			subArray[i] = arr[i];
		}
		notFlag = notMember(subArray, subSize, val); //flags when value found
		delete [] subArray;
		return notFlag; //returns false when value found
	}
	else //if arr[mid] > val
	{
		subSize = s - mid - 1;
		subArray = new int [subSize];
		for(int i = 0; i < subSize; i++) //fills new array with portion of old
		{
			subArray[i] = arr[mid + 1 + i];
		}
		notFlag = notMember(subArray, subSize, val); //flags when value found
		delete [] subArray;
		return notFlag; //returns false when value found
	}

	return true;
}

// *****************************************************************************
// isItPrime function: determines if values in the array are prime or not.
//
// val - represents the number being determined if prime or not.
// div - represents the value used to divide number to determine if prime or not
//******************************************************************************

void isItPrime(int val, int div)
{
	if(div == 1) //base case
		return;
	else if(val % div == 0) //prime determination
	{
		cout << "NOT ";
	}
	else
		isItPrime(val, div - 1); //traverses divisors
}
