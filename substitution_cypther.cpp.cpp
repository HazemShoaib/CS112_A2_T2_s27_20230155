// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: substitution_cypther.cpp
// Program Description: this code is a simple substitution cipher which works by placing a
//                      "key" in the beginning of a new alphabet then placing the rest of the letters
// Last Modification Date: 10/3/2024
// Author : Hazem Khaled


#include <iostream>
#include <string.h>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char encrypt_txt[50], decrypt_txt[50];
string letters = "";

string get_letters(){       //this function is used to make a new alphabet to substitute the letters with

    string  key = "";
    bool flag = true;
    int occurrence;

    while (
            (flag)
            || (key.size()>5)
            || (key == "\n")
            || occurrence >1){
        cout << "please enter your key from 5 letters with no repetition or special characters (',' , ';' , ''' , '\' ....etc):" << endl;
        cin >> key;

        for(int i=0; i<key.size(); i++){
            key[i] = tolower(key[i]);
            if (!isalpha(key[i])){          //here it checks if the the key meets the conditions in order to be valid
                flag = true;
                break;
            }

            else {
                flag = false;
            }
        }
        for(char ch:key){                   //here it checks if the the key has any reoccurring letters
            occurrence = count(key.begin(),key.end(), ch);
            if(occurrence>1)
                break;
        }

    }

    flag = false;
    letters += key;                     //it puts the key in the beginning of the alphabet
    for (int i=0; i<26; i++){           //then puts the remaining letters without repetition
        for (int r=0; r<letters.size(); r++){
            if (alpha[i] == letters[r]){
                flag = false;
                break;
            }
            else{
                flag = true;
            }

        }
        if (flag == true){
            letters += alpha[i];
            flag = false;
        }
    }

    return letters;
}


string encryption_simple(){

    string text = "";
    int n = 0;
    get_letters();
    while(text.empty()){
        cout << "please enter the text you want to encrypt:" << endl;
        cin.ignore(1, '\n');
        getline(cin, text);
    }
    for (int r=0; r<text.size(); r++){                          //it replaces every letter with its equivalent in the new alphabet
        text[r] = tolower(text[r]);
        for (int i=0; i<26; i++){
            if (text[r] == alpha[i]){
                encrypt_txt[r] += letters[i];
                n++;
            }
            else if (!isalpha(text[r])){
                encrypt_txt[r] = text[r];
                n++;
            }
        }
    }

    for (int i=0; i<30; i++){
        cout << encrypt_txt[i];
    }


    return encrypt_txt;
}

string decryption_simple(){

    string text = "";
    int n = 0;
    get_letters();
    while(text.empty()){
        cout << "please enter the text you want to decrypt:" << endl;
        cin.ignore(1, '\n');
        getline(cin, text);
    }
    for (int r=0; r<text.size(); r++){                      //it replaces every letter with its equivalent in the normal alphabet
        text[r] = tolower(text[r]);
        for (int i=0; i<26; i++){
            if (text[r] == letters[i]){
                decrypt_txt[r] += alpha[i];
                n++;
            }
            else if (!isalpha(text[r])){
                decrypt_txt[r] = text[r];
                n++;
            }
        }
    }

    for (int i=0; i<30; i++){
        cout << decrypt_txt[i];
    }


    return decrypt_txt;
}


int main(){

    int choice = 0;


    while (choice != 1 && choice != 2){
        cout << "please choose one of the two choices" << "\n" << "1.encrypt" << "\n" << "2.decrypt" << endl;
        cin >> choice;

        if (choice == 1){
            encryption_simple();
        }
        else if (choice == 2){
            decryption_simple();
        }
    }
    return 0;

}

