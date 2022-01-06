#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void init_arr(int* A, double* B);
void out_in_file(int* A, double* B);
int search_brute_force_method(double* B, double& p);
int bin_search(double* B, double& p);
void bublesort(int* A);
void insertionSort(int* arrayPtr);
void choicesSort(int* arrayPtr);

int main() {
	int N;
	int A[100], d1, d2;
	cin >> N;
	double* B = new double[N], p;

	init_arr(A, B);
	out_in_file(A, B);

	cout << "\nEnter any real number:"; cin >> p;
	cout << "\nSimple search \n";
	d1 = search_brute_force_method(B, p);
	printf("B[%d] = %0.10f\n", d1, B[d1]);

	cout << "\nDichotomous search \n";
	d2 = bin_search(B, p);
	printf("B[%d] = %0.10f\n", d2, B[d2]);

	bublesort(A);
	insertionSort(A);
	choicesSort(A);

	return 0;
}

void init_arr(int* A, double* B) {
	srand(time(0));

	//Заполниение массива A[100]
	int a, b;
	for (int i = 0; i < 100; i++) {
		a = rand();
		b = rand();
		A[i] = int(a / double(b) * 100000) % 100000;
		//cout << "A[" << i <<  "] = " << A[i] << endl;
	}

	//Заполниение массива B[1000]
	int k = 0, fractional_part  = 0, integer_part = -1;
	for (int i = 0; i < 1000; i++) {
		if (i % 10 == 0) {
			integer_part += 1;
			B[i] = integer_part;
		}
		else 
		{
			if (k == 9)
			{
				k = 0;
				fractional_part = 0;
			}
			fractional_part = fractional_part * 10 + k + 1;
			B[i] = integer_part + fractional_part * pow(0.1, k + 1);
			k++;
		}
		//printf("B[%d] = %0.10f\n", i, B[i]);
	}

}

void out_in_file(int* A, double* B) {
	ofstream out1("A.txt");
	for (int i = 0; i < 100; i++)
	{
		out1 << "A[" << i << "] = " << A[i] << endl;
		if (i % 10 == 0) cout << "A[" << i << "] = " << A[i] << endl;
	}
	out1.close();

	ofstream out2("B.txt");
	for (int i = 0; i < 1000; i++)
	{
		out2 << "B[" << i << "] = " << setprecision(11) << B[i] << endl;
		if (i % 100 == 0) cout << "B[" << i << "] = " << setprecision(11) << B[i] << endl;
	}
	out2.close();
}	

int search_brute_force_method(double* B, double& p) {
	clock_t begin = clock(); // число тиков в начале работы программы
	double eps = 0.001;
	int l = -1;

	for (int i = 0; i < 1000; i++) if (abs(B[i] - p) < eps) l = i;

	clock_t end = clock(); // число тиков перед началом работы 
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //время на расчёт в мс
	cout << "Time spent = " << time_spent << " seconds" << endl;

	if (l!= -1) return l;
	else return l;
}

int bin_search(double* B, double& p)
{
	clock_t begin = clock(); // число тиков в начале работы программы
	double eps = 0.001;
	int ib = 0, ie = 1000 - 1, ic;
	while (ib < ie)
	{
		ic = (ib + ie) / 2; if (B[ic] < p) ib = ic + 1;
		else ie = ic;
	}
	clock_t end = clock(); // число тиков перед началом работы 
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //время на расчёт в мс
	cout << "Time spent = " << time_spent << " seconds" << endl;
	if (abs(B[ib] - p) < eps) return ib;
	else return -1;
}

void bublesort(int* A) {
	cout << "\nBuble Sort\n";
	clock_t begin = clock(); // число тиков в начале работы программы

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 99; j++) {
			if (A[j] > A[j + 1]) {
				int b = A[j]; // создали дополнительную переменную
				A[j] = A[j + 1]; // меняем местами
				A[j + 1] = b; // значения элементов
			}
		}
	}
	clock_t end = clock(); // число тиков перед началом работы 
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //время на расчёт в мс
	cout << "Time spent = " << time_spent << " seconds" << endl;

	ofstream out("Buble Sort.txt");
	for (int i = 0; i < 100; i++) out << "A[" << i << "] = " << setprecision(11) << A[i] << endl;
	out.close();
}

void insertionSort(int* arrayPtr) 
{
	cout << "\nInsertion Sort\n";
	clock_t begin = clock(); // число тиков в начале работы программы

	int length = 100;
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}

	clock_t end = clock(); // число тиков перед началом работы 
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //время на расчёт в мс
	cout << "Time spent = " << time_spent << " seconds" << endl;

	ofstream out("Insertion Sort.txt");
	for (int i = 0; i < 100; i++) out << "A[" << i << "] = " << setprecision(11) << arrayPtr[i] << endl;
	out.close();
}

void choicesSort(int* arrayPtr) // сортировка выбором
{
	cout << "\nChoices Sort\n";
	clock_t begin = clock(); // число тиков в начале работы программы

	int length_array = 100;

	for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
	{
		int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
		{
			if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
			{
				temp = arrayPtr[repeat_counter];
				arrayPtr[repeat_counter] = arrayPtr[element_counter];
				arrayPtr[element_counter] = temp;
			}
		}
	}

	clock_t end = clock(); // число тиков перед началом работы 
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //время на расчёт в мс
	cout << "Time spent = " << time_spent << " seconds" << endl;

	ofstream out("Choices Sort.txt");
	for (int i = 0; i < 100; i++) out << "A[" << i << "] = " << setprecision(11) << arrayPtr[i] << endl;
	out.close();
}