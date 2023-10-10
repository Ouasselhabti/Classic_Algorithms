#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


/**
 * lelement is an element of the linked list. It has a generic type (it 
 * could be a string or int ...)  and it contains a pointer to next 
 * lelement in the linked list. 
 */
struct lelement {
  void *value;
  struct lelement *next;
};



/**
 * link_list represent a linked list. It is a pointer to the first 
 * element of the linked list.
 */
struct link_list {
  struct lelement *list_head;
};


extern const struct lelement sentinel;

#define SENTINEL ((struct lelement *) &sentinel)


/**
 * Returns a pointer to the first element of the list.
 */
struct link_list *link_list__init();


/**
 * Retourns 1 if lelement is sentinel, otherwise it returns 0.
 */
int link_list__is_sentinel(const struct lelement *e);




// Insert functions

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__insert_tail(struct link_list *lnk, void *element);

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__insert_head(struct link_list *lnk, void *element);


/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__insert_after(struct link_list *lnk, struct lelement *element, void *new_element_value);



// Remove functions

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__remove_element(struct link_list *lnk, struct lelement *element);

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__remove_all_element(struct link_list *lnk, void *element_value);

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__remove_after(struct link_list *lnk, struct lelement *element);

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__clear(struct link_list *lnk);

/**
 * Returns 1 if successful, otherwise it returns 0.
 */
int link_list__free(struct link_list *lnk);


void link_list__display(struct link_list *lnk);

#endif // __LINKED_LIST_H__
