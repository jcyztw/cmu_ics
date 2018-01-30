/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
	if (q != NULL) {
		q->head = NULL;
		q->tail = NULL;
		q->size = 0;
	}
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */
	if (q != NULL) {
		list_ele_t *tmp, *tmp_pre;
		tmp = q->head;
		while (tmp != NULL) {
			tmp_pre = tmp;
			tmp = tmp->next;
			free(tmp_pre);
		}
    	free(q);
	}
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
	if (q == NULL)
		return false;
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
	if (newh == NULL)
		return false;
    newh->value = v;
    newh->next = q->head;
	if (q->head == NULL)
		q->tail = newh;
    q->head = newh;
	q->size += 1;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
	list_ele_t *newt;
	if (q == NULL)
		return false;
	newt = malloc(sizeof(list_ele_t));
	if (newt == NULL)
		return false;
	newt->value = v;
	newt->next = NULL;
	q->tail->next = newt;
	q->tail = newt;
	q->size += 1;
	return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
	if (q == NULL || (q != NULL && q->head == NULL))
		return false;
	else {
		list_ele_t *discarded = q->head;
		if (vp != NULL)
			*vp = q->head->value;
    	q->head = q->head->next;
		q->size -= 1;
		free(discarded);
    	return true;
	}
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
	return (q == NULL || (q != NULL && q->head == NULL)) ? 0 : q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
	if (q != NULL) {
		list_ele_t *prev, *curr, *next, *orig_tail, *orig_head;
		orig_head = q->head;
		orig_tail = q->tail;
		prev = NULL;
		curr = q->head;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		q->head = orig_tail;
		q->tail = orig_head;
	}
}

