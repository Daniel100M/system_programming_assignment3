#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

/* First section, insertion-sort functions */




void shift_element(int* arr, int i){

    int *pointer = arr;

    int counter = 0; /* Used to iterate over array elements. */

    int save;
    int src; /* Used for shifting. */

    /* Shifting 'i' elements to the right. */
    while (counter < i){

        if (counter == 0) src = *pointer;

        else src = save;
        
        save = *(pointer + 1); /* Saving element before it is over-written. */

        *(pointer + 1) = src; /* Shift. */
        
        counter++;
        pointer++;
    }

    *arr = save; /* Placing over-written element at the 'empty' spot. */
}

void insertion_sort(int* arr, int len){

    /* Used to iterate over array items. */
    int *pointer = arr;

    /* Determines which elements to shift. */
    int *sub_pointer;

    /* Counts how many elements of array should be shifted. */
    int counter = 0;

    /* Compare this value with previous array elements.
        Check if a shift is required. */
    int check_value;

    /* Iterating over array. Sorting process. */
    while (pointer < arr + (len-1)){

        check_value = *(pointer + 1); 

        sub_pointer = pointer;

        while (*sub_pointer > check_value){
            
            counter++;

            /* Checking that pointer is within array bounds.
            Moving pointer only if necessary. */
            if (sub_pointer != arr) sub_pointer--;

            else break;
        }

        /* Making final pointer adjustment if required. */
        if (*sub_pointer <= check_value) sub_pointer++;

        /* Shift only if necessary. */
        if (counter > 0){
            shift_element(sub_pointer, counter);
        }
        
        pointer++;
        counter = 0; /* Restart counter for next shift. */
    }
}







/* Second section, text functions */



// Base functions:

int substring(char *str1, char *str2){

    int len2 = strlen(str2);

    char *p = str1; // Used to check different sub-strings of 'str1'.
    while (*(p + (len2 - 1)) != '\0'){

        char value[len2]; // Saves sub-string of 'str1'.
        strncpy(value, p, len2);

        if (strcmp(value, str2) == 0) return 1;

        p++;
    }

    return 0;
}

int similar(char *s, char *t, int n){

    int s_len = strlen(s);
    int t_len = strlen(t);

    if (t_len > s_len) return 0;

    char *s_point = s; // iterate over characters of 's'.
    char *t_point = t; // iterate over characters of 't'.

    int counter = 0; // counts in how many chars 's' and 't' differ.

    while(counter <= n){
        
        // in-bounds check.
        if (*s_point == '\0' || *t_point == '\0') break;

        if (*s_point != *t_point){
            counter++;
        } else {
            t_point++;
        }

        s_point++;
    }

    if (counter > n) return 0;

    if (*t_point == '\0') t_point--;

    while (*s_point != '\0'){

        counter++;
        if (counter > n) return 0;

        s_point++;
    }

    // Two strings must be identical by this point (same length).
    if (s_len - counter != t_len) return 0;

    return 1;
}


// Input method:

void read_text(char text[250][LINE]){

    int line = 0, col = 0; // Index values to read text as user input.
    int empty_lines = 0; // Counts amount of empty lines.

    while (line < 250 && empty_lines < 2){
        
        col = 0; // Reset index before reading input for new line.
        while(col < LINE){
        
            scanf("%c", &text[line][col]);

            if (text[line][col] == '\n') {
                // Reached end of line.
                text[line][col + 1] = '\0'; 

                if (col == 0) empty_lines++;
                break;
            }
            col++;
        }    
        line++;
    }    
}



// Assistant functions:

void similar_words(char line[], char key_value[]){

    char word[WORD]; // Stores a word in line.
    int length = 0; // Stores logical length of a word.

    int index = 0; // Used to iterate over characters in line.
    while (line[index] != '\0'){

        if (line[index] == ' ' || line[index] == '\t' || line[index] == '\n'){
            // Reached end of a word in line.
            strncpy(word, line + (index - length), length);
            word[length] = '\0';

            if (similar(word, key_value, 1)) printf("%s\n", word);

            length = 0; // Re-calculating length of next word.
        }

        else length++;

        index++;
    }
}

void get_key(char text[250][LINE], char key[WORD]){

    int length = 0; // Logical length of key.

    while (text[0][length] != ' ' && text[0][length] != '\t') length++;

    strncpy(key, text[0], length);
    key[length] = '\0';
}

char get_operation(char text[250][LINE]){

    int index = 0; // Used to iterate over first line of text.

    while (text[0][index] != ' ' && text[0][index] != '\t') index++;

    return text[0][index + 1];
}



// Main assignment methods:

void print_similar_words(char text[250][LINE], char key_value[WORD]){

    int line_index = 2; // Used to iterate through lines of text.

    while (text[line_index][0] != '\n'){

        similar_words(text[line_index], key_value); // Printing similar words in this line.
        line_index++;
    }
}

void print_lines(char text[250][LINE], char key_value[WORD]){

    int line_index = 2; // Used to iterate through lines of text.

    while (text[line_index][0] != '\n'){

        if (substring(text[line_index], key_value)) printf("%s", text[line_index]);
        line_index++; // Advancing to next line.
    }

}



// Additional methods:

void print_text(char text[250][LINE]){

    int empty_lines = 0; // Counts how many empty lines are in text.

    for (size_t i = 0; i < 250 && empty_lines < 2; i++)
    {
        if (text[i][0] == '\n') empty_lines++;

        printf("%s", text[i]);
    }
    
}

void initialize_array(char arr[250][LINE]){

    int line_index = 0, col_index = 2; // Index values to iterate over array.

    while (line_index < 250){
        
        arr[line_index][0] = '\n';
        arr[line_index][1] = '\0';

        while (col_index < LINE){

            arr[line_index][col_index] = 'q'; // Initializing to some arbitrary character.
            col_index++;
        }

        col_index = 2; // Reset for next line.
        line_index++;
    }
}

void print_int_arr(int* arr, int len){

    int *p = arr;

    while (p < arr + (len-1)){
        printf("%d,", *p);
        p++;
    }
    printf("%d\n", *p);
}
