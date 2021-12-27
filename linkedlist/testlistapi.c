#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listapi.h" /* include header file from current directory */
/* note use -I <path> option to specify compiler the include/header file locations */


void test4(void) {
	printf("Running test4\n");
	struct list_node *list1 = list_init();
	for(int i = 0; i < 10; ++i) {
		list1 = list_add_elem(list1, i * 2);
	}
	list_print(list1);
	
	struct list_node *list2 = list_init();
	for(int i = 0; i < 10; ++i) {
		list2 = list_add_elem(list2, i * 3);
	} 
	list_print(list2);
	struct list_node *merged_list = list_merge_list(list1, list2);
	list_print(merged_list);
}
void
test3(void) {
	printf("Running test 3 \n");
	struct list_node *list1 = list_init();
	for (int i = 0;i < 10; ++i) {
		list1 = list_add_elem(list1, i);
	}
	list_print(list1);
	for (int i = -100; i < -90; ++i) {
		list1 = list_add_elem(list1, i);
	}	
	list_print(list1);
	

	for (int i = 50; i < 60; ++i) {
		list1 = list_add_elem(list1, -1 *i);
	}
	list_print(list1);

	list1 = list_del_elem(list1,0);
	list_print(list1);
	list_destroy(list1);

}

void 
test2(void) {
	printf("Running test 2 \n");
	struct list_node *list1 = list_init();
	for(int i = 0; i < 10; ++i) {
		list1 = list_insert_elem(list1, i);
	}
	list_print(list1);
	{ /* create block of code */
		bool found = list_find_elem(list1, 3);
		if(found) {
			printf("found %d in list \n", 3);
		} else {
			printf("%d not found \n", 3);
		}  
	}

	{ /* create block of code */
		bool found = list_find_elem(list1, 30);
		if(found) {
			printf("found %d in list \n", 30);
		} else {
			printf("%d not found \n", 30);
		}  
	}
	/* delete 5 and 50 */
	int delelems[] = {5, 50};
	for (int i = 0; i < sizeof(delelems)/sizeof(delelems[0]); ++i) {
		list1 = list_del_elem(list1, delelems[i]);
	}
	list_print(list1);
	list_destroy(list1); /* free up memory */
}
int
main(int argc, char **argv) {
	/* initialize a list */
	struct list_node *list1 = list_init();
	struct list_node *list2 = list_init();

	list_print(list1);
	list_print(list2);
	
	/* initialize random seed */
	srand(time(NULL)); /* use return value from time(NULL) as seed */
	int v1 = rand();
	printf("v1 = %d\n", v1);
	list1 = list_insert_elem(list1, v1);
	printf("list 1 %p\n", list1);
	v1 = rand();
	printf("v1 = %d\n", v1);
	list1 = list_insert_elem(list1, v1);
	list1 = list_insert_elem(list1, v1);
	int v2 = rand();
	printf("v2 = %d\n", v2);
	list2 = list_append_elem(list2, v2);
	printf("list 1 %p\n", list1);
	list2 = list_append_elem(list2,rand());

	list_print(list1);
	list_print(list2);

	/* destroy list */
	list_destroy(list1);
	list_destroy(list2);

	/* TEST 2 */
	test2();

	/* TEST 3 */
	test3();
	
	/* Test 4 */
	test4();
	return 0;

}
