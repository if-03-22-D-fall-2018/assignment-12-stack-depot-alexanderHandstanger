#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "depot.h"

#include "shortcut.h"
#include "test_depot.h"
#include "memcheck.h"

int main(int argc, char *argv[])
{
	ADD_TEST(create_stack);
	ADD_TEST(add_item_to_stack);
	ADD_TEST(get_item_from_stack);
	ADD_TEST(add_items_to_stack);
	ADD_TEST(get_items_from_stack);
	ADD_TEST(create_depot);
	ADD_TEST(add_item_to_depot);
	ADD_TEST(get_item_from_depot);
	ADD_TEST(fill_depot);
	ADD_TEST(use_depot);

	run_tests();
	return 0;
}
