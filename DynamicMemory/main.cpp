#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template <typename T> void fillRand(T** arra, T rows, T cols);
template <typename T> void print(T** arra, T rows, T cols);

template <typename T> T** allocate(T rows, T cols);
template <typename T> void clear(T** arra, T rows);
template <typename T> T** push_row_back(T** arra, T& rows, T cols);
template <typename T> T** push_row_front(T** arra, T& rows, T cols);
template <typename T> T** insert_row(T** arra, T& rows, T cols, T index);
template <typename T> T** pop_row_back(T** arra, T& rows, T cols);
template <typename T> T** pop_row_front(T** arra, T& rows, T cols);
template <typename T> T** erase_row(T** arra, T& rows, T cols, T index);
template <typename T> void push_col_back(T** arra, T rows, T& cols);
template <typename T> void push_col_front(T** arra, T rows, T& cols);
template <typename T> void insert_col(T** arra, T rows, T& cols, T index);
template <typename T> void pop_col_back(T** arra, T rows, T& cols);
template <typename T> void pop_col_front(T** arra, T rows, T& cols);
template <typename T> void erase_col(T** arra, T rows, T& cols, T index);
//--------------
template <typename T> void FillRand(T* array, T& n);
template <typename T> void Print(T* array, T& n);

template <typename T> T* push_back(T* array, T& n, T value);
template <typename T> T* push_front(T* array, T&, T value);
template <typename T> T* insert(T* array, T& n, T value, T index);
template <typename T> T* pop_back(T* array, T& n);
template <typename T> T* pop_front(T* array, T& n);
template <typename T> T* erase(T* array, T& n, T index);

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
	
	//int** arra = allocate(rows, cols);
	
	int** arra = allocate(rows, cols);
	
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

template <typename T>
void FillRand(T* array, T& n)
{
	for (int i = 0; i < n; i++)
		array[i] = rand() % 100;
}

template <typename T>
void Print(T* array, T& n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << tab;
}

template <typename T>
T* push_back(T* array, T& n, T value)
{
	T* buffer = new T[n + 1];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	delete[] array;

	array = buffer;
	array[n] = value;
	n++;
	return array;
}

template <typename T>
int* push_front(T* array, T& n, T value)
{
	T* buffer = new T[n + 1];

	for (int i = 0; i < n; i++)
		buffer[i + 1] = array[i];

	delete[] array;

	buffer[0] = value;
	n++;

	return buffer;
}

template <typename T>
T* insert(T* array, T& n, T value, T index)
{
	T* buffer = new T[n];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	delete[] array;

	buffer[index] = value;

	return buffer;
}

template <typename T>
T* pop_back(T* array, T& n)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	delete[] array;
	return buffer;
}

template <typename T>
T* pop_front(T* array, T& n)
{
	T* buffer = new T[n + 1];

	for (int i = 0; i < n; i++)
		buffer[i] = array[i];

	for (int i = 0; i < n; i++)
		buffer[i] = buffer[i + 1];

	delete[] array;
	n--;
	return buffer;
}

template <typename T>
T* erase(T* array, T& n, T index)
{
	T* buffer = new T[n + 1];
	
	for (int i = 0; i < n; i++)
		buffer[i] = array[i];
	
	
	for (int i = index - 1; i < n; i++)
		buffer[i] = buffer[i + 1];

	delete[] array;
	n--;
	
	return buffer;

}

//-------------------------------------------------------------
template <typename T>
T** allocate(T rows, T cols)
{ // выделение памяти под массив
	T** arra = new T* [rows];
	for (int i = 0; i < rows; i++) 
	{
		arra[i] = new T[cols] {};
	}

	return arra;
}

template <typename T>
void fillRand(T** arra, T rows, T cols)
{ // заполнение массива рандом числами
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arra[i][j] = rand() % 100;
		}
	}
}

template <typename T>
void print(T** arra, T rows, T cols)
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

template <typename T>
void clear(T** arra, T rows)
{ // удаляем сначало строчки а потом массив указателей
	for (int i = 0; i < rows; i++)
	{
		delete[] arra[i];
	}
	delete[] arra;

}

