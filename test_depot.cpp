#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shortcut.h"
#include "test_depot.h"
#include "stack.h"
#include "depot.h"

// Stack Tests
TEST(create_stack)
{
	Stack stack = create_stack();
	ASSERT_FALSE(stack == 0, "Stack has to be created");
	delete_stack(stack);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(add_item_to_stack)
{
	Stack stack = create_stack();

	Product product = {1};

	push_stack (stack, &product);

	ASSERT_EQUALS(1, get_count(stack));

	delete_stack(stack);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(get_item_from_stack)
{
	Stack stack = create_stack();

	Product product = {9};
	push_stack (stack, &product);

	ASSERT_EQUALS(9, ((Product*)pop_stack (stack))->serial_no);
	ASSERT_EQUALS(0, get_count(stack));

	delete_stack(stack);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(add_items_to_stack)
{
	Stack stack = create_stack();

	Product products[] = {
        {1},
        {2},
        {3}
    };
	push_stack (stack, &products[0]);
	push_stack (stack, &products[1]);
	push_stack (stack, &products[2]);

	ASSERT_EQUALS(3, get_count(stack));

	delete_stack(stack);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(get_items_from_stack)
{
	Stack stack = create_stack();

	Product products[] = {
        {1},
        {2},
        {3}
    };
	push_stack (stack, &products[0]);
	push_stack (stack, &products[1]);
	push_stack (stack, &products[2]);

	ASSERT_EQUALS(3, ((Product*)pop_stack(stack))->serial_no);
	ASSERT_EQUALS(2, ((Product*)pop_stack(stack))->serial_no);

	ASSERT_EQUALS(1, ((Product*)peek_stack(stack))->serial_no);
	ASSERT_EQUALS(1, get_count(stack));

	ASSERT_EQUALS(1, ((Product*)pop_stack(stack))->serial_no);
	ASSERT_EQUALS(0, get_count(stack));

	delete_stack(stack);
	ASSERT_EQUALS(true, memcheck_validate());
}

// Depot Tests
TEST(create_depot)
{
	Depot depot = create_depot();
	ASSERT_FALSE(depot == 0, "Depot has to be created");
	delete_depot(depot);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(add_item_to_depot)
{
	Depot depot = create_depot();
	ASSERT_EQUALS(0, get_count(depot));

	Product product = {9};	

	push_depot(depot, &product);
	ASSERT_EQUALS(1, get_count(depot));

	delete_depot(depot);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(get_item_from_depot)
{
	Depot depot = create_depot();
	ASSERT_EQUALS(0, get_count(depot));

	Product product = {9};	

	push_depot(depot, &product);
	ASSERT_EQUALS(1, get_count(depot));
	ASSERT_EQUALS(9, ((Product*)pop_depot(depot))->serial_no);	
	ASSERT_EQUALS(0, get_count(depot));

	delete_depot(depot);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(fill_depot)
{
	Depot depot = create_depot();

	Product products[] = {
        {1},
        {2},
        {3},
		{4}
    };

	ASSERT_EQUALS(0, get_count(depot));

	push_depot(depot, &products[0]);
	ASSERT_EQUALS(1, get_count(depot));
	push_depot(depot, &products[1]);
	ASSERT_EQUALS(1, get_count(depot));
	push_depot(depot, &products[2]);
	ASSERT_EQUALS(1, get_count(depot));
	push_depot(depot, &products[3]);
	ASSERT_EQUALS(2, get_count(depot));

	delete_depot(depot);
	ASSERT_EQUALS(true, memcheck_validate());
}

TEST(use_depot)
{
	Depot depot = create_depot();

	Product products[] = {
        {1},
        {2},
        {3},
		{4},
		{5},
		{6},
		{7}
    };

	for (int i = 0; i < 7; i++){
		push_depot(depot, &products[i]);
	}
	ASSERT_EQUALS(3, get_count(depot));

	for (int j = 6; j >= 0; j--){
		Product *p = pop_depot(depot);
		ASSERT_EQUALS(j+1, p->serial_no);
		if (j == 4){
			ASSERT_EQUALS(2, get_count(depot));
		}
		if (j == 2){
			ASSERT_EQUALS(1, get_count(depot));
		}
	}
	ASSERT_EQUALS(0, get_count(depot));

	push_depot(depot, &products[0]);
	push_depot(depot, &products[1]);
	push_depot(depot, &products[2]);
	push_depot(depot, &products[3]);
	pop_depot(depot);
	push_depot(depot, &products[4]);
	ASSERT_EQUALS(2, get_count(depot));
	ASSERT_EQUALS(5, ((Product*)pop_depot(depot))->serial_no);
	ASSERT_EQUALS(1, get_count(depot));

	delete_depot(depot);
	ASSERT_EQUALS(true, memcheck_validate());
}
