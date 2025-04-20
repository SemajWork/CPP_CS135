/*
Name: James Ma
Professor: Tong Yi
Project B
Asks a user 7 questions and grades them according to how many they get right.
*/

#include <iostream>
#include <string>

int main(){
    std::string texts[] = {
         "Given char arr[] = {\'A\', \'B\', \'C\'}, what is arr[1]?",
         "Given string arr[] = {\"Hello\", \"Hi\", \"Hey\"}, what is arr[2]?",
         "Given two double variables a and b, find out the return of a^b, that is,\n a raised to the powerof b. Hint: use pow function.",
         R"(Suppose n is properly declared and initialized as an integer. Write a
        statement to throw away the least significant digit from n. For example, if
        n is 12, after the statement, n changes to be 1.)",
        R"(Assume that n is properly declared and initialized. Write a statement to
        declare lastDigit as an integer and initialize it to be the least
        significant digit of integer n. Suppose n is 123, after the statement,
        lastDigit is 3.)",
        "What is the output?\n#include <iostream>\nusing namespace std;\n\nint main() {\n int count = 0;\n for (int i = -6; i < 2; i += 3)\n count++;\n\n cout << count << endl;\n return 0;\n}",
        R"(Write a condition to represent that char variable ch is none of the
        following: \'a\', \'b\', or \'c\'.)"
    };
    std::string ans[]= {
        "\'B\'",
        "\"Hey\"",
        "pow(a, b)",
        "n /= 10;",
        "int lastDigit = n % 10;",
        "3",
        "(ch != \'a\' && ch != \'b\' && ch != \'c\')"
    };
    std::string response;
    double total=0;
    
    for(std::size_t i = 0;i<size(ans);i++){
        std::cout<<"Question "<<i+1<<": "<<texts[i]<<"\n"<<"Enter your answer: ";
        std::getline(std::cin,response);
        if(response == ans[i]){
            std::cout<<"true"<<std::endl;
            total++;
        }else{
            std::cout<<"false"<<std::endl;
        }
    }

    double score=(total/7)*100;

    std::cout<<"\nnumber of correct problems: "<<total<<std::endl;
    std::cout<<"percentage of correct: "<<score<<"%"<<std::endl;

    if(total>=90){
        std::cout<<"excellent";
    }else if(total>=80){
        std::cout<<"good";
    }else if(total >=60){
        std::cout<<"pass";
    }else{
        std::cout<<"please ask help ASAP";
    }

    return 0;
}