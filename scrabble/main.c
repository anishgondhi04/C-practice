// Name: Anish Gondhi 
// Course: CSCI 2122 Assignment 1 
/* This program helps the scrabble players to place words correctly
   on the board */

#include <stdio.h>
#include <string.h>

static int first = 1; //static variable to check if the word is first word to be placed on board
static int n = 0; //To keep track of the size of the board

// printboard function will print the board
static void printboard(char board[n][n]){

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

//placeWord function will take the word and add it to the board character by character
static void placeWord(char board[n][n], char* word,int row_loc, int column_loc, char direction){

    int len = strlen(word);

    //checking if the word needs to be placed Vertically or Horizontally
    if(direction == 'V') {
        for (int i = 0; i < len; ++i) {
            board[row_loc++][column_loc] = word[i];
        }
    }else if (direction == 'H') {
        for (int i = 0; i < len; ++i) {
            board[row_loc][column_loc++] = word[i];
        }
    }
}

//validate function is used to check if the word placement is according to the rules
//There is special case if the first word is being placed it will only check if the word is not exceeding board length
static int validate(char board[n][n], char* word, int row_loc, int column_loc, char direction){

    int len = strlen(word);

    //In both cases it will check if the word is the first to be placed and if it is then, it will set first to 0
    //In else condition if there is a common letter between already existing word then function will return 1

    if(direction == 'V'){
        if( len + row_loc > n){
            return 0;
        }else if(first == 1){
            first = 0;
            return 1;
        }else{
            for (int i = 0; i < len; ++i) {
                if(board[row_loc++][column_loc] == word[i]){
                    return 1;
                }
            }
        }

    }else if(direction == 'H'){
        if( len + column_loc > n){
            return 0;
        }else if(first == 1){
            first = 0;
            return 1;
        }else{
            for (int i = 0; i < len; ++i) {
                if(board[row_loc][column_loc++] == word[i]){
                    return 1;
                }
            }
        }
    }

    return 0;
}

//This function checks the possible location where the word with given character can be placed
//It checks if the word bounds are in the size of board
//It also checks if there is enough space for the word
static void whereToPlace(char board[n][n],int before, char character, int after){

    //n*n for loop to check with each character on the board
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            //if the character and board character at position i and j are equal
            if(board[i][j] == character){

                //if the word is out of bound when trying place Vertically
                if((i - before >= 0) && (i + after < n)){
                    int flag = 0;                              //keeping track of the status to print the location
                    for (int k = i-1; k >= i - before ; --k) {
                        if(board[k][j]!='.'){
                            flag++;
                        }
                    }
                    for (int k = i+1; k <= i + after; ++k) {
                        if(board[k][j]!='.'){
                            flag++;
                        }
                    }
                    if(flag == 0){                      //location is only printed when the board has space for word
                        printf("Place vertically at (%d,%d)\n",j,i); // (i -> Y_axis) (j -> X_axis)
                    }
                }
                //if the word is out of bound when trying place Horizontally
                if((j - before >= 0) && (j + after < n)){
                    int flag = 0;
                    for (int k = j-1; k >= j - before ; --k) {
                        if(board[i][k]!='.'){
                            flag++;
                        }
                    }
                    for (int k = j+1; k <= j + after; ++k) {
                        if(board[i][k]!='.'){
                            flag++;
                        }
                    }
                    if(flag == 0){
                        printf("Place horizontally at (%d,%d)\n",j,i);
                    }
                }
            }
        }
    }
}

int main()
{
    // n is the size of the board N x N
    // w is the no of words, added to the board
    // x coordinate of the first character of the word
    // y coordinate of the first character of the word
    // f is a pointer, and it will be 0 indicating lowercase words

    int w,x,y,f;

    scanf("%d",&n);      // taking input in n
    scanf("%d",&w);       // taking input in w

    // d is the direction in which word is written V 'vertically' or H 'horizontally'
    // s is the word
    // board is 2D array representing game board
    char d, s[n], board[n][n];

    // initializing the board with '.'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = '.';
        }
    }

    //taking input for all the words and placing them on the board
    for (int i = 0; i < w; ++i) {
        scanf("%d %d %c %s",&x,&y,&d,s);

        int validity = validate( board,s,y,x,d);

        if(validity == 1){
            placeWord( board, s,y,x,d);
        }else if(validity == 0) {
            printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s);
        }
    }

    scanf("%d",&f);

    printboard(board);

    //This condition runs only if the user enters any words to checked to know where they can be placed
    if( f > 0 ){

        //before is the space required before the character
        //after is the space required after the character
        //character of the word to be placed
        int before,after;
        char character;

        //for loops takes the input for f times and calls whereToPlace function to print the location
        for (int i = 0; i < f; ++i) {

            scanf("%d %c %d",&before,&character,&after);

            whereToPlace(board, before, character, after);
        }
    }

    return 0;
}
