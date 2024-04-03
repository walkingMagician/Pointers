#include<iostream>
using namespace std;

#define TAB "\t"

void FillRand(int *arr, int n);
void Print(int *arr, int n);
int* push_back(int *arr, int& n, int value);
int* push_front(int* arr, int& n, int value);

int* pop_back(int* arr, int& n);

#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void Print(int** array, int rows, int cols);


int main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	/*int n;
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
	cout << "вывод изменённого массива3 = "; Print(arr, n);*/

	int rows, cols; 
	cout << "rows = ";  cin >> rows;
	cout << "cols = ";  cin >> cols;
	int** array = new int* [rows] ;
	for (int i = 0; i < rows; i++) array[i] = new int[cols] {};
	
	Print(array, rows, cols);


#endif

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

int* push_back(int *arr, int& n, int value)
{
	int *buffer = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	arr[n] = value;

	n++;

	return arr;
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
		{
			buffer[i + 1] = arr[i];
		}

	delete[] arr;

	buffer[0] = value;
	return buffer;
}

int* pop_back(int* arr, int& n)
{
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;*/

	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
