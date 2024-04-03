#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define TAB "\t"

void 

int* push_back(int* array, int& n, int value);
int* push_front(int* array, int&, int value);
int* insert(int* array, int& n, int value, int index);
int* pop_back(int* array, int& n);

int main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n;
	cout << "n = "; cin >> n;
	int *arr = new int[n];
	int value;
	cout << "value = "; cin >> value;

	FillRand(arr, n);
	cout << "вывод массива = ";  Print(arr, n);

	cout << "value = "; cin >> value;
	arr = push_back(arr, n, value);
	cout << "вывод изменённого массива2 = "; Print(arr, n);

	arr = pop_back(arr, n);
	cout << "вывод изменённого массива3 = "; Print(arr, n);
#endif	


	int rows, cols; 
	cout << "rows = ";  cin >> rows;
	cout << "cols = ";  cin >> cols;
	int** array = new int* [rows] ;
	for (int i = 0; i < rows; i++) array[i] = new int[cols] {};
	
	Print(array, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[i] array[i];
	}

	delete[] array;


}

void FillRand(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int* arr, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << TAB;
	}
	cout << endl;
}

void Print(int** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << TAB;
		}
		cout << endl;
	}
}

	int n;
	int value, index = 4;

	cout << "строчек в массиве: "; cin >> n;
	cout << endl;

	int* array = new int[n];

	FillRand(array, n);
	cout << "вывод массива: "; Print(array, n);
	cout << endl;

	cout << "value в массиве: "; cin >> value;
	
	array = push_back(array, n, value);
	Print(array, n); 
	cout << endl;

	cout << "value в массиве: "; cin >> value;
	array = push_front(array, n, value);
	Print(array, n);
	cout << endl;
	cout << endl;

	array = insert(array, n, value, index);
	Print(array, n);
	cout << endl;
	
	array = pop_back(array, n);
	Print(array, n); 
	cout << endl;
	cout << endl;

	
}

void FillRand(int* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i] = rand() % 100;
}

void Print(int* array, int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << TAB;
}

int* push_back(int* array, int& n, int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	delete[] array;

	array = buffer;
	array[n] = value;
	n++ ;
	return array;
}

int* push_front(int* array, int& n, int value)
{
	int* buffer = new int[n + 1];
	
	for (int i = 0; i < n; i++)
		buffer[i + 1] = array[i];

	delete[] array;

	buffer[0] = value;
	n++;

	return buffer;
}

int* insert(int* array, int& n, int value, int index)
{
	int* buffer = new int[n];
	
	for (int i = 0; i < n; i++) 
		buffer[i] = array[i];

	delete[] array;

	buffer[index] = value;
	
	return buffer;
}

int* pop_back(int* array, int& n)
{
	int* buffer = new int[--n];
	
	for (int i = 0; i < n; i++)
		buffer[i] = array[i];
	
	delete[] array;
	return buffer;
}
