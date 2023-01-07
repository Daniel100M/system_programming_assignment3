#define LINE 256
#define WORD 30


/**
 * Shifts first 'i' elements, one slot to the right.
*/
void shift_element(int* arr, int i);

/**
 * Sorts array in ascending order using 
 * 'insertion sort' algorithm.
*/
void insertion_sort(int* arr, int len);

/**
 * Output to console integers of array.
*/
void print_int_arr(int* arr, int len);

/**
 * Returns 1 if 'str2' is a sub-string of 'str1'.
 * Otherwise, returns 0.
*/
int substring(char *str1, char *str2);

/**
 * Returns 1 if string 't' can be produced out of string 's'
 * by deleting (exactly) 'n' characters from 's'.
 * Otherwise, returns 0.
*/
int similar(char *s, char *t, int n);

/**
 * Parameters:
 * - Two dimensional array of characters (text).
 * - String value (word to be searched for).
 * Prints:
 * - Lines which contain the parameter as sub-string.
*/
void print_lines(char text[][LINE], char key_value[]);

/**
 * Parameters:
 * - Two dimensional array of characters (text).
 * - String value (word to be searched for).
 * Prints:
 * - Words in text that are similar to given parameter.
*/
void print_similar_words(char text[][LINE], char key_value[]);

/**
 * Parameters:
 * - Two dimensional array to store text.
 * Functionality:
 * - Reads text as user input, line by line.
*/
void read_text(char text[][LINE]);

/**
 * Prints out to console contents of text file.
*/
void print_text(char text[][LINE]);

/**
 * Parameters:
 * - Array of characters representing a text line.
 * - Array of characters representing the key word.
 * Prints:
 * - Words in line that are similar to key string.
*/
void similar_words(char line[], char key_value[]);

/**
 * Parameters:
 * - Two dimensional array to be initialized.
 * Functionality:
 * - initializes array values to some default.
*/
void initialize_array(char arr[][LINE]);

/**
 * Parameters:
 * - Two dimensional array representing text.
 * - Array to store key string.
 * 
 * Functionality:
 * - Recieves key string from text.
 * - Assuming key is first word of first line in text.
*/
void get_key(char text[][LINE], char key[WORD]);

/**
 * Parameters:
 * - Two dimensional array representing text.
 * 
 * Return:
 * - Character representing the operation to be performed.
*/
char get_operation(char text[][LINE]);