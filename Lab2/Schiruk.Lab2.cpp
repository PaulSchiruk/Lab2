#include<iostream>

using namespace std;

void EnterArray(double**, int, double);
void EnterArrayFLib(double**, int);
void DisplayArray(double**, int);
double** MemoryFill(int);
void MemoryFree(double**, int);
double Cosinus(double, double);
void Comparison(double**, double**,double**, int);
void MaxDifference(double**, int);

int main()
{
	int n = 100;
	double eps = 0.0000001;
	//cin >> n;
	//cin >> eps;
	double** a = MemoryFill(n);
	double** b = MemoryFill(n);
	double** c = MemoryFill(n);
	EnterArray(a, n, eps);
	EnterArrayFLib(b, n);
	Comparison(a, b, c, n);
	//DisplayArray(a, n);
	cout << endl;
	//DisplayArray(b, n);
	cout << endl;
	//DisplayArray(c, n);
	cout << endl;
	MaxDifference(c, n);
	MemoryFree(a, n);
	MemoryFree(b, n);
	system("pause");
	return 0;
}

double** MemoryFill(int n)
{
	double** a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	return a;
}

void EnterArray(double** a, int n, double eps)
{
	double pi = 3.14159265359;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{			
			if (i == j)
			{
				double t = i + j;
				while (t > pi)
					t -= 2 * pi;
				while (t < (-1)* pi)
					t += 2 * pi;
				a[i][j] = (Cosinus(t, eps) + 2 * i - j) / ((i + j + 1)*(i + j + 1));
			}
			else a[i][j] = i - j;
		}
	}
	return;
}


void EnterArrayFLib(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) 
				a[i][j] = (cos(i + j) + 2 * i - j) / ((i + j + 1)*(i + j + 1));
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
			cout.width(10);
			cout << a[i][j];
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

void Comparison(double** a, double** b,double** c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				c[i][j] = fabs(a[i][j] - b[i][j]);
			else c[i][j] = 0;
		}
	}
}

void MaxDifference(double** a, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) 
				if (a[i][j] > max)
					max = a[i][j];
		}
	}
	cout << " Maximum differemce is: " << max << endl;
}
