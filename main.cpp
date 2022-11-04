

#include < iostream >

#include < conio.h >

#include <iostream>
#include <cstdlib>
#include <ctime>
#include<pugixml.hpp>
using namespace std;

int rule(char p, char c) {
    if (p == c) {
        return 0;
    }

    if (p == 'r' && c == 'p') {
        return -1;
    }
    else if (p == 's' && c == 'p') {
        return 1;
    }
    else if (p == 'p' && c == 'r') {
        return 1;
    }
    else if (p == 's' && c == 'r') {
        return -1;
    }
    else if (p == 'r' && c == 's') {
        return 1;
    }
    else if (p == 'p' && c == 's') {
        return -1;
    }

}

struct LanguageData {
    string Welcome ="";
    string Note = "";
    string Enter = "";
    string won ="";
    string loose ="";
    string tie ="";
    string PlayAgain ="";
    string exit ="";
    string rock ="";
    string paper ="";
    string scissor ="";
};

LanguageData languageData;

void ReadLanguage(std::string lang)
{
    pugi::xml_document language;
    pugi::xml_parse_result result = language.load_file("language.xml");
    if (!result) {
        return;
    }

    pugi::xml_object_range<pugi::xml_node_iterator> states = language.child("language").children();
    if (!result) {
        return;
    }

    pugi::xml_node_iterator languageIt;
    for (languageIt = states.begin(); languageIt != states.end(); languageIt++) {
        pugi::xml_node languageNode = *languageIt;

        pugi::xml_attribute category = languageNode.attribute("lang");
        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "Welcome")
            languageData.Welcome = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "Note")
            languageData.Note = languageNode.child_value();


        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "Enter")
            languageData.Enter = languageNode.child_value();


        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "won")
            languageData.won = languageNode.child_value();


        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "loose")
            languageData.loose = languageNode.child_value();


        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "tie")
            languageData.tie = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "PlayAgain")
            languageData.PlayAgain = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "exit")
            languageData.exit = languageNode.child_value();

        if(std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "rock")
            languageData.rock = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "paper")
            languageData.paper = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "scissor")
            languageData.scissor = languageNode.child_value();


    }
}

int main() {

    char computer;
    char player;
    char Playmore;

    string Welcome;
    string Note;
    string Enter;
    string won;
    string loose;
    string tie;
    string  PlayAgain;
    string exit;
    string rock;
    string paper;
    string scissor;
    int inputLanguage;

    cout << "\t\t\t\t";
    cout << "choose language press 1 for English";
    cout << "choose language press 2 for Arabic";
    cout << "choose language press 3 for Indian";
    cin >> inputLanguage;

    switch (inputLanguage)
    {
    case 1:
        ReadLanguage("eng");
        break;

    case 2:
        ReadLanguage("arb");
        break;
    case 3:
        ReadLanguage("ind");
        break;
    default:
        ReadLanguage("eng");
        break;
    }






    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "\t\t\t\t";
    cout << languageData.Welcome << endl;  //language options
    cout << "\t\t\t\t";
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "\t\t\t\t";
    cout << languageData.Note << endl;  //language options //Note
    cout << "\t\t\t\t";
    cout << "\t\t\t\t" << languageData.rock<< endl << "\t\t\t\t" << languageData.paper<< endl << "\t\t\t\t" <<  languageData.scissor  << endl << "\t\t\t\t" << endl << endl;  //language options //rock // Paper //Scissor
    cout << "\t\t\t\t";
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
    do {
        int number = 0;
        srand(time(0));        // initialized time to 0
        number = rand() % 100; // will choose a number in range 0 - 99
        // r - for rock
        // p - for paper
        // s - for scissors
        if (number < 33)
        {
            computer = 'r';
        }
        else if (number > 66)
        {
            computer = 's';
        }
        else
        {
            computer = 'p';
        }
        // cout << "Note: \"r\" for \"Rock\", \"p\" for \"Paper\", \"s\" for \"Scissor\"." << endl;
        cout << "\t\t\t\t";
        cout << languageData.Enter; //language options //Enter
        cin >> player;
        int result = rule(player, computer);
        if (result == 1) {
            cout << "\t\t\t\t";
            cout << languageData.won << endl; //language options //
        }
        else if (result == -1) {
            cout << "\t\t\t\t";
            cout << languageData.loose << endl; //language options
        }
        else {
            cout << "\t\t\t\t";
            cout << languageData.tie<< endl; //language options
        }
        cout << "\t\t\t\t";
        cout << languageData.PlayAgain << endl; //language options
        cout << "\t\t\t\t";
        cout << languageData.exit; //language options
        cin >> Playmore;
        cout << "\t\t\t\t";
        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl;
    } while(Playmore != 'n');

    return 0;
}