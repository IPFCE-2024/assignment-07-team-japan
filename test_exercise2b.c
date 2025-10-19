#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(void) {
    stack s;

    /* Law (1): After initialize(s); the stack s must be empty. */
    initialize(&s);
    assert(empty(&s) == true);
    printf("Law 1 passed\n");

    /* Law (2): push(x, s); y = pop(s); s must be same as before, and x == y. */
    initialize(&s);
    node *old_head = s.head;
    push(42, &s);
    int y = pop(&s);
    assert(y == 42) && "Law 2 failed: popped value does not match pushed value";
    assert(s.head) == old_head && "Law 2 failed: stack not restored to original state after push/pop";
    printf("Law 2 passed \n");


    /* Law (3): push(x0,s); push(x1,s); y0=pop(s); y1=pop(s); s same as before; x0==y1; x1==y0 */
    initialize(&s);
    push(7, &s);
    old_head = s.head;

    int x0 = 123;
    int x1 = 456;
    push(x0, &s);
    push(x1, &s);

    int y0 = pop(&s);
    int y1 = pop(&s);

    assert(s.head == old_head && "Law 3 failed: stack not restored after sequence of pushes/pops");
    assert(x0 == y1 && x1 == y0 && "Law 3 failed: LIFO wrong order");
    printf("Law 3 passed\n");

    printf("All stack law tests passed\n");
    return 0;
}
