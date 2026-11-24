#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

int main()
{
	int N;// (N <= 1000)
	double H;
	
	cin >> N;
	
	for (int i = 1; i <= N;i++){
		
		H += 1 / i;
	}
	
	cout << fixed << setprecision(4) << N << endl;

	return 0;
}