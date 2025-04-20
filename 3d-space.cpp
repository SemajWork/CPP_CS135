/* 
Name:James Ma
Professor: Tong Yi


*/
#include <iostream>
#include <cmath>

//class cord3d that stores coordinates in {x,y,z} fashion
class Coord3D {
    public:
        double x;
        double y;
        double z;
};
//uses pointer p to call the values associated with it 
//returns length of vector 
double length(Coord3D *p){
    return sqrt(pow(p->x,2)+pow(p->y,2)+pow(p->z,2));
}
Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    return (length(p1)>length(p2)) ? p1 : p2; //uses a ternary: if p1 is longer than p2 return p1 else return
}

//points to the x,y,z values being pointed to by the Coord3d class object ppos 
void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x= ppos->x + pvel->x * dt;
    ppos->y= ppos->y + pvel->y * dt;
    ppos->z= ppos->z + pvel->z * dt;
}
//position of object, velocity of object, time interval is dt
//shouldnt return should just update w the objects new position

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z){
    Coord3D* cord = new Coord3D;
    cord->x=x;
    cord->y=y;
    cord->z=z;
    return cord;
}

// free memory
void deleteCoord3D(Coord3D *p){
    delete p;
}

int main() {
    double x, y, z;
    std::cout << "Enter position: ";
    std::cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    std::cout << "Enter velocity: ";
    std::cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    std::cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}