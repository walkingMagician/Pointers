#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** allocate(int rows, int cols);
void clear(int** arra, int rows);

void print(int** arra, int rows, int cols);

void FillRand(int* array, int& n);
void Print(int* array, int& n);

int* push_back(int* array, int& n, int value);
int* push_front(int* array, int&, int value);
int* insert(int* array, int& n, int value, int index);
int* pop_back(int* array, int& n);
int* pop_front(int* array, int& n);
int* erase(int* array, int& n, int index);

//#define DYNAMIC_MEMORY_1 
//#define DYNAMIC_MEMORY_2 


int main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	int value, index;

	cout << "������� � �������: "; cin >> n;
	cout << endl;

	int* array = new int[n];

	FillRand(array, n);
	cout << "����� �������: "; Print(array, n);
	cout << endl << endl;

	cout << "����� ������� ������ ������ � ����� �������: "; cin >> value;
	array = push_back(array, n, value);
	cout << "����� �������: ";
	Print(array, n);
	cout << endl << endl;

	cout << "����� ������� ������ ������ ������� �������: "; cin >> value;
	array = push_front(array, n, value);
	cout << "����� �������: ";
	Print(array, n);
	cout << endl << endl;

	cout << "���� ����� ������� ������� ��������: "; cin >> value;
	cout << "�� ����� ����� ������� ��� ������ �� 0 �� " << n - 1 << ": "; cin >> index;
	array = insert(array, n, value, index);
	cout << "����� �������: ";
	Print(array, n);
	cout << endl << endl;

	cout << "����� ������� � �������� ��������� ���������: ";
	array = pop_back(array, n);
	Print(array, n);
	cout << endl << endl;

	cout << "����� ������� � �������� ������ ���������: ";
	array = pop_front(array, n);
	Print(array, n);
	cout << endl << endl;
	
	cout << "�� ����� ������� ������� ������ �������: "; cin >> index;
	array = erase(array, n, index);
	Print(array, n);
	cout << endl << endl;
	
#endif



	int rows;
	int cols;
	cout << "������� ���-�� �����: "; cin >> rows;
	cout << "������� ���-�� �������� ���������� ������: "; cin >> cols;
	
	int** arra = allocate(rows, cols);

	allocate(rows, cols);
	
	print(arra, rows, cols);
	
	clear(arra, rows);


}

void FillRand(int* array, int& n)
{
	for (int i = 0; i < n; i++)
		array[i] = rand() % 100;
}

void Print(int* array, int& n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << tab;
}

int* push_back(int* array, int& n, int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	delete[] array;

	array = buffer;
	array[n] = value;
	n++;
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


int* pop_front(int* array, int& n)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	for (int i = 0; i < n; i++)
		buffer[i] = buffer[i + 1];

	delete[] array;
	n--;
	return buffer;
}

int* erase(int* array, int& n, int index)
{
	int* buffer = new int[n + 1];
	
	for (int i = 0; i < n; i++)
		buffer[i] = array[i];
	
	
	for (int i = index - 1; i < n; i++)
		buffer[i] = buffer[i + 1];

	delete[] array;
	n--;
	
	return buffer;

}

int** allocate(int rows, int cols)
{ // ��������� ������ ��� ������
	int** arra = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		arra[i] = new int[cols] {};
	}

	return arra;
}

void print(int** arra, int rows, int cols)
{ // ����� 2D ������� � ������� 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arra[i][j] << tab;
		}
		cout << endl;
	}
}

void clear(int** arra, int rows)
{ // ������� ������� ������� � ����� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		delete[] arra[i];
	}
	delete[] arra;

}


