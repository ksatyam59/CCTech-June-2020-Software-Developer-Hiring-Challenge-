// Program is not in function
// it is just a tried approach which is not fruitful

// program to calculate total area of buildings exposed to sunlight

#include<iostream>
#include<algorithm>

using namespace std;


// Declaring structure for Co-ordinates
struct Point
{
    int x;
    int y;
};

// sorting the array on the basis of size of building

void XSorted( double *stored_points[n])
{
   std::sort(stored_points, stored_points + n,
    [](double *pt1, double *pt2) {
      return pt1[0] != pt2[0]
        ? pt1[0] < pt2[0]
        : pt1[1] < pt2[1];
    });


}


// sorting the array on the basis of size of building
void YSorted( double *stored_points[n])
{
     std::sort(stored_points, stored_points + n,
    [](double *pt1, double *pt2) {
      return pt1[1] != pt2[1]
        ? pt1[1] < pt2[1]
        : pt1[0] < pt2[0];
    });


}

//it checks the interval no. of times building edges gets intersected

bool number_interval(number pX, const interval& pInterval)
{
    if (pInterval.first < pInterval.second)
    {
        return pX > pInterval.first && pX < pInterval.second;
    }
    else
    {
        return pX > pInterval.second && pX < pInterval.first;
    }
}

bool inteveral_interval(const interval& pFirst, const interval& pSecond)
{
    return number_interval(pFirst.first, pSecond) ||
            number_interval(pFirst.second, pSecond) ||
            number_interval(pSecond.first, pFirst) ||
            number_interval(pSecond.second, pFirst);
}


// function to check if the point make segment on another building

bool segment_Building(const segment& pSegment, const rectangle& pRectangle)
{
    // project onto x (discard y values)
    interval segmentX =
                std::make_pair(pSegment.first.x, pSegment.second.x);
    interval rectangleX =
                std::make_pair(pRectangle.first.x, pRectangle.second.x);

    if (!inteveral_interval(segmentX, rectangleX))
        return false;
}


float If_Intersect_add (Point Building[][4],int n, Point p)
{
    float value;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Building[i][j].x>P.x && Building[i][j].y>p.y )
            {
                XSorted(Building[i][4]);
            }
            else
                YSorted(Building[i][4]);


        }

    }
}

int main()
{

    float result;
    Point Building[][4]={{{4,0},{4,-5},{7,-5},{7,0}}, {{0.4,-2},{0.4,-5},{2.5,-5},{2.5,-2}}};
    const size_t n = sizeof Building / sizeof *Building;
    Point p= {-3.5,1};

    result= If_Intersect_add ( Building, n,  p);

    cout<< result;

    return 0;

}
