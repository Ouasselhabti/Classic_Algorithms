#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

#include "linked_list.h"

int MAX_INT = INT_MAX;
int * const p = &MAX_INT;

const struct lelement sentinel = {p,
                                  (struct lelement *)&sentinel};

struct link_list *link_list__init() {
    struct link_list *head = malloc(sizeof(head));
    head->list_head = SENTINEL;
    return head;
}

int link_list__is_sentinel(const struct lelement *e) {
    return e == SENTINEL;
}

int link_list__insert_tail(struct link_list *lnk, void *element) {
    if (lnk->list_head == SENTINEL) {
        lnk->list_head = malloc(sizeof(struct lelement));
        lnk->list_head->value = element;
        lnk->list_head->next = SENTINEL;
        return 1;
    }
    struct lelement *new_element = malloc(sizeof(*new_element));
    new_element->value = element;
    new_element->next = NULL;

    struct lelement *iterator = lnk->list_head;
    while (iterator->next != SENTINEL) {
        iterator = iterator->next;
    }
    iterator->next = new_element;
    new_element->next = SENTINEL;
    return 1;
}

int link_list__insert_head(struct link_list *lnk, void *element) {
    struct lelement *new_element = malloc(sizeof(*new_element));
    new_element->value = element;
    struct lelement *saver = lnk->list_head;
    new_element->next = saver;
    lnk->list_head = new_element;
    return 1;
}

// We have data from any type so we can't use a dichotomic search algorithm.
int link_list__insert_after(struct link_list *lnk, struct lelement *element, void *new_element_value) {
    if (element == SENTINEL) {
        printf("Error: we can't add element after SENTINEL\n");
        return 0;
    }
    
    struct lelement *iterator = lnk->list_head;
    while (iterator != element && iterator != SENTINEL) {
        iterator = iterator->next;
    }
    if (iterator == SENTINEL) {
        printf("Error: we can't find the second argument. It doesn't exist in the linked list %p\n", lnk);
        return 0;
    }
    struct lelement *new_element = malloc(sizeof(*new_element));
    new_element->value = new_element_value;
    struct lelement *saver = iterator->next;
    iterator->next = new_element;
    new_element->next = saver;
    return 1;
}


int link_list__remove_element(struct link_list *lnk, struct lelement *element) {
    if (link_list__is_sentinel(element)) {
        printf("Error: can't remove sentinel\n");
        return 0;
    }
    else if (element == lnk->list_head) {
        struct lelement *element_saver = lnk->list_head;
        lnk->list_head = lnk->list_head->next;
        free(element_saver);
        return 1;
    }
    else {
        struct lelement *iterator = lnk->list_head;
        while (iterator != SENTINEL && iterator->next != element) {
            iterator = iterator->next; 
        }
        if (link_list__is_sentinel(iterator)) {
            printf("Error: we can't find the second argument. It doesn't exist in the linked list %p\n", lnk);
            return 0;
        }    
        struct lelement *element_saver = iterator->next;
        iterator->next = iterator->next->next;
        free(element_saver);
        return 1;
    }
}


int link_list__remove_all_element(struct link_list *lnk, void *element_value) {
    struct lelement *iterator = lnk->list_head;
    while (iterator != SENTINEL) {
        if (iterator->value == element_value) {
            struct lelement *element_saver = iterator;
            iterator = iterator->next;
            link_list__remove_element(lnk, element_saver);
        }
        else {
            iterator = iterator->next;
        }
    }
    return 1;
}

int link_list__free_elements(struct link_list *lnk) {
    if (lnk->list_head != SENTINEL) {
        struct lelement *saver = lnk->list_head->next;
        while (saver != SENTINEL) {
            free(lnk->list_head);
            lnk->list_head = saver;
            saver = saver->next;
        }
        free(lnk->list_head);
    }
    return 1;
}

int link_list__clear(struct link_list *lnk) {
    link_list__free_elements(lnk);
    lnk->list_head = SENTINEL;
    return 1;
}


int link_list__free(struct link_list *lnk) {
    link_list__free_elements(lnk);
    free(lnk);
    return 1;
}


// Works only with int values.
void link_list__display(struct link_list *lnk) {
    struct lelement *iterator = lnk->list_head;
    printf("[");
    while (iterator != SENTINEL) {
        printf("(adress: %p, value: %d), ", iterator->value, *((int *) iterator->value));
        iterator = iterator->next;
    }
    printf("sentinel: (adress: %p, value: %d)]\n", iterator, *((int *) iterator->value));
}
