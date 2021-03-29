#include <iostream>
#include <string>
using namespace std;

string* create_words_array(string sentence, int& out_words_arr_size);
void print_words_array(const string arr[], int arr_size);

int main() {
    string sentence;

    cout << "Please enter a sentence:\n";
    getline(cin, sentence);

    int words_arr_size;
    string* words_arr = create_words_array(sentence, words_arr_size);
    
    print_words_array(words_arr, words_arr_size);

    delete [] words_arr;

    return 0;
}

string* create_words_array(string sentence, int& out_words_arr_size) {
    int start = 0, word_count = 0;
    string* words_arr = new string[sentence.length()];

    for (int end = 0; end < sentence.length(); end++) {
        if (sentence[end] == ' ') {
            words_arr[word_count++] = sentence.substr(start, end - start);
            start = end + 1;
        }
    }

    words_arr[word_count++] = sentence.substr(start);
    out_words_arr_size = word_count;

    return words_arr;
}

void print_words_array(const string arr[], int arr_size) {
    cout << "Words array: [";

    for (int i = 0; i < arr_size; i++) {
        cout << "\"" << arr[i] << "\"";

        if (i != arr_size - 1) {
            cout << ", ";
        }
    }

    cout << "]\n";
}
