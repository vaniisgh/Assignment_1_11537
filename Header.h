
#include <iostream>



using namespace std;


string file_name="sample.txt";

//functions used.
void show_menu();
void process_option(char a);
void count_probability(string search_string);
void dictionary_search(string search_string);
void count_paragraphs();
void dictionary_search(string search_string);
void Find_Pattern(string search_string, string main_string);
bool single_search(string search_string, string main_string);
void Longest_Proper_Prefix_Array(string search_string, int string_size, int lps[]);



void show_menu(){
    char choice ;
    cout << "Menu Options: " << endl;
    cout << "1. pattern Search" << endl;
    cout << "2. Count number of paragraphs" << endl;
    cout << "3. Dictionary Search" << endl;
    cout << "4. Probability of word in document" << endl;
    cout << "5. EXIT" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    string pattern_tomatch;
    getline(cin, pattern_tomatch);
    process_option(choice);
}


void count_probability(string search_string){
    ifstream file (file_name);
    int count_words = 0;
    if (file.is_open()){
        string word;
        char x ;
        word.clear();
        int total_words = 0;
        
        while ((x = file.get()) != EOF)
        {
            while ( x != ' ' && x !='\n')
            {
                word = word + x;
                if ((x = file.get()) == EOF){
                    break;
                }
            }
            total_words++;
            if (word.length()>0){
                if (single_search(search_string, word)){
                    count_words++;
                }
            }
            word.clear();
        }
        file.close();
        cout << "Total words = " << total_words << endl;
        cout << "Total occurances of selected string = " << count_words << endl;
        cout << "Probability = " << (count_words*100 / total_words) << " percent" <<endl;
    }else{
        cout << "Unable to open file" << endl;
    }
}


void dictionary_search(string search_string){
    ifstream file (file_name);
    cout << endl;
    cout << endl;
    cout << "If any word is found, it will be mentioned below: " << endl;
    int counter = 0;
    if (file.is_open()){
        string word = "";
        char x ;
        while ((x = file.get()) != EOF)
        {
            while ( x != ' ' && x !='\n')
            {
                word = word + x;
                if ((x = file.get()) == EOF){
                    break;
                }
            }
            if (word.length()>0){
                if (single_search(search_string, word)){
                    counter ++;
                    cout << word << endl;
                }
            }
            word = "";
        }
        file.close();
        if (counter == 0){
            cout << endl;
            cout << "No word found." << endl;
        }else{
            cout << endl;
            cout << "Total words found: " << counter << endl;
        }
    }
    else{
        cout << "Unable to open file" << endl;
    }
}




void count_paragraphs(){
    string line;
    bool found_something = false;
    ifstream file (file_name);
    if (file.is_open())
    {
        int count = 1;
        char ch;
        while((ch = file.get()) != EOF)
        {
            if(ch != '\n' && ch != ' ' && ch != '\t')
            {
                found_something = true;
                if ((ch = file.get()) != EOF){
                    if (ch == '\n')
                    {
                        if ((ch = file.get()) != EOF){
                            if (ch == '\n')
                            {
                                count += 1;
                            }
                        }
                    }
                }
            }
        }
        file.close();
        if (found_something) cout << "Total paragraph count = " << count<< endl;
        else cout << "No paragraphs found" << endl;
    }else{
        cout << "Unable to open file" << endl;
    }
}



void Find_Pattern(string search_string, string main_string){
    int string_size = search_string.length();
    int N = main_string.length();
    
    int lps[string_size];
    int j = 0;
    
    Longest_Proper_Prefix_Array(search_string, string_size, lps);
    
    int i = 0;
    
    while (i < N){
        if (search_string[j] == main_string[i])
        {
            j++;
            i++;
        }
        if (j == string_size)
        {
            cout << "Found given search string at index " << (i - j) << endl;
            j = lps[j-1];
        }
        else if (i < N && search_string[j] != main_string[i]){
            if (j != 0)
            {
                j = lps[j-1];
            }else{
                i = i + 1;
            }
        }
    }
}


bool single_search(string search_string, string main_string){
    int string_size = search_string.length();
    int N = main_string.length();
    
    int lps[string_size];
    int j = 0;
    
    Longest_Proper_Prefix_Array(search_string, string_size, lps);
    
    int i = 0;
    
    while (i < N){
        if (search_string[j] == main_string[i])
        {
            j++;
            i++;
        }
        if (j == string_size)
        {
            return true;
        }
        else if (i < N && search_string[j] != main_string[i]){
            if (j != 0)
            {
                j = lps[j-1];
            }else{
                i = i + 1;
            }
        }
    }
    
    return false;
}



void Longest_Proper_Prefix_Array(string search_string, int string_size, int lps[]){
    int len = 0;
    int i;
    
    lps[0] = 0;
    i = 1;
    
    while (i < string_size){
        if (search_string[i] == search_string[len])
        {
            len++;
            lps[i] = len;
            i++;
        }else{
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}