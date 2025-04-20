/* 
Name: James Ma
Professor: Tong Yi
Date: 4-8-25
*/

#include <iostream>
/* #include <cstdlib>
#include <cmath> */

class Time { 
    public:
        int h;
        int m;
};
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
    public: 
        std::string title;
        Genre genre;     // only one genre per movie
        int duration;    // in minutes
};
    
class TimeSlot { 
    public: 
        Movie movie;     // what movie
        Time startTime;  // when it starts
};
int minutesSinceMidnight(Time time){
    return time.h*60+time.m;
}

int minutesUntil(Time earlier, Time later){
    return ((earlier.h-later.h)*60*-1)+((earlier.m-later.m)*-1);
}
Time addMinutes(Time time0, int min){
    time0.h+=(time0.m+min)/60;
    time0.m=(time0.m+min)%60;
    return time0;
}

void printMovie(Movie mv){  
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
//just prints out the og timeslot and calculates the time after the movie
void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie);
    std::cout<<" [starts at "<<ts.startTime.h<<":"<<ts.startTime.m<<", ends by "<<
    ts.startTime.h+(ts.startTime.m+ts.movie.duration)/60<<":"<<(ts.startTime.m+ts.movie.duration)%60<<
    "]"<<std::endl; 
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    ts.startTime.h=ts.startTime.h+(ts.startTime.m+ts.movie.duration)/60;
    ts.startTime.m=(ts.startTime.m+ts.movie.duration)%60;
    ts.movie.genre=nextMovie.genre;
    ts.movie.duration=nextMovie.duration;
    ts.movie.title=nextMovie.title;
    
    return ts;
}
//if it is negative that means that the first movie is after then if it is after, to check if it is overlap, the duration of the 2nd movie must be longer than the time difference
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    int mintill=minutesUntil(ts1.startTime,ts2.startTime);
    if(mintill<0 && (mintill+ts2.movie.duration)>0){ //mintill being negative means the first parameter movie is ahead. So it checks if the difference between the duration of the 2nd parameter movie will be greater than the difference in time between the two showings 
        return true;
    }else if(mintill>0 && mintill<ts1.movie.duration){//mintill being positive means the first paramter movie goes before the second one. So it checks if the duration of the first one is greater than the difference in time between the two showings
        return true;
    }else if(mintill==0){ //if there is no difference, the movies are running at the same time
        return true;
    }else{
        return false;
    }
} 
int main(){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot boring = {movie2, {10, 15}};
    TimeSlot morning1=scheduleAfter(morning,movie2);
    printMovie(morning1.movie);
    if(timeOverlap(morning,boring)==true){
        std::cout<<"overlap";
    }else{
        std::cout<<"no overlap";
    }

    return 0;
}

