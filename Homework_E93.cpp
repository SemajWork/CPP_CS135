/* 
Name: James Ma
Professor: Tong Yi
Date: 4-11-25
*/

#include <iostream>
using namespace std;

/* 
Simulate a circuit for controlling a hallway light that has
 switches at both ends of the hallway. Each switch can be up or down, 
 and the light can be on or off. Toggling either switch turns the lamp on or off. 
 Provide member functions
 */
class Circuit {
	public:
		int get_first_switch_state();
		int get_second_switch_state();
		int get_lamp_state();
		void toggle_first_switch();
		void toggle_second_switch();
	private:
		int first_switch = 0;
		int second_switch = 0;
		int lamp_state = 0;
};

int Circuit::get_first_switch_state(){
    return first_switch;
} // 0 for down, 1 for up
int Circuit::get_second_switch_state(){
    return second_switch;
}
int Circuit::get_lamp_state(){
    lamp_state=(first_switch+second_switch)%2;  //can either be 0,1 by modular 2 it concedes the range [0,1]
    return lamp_state;
} // 0 for off, 1 for on
void Circuit::toggle_first_switch(){
    first_switch=(first_switch+1)%2; //can either be 0,1 by modular 2 it concedes the range [0,1]
}
void Circuit::toggle_second_switch(){
    second_switch=(second_switch+1)%2; //can either be 0,1 by modular 2 it concedes the range [0,1]
}