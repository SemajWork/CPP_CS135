/* 
Name: James Ma
professor: Tong Yi
Date: 4-19-25
*/
#include <iostream>
#include <fstream> //ifstream
#include <string> //starts_with, c++20
#include <climits> //INT_MAX
#include <string.h> //c-string, strlen(...)
#include <cctype> //isspace

using namespace std;

struct Question {
    string text; //question text
    string answer;
    string explanation;
    string version;
    string type;
    string label;
};

void read_file(string fileName, Question ques[], int capacity, int& size);

void display(Question ques[], int size);

string trim(string str);

//count number of occurrences of ch in str
int count_occurrences(string str, char ch); 

//extract type separated by ; 
//then put the trimmed type in 
//dynamically allocated array of strings
string* extract_type(string type, int& num_types_curr_item);

void insert_order_unique(string types[], int type_capacity, int& type_count, string toAdd);

void insert_order_unique(string types[], int type_capacity, int& type_count, Question ques[], int ques_size);


void randomize(Question ques[], int size);

string choose_type(string* types, int type_count);

//answer questions, let users try at most 3 times,
//and return the number of correct answers in three or fewer tries
void answer_by_type(Question ques[], int size, string chosenType);

void feedback(int numCorrect, int numQuestionsInType);

void reorder(Question ques[],int size, int idx);

bool type_related(string type_to_focus, string curr_type);

#ifndef UNIT_TEST
int main2() {
    const int CAPACITY = 1000;
    Question ques[CAPACITY];
    int size = 0;

    read_file("cs135_midterm_f24_v2.txt",ques, CAPACITY, size);
    return 0;
}
#endif



//TODO
void read_file(string fileName, Question ques[], int capacity, int& size) {

}

//TODO
void display(Question ques[], int size) {

}

//implement trim function (finished)
string trim(string str) {
    int i = 0;
    while (i < str.size() && isspace(str[i]))
        i++;
    
    //once outside the while loop
    //(i < str.size() && isspace(str[i])) is not correct, 
    //aka, not satisified
    //that is,
    //either i == str.size()
    //or i < str.size() && str[i] is not a space

    //walk backwards, to find out the index of the last letter that is not a space
    int j = str.size() -1;
    while ( j >= 0 && isspace(str[j]) )
        j--;

    return str.substr(i, j-i+1);
}

//count number of occurrences of ch in str
int count_occurrences(string str, char ch) {
    int count =0;
    for(int i=0;i<str.size(); i++)
        if(str[i]==ch)
            count++;

    return count;
}

//TODO: extract type separated by ; 
//then put the trimmed type in 
//dynamically allocated array of strings
//this version does not use find method from string class and it works
string* extract_type(string type, int& num_types_curr_item) {
    num_types_curr_item = count_occurrences(type,';') +1;
    
    string* typeArr = new string[num_types_curr_item];

    int start =0;//start index of type item in type

    int i=0;
    int j=0;

    while(i< type.size()){
        if(type[i]==';'){
            string item = type.substr(start,i-start);
            item = trim(item);
            typeArr[j]=item;
            j++;
            start = i+1; //if found it will move the beginning pointer to after semicolon
        }
        i++;
    }

    string item = type.substr(start); //get last element
    item=trim(item);
    typeArr[j] = item;

    return typeArr;
}

//TODO: insert_order_unique, add a string
void insert_order_unique(string types[], int type_capacity, int& type_count, string toAdd) {
    //TODO: If array types is full, that is,
    //type_count, the to_write index of types
    //larger than or equal to capacity,
    //There is nothig we can do but return.
    if (type_count > type_capacity)
        return;


    //now type_count < capacity
    //TODO: Find out the index position to insert toAdd
    //Note that we need to maintain the sort order in the process of insertion
    //(1) any string before idx in types is < toAdd,
    //where for strings s and t, 
    //s < t means s appears before t in a dictionary
    //(2) any string after idx is >= toAdd
    //(3) Said differently, find out 
    //the FIRST string in types that is >= toAdd.
    //Or, keep on moving as long as the strings in    //sorted types is < toAdd.
    int idx = 0;
    while (idx < type_count && types[idx] < toAdd)
        idx++;


    //either idx == type_count
    //or idx < type_count but types[idx] >= toAdd

    //TODO: if types[idx] == toAdd, do nothing and return
    //since we do not want to insert 
    //a string more than once in types
    if (types[idx] == toAdd)
        return;

    //Now types[idx] > toAdd  
    //TODO: move all elements 
    //from the element indexed at idx to
    //the element at the last element to the right
    //to leave a spot for toAdd to insert.
    //which way should we move - forwards or backwards?
    //index of the last element of types with
    //type_count many element is type_count-1
    //Warning: how to update i?
    for (int i = type_count-1; i >= idx; i--)
        types[i+1] = types[i];


    //TODO: insert toAdd at idx 
    
    types[idx] = toAdd;
 
    //TODO: do not forget to update type_count
    type_count++;
}

