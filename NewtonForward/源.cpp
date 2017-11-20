#include <iostream>

using namespace std;
#define ERROR 10e-4
void scanf_data(double ** &A, double & range_value, double ** &temp_a, double &x, int &n);
void solution(double ** &A, double ** &temp_a, double x, int n);
void diff_value(double **A, double range_value, double **temp_a, double x, int n);
int main()
{
	double **A = NULL, **temp_a = NULL;
	int n = 0;
	double x = 0;
	double range_value = 0;

	scanf_data(A, range_value, temp_a, x, n);

	solution(A, temp_a, x, n);

	diff_value(A, range_value, temp_a, x, n);

	system("PAUSE");
}

void scanf_data(double ** &A, double & range_value, double ** &temp_a, double &x, int &n)
{
	cout << "********请输入数值的个数:**********\n";
	cin >> n;

	A = new double *[n];
	temp_a = new double *[2];

	cout << "********请输入间距的值:**********\n";
	cin >> range_value;

	cout << "********请先输入" << n << "个x,然后输入" << n << "个f(x):**********\n";
	for (size_t i = 0; i < n; i++)
	{
		A[i] = new double[n];
		if (i < 2)
			temp_a[i] = new double[n];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp_a[i][j];
			//cout << temp_a[i][j] << " ";
		}
		//cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				A[j][i] = temp_a[1][j];

			}
			else
			{
				A[j][i] = 0;
			}
			//cout << A[j][i] << " ";
		}
		//cout << endl;
	}
	cout << "\n\n********需要计算的x的值**********\n";
	cin >> x;
}

void solution(double ** &A, double ** &temp_a, double x, int n)
{

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			double temp1 = A[j][i - 1] - A[j - 1][i - 1];
			//double temp2 = temp_a[1][j] - temp_a[1][j - i];
			//cout<<temp1 <<" "<<temp2<<endl;
			A[j][i] = temp1;
		}
	}

	cout << "\n\n**********差分表********\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

}

void diff_value(double **A, double range_value, double **temp_a, double x, int n)
{
	double ** n_table = NULL;
	int i, j;
	double t = (x - temp_a[0][0]) / range_value;
	int k = 0;
	double sum1, sum2 = 0;
	for (k = 1; k <= n; k++)
	{
		sum1 = sum2;
		sum2 = 0;
		for (i = 0; i < k; i++)
		{
			double temp_sum = 1;
			for (j = 0; j < i; j++)
			{
				temp_sum *=( t - j )/(1.0*(1+j));

			}
			sum2 += temp_sum * A[i][i];
		}
		//cout <<sum1 <<" "<< sum2 << endl;
		if (fabs(sum1 - sum2) <= ERROR)
		{
			//cout << "第"<<k << endl;
			break;
		}
	}
	cout << "\n\n****************计算结果为************\n\n";
	cout << "\t" << k - 1 << "次的方程满足条件\n" << endl;
	cout << "\t" << "插值结果y为：" << sum2 << "\n\n";
}