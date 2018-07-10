#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include <Windows.h>
#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

start:

	cout << "Задача № ";
	cin >> tn;

	switch (tn)
	{
	case 1:
	{
		// первое и последнее элементы массивов не трогать, а остальные заменить на полусумму соседей с двух сторон

		const int n = 5;
		double a[n] = { 1, 20, 3, 17, 11 };

		double temp = 0;
		double temp2 = a[0]; // изначально присваиваем значение нулевого НЕИЗМЕНЯЕМОГО элемента массива

		for (int i = 1; i < 4; i++) // т.к. крайние элементы не трогаем по условию
		{
			temp = a[i]; // сохраняем перед изменением

			a[i] = (temp2 + a[i + 1]) / 2.0;
			temp2 = temp; //перезаписываем для следующей итерации
		}
		
		for (int i = 0; i < n; i++)
		cout << a[i] << " ";

		cout << endl << endl;
		
	}
	break;
	case 3: // произведение элементов, находящихся в массиве по порядку между максимальным и минимальным значением
	{
		const int n = 8;
		double a[n] = { 4, 7, 20, 3, 17, 11, 1, 18 };
		double min_e, max_e;
		int imax, imin, begin, end;
		double p = 1;

		min_e = a[0];
		max_e = a[0];

		for (int i = 0; i < n; i++)
		{
			if (a[i]<min_e)
			{
				min_e = a[i];
				imin = i;
			}
			if (a[i]>max_e)
			{
				max_e = a[i];
				imax = i;
			}
		}
		begin = imin < imax ? imin : imax;
		end = imin < imax ? imax : imin;

		// либо вот так в одну строку
		//imin < imax ? (begin=imin, end=imax):(begin=imax, end=imin);

		for (int i = begin + 1; i < end; i++)
		{
			p *= a[i];
		}

		if (abs(imax - imin) == 1) p = 0; // если между минимумом и максимумом нет значений
		cout << p << endl << endl;

	}
	break;
	case 4:
	{
		// ПУЗЫРЬКОВАЯ СОРТИРОВКА bubble sort

		const int n = 8;
		double a[n] = { 4, 0, 7, 17, 11, 1, 18, 20};

		for (int pass=0; pass<n-1; pass++)
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		cout << endl << endl;
	}
	break;
	case 5: // insertion sort СОРТИРОВКА СО ВСТАВКОЙ
	{
		/*const int n = 8;
		double a[n] = { 4, 0, 7, 17, 11, 1, 18, 20 };

		for (int pass = 0; pass < n; pass++) // это не то получилось, всего лишь модификация пузырьковой сортировки
		{
			for (int i = 0; i <= pass; i++)
				if (a[i] > a[i + 1])
					swap(a[i], a[i + 1]);

			for (int i = 0; i <= pass; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		cout << endl;*/

		const int n = 8;
		double a[n] = { 4, 0, 7, 17, 11, 1, 18, 20 };

		int i = 0;
		for (int pass = 1; pass < n; pass++) // начинаем сравнивать сразу с двух элементов 0 и 1
		{
			i = pass;
			while ((a[i] < a[i - 1]) && i > 0) // сранивниваем в обратную сторону первый и нулевой и тд
			{
					swap(a[i], a[i - 1]);
					i--;
			}
				
			for (int i = 0; i <= pass; i++) // поступенчатый вывод для наглядносити
			{
				cout << a[i] << " ";
			}
			cout << endl;

		}

		cout << endl;
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		cout << endl << endl;
	}
	break;
	case 6: // selection sort сортировка выбора
	{
		const int n = 8;
		double a[n] = { 4, 7, 0, 20, 17, 11, 1, 18 };
		
		int i=0;
		double min_e;
		int k = 0;

		for (int pass = 0; pass < n; pass++)
		{
			
			min_e = a[pass + 1];
			for (i = pass + 1; i < n; i++)
			{
				if (a[i] <= min_e)
				{
					min_e=a[i];
					k = i;
				}
			}
			swap(a[k], a[pass]);

			
		}

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		cout << endl << endl;
	}
	break;
	case 7: // БИНАРНЫЙ ПОИСК
	{
		const int n = 8;
		double a[n] = { 4, 0, 7, 17, 11, 1, 18, 20 };
		int low;
		int high;
		int middle;
		double key = 11; // искомое число, для простоты ввели заранее

		int i = 0;
		for (int pass = 1; pass < n; pass++) // здесь просто отсортируем, потому что бинарный поиск только для упорядоченного массива
		{
			i = pass;
			while ((a[i] < a[i - 1]) && i > 0)
			{
				swap(a[i], a[i - 1]);
				i--;
			}
		}

		low = 0;
		high = n - 1;

		while (low <= high)
		{
			middle = (low + high) / 2;
			if (key > a[middle])
				low = middle + 1;
			else if (key < a[middle])
				high = middle - 1;
			else break; // то есть когда key==a[middle] - искомое число найдено
		}

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		cout << endl;
		cout << "i = " << middle << endl; // выводим номер элемента искомого числа

	}
	break;
	case 8:
	{
		
	}
	break;
	case 9:
	{

	}
	break;
	case 10:
	{

	}
	break;
	default:
		cout << "нет такой задачи" << endl << endl;
	}
	goto start;

	system("pause");
	return 0;
}