//TODO: insert_order_unique, add several questions 
void insert_order_unique(string types[], int type_capacity, int& type_count, Question ques[], int ques_size) {
    for(int i=0;i<ques_size;i++){
        int numoccurances=count_occurrences(ques[i].type,';');
        string* p =extract_type(ques[i].type,numoccurances);
        for(int j=0;j<numoccurances;j++){
            insert_order_unique(types,type_capacity,type_count,p[j]);
        }
        delete[] p;
    }
}

//TODO:
void randomize(Question ques[], int size) {
    int numToChoose =size;
    srand(time(0));
    while(numToChoose>1){
        int chosen = rand()%numToChoose;
        swap(ques[chosen],ques[numToChoose-1]);
        numToChoose--;
    }
}

//TODO: 
string choose_type(string* types, int type_count) {
    std::cout<<"0. ALL TYPES"<<endl;
    for(int i=0;i<type_count;i++){
        std::cout<<i+1<<". "<<types[i]<<endl;
    }
    cout<<"Which type do you want? "<<endl;
    int type;
    cin>>type;
    cin.ignore(INT_MAX, '\n'); 
    while(type<0 || type>type_count){ // if type entered is less than 0 or greater than # of elements reprompt
        cout<<"Enter a valid selection: ";
        cin>>type;
        cin.ignore(INT_MAX, '\n'); 
    }
    if(type==0){
        return "";
    }
    return types[type-1];
}
bool type_related(string type_to_focus, string curr_type){
    int occur = count_occurrences(type_to_focus,';')+1;
    string* arr = extract_type(type_to_focus,occur);

    for(int i=0;i<occur;i++){
        if(curr_type.find(arr[i]) != std::string::npos){ //found type in curr_type
            delete[] arr; //deallocate memory
            return true;
        }
    }

    delete[] arr; //deallocate memory
    return false;
}
void reorder(Question ques[], int size, int idx){
    int beginidx =idx+1; //keeps track of the indexes in ques after indx

    while(type_related(ques[idx].type,ques[beginidx].type)==true && beginidx<size){
        beginidx++;
    }

    //i have to check if the index is 1 less than size-1 atleast b/c we're swapping 2 elements
    if(beginidx<size-1){
        for(int i=size-1;i>beginidx;i--){
            if(type_related(ques[idx].type,ques[i].type)){
                swap(ques[beginidx],ques[i]);
                beginidx++;
            }
        }
    }else
        return;
}
//TODO: answer questions, let users try at most 3 times,
//and return the number of correct answers in three or fewer tries
void answer_by_type(Question ques[], int size, string chosenType) {
    //TODO: call randomize function
    randomize(ques,size);
    //TODO: display questions and answer them
    string ans;//keeps track of the user's input
    int numCorrect=0;
    int numQuestions=0;
    int j;//initiates 2 integers to keep track of the # of questions & correctly answered ones, j is to keep track of # of times a question has been answered
    for(int i=0;i<size;i++){
        if(ques[i].type.rfind(chosenType)!=std::string::npos){//if the chosentype is found within a question's type it will print out the question & prompt for answer up to 3 times
            numQuestions++;
            std::cout<<"question "<<ques[i].text<<endl;
            for(j=1;j<4;j++){
                std::cout<<"Enter your answer: ";
                getline(cin,ans);
                ans=trim(ans);
                std::cout<<"Number of tries: "<<j<<endl;
                if(ans==ques[i].answer){ //if the answer is correct program prints true, increments numcorrect by 1 and breaks out of the loop
                    std::cout<<"true"<<endl;
                    numCorrect++;
                    break;
                }else{ //if wrong it will print false and continue
                    std::cout<<"false"<<endl;
                }
                if(j==3){ //if user inputs wrong answer 3 times, j will equal 4. if the question has an explanation, the program will print it out 
                    std::cout<<"Explanation: "<<ques[i].explanation<<std::endl;
                    reorder(ques,size,i);
                }
            }
        }
    }
    feedback(numCorrect,numQuestions);
}

//TODO: 
void feedback(int numCorrect, int numQuestionsInType) {
    cout<<"Number of correct questions: "<<numCorrect<<endl;
    double total=(numCorrect*1.0/numQuestionsInType)*100;
    std::cout<<"You got a "<<total<<"%"<<endl;
    if(total>=90){
        cout<<"excellent";
    }else if(total >=80){
        std::cout<<"good";
    }else if(total>=70){
        std::cout<<"pass";
    }else{
        std::cout<<"please ask help ASAP";
    }
}


