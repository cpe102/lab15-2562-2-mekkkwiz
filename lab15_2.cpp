#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr,int N,int M)
{
	
	for (int i = 0; i < N*M; i++){
		*(dPtr+i) = (rand()%101)/100.0;
	}
}

void findColSum(const double *data,double *result,int N,int M)
{
	double sum = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum += *(data+(i+7*j));
		}
		*result = sum;
		sum = 0;
		result++;
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