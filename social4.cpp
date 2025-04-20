/* 
Name:  James Ma
Professor: Tong Yi
Date: 4-19-25
*/

/* 
Name:
Professor: 
*/
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

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
Profile::Profile(){
    username="";
    displayname="";
}
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

class Network {
    private:
        static const int MAX_USERS = 20; 
        int numUsers;                    
        Profile profiles[MAX_USERS];     
        bool following[MAX_USERS][MAX_USERS];    // new 
        int findID (string usrn);
        static const int MAX_POSTS = 100;
        int numPosts;
        Post posts[MAX_POSTS];
    public:
        Network();
        bool addUser(string usrn, string dspn);
        bool follow(string usrn1, string usrn2); // new
        void printDot();                         // new
        bool writePost(std::string usrn, std::string msg); //adds a new post to the user
        bool printTimeline(std::string usrn); //prints the user's timeline
    };

bool Network::writePost(std::string usrn, std::string msg){
      
}
bool Network::printTimeline(std::string usrn){
    
}
struct Post{
    std::string username;
    std::string message;    
};

//goes through the list of names and returns theindex of an username if the input name is a match to the current index's element
int Network::findID(string usrn){
    for(int i=0;i<numUsers;i++){
        if(usrn==profiles[i].getUsername())
            return i;
    }
    return -1;
}
//initalizes the object & sets every element in the 2d array to false
Network::Network(){
    numUsers=0;
    for(int row=0;row<MAX_USERS;row++)
        for(int col=0;col<MAX_USERS;col++)
            following[row][col]=false;
}

//attempts to add a user to a profile object array -- if in the array already return false, else return true
bool Network::addUser(string usrn,string dspn){
    if(numUsers+1<=MAX_USERS && findID(usrn)==-1){
        for(int i=0;i<usrn.size();i++){
            if(!isalnum(usrn[i])){  //isalnum checks if a character is a digit or alphabetic
                return false;
            }
        } 
        numUsers++;
        profiles[numUsers-1]={usrn,dspn};
        return true;
    }
    return false;
}
//if usrn1 and usrn2 exist, make it so usrn1 follows usrn2
bool Network::follow(string usrn1,string usrn2){
    if(findID(usrn1)!=-1 && findID(usrn2)!=-1){
        following[findID(usrn1)][findID(usrn2)]=true; //b/c the # of each column and row correspond to each other, findID(usrn1) gives me the index that matches the first name, and findID(usrn2) gives me the index in that row that matches the usrn2
        return true;
    }
    return false;
}

//should display a graphical representation of who is following who idk
void Network::printDot(){
    std::cout<<"digraph {"<<std::endl;
    for(int i=0;i<numUsers;i++){
        std::cout<<"  "<<"\"@"<<profiles[i].getUsername()<<"\""<<std::endl;
    }
    for(int row=0;row<numUsers;row++){
        for(int col=0;col<numUsers;col++)
            if(following[row][col]==true)
                std::cout<<"  "<<"\"@"<<profiles[row].getUsername()<<"\" ->"<<" \"@"<<profiles[col].getUsername()<<"\""<<std::endl;
    }
    std::cout<<"}";
}
int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
     
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
  
    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");
  
    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;
  
    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
  }