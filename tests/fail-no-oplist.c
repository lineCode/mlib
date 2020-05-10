#include "m-core.h"

#if !defined(TEST)
# warning Please define TEST variable to select the test to run

#elif TEST == 1

/* Test of the call to no default function */
#define OP (INIT(init))

void f(int x, int y) {
  M_CALL_SWAP(OP, x, y);
}

#elif TEST == 2

void f(int x, int y) {
  M_CALL_SET(M_VALID_OPLIST(DEFAULT_OPLIST), x, y);
}
     
#elif TEST == 3

#include "m-array.h"
ARRAY_DEF(array, int, DEFAULT_OPLIST)

#elif TEST == 4

#include "m-list.h"
LIST_DEF(list, int, DEFAULT_OPLIST)

#elif TEST == 5

#include "m-list.h"
LIST_DUAL_PUSH_DEF(list, int, DEFAULT_OPLIST)

#elif TEST == 6

#include "m-deque.h"
DEQUE_DEF(deque, int, DEFAULT_OPLIST)

#elif TEST == 7

#include "m-i-list.h"
typedef struct tmp_str_s {
  ILIST_INTERFACE(tmpstr, struct tmp_str_s);
  int n;
} tmp_str_t;
ILIST_DEF(tmpstr, tmp_str_t, DEFAULT_OPLIST)

#elif TEST == 8

#include "m-string.h"
void f(void)
{
  M_LET(x, M_STRING_OPLIST) {
  }
}

#elif TEST == 9

#include "m-string.h"
typedef string_t my_type;
#define M_OPL_my_type() MSTRING_OPLIST
void f(void)
{
  M_LET(x, my_type) {
  }
}

#elif TEST == 10

void f(void)
{
  M_LET(x, () ) {
  }
}

#elif TEST == 11

#include "m-algo.h"
#include "m-array.h"

ARRAY_DEF(array, int)
ALGO_DEF(array, M_ARRAY_OPLIST(array))

#elif TEST == 12

#include "m-algo.h"
#include "m-array.h"

ARRAY_DEF(array, int)
ALGO_DEF(array, (OPLIST(array)))

#elif TEST == 13

#include "m-bptree.h"

BPTREE_DEF2(tree, 4, int, M_DEFAULT_OPLIST, int, DEFAULT_OPLIST)

#elif TEST == 14

#include "m-bptree.h"

BPTREE_DEF2(tree, 4, int, DEFAULT_OPLIST, int, M_DEFAULT_OPLIST)

#elif TEST == 15

#include "m-bptree.h"

BPTREE_DEF(tree, 4, int, DEFAULT_OPLIST)

#elif TEST == 16

#include "m-bptree.h"

BPTREE_MULTI_DEF2(tree, 4, int, DEFAULT_OPLIST, int, M_DEFAULT_OPLIST)

#elif TEST == 17

#include "m-bptree.h"

BPTREE_MULTI_DEF(tree, 4, int, DEFAULT_OPLIST)

#elif TEST == 18

#include "m-buffer.h"

BUFFER_DEF(buffer, int, 0, BUFFER_QUEUE, DEFAULT_OPLIST)

#elif TEST == 19

#include "m-buffer.h"

QUEUE_MPMC_DEF(buffer, int, BUFFER_QUEUE, DEFAULT_OPLIST)

#elif TEST == 20

#include "m-buffer.h"

QUEUE_SPSC_DEF(buffer, int, BUFFER_QUEUE, DEFAULT_OPLIST)

#elif TEST == 21

#include "m-array.h"
#include "m-concurrent.h"

ARRAY_DEF(array, int)
CONCURRENT_DEF(lock_array, array_t, M_ARRAY_OPLIST(array))

#elif TEST == 22

#include "m-array.h"
#include "m-concurrent.h"

ARRAY_DEF(array, int)
CONCURRENT_RP_DEF(lock_array, array_t, MARRAY_OPLIST(array))

#elif TEST == 23

#include "m-dict.h"

DICT_DEF2(array, int, M_DEFAULT_OPLIST, int, DEFAULT_OPLIST)

#elif TEST == 24

#include "m-dict.h"

DICT_DEF2(array, int, DEFAULT_OPLIST, int, M_DEFAULT_OPLIST)

#elif TEST == 25

#include "m-dict.h"

DICT_STOREHASH_DEF2(array, int, DEFAULT_OPLIST, int, M_DEFAULT_OPLIST)

#elif TEST == 26

#include "m-dict.h"

DICT_STOREHASH_DEF2(array, int, M_DEFAULT_OPLIST, int, DEFAULT_OPLIST)

#elif TEST == 27

#include "m-dict.h"

DICT_OA_DEF2(array, int, DEFAULT_OPLIST, int, M_DEFAULT_OPLIST)

#elif TEST == 28

#include "m-dict.h"

DICT_OA_DEF2(array, int, M_DEFAULT_OPLIST, int, DEFAULT_OPLIST)

#elif TEST == 29

#include "m-dict.h"

DICT_SET_DEF(array, int, DEFAULT_OPLIST)

#elif TEST == 30

#include "m-dict.h"

DICT_OASET_DEF(array, int, DEFAULT_OPLIST)

#elif TEST == 31

#include "m-i-shared.h"

typedef struct tmp_s {
  ISHARED_PTR_INTERFACE(tmpi, struct_tmp_s);
  const char *s;
} tmp_t;

ISHARED_PTR_DEF(tmpi, tmp_t, NOT_AN_OPLIST)

#elif TEST == 32

#include "m-prioqueue.h"

PRIOQUEUE_DEF(prio, int, DEFAULT_OPLIST)

#elif TEST == 33

#include "m-rbtree.h"

RBTREE_DEF(tree, int, M_DEFAULT_OPLIST() )

#elif TEST == 34

#include "m-shared.h"

SHARED_PTR_DEF(shared, int, M_DEFAULT_OPLIST2 )

#elif TEST == 35

#include "m-shared.h"

SHARED_RESOURCE_DEF(shared, int, M_DEFAULT_OPLIST3 )

#elif TEST == 36

#include "m-snapshot.h"

SNAPSHOT_SPSC_DEF(snap, int, M_DEFAULT_OPLIST2 )

#elif TEST == 37

#include "m-snapshot.h"

SNAPSHOT_SPMC_DEF(snap, int, M_DEFAULT_OPLIST2 )

#elif TEST == 38

#include "m-snapshot.h"

SNAPSHOT_MPMC_DEF(snap, int, M_DEFAULT_OPLIST8 )

#else
# warning TEST variable is out of range.
#endif
