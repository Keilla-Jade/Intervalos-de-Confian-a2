#include <iostream>
#include <cmath>
#include<cstdlib>

using namespace std;

double erf(double x)
{  
	double y = 1.0 / ( 1.0 + 0.3275911 * x);   
	return 1 - (((((+ 1.061405429  * y - 1.453152027) * y + 1.421413741) * y - 0.284496736) * y + 0.254829592) * y) * exp(-x * x);      
}

double pdf(double x, double mu, double std_dev)
{
	static const double pi = 3.14159265; 
	return exp( -1 * (x - mu) * (x - mu) / (2 * std_dev * std_dev)) / (std_dev * sqrt(2 * pi));
}

double cdf(double x, double mu, double std_dev)
{
	return 0.5 * (1 + erf((x - mu) / (std_dev * sqrt(2.))));
}

double cdf(double x1, double x2, double mu, double std_dev)
{

	if (x1 > x2);{
	double cdf(x1, mu, std_dev) - cdf(x2, mu, std_dev);
	}	
	else;{
	double cdf(x2, mu, std_dev) - cdf(x1, mu, std_dev);
	
	}
		return 0;
		
int main()
{	
	double x, mu, std_dev;
	
	cout << "Insira os valores, na sequencia, de: x, mu, std_dev: ";
	cin >> x >> mu >> std_dev;

	cout << "PDF de x e: " << pdf(x, mu, std_dev) << endl;
	cout << "CDF de x e: " << cdf(x, mu, std_dev) << endl;
	cout << "CDF de x e (mu = 0, std_dev = 1): " << cdf(x, 0, 1) << endl;

	return 0;
}
