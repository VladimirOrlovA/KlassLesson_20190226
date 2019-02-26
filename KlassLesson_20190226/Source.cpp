#include<iostream>
#include<time.h>
#include<locale.h>

using namespace std;


// расширение массива

void fillArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] =-1 + rand() % 3;
}

void printArray(const int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
}

void allocateArray(int *&arr, int n)
{
	arr = new int[n];
}


void addElementArray(int *&arr, int &n)
{
	int *tmp = new int[n + 1];

	// копируем массив

	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}

	// добавляем в расширенный массив элемент

	tmp[n] = 50;

	cout << endl;

	delete[] arr;
	arr = tmp;
	n++;
}


////////////// расширение массива на 2 элемента на начало и на конец  //////////////

void addStEndElementArray(int *&arr, int &n)
{
	int *tmp = new int[n + 2];

	// копируем массив

	for (int i = 0; i < n; i++)
	{
		tmp[i+1] = arr[i];
	}

	// добавляем в расширенный массив элемент

	tmp[0] = 50;
	tmp[n+1] = 50;

	cout << endl;

	delete[] arr;
	arr = tmp;
	n+=2;
}

/*
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int *arr;
	int n;

	cout << "Enter size of array -> ";
	cin >> n;
	cout << endl;
	arr = new int[n];

	allocateArray(arr, n);
	fillArray(arr, n);
	printArray(arr, n);
	addElementArray(arr, n);
	printArray(arr, n);

	allocateArray(arr, n);
	fillArray(arr, n);
	printArray(arr, n);
	addStEndElementArray(arr, n);
	printArray(arr, n);
	
	system("pause");

	return 0;
}
*/



//33.	**Написать функцию, которая принимает указатель на массив и количество элементов.Функция сжимает массив, удаляя из него элементы равные 0. 
//Возвращает указатель на новый массив, не содержащий 0.

/*
int* remove0(int*arr, int n, int &newSize)
{
	int *tmp, k = 0;

	for (int i = 0; i < n; i++)
		if (arr[i] != 0) k++;

	tmp = new int[k];
	k = 0;

	for (int i = 0; i < n; i++)
		if (arr[i] != 0)
			tmp[k++] = arr[i];

	newSize = k;
	return tmp;
}


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int *arr, *b;
	int n, m;

	cout << "Enter size of array -> ";
	cin >> n;
	cout << endl;
	
	allocateArray(arr, n);
	fillArray(arr, n);
	printArray(arr, n);
	b = remove0(arr, n, m);
	printArray(arr, m);
	printArray(arr, n);

	system("pause");
	return 0;
}
*/




//48.	**Написать функцию, которая принимает указатель на массив, количество элементов массива и новый элемент и выполняет вставку нового элемента
//после первого отрицательного элемента в массиве. Если такого элемента в массиве нет, то вставляет в начало массива.


int* addNewElem(int*arr, int &n, int elem)
{
	int *tmp, pos = -1;

	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
		{
			pos = i;
			break;
		}

	n++;
	tmp = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		if (i <=pos)
			tmp[i] = arr[i];

		else if (i==pos+1) 
			tmp[i] = elem;

		else if (i>pos+1) 
			tmp[i] = arr[i-1];
	}
	
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int *arr, *arr2;
	int n, m, elem=50;

	cout << "Enter size of array -> ";
	cin >> n;
	cout << endl;

	allocateArray(arr, n);
	fillArray(arr, n);
	printArray(arr, n);
	arr2 = addNewElem(arr, n, elem);
	printArray(arr, n);
	

	system("pause");
	return 0;
}  


// 52.	**Написать программу, которая переводит введенное десятичное число в двоичное число.Результат перевода сохранить в массив минимально возможного размера.