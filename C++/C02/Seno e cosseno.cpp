#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double N1, N2;
	cin >> N1 >> N2;

	if (N1 >= N2)
	{
		cout << "O valor de N1 deve ser menor que N2." << endl;
		return 0;
	}

	double intervaloInicial = N1;
	double intervaloFinal = N2;

	double primeiroPositivo = 0.0;
	double ultimoPositivo = 0.0;

	for (double theta = intervaloInicial; theta <= intervaloFinal; theta += 0.1)
	{
		double resultado = sin(theta) * cos(theta);

		if (resultado > 0)
		{
			if (primeiroPositivo == 0.0)
			{
				primeiroPositivo = theta;
			}
			ultimoPositivo = theta;
		}
	}

	if (primeiroPositivo == 0.0)
	{
		cout << "Nenhum valor positivo encontrado no intervalo." << endl;
	}
	else
	{
		cout << fixed << setprecision(1);
		cout << primeiroPositivo << " a " << ultimoPositivo << endl;
	}

	return 0;
}
