#include <iostream>
#include <iomanip>
#include <chrono>
#include <conio.h>
using namespace std;
using namespace chrono;

void randArr(int* arr, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 199 - 99;
	}
}

void randomArray()
{
	const int length = 100;
	int arr[length];
	randArr(arr, length);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

void bubbleSort(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
}

void shakerSort(int* arr, int length)
{
	bool swapped = true;
	int start = 0;
	int end = length - 1;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < length - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		--end;
		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

void combSort(int* arr, int length)
{
	float k = 1.247;
	int gap = length - 1;
	while (gap >= 1)
	{
		for (int i = 0; i + gap < length; i++)
		{
			if (arr[i] > arr[i + gap]) {
				swap(arr[i], arr[i + gap]);
			}
		}
		gap /= k;
	}
}

void insertSort(int* arr, int length)
{
	int i, j, key;
	for (i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

void quickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int pivot_value = arr[right];
		int j = left;
		for (int i = left; i < right; i++) {
			if (arr[i] <= pivot_value) {
				swap(arr[j], arr[i]);
				j++;
			}
		}
		swap(arr[j], arr[right]);

		int pivot_index = j;

		quickSort(arr, left, pivot_index - 1);

		quickSort(arr, pivot_index + 1, right);
	}
}

void sortedArray()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	cout << "Неотсортированный массив:\n";
	const int length = 100;
	int arr[length];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 199 - 99;
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	cout << "Отсортированный массив (bubble sort): \n";
	auto start1 = steady_clock::now();
	bubbleSort(arr, length);
	auto end1 = steady_clock::now();
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cout << "\nДлительность (bubble sort): " << result1.count() << " nanoseconds\n";

	cout << "\n======================================\n";

	randArr(arr, length);

	cout << "\nОтсортированный массив (shaker sort): \n";
	auto start2 = steady_clock::now();
	shakerSort(arr, length);
	auto end2 = steady_clock::now();

	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	auto result2 = duration_cast<nanoseconds>(end2 - start2);
	cout << "\nДлительность (skaker sort): " << result2.count() << " nanoseconds\n";

	cout << "\n======================================\n";

	randArr(arr, length);

	cout << "\nОтсортированный массив (comb sort): \n";
	auto start3 = steady_clock::now();
	combSort(arr, length);
	auto end3 = steady_clock::now();
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	auto result3 = duration_cast<nanoseconds>(end3 - start3);
	cout << "\nДлительность (comb sort): " << result3.count() << " nanoseconds\n";

	cout << "\n======================================\n";

	randArr(arr, length);

	cout << "\nОтсортированный массив (insert sort): \n";
	auto start4 = steady_clock::now();
	insertSort(arr, length);
	auto end4 = steady_clock::now();
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	auto result4 = duration_cast<nanoseconds>(end4 - start4);
	cout << "\nДлительность (insert sort): " << result4.count() << " nanoseconds\n";

	cout << "\n======================================\n";

	randArr(arr, length);

	cout << "\nОтсортированный массив (quick sort): \n";
	int left = 0;
	int right = length - 1;
	auto start5 = steady_clock::now();
	quickSort(arr, left, right);
	auto end5 = steady_clock::now();
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	auto result5 = duration_cast<nanoseconds>(end5 - start5);
	cout << "\nДлительность (quick sort): " << result5.count() << " nanoseconds\n";

	cout << "\n\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

void minmaxElement()
{
	const int length = 100;
	int arr[length];
	randArr(arr, length);
	int min = arr[0];
	int max = arr[0];
	auto start = steady_clock::now();
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}
	auto end = steady_clock::now();
	cout << "Для неотсортированного массива:\n\n"
		<< "Минимальный элемент: " << min << "\n"
		<< "Максимальный элемент: " << max << "\n";
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "Длительность: " << result.count() << " nanoseconds\n";

	insertSort(arr, length);
	int min_sort = arr[0];
	int max_sort = arr[0];
	auto start3 = steady_clock::now();
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max_sort)
			max_sort = arr[i];
		else if (arr[i] < min_sort)
			min_sort = arr[i];
	}
	auto end3 = steady_clock::now();
	cout << "\nДля отсортированного массива:\n";
	auto result3 = duration_cast<nanoseconds>(end3 - start3);
	cout << "Длительность: " << result3.count() << " nanoseconds\n\n";
	cout << "Отсортированный массив:\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}

	cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

