#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#include "linked_list.h"


void link_list__test_free(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();

    assert(lnk->list_head == SENTINEL);

    link_list__free(lnk);
    printf("OK!\n\n");
}


void link_list__test_insert_tail(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();

    assert(lnk->list_head == SENTINEL);

    int value1 = 2;
    int value2 = 3;
    int value3 = 1;

    link_list__insert_tail(lnk, &value1);
    link_list__insert_tail(lnk, &value2);
    link_list__insert_tail(lnk, &value3);

    link_list__display(lnk);

    assert(lnk->list_head->value == (void *)&value1);
    assert(lnk->list_head->next->value == (void *)&value2);
    assert(lnk->list_head->next->next->value == (void *)&value3);
    assert(lnk->list_head->next->next->next == SENTINEL);

    link_list__free(lnk);
    printf("OK!\n\n");
}


void link_list__test_insert_head(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();

    assert(lnk->list_head == SENTINEL);

    int value1 = 4;
    int value2 = 2;
    int value3 = 1;

    link_list__insert_head(lnk, &value1);
    link_list__insert_head(lnk, &value2);
    link_list__insert_head(lnk, &value3);

    link_list__display(lnk);

    assert(lnk->list_head->value == (void *)&value3);
    assert(lnk->list_head->next->value == (void *)&value2);
    assert(lnk->list_head->next->next->value == (void *)&value1);
    assert(lnk->list_head->next->next->next == SENTINEL);

    link_list__free(lnk);
    printf("OK!\n\n");
}


void link_list__test_insert_after(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();

    assert(lnk->list_head == SENTINEL);

    int value1 = 4;
    int value2 = 2;
    int value3 = 1;

    link_list__insert_head(lnk, &value1);
    link_list__insert_after(lnk, lnk->list_head, &value2);
    link_list__insert_after(lnk, lnk->list_head, &value3);
    // 4, 1, 2

    link_list__display(lnk);

    assert(lnk->list_head->value == (void *)&value1);
    assert(lnk->list_head->next->value == (void *)&value3);
    assert(lnk->list_head->next->next->value == (void *)&value2);
    assert(lnk->list_head->next->next->next == SENTINEL);

    link_list__free(lnk);
    printf("OK!\n\n");
}


void link_list__test_remove_element(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();
    
    int value1 = 14;
    int value2 = 22;
    int value3 = 13;

    link_list__insert_head(lnk, &value1);
    link_list__insert_after(lnk, lnk->list_head, &value2);
    link_list__insert_after(lnk, lnk->list_head, &value3);
    // 14, 13, 22

    link_list__display(lnk);

    assert(lnk->list_head->value == (void *)&value1);
    assert(lnk->list_head->next->value == (void *)&value3);
    assert(lnk->list_head->next->next->value == (void *)&value2);
    assert(lnk->list_head->next->next->next == SENTINEL);

    link_list__remove_element(lnk, lnk->list_head);

    link_list__display(lnk);

    assert(lnk->list_head->value == (void *)&value3);

    int value4 = 44;
    int value5 = 55;
    
    link_list__insert_head(lnk, &value4);
    link_list__insert_head(lnk, &value5);

    link_list__display(lnk);

    link_list__remove_element(lnk, lnk->list_head);
    link_list__remove_element(lnk, lnk->list_head->next);

    assert(lnk->list_head->value == (void *)&value4);
    
    link_list__display(lnk);

    link_list__free(lnk);
    printf("OK!\n\n");
}


void link_list__test_remove_all_element(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();
    
    int values[5] = {22, 13, 15, 22, 13};
    for (int i = 0; i < 5; i++) {
        link_list__insert_head(lnk, &values[i]);
    }
    link_list__insert_head(lnk, &values[0]);

    link_list__display(lnk);

    link_list__remove_all_element(lnk, (void *)&values[0]);
    
    struct lelement *iterator = lnk->list_head;
    while (iterator != SENTINEL) {
        assert(iterator->value != (void *)&values[0]);
        iterator = iterator->next;
    }
    
    link_list__display(lnk);

    link_list__free(lnk);
    printf("OK!\n\n");
}


void link_list__test_clear(void) {
    printf("%s\n", __func__);

    struct link_list *lnk = link_list__init();
    
    int values[5] = {22, 13, 15, 22, 13};
    for (int i = 0; i < 5; i++) {
        link_list__insert_head(lnk, &values[i]);
    }

    link_list__display(lnk);

    link_list__clear(lnk);

    assert(lnk->list_head == SENTINEL);

    link_list__display(lnk);

    link_list__free(lnk);
    printf("OK!\n\n");
}


int main() {
    printf("%s\n", __FILE__);

    link_list__test_free();
    link_list__test_insert_tail();
    link_list__test_insert_head();
    link_list__test_insert_after();
    link_list__test_remove_element();
    link_list__test_remove_all_element();
    link_list__test_clear();

    return EXIT_SUCCESS;
}
