#include <iostream>

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
int* pop_front(int* array, int& n);
int* erase(int* array, int& n, int index);


int main()
{
	setlocale(LC_ALL, "");

	int n;
	int value, index;

	cout << "строчек в массиве: "; cin >> n;
	cout << endl;

	int* array = new int[n];

	FillRand(array, n);
	cout << "вывод массива: "; Print(array, n);
	cout << endl << endl;

	cout << "число которое хотите видеть в конце массива: "; cin >> value;
	array = push_back(array, n, value);
	cout << "вывод массива: ";
	Print(array, n);
	cout << endl << endl;

	cout << "число которое хотите видеть вначале массива: "; cin >> value;
	array = push_front(array, n, value);
	cout << "вывод массива: ";
	Print(array, n);
	cout << endl << endl;

	cout << "ваше число которое желаете вставить: "; cin >> value;
	cout << "на какой позии желаете его видеть от 0 до " << n - 1 << ": "; cin >> index;
	array = insert(array, n, value, index);
	cout << "вывод массива: ";
	Print(array, n);
	cout << endl << endl;

	cout << "вывод массива с удалённым последним элементом: ";
	array = pop_back(array, n);
	Print(array, n);
	cout << endl << endl;

	cout << "вывод массива с удалённым первым элементом: ";
	array = pop_front(array, n);
	Print(array, n);
	cout << endl << endl;
	
	cout << "на какой позиции удалить эемент массива: "; cin >> index;
	array = erase(array, n, index);
	Print(array, n);
	cout << endl << endl;
	

}

void FillRand(int* array, int& n)
{
	for (int i = 0; i < n; i++)
		array[i] = rand() % 100;
}

void Print(int* array, int& n)
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

int** allocate(const int rows, const int cols)
{ // РІС‹РґРµР»РµРЅРёРµ РїР°РјСЏС‚Рё РїРѕРґ РјР°СЃСЃРёРІ
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		arr[i] = new int[cols] {};
	}

	return arr;
}

void clear(int** arr, const int rows)
{ // СѓРґР°Р»СЏРµРј СЃРЅР°С‡Р°Р»Рѕ СЃС‚СЂРѕС‡РєРё Р° РїРѕС‚РѕРј РјР°СЃСЃРёРІ СѓРєР°Р·Р°С‚РµР»РµР№
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}


