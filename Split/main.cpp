#include <iostream>
using namespace std;

#define TAB "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Print_even(int *even_arr, int even_count);
void Print_odd(int *odd_arr, int odd_count);


int main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;
	// вычисляем кол-во элиментов массива 
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
	}
	cout << "кол-во четных элиментов: " << even_count << endl;
	cout << "кол-во нечетных элиментов: " << odd_count << endl;

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	// распределение значений
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			even_arr[j++] = arr[i];
		else
			odd_arr[k++] = arr[i];
	}
	// вывод массивов
	cout << "Even arr: "; Print_even(even_arr, even_count);
	cout << "Odd arr: "; Print_odd(odd_arr, odd_count);
	
	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << TAB;
	}
	cout << endl;
}

void Print_even(int* odd_arr, int odd_count)
{
	for(int i = 0; i < odd_count; i++)
	{
		cout << odd_arr[i] << TAB;
	}
	cout << endl;
}

void Print_odd(int *even_arr, int even_count)
{

	for (int i = 0; i < even_count; i++)
	{
		cout << even_arr[i] << TAB;
	}
	cout << endl;
}


