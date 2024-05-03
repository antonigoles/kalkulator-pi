#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <iomanip>



namespace MonteCarlo 
{
    class Vector2 
    {  
    public:
        double x;
        double y;

        Vector2(double _x, double _y) 
        {
            x = _x; 
            y = _y;
        };

        double distance(Vector2 &other) 
        {
            return sqrt( pow(other.x - this->x, 2) + pow(other.y - this->y, 2) );
        }
    };

    double randomDoubleInRange(double min, double max, std::default_random_engine &re)
    {
        std::uniform_real_distribution<double> unif(min, max);
        return unif(re);
    }

    Vector2 getRandomPointInSqaure(double sideLength, std::default_random_engine &re) 
    {
        return Vector2{randomDoubleInRange(0, sideLength, re), randomDoubleInRange(0, sideLength, re)};;
    }


    double performMonteCarloSearchWithNRandomPoints(int n) 
    {
        int count = 0;
        Vector2 center = {0.0,0.0};
        std::default_random_engine re;
        for ( int i = 0; i<n; i++ ) {
            Vector2 currentPoint = getRandomPointInSqaure(1.0, re);
            double distance = center.distance(currentPoint);
            if ( distance <= 1.0 ) count++;
        }
        double doubleN = (double)n;
        return 4 * count / doubleN;
    }

    void performUserDialog() 
    {
        int n;
        std::cout << "Ile punktow chcesz wylosowac? ";
        std::cin >> n;
        double result = performMonteCarloSearchWithNRandomPoints(n);
        std::cout << std::setprecision(15) << "Wynik: " << result << "\n";
    }
}
