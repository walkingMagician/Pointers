#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define TAB "\t"

void FillRand(int* array, int& n);
void Print(int* array, int& n);

int* push_back(int* array, int& n, int value);
int* push_front(int* array, int&, int value);
int* insert(int* array, int& n, int value, int index);
int* pop_back(int* array, int& n);

int main()
{
	setlocale(LC_ALL, "");

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
	{
		array[i] = rand() % 100;
	}
}

void Print(int* array, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << TAB;
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
