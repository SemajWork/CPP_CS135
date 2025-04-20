#include <iostream>
#include <string>
#include <fstream>
#include <string_view>
#include <algorithm>
#include <vector>

struct Question {
    std::string text;
    std::string answer;
    std::string explanation;
    std::string version;
    std::string type;
    std::string label;
};

std::string finalgrade(double num) {
    if (num >= 90) {
        return "excellent";
    } else if (num >= 80) {
        return "good";
    } else if (num >= 60) {
        return "pass";
    } else {
        return "please ask help ASAP";
    }
}

std::ifstream openFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "file can't be opened" << std::endl;
        exit(1);
    }
    return file;
}

double questioncounter(std::ifstream& file) {
    std::string text;
    double count = 0.0;
    while (std::getline(file, text)) {
        if (text.find("question:") != std::string::npos) {
            count++;
        }
    }
    file.clear();
    file.seekg(0);
    return count;
}

void startswith(std::string& text, const std::string& line) {
    if (line.rfind("question", 0) == 0) {
        text = "question";
    } else if (line.rfind("answer", 0) == 0) {
        text = "answer";
    } else if (line.rfind("explanation", 0) == 0) {
        text = "explanation";
    } else if (line.rfind("version", 0) == 0) {
        text = "version";
    } else if (line.rfind("label", 0) == 0) {
        text = "label";
    } else if (line.rfind("type", 0) == 0) {
        text = "type";
    }
}

void resetwords(Question& q) {
    q.text.clear();
    q.answer.clear();
    q.explanation.clear();
    q.version.clear();
    q.label.clear();
    q.type.clear();
}

// Inputs parses through a text file and inputs elements into an array
void arrayholder(std::vector<std::string>& arr, std::ifstream& fin, Question& q) {
    std::string test;
    std::string holder;
    while (std::getline(fin, holder)) {
        startswith(test, holder);
        if (test == "question") {
            q.text += holder + "\n";
        } else if (test == "answer") {
            if (holder.length() >= 8) {
                q.answer += holder.substr(8);
            } else {
                std::cerr << "Error: 'answer' line too short: " << holder << std::endl;
            }
        } else if (test == "explanation") {
            q.explanation += holder + "\n";
        } else if (test == "version") {
            q.version += holder;
        } else if (test == "label") {
            q.label += holder;
        } else if (test == "type") {
            if (holder.length() >= 6) {
                q.type += holder.substr(6);
            } else {
                std::cerr << "Error: 'type' line too short: " << holder << std::endl;
            }
            arr.push_back(q.text);
            arr.push_back(q.answer);
            arr.push_back(q.explanation);
            arr.push_back(q.version);
            arr.push_back(q.label);
            arr.push_back(q.type);
            resetwords(q);
        }
    }
}

// Bubble sorts the array according to their indexes
void arraysort(std::vector<std::string>& arr) {
    int len = arr.size();
    for (int i = len - 6; i >= 5; i -= 6) {
        for (int j = i; j >= 5; j -= 6) {
            if (arr[j] > arr[j + 6]) {
                std::swap(arr[j], arr[j + 6]);
                std::swap(arr[j - 1], arr[j + 5]);
                std::swap(arr[j - 2], arr[j + 4]);
                std::swap(arr[j - 3], arr[j + 3]);
                std::swap(arr[j - 4], arr[j + 2]);
                std::swap(arr[j - 5], arr[j + 1]);
            }
        }
    }
}

void typestuff(const std::vector<std::string>& arr, std::vector<std::string>& types, Question& q) {
    for (size_t i = 5; i < arr.size(); i += 6) {
        std::size_t found = arr[i].find_first_not_of(" ");
        if (found != std::string::npos) {
            q.text = arr[i].substr(found);
            if (q.text.find(";") != std::string::npos) {
                found = q.text.find(";");
                std::string first = q.text.substr(0, found);
                std::string second = q.text.substr(found + 1);
                if (std::find(types.begin(), types.end(), first) == types.end()) types.push_back(first);
                if (std::find(types.begin(), types.end(), second) == types.end()) types.push_back(second);
            } else {
                if (std::find(types.begin(), types.end(), q.text) == types.end()) types.push_back(q.text);
            }
        }
    }

    std::sort(types.begin(), types.end());
}

// Prompts user with type of question they want according to input file
int main() {
    Question q;
    std::vector<std::string> arr;
    std::vector<std::string> types;
    std::string fileName;
    std::cout << "Which file do you want? (cs135_midterm_f24_v2.txt or civics_65_20.txt): ";
    std::cin >> fileName;
    std::ifstream fin(openFile(fileName));
    double question = questioncounter(fin);
    arrayholder(arr, fin, q);
    arraysort(arr);
    typestuff(arr, types, q);

    int correct = 0;
    double grade = correct / question * 100;
    for (const auto& type : types) {
        std::cout << type << std::endl;
    }
    std::cout << "number of correct problems: " << correct << std::endl;
    std::cout << "percentage of correct: " << grade << "%" << std::endl;
    std::cout << finalgrade(grade) << std::endl;
    return 0;
}