void averageValue()
{
	const int length = 100;
	int arr[length];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 199 - 99;
	}
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}
	int averageV;
	averageV = (max + min) / 2;

	insertSort(arr, length);

	int min_sort = arr[0];
	int max_sort = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max_sort)
			max_sort = arr[i];
		else if (arr[i] < min_sort)
			min_sort = arr[i];
	}
	int averageVSort;
	averageVSort = (max_sort + min_sort) / 2;
	cout << "Среднее значение: " << averageVSort << "\n\n";

	cout << "==================================================\n\n";

	cout << "Индексы элементов, которые равны среднему значению: ";
	int count = 0;

	auto start = steady_clock::now();

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == int(averageVSort))
		{
			cout << i << ' ';
			count = count + 1;
		}
	}
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "\nКоличество таких элементов: " << count;
	cout << "\nДлительность нахождения количества таких элементов: " << result.count() << " nanoseconds\n";
	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}

	cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

void lessThanValue()
{
	srand(time(NULL));
	const int length = 100;
	int arr[length];
	randArr(arr, length);
	insertSort(arr, length);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	double a;
	int count = 0;
	cout << "Введите число: ";
	cin >> a;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < a)
			count += 1;
	}
	cout << "\nКоличество элементов в отсортированном массиве, которые меньше введенного числа: " << count;

	cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

void moreThanValue()
{
	srand(time(NULL));
	const int length = 100;
	int arr[length];
	randArr(arr, length);
	insertSort(arr, length);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n\n";

	double b;
	int count = 0;
	cout << "Введите число: ";
	cin >> b;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > b)
			count += 1;
	}
	cout << "\nКоличество элементов в отсортированном массиве, которые больше введенного числа: " << count;

	cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

int bianrySearch(int arr[], int left, int right, int c)
{
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == c) {
			return mid;
		}
		if (arr[mid] > c) {
			right = mid - 1;
		}
		if (arr[mid] < c) {
			left = mid + 1;
		}
	}
	return -1;
}

int mainSearch()
{
	srand(time(NULL));
	const int length = 100;
	int arr[length];
	randArr(arr, length);
	insertSort(arr, length);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\n";

	int c, count = 0, check;
	cout << "Введите число для проверки, находится ли оно в массиве: ";
	cin >> c;

	auto start = steady_clock::now();
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == c)
			count += 1;
	}
	if (count >= 1)
		check = 1;
	else
		check = 0;
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	if (check == 1)
		cout << "\nВведенное число находится внутри массива!";
	else
		cout << "\nВведенное число не находится внутри массива!";

	cout << "\n\nДлительность метода перебором: " << result.count() << " nanoseconds";

	cout << "\n=====================================================\n";

	int size = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = size - 1;

	auto start1 = steady_clock::now();
	int index = bianrySearch(arr, left, right, c);
	auto end1 = steady_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);

	cout << "Длительность бинарного поиска: " << result1.count() << " nanoseconds";


	cout << "\n\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
	return 0;
}

void swapping()
{
	srand(time(NULL));
	const int length = 100;
	int arr[length];
	randArr(arr, length);
	insertSort(arr, length);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\n";

	int firstIndex, secondIndex;
	cout << "Введите два числа, соответсвующие индексам элементов, которые хотите поменять местами: ";
	cin >> firstIndex >> secondIndex;

	auto start = steady_clock::now();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (i == firstIndex && j == secondIndex)
				swap(arr[i], arr[j]);
		}
	}
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "\nИзменненый массив:\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\nСкорость обмена: " << result.count() << " nanoseconds";

	cout << "\n\n\nНажмите любую клавишу, чтобы вернуться в главное меню\n\n";
	_getch();
	system("cls");
}

void menu()
{
	setlocale(LC_ALL, "RU");
	int mainMenu;
	{
		cout << "Какой пункт вы хотите выбрать?\n"
			<< "1 - Создать массив со случайными значениями в диапозоне от -99 до 99\n"
			<< "2 - Отсортировать заданный в пункте 1 массив сортировкой (от меньшего к большему)\n"
			<< "3 - Найти максимальный и минимальный элементы массива\n"
			<< "4 - Вывести среднее значение максимального и минимального значения\n"
			<< "5 - Вывести количество элементов в отсортированном массиве, которые меньше введенного числа\n"
			<< "6 - Вывести количество элементов в отсортированном массиве, которые больше введенного числа\n"
			<< "7 - Проверка - есть ли введенное число в отсортированном массиве (бинарный поиск)\n"
			<< "8 - Поменять местами элементы массива\n"
			<< "9 - Выход\n\n";
	}
	cin >> mainMenu;

	switch (mainMenu)
	{
	case 1:
		randomArray();
		menu();
		break;
	case 2:
		sortedArray();
		menu();
		break;
	case 3:
		minmaxElement();
		menu();
		break;
	case 4:
		averageValue();
		menu();
		break;
	case 5:
		lessThanValue();
		menu();
		break;
	case 6:
		moreThanValue();
		menu();
		break;
	case 7:
		mainSearch();
		menu();
		break;
	case 8:
		swapping();
		menu();
		break;
	case 9:
		exit(1);
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		_getch();
		system("cls");
		menu();
		break;
	}
}

int main()
{
	menu();
	return 0;
}

