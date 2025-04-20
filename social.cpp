/* 
Name: James Ma
Professor: Tong Yi
Date: 4-11-25
*/
#include <iostream>
using namespace std;
/* 

setDisplayname allows to change the displayname property. (Username is a unique user identifier and cannot change, while displayname can be any string and can be modified, so the class provides a mechanism for updating it.)
*/
class Profile {
    private:
        string username;
        string displayname;
    public:
        // Profile constructor for a user (initializing 
        // private variables username=usrn, displayname=dspn)
        Profile(string usrn, string dspn);
        // Default Profile constructor (username="", displayname="")
        Profile();
        // Return username
        string getUsername();
        // Return name in the format: "displayname (@username)"
        string getFullName();
        // Change display name
        void setDisplayName(string dspn);
};
Profile::Profile(string usrn,string dspn){
    username=usrn;
    displayname=dspn;
}
string Profile::getUsername(){
    return username;
}
string Profile::getFullName(){
    return displayname+"(@"+username+")";
}
void Profile::setDisplayName(string dspn){
    displayname=dspn;
}
int main() {
Profile p1("marco", "Marco");    
cout << p1.getUsername() << endl; // marco
cout << p1.getFullName() << endl; // Marco (@marco)

p1.setDisplayName("Marco Rossi"); 
cout << p1.getUsername() << endl; // marco
cout << p1.getFullName() << endl; // Marco Rossi (@marco)

Profile p2("tarma1", "Tarma Roving");    
cout << p2.getUsername() << endl; // tarma1
cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}