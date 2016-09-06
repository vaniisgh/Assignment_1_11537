
#include <iostream>
#include <string.h>
#include <fstream>//header for file-handling.
#include <stdlib.h>

#include "Header.h"


using namespace std;




int main()
{
    cout<<"enter name of the file";
    cin>>file_name;
    
    ifstream ifs(file_name);               //ifs : ifilestream
    string main_string;
    main_string.assign( (istreambuf_iterator<char>(ifs) ),
                   (istreambuf_iterator<char>()    ) );
    
    cout<<main_string;
    
    show_menu();
    return 0;
}



void process_option(char choice){
    string search_string;
    string main_string;
    switch (choice){
        case '0':
            show_menu();
            break;
        case '1':
            cout << "For Pattern Search." << endl;
            cout << "Enter sub string to be searched" << endl;
            getline(cin, search_string);
            Find_Pattern(search_string, main_string);
            cout << endl;
            cout << endl;
            show_menu();
            break;
        case '2':
            cout << endl;
            count_paragraphs();
            cout << endl;
            cout << endl;
            show_menu();
            break;
        case '3':
            cout << endl;
            cout << "Enter the string you want to use for dictionary search" << endl;
            cin >> search_string;
            dictionary_search(search_string);
            cout << endl;
            cout << endl;
            show_menu();
            break;
        case '4':
            cout << endl;
            cout << "Enter the string you want to get probability of" << endl;
            cin >> search_string;
            count_probability(search_string);
            cout << endl;
            cout << endl;
            show_menu();
            break;
        case '5':
            cout << endl;
            cout << endl;
            cout << "Bye!" << endl;
            cout << endl;
            cout << endl;
            exit(0);
            break;
    }
}

