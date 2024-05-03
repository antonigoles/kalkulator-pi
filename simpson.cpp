#include <iostream>
#include <math.h>
#include <iomanip>

namespace Simpson 
{
    double func(double x) 
    {
        return 1 / ( 1.0 + ( x * x ) );
    }

     int roundToClosestEven(double n) 
    {
        return std::round(n / 2.0) * 2;
    }

    double compositeSimpson(double a, double b, double h)
    {
        double sum = func(a) + func(b);
        int n = roundToClosestEven((b-a) / h);
        h = (b-a) / n;
        for ( int i = 1; i<n; i++ ) {  
            double xi = a + i * h;
            double m = i & 1 ? 4 : 2;
            sum += m * func(xi);        
        }
        return (1.0/3.0) * h*sum;
    }

    double findHByError(double e) 
    {
        // assume that a = 0
        return std::pow(7.5 * e, 0.25);
    }

    double calcPIWithE(double e) 
    {
        double h = findHByError(e);
        return (4.0) * compositeSimpson(0.0, 1.0, h);
    }

    void performUserDialog()
    {
        double err;
        std::cout << "Jaki dopuszczalny blad? ";
        std::cin >> err;
        double result = calcPIWithE(err);
        std::cout << std::setprecision(15) << "Wynik: " << result << std::endl;
    }
}

