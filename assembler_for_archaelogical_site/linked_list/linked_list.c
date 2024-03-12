//
// Created by Alex Brodsky on 2023-09-20.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linked_list.h"

extern linked_list_t *ll_new() {
    linked_list_t *list = calloc(1, sizeof(linked_list_t));
    return list;
}

extern void ll_destroy(linked_list_t *list) {
    assert(list != NULL);
    while (list->head != NULL) {
        ll_node_t *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }

    free(list);
}

static ll_node_t *new_node(void *item, ll_node_t *prev, ll_node_t *next) {
    ll_node_t *n = calloc(1, sizeof(ll_node_t));
    if (n != NULL) {
        n->item = item;
        n->prev = prev;
        n->next = next;
    }
    return n;
}


extern int ll_add_front(linked_list_t *list, void *item) {
    assert(list);

    ll_node_t *n = new_node(item, NULL, list->head);
    if (n != NULL) {
        if (list->tail == NULL) {
            list->tail = n;
        } else {
            list->head->prev = n;
        }
        list->head = n;
    }
    list->size++;
    return n != NULL;
}

extern int ll_add_back(linked_list_t *list, void *item) {
    assert(list);

    ll_node_t *n = new_node(item, list->tail, NULL);
    if (n != NULL) {
        if (list->head == NULL) {
            list->head = n;
        } else {
            list->tail->next = n;
        }
        list->tail = n;
    }
    list->size++;
    return n != NULL;
}

extern void *ll_remove_front(linked_list_t *list) {
    assert(list);

    void *item = NULL;
    if (list->head != NULL) {
        ll_node_t *n = list->head;
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;
        } else {
            list->head->prev = NULL;
        }

        item = n->item;
        free(n);
    }
    list->size--;
    return item;
}

extern void *ll_remove_back(linked_list_t *list) {
    assert(list);

    void *item = NULL;
    if (list->tail != NULL) {
        ll_node_t *n = list->tail;
        list->tail = list->tail->prev;
        if (list->tail == NULL) {
            list->head = NULL;
        } else {
            list->tail->next = NULL;
        }

        item = n->item;
        free(n);
    }
    list->size--;
    return item;
}

extern void *ll_get_front(linked_list_t *list) {
    assert(list);

    void *item = NULL;
    if (list->head != NULL) {
        item = list->head->item;
    }
    return item;
}

extern void *ll_get_back(linked_list_t *list) {
    assert(list);

    void *item = NULL;
    if (list->head != NULL) {
        item = list->tail->item;
    }
    return item;
}

extern unsigned int ll_size(linked_list_t *list) {
    assert(list);

    return list->size;
}

extern int ll_is_empty(linked_list_t *list) {
    assert(list);
    return list->head == NULL;
}

extern int ll_insert(linked_list_t *list, ll_node_t *node, void *item) {
    assert(list);
    assert(node);

    if (node->next == NULL) {
        assert(list->tail == node);
        return ll_add_back(list, item);
    } else {
        ll_node_t *n = new_node(item, node, node->next);
        if (n != NULL) {
            node->next->prev = n;
            node->next = n;
        }
        list->size++;
        return n != NULL;
    }
}


extern void *ll_remove(linked_list_t *list, ll_node_t *node) {
    assert(list);
    assert(node);

    if (node->prev == NULL) {
        assert(list->head == node);
        return ll_remove_front(list);
    } else if (node->next == NULL) {
        assert(list->tail == node);
        return ll_remove_back(list);
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        void *item = node->item;
        free(node);
        list->size--;
        return item;
    }
}

/************************************************************************
 * Your code below
 ************************************************************************/

// This Function takes two linked lists and a compare function pointer as arguments.
// ll_overlap will check if there is any intersection between last set of words in list1 and first set of words in list2
// It returns zero if there is no overlap
// It returns the size of list2 if the set of words in list2 are subset of list1
extern unsigned int ll_overlap(linked_list_t *list1, linked_list_t *list2,
                               int (*compare)(void *, void *)) {
    // Your Code Here
    assert(list1);
    assert(list2);
    int overlap = 0;


    //checks if either of List1 or list2 is empty
    if (list1->head != NULL && list2->head != NULL) {

        ll_node_t *node1 = list1->head;
        ll_node_t *node2 = list2->head;


        //This while loop continues until it reaches the end of list1
        while (node1 != NULL) {

            //checks if list2 is empty and returns overlap (subset condition)
            if(!node2){
                return overlap;
            }

            int result = compare(node1->item, node2->item);

            //checks if two nodes/words are same
            if (!result) {
                node1 = node1->next;
                node2 = node2->next;
                overlap++;

                //checks if list2 is empty and returns overlap (subset condition)
                if (node2 == NULL && node1 != NULL) {
                    return overlap;
                }

            } else {
                //if node2 is at list2 head, then move node1 to next node.
                //else set node2 to list2->head
                if (node2 == list2->head) {
                    node1 = node1->next;
                    overlap = 0;
                } else {
                    node2 = list2->head;
                    overlap = 0;
                }
            }

        }
    }

    return overlap;
}

//This function takes two lists and concatenates the list2 in list1 using overlap
extern void ll_splice(linked_list_t *list1, linked_list_t *list2,
                      unsigned int overlap) {
    // Your Code Here
    assert(list1);
    assert(list2);

    //checks if the size of list2 is same as overlap that means list2 is substring of list1
    if (list2->size == overlap){
        return;
    }

    //if overlap is zero then we can assume that either list1 is empty or they don't empty intersection set.
    if (overlap == 0) {
        if (list2->head != NULL) {
            ll_node_t *node = list2->head;
            while (node) {
                ll_add_back(list1, node->item);
                node = node->next;
            }

            while (list2->size){
                ll_remove_back(list2);
            }
        }
    } else { //if overlap is not zero we can move node to the next word after overlaped words and start adding it to
        // list1
        ll_node_t *node = list2->head;
        for (int i = 0; i < overlap && node != NULL; ++i) {
            node = node->next;
        }
        while (node) {
            ll_add_back(list1, node->item);
            node = node->next;
        }

        //removing overlaped words from list2
        while (list2->size > overlap){
            ll_remove_back(list2);
        }
    }


}
