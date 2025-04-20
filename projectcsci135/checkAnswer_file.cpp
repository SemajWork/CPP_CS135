#include <iostream>
#include <string>
#include <fstream>
#include <string_view>

struct Question{
    std::string text;
    std::string answer;
    std::string explanation;
    std::string version;
    std::string type;
    std::string label;
};

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

std::ifstream openFile(){
    std::string fileName;
    std::cout<<"Which file do you want? (cs135_midterm_f24_v2.txt or civics_65_20.txt): ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if(file.fail()){
        std::cerr<<"file cant be openned"<<std::endl;
        exit(1);
    }
    return file;
}

double questioncounter(std::ifstream &file,std::string text){
    double i =0.0;
    while(std::getline(file,text)){
        if(text.find("question:") != std::string::npos){
            i++;
        }
    }
    file.clear();
    file.seekg(0);
    return i;
}

bool startswith(std::string text, const std::string find){
    return text.rfind(find,0) == 0;
}
bool addstring(std::string text){
    return startswith(text,"question:");
}

bool addanswer(std::string text){
    return startswith(text,"answer:");
}

bool explanation(std::string text){
    return startswith(text,"explanation:");
}

bool neither(std::string text){
    if(startswith(text,"version:") || startswith(text,"label:") || startswith(text,"type:"))
        return true;
    return false;
}

void gettype(std::string& text, std::string line){
    if(addstring(line)){
        text="question";
    }else if(addanswer(line)){
        text="answer";
    }else if(explanation(line)){
        text="explanation";
    }else if(neither(line)){
        text="neither";
    }
}

void resetwords(std::string& text,std::string& text2,std::string& text3,std::string& text4,int& i){
    text="";
    text2="";
    text3="";
    text4="";
    i=0;
}

int main(){
    Question q;
    const int SIZE = 200;
    std::string arr[SIZE];
    std::ifstream fin(openFile());

    double question= questioncounter(fin,q.text);
    int correct = 0;
    int j=0;
    int rand =0;
    
    std::string holder;
    std::string test = "";
    while(std::getline(fin,holder)){
        gettype(test,holder);

        if(test=="question"){
            q.text +=holder + "\n";
        }else if(test=="answer"){
            q.answer +=holder.substr(8);
        }else if(test=="explanation"){
            q.explanation +=holder + "\n";
        }else if(test=="neither"){
            if(q.text.find("question: ") == std::string::npos){
                continue;
            }
            std::cout<<q.text<<std::endl;
            for(j=1;j<=3;j++){
                std::cout<<"Enter your answer: ";
                if(rand==0) std::cin.ignore();
                std::getline(std::cin,holder);
                rand++;
                if(holder!=q.answer){
                    std::cout<<"Number of tries: "<<j<<std::endl;
                    std::cout<<"false"<<std::endl;
                }else{
                    std::cout<<"Number of tries: "<<j<<std::endl;
                    std::cout<<"true"<<std::endl;
                    correct++;
                    break;
                }
            }
            rand++;
            if(j>=3){
                std::cout<<"answer: "<<q.answer<<std::endl;
                std::cout<<q.explanation<<std::endl;
            }
            resetwords(q.text,q.answer,q.explanation,test,j);
        }
    }
    fin.close();

    double grade=correct/question*100;
    std::cout<<"number of correct problems: "<<correct<<std::endl;
    std::cout<<"percentage of correct: "<<grade<<"%"<<std::endl;
    std::cout<<finalgrade(grade);
    return 0;
}
