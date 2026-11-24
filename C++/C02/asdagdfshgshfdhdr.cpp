#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float M,C,i,ii,lucro;
    int t;
    
    cin >> C;
    cin >> i;
    cin >> t;
    
    ii = 1 + (i/100);
    M = C *(pow(ii,t));
    lucro = M - C;
    
    cout << fixed << setprecision(2) << "LUCRO = " << lucro << endl;
    
    return 0;
}