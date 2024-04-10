#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void fillRand(int** arra, int rows, int cols);
void print(int** arra, int rows, int cols);

int** allocate(int rows, int cols);
void clear(int** arra, int rows);
int** push_row_back(int** arra, int& rows, int cols);
int** push_row_front(int** arra, int& rows, int cols);
int** insert_row(int** arra, int& rows, int cols, int index);
int** pop_row_back(int** arra, int& rows, int cols);
int** pop_row_front(int** arra, int& rows, int cols);
int** erase_row(int** arra, int& rows, int cols, int index);
void push_col_back(int** arra, int rows, int& cols);
void push_col_front(int** arra, int rows, int& cols);
void insert_col(int** arra, int rows, int& cols, int index);
void pop_col_back(int** arra, int rows, int& cols);
void pop_col_front(int** arra, int rows, int& cols);
void erase_col(int** arra, int rows, int& cols, int index);
//--------------
void FillRand(int* array, int& n);
void Print(int* array, int& n);

int* push_back(int* array, int& n, int value);
int* push_front(int* array, int&, int value);
int* insert(int* array, int& n, int value, int index);
int* pop_back(int* array, int& n);
int* pop_front(int* array, int& n);
int* erase(int* array, int& n, int index);

//#define DYNAMIC_MEMORY_1 
#define DYNAMIC_MEMORY_2 

int main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
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
	
#endif // DYNAMIC_MEMORY_1 

#ifdef DYNAMIC_MEMORY_2

	int rows, cols; // rows - строка, cols - столбец
	int index;
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во столбцов эелементов строки: "; cin >> cols;
	
	int** arra = allocate(rows, cols);

	allocate(rows, cols);
	
	fillRand(arra, rows, cols);
	cout << "исходный массив: " << endl;
	print(arra, rows, cols);

	arra = push_row_back(arra, rows, cols);
	cout << "push_row_back: " << endl;
	print(arra, rows, cols);
	
	arra = push_row_front(arra, rows, cols);
	cout << "push_row_front: " << endl;
	print(arra, rows, cols);
	
	cout << "insert_row:" << endl;
	cout << "индекс вставки строчки: "; cin >> index;
	arra = insert_row(arra, rows, cols, index);
	print(arra, rows, cols);
	
	arra = pop_row_back(arra, rows, cols);
	cout << "pop_row_back: " << endl;
	print(arra ,rows, cols);

	arra = pop_row_front(arra, rows, cols);
	cout << "pop_row_front: " << endl;
	print(arra, rows, cols);
	
	cout << "удалить строчку: "; cin >> index;
	cout << "erase_row: " << endl;
	arra = erase_row(arra, rows, cols, index);
	print(arra, rows, cols);

	push_col_back(arra, rows, cols);
	cout << "push_col_back: " << endl;
	print(arra, rows, cols);
	
	push_col_front(arra, rows, cols);
	cout << "push_col_back: " << endl;
	print(arra, rows, cols);
	
	cout << "индекс вставки столбца: "; cin >> index;
	cout << "insert_col: " << endl;
	insert_col(arra, rows, cols, index);
	print(arra, rows, cols);

	pop_col_back(arra, rows, cols);
	cout << "pop_col_back: " << endl;
	print(arra, rows, cols);

	pop_col_front(arra, rows, cols);
	cout << "pop_col_front: " << endl;
	print(arra, rows, cols);

	cout << "удалить столбец: "; cin >> index;
	cout << "erase_col: " << endl;
	erase_col(arra, rows, cols, index);
	print(arra, rows, cols);

	clear(arra, rows);

#endif // DYNAMIC_MEMORY_2
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

//-------------------------------------------------------------

int** allocate(int rows, int cols)
{ // выделение памяти под массив
	int** arra = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		arra[i] = new int[cols] {};
	}

	return arra;
}

void fillRand(int** arra, int rows, int cols)
{ // заполнение массива рандом числами
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arra[i][j] = rand() % 100;
		}
	}
}

