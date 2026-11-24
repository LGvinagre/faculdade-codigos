#include <iostream>

using namespace std;

int main()
{
	int i, j;
	cin >> i;
	cin >> j;
	
	int maiorC = 0;
	
	for (int num = i; num <= j; num++){
		int comprimento = 1;
		int n = num;
		
		while (n!= 1){
			if (n % 2 == 0){
				n /= 2;
			} else {
				n = n * 3 + 1;
			}
			comprimento++;
		}
		if (comprimento > maiorC){
			maiorC = comprimento;
		}	
	}
	cout << i << " " << j << " " << maiorC << endl;
	 
	return 0;
}