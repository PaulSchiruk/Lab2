#include<iostream>

using namespace std;

void EnterArray(double**, int, double);
void EnterArrayFLib(double**, int);
void DisplayArray(double**, int);
void MemoryFill(double**, int);
void MemoryFree(double**, int);
double Cosinus(double, double);

int main()
{
	int n = 20;
	double eps = 0.0001;
	//cin >> n;
	//cin >> eps;
	double** a = NULL;
	double** b = NULL;
	MemoryFill(a, n);
	MemoryFill(b, n);
	EnterArray(a, n, eps);
	EnterArrayFLib(b, n);
	DisplayArray(a, n);
	cout.width(20);
	DisplayArray(b, n);
	MemoryFree(a, n);
	MemoryFree(b, n);
	system("pause");
	return 0;
}

void MemoryFill(double** a, int n)
{
	a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
}

void EnterArray(double** a, int n, double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			if (i == j)  a[i][j] = (Cosinus(i + j, eps) + 2 * i - j) / ((i + j + 1)*(i + j + 1)); 
			else a[i][j] = i - j;
		}
	}
}

void EnterArrayFLib(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			if (i == j) a[i][j] = (cos(i + j) + 2 * i - j) / ((i + j + 1)*(i + j + 1));
			else a[i][j] = i - j;
		}
	}
}

void DisplayArray(double** a, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cout.width(7);
			cout << a[i];
		}
		cout << endl;
	}
}


void MemoryFree(double** a, int n)
{

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete a;
}

double Cosinus(double a, double eps)
{
	int m = 1;
	double sum = 1, n = (-1 * a * a) / (m * (m + 1));
	while (fabs(n) >= eps)
	{
		m += 2;
		sum += n;
		n *= (-1 * a * a) / (m * (m + 1));
	}
	return sum;
}