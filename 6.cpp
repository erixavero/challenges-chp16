#include<iostream>

using namespace std;

class IntArray{
private:
	int *aptr; // Pointer to the array
	int arraySize; // Holds the array size
	void subscriptError(); // Handles invalid subscripts
public:
	IntArray(int); // Constructor
	IntArray(const IntArray &); // Copy constructor
	~IntArray(); // Destructor
	
	class InvalidSub{};

	int size() const // Returns the array size
	{ return arraySize;}

	int &operator[](const int &); // Overloaded [] operator
};

IntArray::IntArray(int s)
{
	arraySize = s;
	aptr = new int [s];
	for (int count = 0; count < arraySize; count++)
	*(aptr + count) = 0;
}

//******************************************************
// Copy Constructor for IntArray class. *
//******************************************************

IntArray::IntArray(const IntArray &obj)
{
	arraySize = obj.arraySize;
	aptr = new int [arraySize];
	for(int count = 0; count < arraySize; count++)
	*(aptr + count) = *(obj.aptr + count);
}

//******************************************************
// Destructor for IntArray class. *
//******************************************************

IntArray::~IntArray()
{
	if (arraySize > 0)
	delete [] aptr;
}

//************************************************************
// subscriptError function. Displays an error message and *
// terminates the program when a subscript is out of range. *
//************************************************************

void IntArray::subscriptError()
{
	throw InvalidSub();
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element *
// in the array indexed by the subscript. *
//*******************************************************

int &IntArray::operator[](const int &sub)
{
	if (sub < 0 || sub >= arraySize)
	subscriptError();
	return aptr[sub];
}

int main(){
	
	const int SIZE = 10; // Array size
try{
	// Define an IntArray with 10 elements.
	IntArray table(SIZE);

	// Store values in the array.
	for (int x = 0; x < SIZE; x++)
	table[x] = (x * 2);

	// Display the values in the array.
	for (int x = 0; x < SIZE; x++)
	cout << table[x] << " ";
	cout << endl;

	// Use the standard + operator on array elements.
	for (int x = 0; x < SIZE; x++)
	table[x] = table[x] + 5;

	// Display the values in the array.
	for (int x = 0; x < SIZE; x++)
	cout << table[x] << " ";
	cout << endl;

	// Use the standard ++ operator on array elements.
	for (int x = 0; x < SIZE; x++)
	table[x]++;

	// Display the values in the array.
	for (int x = 0; x < SIZE; x++)
	cout << table[x] << " ";
	cout << endl;
}
	catch (IntArray::InvalidSub){
		cout<<"INVALID SUB";
	}
	
	return 0;
}
