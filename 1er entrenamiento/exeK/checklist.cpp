#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

typedef struct 
{
    /* data */
    int x;
    int y;
} Point;

int main()
{
    int n, c = 0;
    cin >> n;

    if (n > 100000)
        return 0;

    vector<Point> points;
    

    for (int i = 0; i < n; i++)
    {
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    for (Point point : points)
    {
        vector<Point> midPoints; 
        vector<Point> upperPoints;

        for (Point point2 : points)
        {
            if (point2.x > point.x)
            {
                if (point2.y < point.y)
                    midPoints.push_back(point2);
                else if (point2.y > point.y)
                    upperPoints.push_back(point2);
            }
        }

        for (auto point2 : midPoints)
        {
            for (auto point3 : upperPoints)
            {
                if (point3.x > point2.x && point3.y > point2.y)
                    c++;
            }
        }
    }

    cout << c << endl;
}