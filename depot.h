/** @file depot.h
*/
#ifndef SPL_DEPOT_H
#define SPL_DEPOT_H

#define STACK_SIZE_LIMIT 3

typedef struct DepotImplementation* Depot;

struct Product {
    int serial_no;
};

/**
 * Used to create a depot.
 * @return The newly created depot.
 */
Depot create_depot();

/**
 * Used to free all memory the supplied depot allocated.
 * @param depot The depot to be deleted.
 */
void delete_depot(Depot depot);

/**
 * Adds a product to the depot.
 * @param depot The depot on which to be pushed.
 * @param product The product to be added.
 */
void push_depot(Depot depot, Product *product);

/**
 * @param depot The depot which count to be retrieved.
 * @return The number of item stacks currently in the depot.
 */
int get_count(Depot depot);

/**
 * Removes and returns a product from the depot
 * @param depot The depot from which the product to be taken.
 * @return The removed product.
 */
Product* pop_depot(Depot depot);

#endif //SPL_DEPOT_H
