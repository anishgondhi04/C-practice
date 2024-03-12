// Name: Anish Gondhi Assignment 3
// This code uses concept of linked_list to reassemble pieces of texts found at the Archeological digs.
// In this code I have created lists pointer L that contains no_of_segments taken from input stream and stored as
// linked_list_t l_list. These segments are combined using the overlap and splice functions
// For neat and tidy main function helper functions are used. It also helped in debugging for significant bigger input
// size.


#include <stdio.h>
#include "linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER 256

//struct segments uses pointers next and prev for pointing to itself to store prev and next node information
//each node has a value section that stores the linked_list that stores the single segment taken from input stream
typedef struct segments {
    struct segments *next;
    struct segments *prev;
    linked_list_t *value;
} segments;

//struct lists is designed to keep track of top of the lists in this case which is first segment and current l_list
//added to the L. Also it has a field to keep track of the length of the lists L.
typedef struct lists {
    segments *top;
    segments *current;
    int no_of_segments;
} lists;

//creates a new lists L and returns it.
static lists *lists_new() {
    lists *L = calloc(1, sizeof(lists));
    assert(L);

    return L;
}

//This function takes three argument containing values to prev and next nodes in Lists L and value l_list
//IT allocates memory to a new segment of type segments.
//it initializes all the fields in the newly created segment and returns the pointer.
static segments *new_segment(segments *prev, segments *next, linked_list_t *l_list) {

    segments *segment = calloc(1, sizeof(segments));
    assert(segment);
    segment->prev = prev;
    segment->next = next;
    segment->value = l_list;

    return segment;
}

//add_segment function is used to add new l_list to the back of L
static void add_segment(lists *L, linked_list_t *l_list) {
    assert(L);
    assert(l_list);

    segments *temp = new_segment(L->current, NULL, l_list);

    //checks if lists is empty
    if (L->top == NULL) {
        L->top = temp;
    } else {
        L->current->next = temp;
    }
    L->current = temp;
    L->no_of_segments++;
}

//print_segment takes a segment and prints all the words in value field using specified format requirement
//in assignment.
static void print_segment(segments *T) {

    //If segment is not NULL then
    if (T != NULL) {
        size_t len = 0;
        //this loop runs until T->value is empty
        while (T->value->size) {
            char *word = (char *) ll_remove_front(T->value);

            len = strlen(word) + 1 + len;
            printf("%s ", word);

            //checks if the printed string is more than 30 characters and it is not the end of output
            if (len > 30 && T->value->size != 0) {
                len = 0;
                printf("\n");
            }
        }
        printf("\n");

    }
}

//This function is used to remove a segment and maintain the structure of lists L.
static void remove_segment(lists *L, segments *segment) {
    assert(L);
    assert(segment);


    if (segment == L->top) {
        L->top = segment->next;
    } else {
        if (segment->next != NULL) {
            segment->next->prev = segment->prev;
        }
        if (segment->prev != NULL) {
            segment->prev->next = segment->next;
        }
    }
    L->no_of_segments--;
}

static int compare(void *s1, void *s2) {
    return strcmp(s1, s2);
}

int main() {

    //read one word at a time from input stream
    char *word = calloc(BUFFER, sizeof(char));
    assert(word);

    //L stores all the l_list
    lists *L = lists_new();
    linked_list_t *l_list = ll_new();

    //while we have input
    while (scanf("%256s", word)) {

        //if it is start of the segment, then check if the word is EOS
        //terminate the loop if it is, else add the word to the l_list using add_segment() function
        if (l_list->size == 0) {
            if (strcmp(word, "EOS") == 0) {
                break;
            } else {
                ll_add_back(l_list, word);
            }
        } else {
            //if list is not empty check if it is the end of the segment
            //in this case add the l_list to L and assign new memory to l_list
            if (strcmp(word, "EOS") == 0) {
                add_segment(L, l_list);
                l_list = ll_new();
            } else { //else normally add to the back of the l_list
                ll_add_back(l_list, word);
            }
        }

        //each iteration allocates new memory for word pointer
        word = calloc(BUFFER, sizeof(char));
        assert(word);
    }

    //if the L is not empty
    if (L->no_of_segments != 0) {

        //T is the first segment taken from L
        segments *T = L->top;

        //updating top and no_of_segments
        L->top = L->top->next;
        L->no_of_segments--;

        //This loop runs until there are no elements in L
        while (L->no_of_segments != 0 && T != NULL) {
            //S is the other segment taken from L
            segments *S = L->top;

            unsigned int max = 0;
            segments *temp;
            int flag;

            //this loops iterates throuth all the segment and finds the S with largest overlap to T
            while (S) {
                unsigned int TS = ll_overlap(T->value, S->value, &compare);
                unsigned int ST = ll_overlap(S->value, T->value, &compare);

                if (TS > max) {
                    max = TS;
                    temp = S;
                    flag = 0;
                }
                if (ST > max) {
                    max = ST;
                    temp = S;
                    flag = 1;
                }
                S = S->next;
            }
            S = temp;

            //if max_overlap is between TS then splice(T,S)
            //else it swaps the T with S using a new segment
            if (flag == 0) {
                ll_splice(T->value, S->value, max);
                remove_segment(L, S);
            } else if (flag == 1) {
                segments *segment = new_segment(S->prev, S->next, T->value);

                if (segment->next != NULL) {
                    segment->next->prev = segment;
                }
                if (segment->prev != NULL) {
                    segment->prev->next = segment;
                }
                if (S == L->top) {
                    L->top = segment;
                }
                if (S == L->current) {
                    L->current = segment;
                }

                T = S;
                S = segment;

                ll_splice(T->value, S->value, max);
                remove_segment(L, S);
            }
        }
        //printing to output stream
        print_segment(T);
    }

    free(L);
    return 0;
}
