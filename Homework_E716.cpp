/* 
Name:James Ma
Professor: Tong Yi
Define a structure Point. A point has an x- and a y-coordinate. Write a function double 
distance(Point a, Point b) that computes the distance from a to b. 
Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>

struct Point{
    double x;
    double y;
    Point(double x,double y): x(x), y(y){};
};

double distance(Point a, Point b){
    return sqrt(pow(b.y-a.y,2)+pow(b.x-a.x,2));
}

int main(){
    Point pointone(2,3);
    Point pointtwo(3,6);
    std::cout<<distance(pointone,pointtwo);

    return 0;
}