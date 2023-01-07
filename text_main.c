#include <stdio.h>
#include <string.h>
#include "methods.h"

#define WORD 30
#define LINE 256

int main(){

    char text[250][LINE]; // Will hold text recieved as user input.

    initialize_array(text);
    read_text(text);

    char key[WORD]; // String value to be compared with words in text.
    get_key(text, key);

    char operation = get_operation(text);

    if (operation == 'a') print_lines(text, key);

    else print_similar_words(text, key);

    return 0;
}

