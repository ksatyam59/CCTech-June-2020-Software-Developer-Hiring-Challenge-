// This program basically checks if a point lies inside the polygon or not
// it does not considers the special cases of lying on edges


#include<iostream>
#define MIN(x,y) (x < y ? x : y)// uses to find minimum of two values
#define MAX(x,y) (x > y ? x : y)// uses to find maximum of two values


using namespace std;

// this structure used to create co-ordinates for any points
typedef struct {
   double x,y;
} Point;


// function to check if point lies inside the polygon or not

int InsidePolygon(Point *polygon,int N,Point p)
{
  int counter = 0;
  int i;
  double pointers;
  Point p1,p2;

  p1 = polygon[0];
  for (i=1;i<=N;i++) {
    p2 = polygon[i % N];
    if (p.y > MIN(p1.y,p2.y)) {
      if (p.y <= MAX(p1.y,p2.y)) {
        if (p.x <= MAX(p1.x,p2.x)) {
          if (p1.y != p2.y) {
            pointers = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
            if (p1.x == p2.x || p.x <= pointers)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0)
    return 0;
  else
    return 1;
}


// main function to drive the  above function

int main()
{
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    Point p = {9, 3};

    int x=InsidePolygon( polygon1, n, p);

    if(x==0)
        cout<<"Outside";
    else
        cout<<"Inside";

    return 0;

}