template <typename T>
T** push_row_back(T** arra, T& rows, T cols)
{ // добовление сточки в начало
	T** buffer = new T* [rows + 1]; // создание 2D массива
	for (int i = 0; i < rows; i++) buffer[i] = arra[i]; // копиррование значени исходного массива в буфер

	delete[] arra;
	buffer[rows] = new T[cols] {}; // добавление строчки в конец
	rows++;

	return buffer;
}

template <typename T>
T** push_row_front(T** arra, T& rows, T cols)
{ // добавление строчки в начало
	T** buffer = new T* [rows + 1]; // создание 2D массива
	for (int i = 0; i < rows; i++) buffer[i + 1] = arra[i]; // перенос значение исход массива в буфер со сдвигом на 1+ элемент впрово
	
	delete[] arra;
	buffer[0] = new T[cols] {}; // в нулевом элементе создаётся пустая строчка 
	rows++;

	return buffer;
}

template <typename T>
T** insert_row(T** arra, T& rows, T cols, T index)
{ // добавление строчки по индексу
	T** buffer = new T* [rows + 1]; 

	for (int i = 0; i < rows; i++) 
	{
		if (i < index - 1) // пока i меньше значения index всё копируется нормально
		{		// index - 1 так как массив считается от 0 до n++ 
			buffer[i] = arra[i];
		} 
		else // нужен для того чтоб в нужном месте создать пустую строчку 
		{
			buffer[index - 1] = new T[cols] {};
		}
		buffer[i + 1] = arra[i]; // продолжение но со сдвигом на 1+ элемент впрово
	}

	delete[] arra;
	rows++;

	return buffer;
}

template <typename T>
T** pop_row_back(T** arra, T& rows, T cols)
{ // стирание последней строчки массива 
	T** buffer = new T* [--rows]; // записуем в меньший массив
	for (int i = 0; i < rows; i++) buffer[i] = arra[i]; 

	delete[] arra;

	return buffer;
}

template <typename T>
T** pop_row_front(T** arra, T& rows, T cols)		
{ // стирание нулевой строчки
	T** buffer = new T* [rows + 1]; 
	for (int i = 0; i < rows; i++) buffer[i] = arra[i];

	for (int i = 0; i < rows; i++) buffer[i] = buffer[i + 1];
	
	delete[] arra;
	rows--;

	return buffer;
}

template <typename T>
T** erase_row(T** arra, T& rows, T cols, T index)
{ // стирание по индексу
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
		buffer[i] = arra[i]; // копируем полностью массив

	for (int i = index - 1; i < rows; i++) // переписуем нужную строчку на элемет справа а потом уменьшаем на 1 массив
		buffer[i] = buffer[i +  1];

	delete[] arra;
	rows--;

	return buffer;
}

template <typename T>
void push_col_back(T** arra, T rows, T& cols)
{ //добавление столбца в конец
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {}; // с каждой новой итерацией i создаётся буффер
		for (int j = 0; j < cols; j++) buffer[j] = arra[i][j];
		delete[] arra[i];
		arra[i] = buffer;
	}
	cols++;
}

template <typename T>
void push_col_front(T** arra, T rows, T& cols)
{ // добавление столбца в начало
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {}; // с каждой новой итерацией i создаётся буффер
		for (int j = 0; j < cols; j++) buffer[j + 1] = arra[i][j]; // записуем в буфеер значение со сдвигом на 1+ вправо чтоб первым элементом был ноль
		delete[] arra[i];
		arra[i] = buffer;
	}
	cols++;
}

template <typename T>
void insert_col(T** arra, T rows, T& cols, T index)
{ // добавление столбца по индексу
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
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

template <typename T>
void pop_col_back(T** arra, T rows, T& cols)
{ // удаление столбца в конце 
	// нечего нового 
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arra[i][j];
		delete[] arra[i];
		arra[i] = buffer;
	}
}

template <typename T>
void pop_col_front(T** arra, T rows, T& cols)
{ // удаление столбца
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arra[i][j + 1];
		}
		delete[] arra[i];
		arra[i] = buffer;
	}
}

template <typename T>
void erase_col(T** arra, T rows, T& cols, T index)
{ // удаление столбца по индексу
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
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

