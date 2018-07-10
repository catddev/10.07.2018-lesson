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
		double temp2 = a[0];

		for (int i = 1; i < 4; i++)
		{
			temp = a[i];

			a[i] = (temp2 + a[i + 1]) / 2.0;
			temp2 = temp;
		}
		
		for (int i = 0; i < n; i++)
		cout << a[i] << " ";
		cout << endl << endl;
		
	}
	break;
	case 2:
	{
		/*const int n = ;
		double a[n] = { 4, 7, 20, 3, 17, 11, 1, 18 };
		int min_v = INT_MAX;
		int max_v = INT_MIN;
		int j1=0, j2=0;
		double p = 1;


		for (int i = 0; i < n; i++)
		{
			if (a[i] < min_v)
			{
				min_v = a[i];
				i = j1;
			}
			if (a[i] > max_v)
			{
				max_v = a[i];
				i = j2;
			}
		}

		int jtemp = 0;
		if (j1 > j2)
		{
			jtemp = j1;
			j1 = j2;
			j2 = jtemp;
		}
		for (int i = j1+1; i < j2; i++)
		{
			p = p*a[i];
		}
		cout << p << endl << endl;*/
	}
	break;
	case 3:
	{
		const int n = 8;
		double a[n] = { 4, 7, 20, 3, 17, 11, 1, 18};
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
		// ПУЗЫРЬКОВАЯ СОРТИРОВКА

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
	case 5:
	{

	}
	break;
	case 6:
	{

	}
	break;
	case 7:
	{

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