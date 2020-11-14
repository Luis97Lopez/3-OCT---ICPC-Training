#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct 
{
    int id;
    int x;
    int y;
} Point;

bool point_sorter_in_x(Point p1, Point p2) {
    return p1.x < p2.x;
}

bool point_sorter_in_y(Point p1, Point p2) {
    return p1.y < p2.y;
}


int main()
{
    int n, c = 0;
    cin >> n;

    vector<Point> points;
    //vector<Point> sorted_x;
    //vector<Point> sorted_y;
    

    for (int i = 0; i < n; i++)
    {
        Point p;
        cin >> p.x >> p.y;
        p.id = i;
        points.push_back(p);
        //sorted_x.push_back(points.back());
        //sorted_y.push_back(points.back());
    }

    auto start = high_resolution_clock::now(); 


    
    //sort(sorted_x.begin(), sorted_x.end(), &point_sorter_in_x);
    //sort(sorted_y.begin(), sorted_y.end(), &point_sorter_in_y);

    /*
    for(int i = 0; i < sorted_x.size(); i++){
        for(int j = i + 1; j < sorted_x.size(); j++){
            for(int k = j + 1; k < sorted_x.size(); k++){
                if(sorted_x[i].x < sorted_x[j].x && 
                   sorted_x[j].x < sorted_x[k].x &&
                   sorted_x[i].y > sorted_x[j].y &&
                   sorted_x[k].y > sorted_x[i].y)
                   c++;
            }
        }
    }
    */
    
    
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
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    // To get the value of duration use the count() 
    // member function on the duration object 
    cout << duration.count() << endl; 

}