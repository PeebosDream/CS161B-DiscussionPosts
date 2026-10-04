#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//function prototypes
void takeInput(char userInput[21]); 
void print(char text[101], bool endLine, bool startLine);
void phraseLogic(char phraseNoSpace[21]);
bool isNumCode(char userNum[5]);
void numLogic(char userNum[5]);
void punctLogic(char punct[2]);
bool isPUNCTcode(char punct[2]);


int main () {
    char phrase[21];
    char code[5];
    char userPunct[2];
    char newPassword[21];
    char prompt[101];

    strcpy(prompt, "Greetings Password Monger");

    print(prompt, true, true);
    strcpy(prompt, "Please enter a word or phrase of your choice:");
    print(prompt, true, true);


    takeInput(phrase);
    phraseLogic(phrase);
    strcpy(newPassword, phrase);
    
    strcpy(prompt, "Input a 4 digit number:");
    print(prompt, true, true);
    numLogic(code);
    strcat(newPassword, code);

    strcpy(prompt, "Input a punctuation: ");
    print(prompt, true, true);
    punctLogic(userPunct);
    strncat(newPassword, userPunct, 1);

    strcpy(prompt, "Your safe password is: ");
    strcat(prompt, newPassword);
    print(prompt, true, true);

    
    return 0;
}
// punctuation 
void punctLogic(char punct[2]) {
    
    bool isPUNCT = false;
    char prompt[31] = "Incorrect input, try again!: ";
    while (!isPUNCT) {
        takeInput(punct);

        isPUNCT = isPUNCTcode(punct);
        if (!isPUNCT) {
            print(prompt, true, true);
        }
    }

}
bool isPUNCTcode(char punct[2]) {
   return ispunct(punct[0]);
}
// number
bool isNumCode(char userNum[5]) {
    int counter = 0;
    for (int i = 0; i < strlen(userNum); i++) {
        counter += int(isdigit(userNum[i]));
    }
    if (counter == 4) {
        return true;
    }
    return false;
}
void numLogic(char userNum[5]) {
    
    bool isNum = false;
    char prompt[31] = "Incorrect input, try again!: ";
    while (!isNum) {
        takeInput(userNum);
        isNum = isNumCode(userNum);
        if (!isNum) {
            print(prompt, true, true);
        }
    }

}
void phraseLogic(char phraseNoSpace[21]) {
    strtok(phraseNoSpace, " ");
}

void takeInput(char userInput[21]) {
    cin.getline(userInput,21);

}

void print(char text[101], bool endLine, bool startLine){
    if (startLine){
        cout << endl;
    }
    if (endLine){
        cout << text << endl;
        }
    else {
        cout << text;
    }
}