void print(int** arra, int rows, int cols)
{ // вывод 2D массива в консоль 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arra[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

void clear(int** arra, int rows)
{ // удаляем сначало строчки а потом массив указателей
	for (int i = 0; i < rows; i++)
	{
		delete[] arra[i];
	}
	delete[] arra;

}

int** push_row_back(int** arra, int& rows, int cols)
{ // добовление сточки в начало
	int** buffer = new int* [rows + 1]; // создание 2D массива
	for (int i = 0; i < rows; i++) buffer[i] = arra[i]; // копиррование значени исходного массива в буфер

	delete[] arra;
	buffer[rows] = new int[cols] {}; // добавление строчки в конец
	rows++;

	return buffer;
}

int** push_row_front(int** arra, int& rows, int cols)
{ // добавление строчки в начало
	int** buffer = new int* [rows + 1]; // создание 2D массива
	for (int i = 0; i < rows; i++) buffer[i + 1] = arra[i]; // перенос значение исход массива в буфер со сдвигом на 1+ элемент впрово
	
	delete[] arra;
	buffer[0] = new int[cols] {}; // в нулевом элементе создаётся пустая строчка 
	rows++;

	return buffer;
}

int** insert_row(int** arra, int& rows, int cols, int index)
{ // добавление строчки по индексу
	int** buffer = new int* [rows + 1]; 

	for (int i = 0; i < rows; i++) 
	{
		if (i < index - 1) // пока i меньше значения index всё копируется нормально
		{		// index - 1 так как массив считается от 0 до n++ 
			buffer[i] = arra[i];
		} 
		else // нужен для того чтоб в нужном месте создать пустую строчку 
		{
			buffer[index - 1] = new int[cols] {};
		}
		buffer[i + 1] = arra[i]; // продолжение но со сдвигом на 1+ элемент впрово
	}

	delete[] arra;
	rows++;

	return buffer;
}

int** pop_row_back(int** arra, int& rows, int cols)
{ // стирание последней строчки массива 
	int** buffer = new int* [--rows]; // записуем в меньший массив
	for (int i = 0; i < rows; i++) buffer[i] = arra[i]; 

	delete[] arra;

	return buffer;
}

int** pop_row_front(int** arra, int& rows, int cols)		
{ // стирание нулевой строчки
	int** buffer = new int* [rows + 1]; 
	for (int i = 0; i < rows; i++) buffer[i] = arra[i];

	for (int i = 0; i < rows; i++) buffer[i] = buffer[i + 1];
	
	delete[] arra;
	rows--;

	return buffer;
}

int** erase_row(int** arra, int& rows, int cols, int index)
{ // стирание по индексу
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
		buffer[i] = arra[i]; // копируем полностью массив

	for (int i = index - 1; i < rows; i++) // переписуем нужную строчку на элемет справа а потом уменьшаем на 1 массив
		buffer[i] = buffer[i +  1];

	delete[] arra;
	rows--;

	return buffer;
}

void push_col_back(int** arra, int rows, int& cols)
{ //добавление столбца в конец
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {}; // с каждой новой итерацией i создаётся буффер
		for (int j = 0; j < cols; j++) buffer[j] = arra[i][j];
		delete[] arra[i];
		arra[i] = buffer;
	}
	cols++;
}

void push_col_front(int** arra, int rows, int& cols)
{ // добавление столбца в начало
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {}; // с каждой новой итерацией i создаётся буффер
		for (int j = 0; j < cols; j++) buffer[j + 1] = arra[i][j]; // записуем в буфеер значение со сдвигом на 1+ вправо чтоб первым элементом был ноль
		delete[] arra[i];
		arra[i] = buffer;
	}
	cols++;
}

void insert_col(int** arra, int rows, int& cols, int index)
{ // добавление столбца по индексу
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) 
		{
			if (j < index - 1) // пока j меньше index в буффер записуется значение по порядку
			{
				buffer[j] = arra[i][j];
			}
			else // создаём пустой элемент 
			{
				buffer[index - 1] = {};
			}
			buffer[j + 1] = arra[i][j];  // продолжаем записывать но уже со сдвигом вправо на 1+
			
		}

		delete[] arra[i];
		arra[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arra, int rows, int& cols)
{ // удаление столбца в конце 
	// нечего нового 
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arra[i][j];
		delete[] arra[i];
		arra[i] = buffer;
	}
}

void pop_col_front(int** arra, int rows, int& cols)
{ // удаление столбца
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arra[i][j + 1];
		}
		delete[] arra[i];
		arra[i] = buffer;
	}
}

void erase_col(int** arra, int rows, int& cols, int index)
{ // удаление столбца по индексу
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arra[i][j];
		}

		for (int j = index - 1; j < cols; j++) // переписываем нужный индекс на элемент справа
		{
			buffer[j] = buffer[j + 1];
		}
		delete[] arra[i];
		arra[i] = buffer;
	}
	cols--; // уменьшаем массив чтоб стереть лишнее
}

