#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *dPtr,int N,int M)
{
	
	for (int i = 0; i < N*M; i++){
		*(dPtr+i) = (rand()%101)/100.0;
	}
}

void findRowSum(const double *data,double *result,int N,int M)
{
	double sum = 0;
	for (int i = 1; i < N*M+1; i++)
	{
		
		sum += *(data + i - 1);
		if (i%7==0)
		{
			*result = sum;
			sum = 0;
			result++;
		}
		
		
	}
	
	
	
}

void showData(double *data,int N,int M)
{
	cout << endl ;
	for (int i = 1; i < N*M+1; i++)
	{
		cout << setw(8) << *(data+i-1);
		if (i%M==0)
		{
			cout << endl;
		}
		
	}
	
}
