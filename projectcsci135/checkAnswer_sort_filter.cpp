/* 
student:  James Ma
professor: Tong Yi
Date: 3-16-25
*/

#include <iostream>
#include <string>
#include <fstream>
#include <string_view>
#include <algorithm>


struct Question{
    std::string text;
    std::string answer;
    std::string explanation;
    std::string version;
    std::string type;
    std::string label;
};
//returns a string depending on value of num
std::string finalgrade(double num){
    if(num>=90){
        return "excellent";
    }else if(num>=80){
        return "good";
    }else if(num>=60){
        return "pass";
    }else
        return "please ask help ASAP";
}
//opens file according to user input
std::ifstream openFile(std::string filen){
    std::ifstream file(filen);
    if(file.fail()){
        std::cerr<<"file cant be openned"<<std::endl;
        exit(1);
    }
    return file;
}
//sets text to equal to a certain label/type 
void startswith(std::string& text,std::string line){
    if(line.rfind("question",0) == 0){
        text="question";
    }else if(line.rfind("answer",0) == 0){
        text="answer";
    }else if(line.rfind("explanation",0) == 0){
        text="explanation";
    }else if(line.rfind("version",0) == 0){
        text="version";
    }else if(line.rfind("label",0) == 0){
        text="label";
    }else if(line.rfind("type",0) == 0){
        text="type";
    }
}
//resets the struct variables to equal ""
void resetwords(std::string& test,std::string& text,std::string& text2,std::string& text3,std::string& text4,std::string& text5,std::string& text6){
    test="";
    text="";
    text2="";
    text3="";
    text4="";
    text5="";
    text6="";
}
//inputs parses through a text file and inputs element into an array
void arrayholder(std::string arr[],std::ifstream& fin,Question q,int &i){
    std::string test; // type holder 
    std::string holder; //stores each line of text
    while(std::getline(fin,holder)){
        startswith(test,holder); //calls upon the startswith function to set test equal to a certain label
        if(test=="question"){
            if(holder.rfind("question:",0)==0){
                if(holder.length()>10){ 
                    q.text+=holder.substr(10) +"\n";
                }
            }else{
                q.text +=holder + "\n";
            }
        }else if(test=="answer"){
            q.answer +=holder.substr(8);
        }else if(test=="explanation"){
            q.explanation +=holder + "\n";
        }else if(test=="version"){
            q.version+=holder;
        }else if(test=="label"){
            q.label+=holder;
        }else if(test=="type"){
            if(i+5<=200){
                if (holder.length() > 6) q.type+=holder.substr(6);}
            arr[i]=q.text;
            arr[i+1]=q.answer;
            arr[i+2]=q.explanation;
            arr[i+3]=q.version;
            arr[i+4]=q.label;
            arr[i+5]=q.type;
            i+=6;
            resetwords(test,q.text,q.answer,q.explanation,q.version,q.label,q.type);
        }else{
            continue;
        }
    }
}
void typestuff(std::string arr[], std::string types[], int len, Question q,int &count) {
    for (int i = 6; i <= len; i += 6) {
        if (arr[i].find(";")!=std::string::npos) {
            std::size_t found = arr[i].find(";");
            std::string first = arr[i].substr(0, found);
            std::string second = arr[i].substr(found+2); // Skip semicolon
            // Add first and second if not already in types
            if (std::find(types, types + count, first) == types + count) {
                types[count-1] = first;
                count++;
            }
            if(second.find(";")!=std::string::npos){
                continue;
            }else if (std::find(types, types + count, second) == types + count) {
                types[count-1] = second;
                count++;
            }
        }
        else {
            if (std::find(types, types + count, arr[i]) == types + count) {
                types[count-1] = arr[i];
                count++;
            }
        }
    }

    // Sorting types array
    std::sort(types, types + count);
}
//prompts user w type of question they want according to input file
int main(){
    int sizey=1; //an integer to keep track of the number of questions
    int typesizey=1; //keeps track of the number of types 
    Question q; //creates a struct object q
    const int SIZE=200; //constant variable to represent amount of possible elements stored in an array
    //initiate the arrays
    std::string arr[SIZE];
    std::string type[SIZE];

    //asks user for which file they want, store in string var filename and sets contents to ifstream object fin
    std::string fileName;
    std::cout<<"Which file do you want? (cs135_midterm_f24_v2.txt or civics_65_20.txt): "<<std::endl;
    std::cin >> fileName;
    std::ifstream fin(openFile(fileName));


    double question=0.0; //intiate double var question to store # of questions prompted
    arrayholder(arr,fin,q,sizey); //calls arrayholder and stores textfile elements into array 'arr'
    typestuff(arr,type,sizey,q,typesizey); //stores question types into array 'type' and sorts them
 
    int correct = 0;
    int rand=0;

    //prints out sorted types stored in type
    for(int i=1;i<typesizey;i++){
        std::cout<<i<<". "<<type[i]<<std::endl;
    }

    //prompts user for what type they want to answer & stores type into string typesorta
    std::cout<<"Enter a type: ";
    int sorta;
    std::cin>>sorta;
    std::string typesorta= type[sorta];

    std::string answer;
    int j;

    //sorts array for question type. If type is found, it prints out question and prompts until answer is correct or wrong answer is input 3times
    for(int i=6;i<=sizey;i+=6){
        if(arr[i].find(typesorta)!=std::string::npos){
            question++;
            std::cout<<"Question "<<((i-5)/6)+1<<": "<<arr[i-5]<<std::endl;
            for(j=1;j<=3;j++){
                std::cout<<"Enter your answer: ";
                if(rand==0) std::cin.ignore();
                std::getline(std::cin,answer);
                rand++;
                if(answer!=arr[i-4]){
                    std::cout<<"Number of tries: "<<j<<std::endl;
                    std::cout<<"false"<<std::endl;
                }else{
                    std::cout<<"Number of tries: "<<j<<std::endl;
                    std::cout<<"true"<<std::endl;
                    correct++;
                    break;
                }
            }
            if(j>3){
                std::cout<<"answer: "<<arr[i-4]<<std::endl;
                std::cout<<arr[i-3]<<std::endl;
            }
        }
    }
    
    double grade=correct/question*100;
    std::cout<<"number of correct problems: "<<correct<<std::endl;
    std::cout<<"percentage of correct: "<<grade<<"%"<<std::endl;
    std::cout<<finalgrade(grade); 
    return 0;
}