/* 
Name:James Ma
Professor: Tong Yi

Define a structure Triangle that contains three Point members. 
Write a function that computes the perimeter of a Triangle. 
Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>

//Creates struct Point that represents a coordinate point
struct Point{
    double x;
    double y;
    Point(double x, double y): x(x),y(y){};
};
//Creates a struct triangle that has three members of Point
struct Triangle{
    Point one; //creates an object 'one' of the struct Point
    Point two;
    Point three;
};

double perimeter(Triangle a){
    double edge1=sqrt(pow(a.two.x-a.one.x,2)+pow(a.two.y-a.one.y,2));//gets the length of one edge
    double edge2=sqrt(pow(a.three.x-a.one.x,2)+pow(a.three.y-a.one.y,2));
    double edge3=sqrt(pow(a.three.x-a.two.x,2)+pow(a.three.y-a.two.y,2));
    return edge1+edge2+edge3; //returns the sums of the legths of the three sides
}

int main(){
    
    return 0;
}
