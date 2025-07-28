#include "vld.h"
#include "in_function.h"
#include "in_constructor.h"
#include "objects.h"
#include "search_product.h"

int main() {

	_in_functionUsage();
	_in_constyructorUsage();
	_objectsUsage();
	_search_productUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	// int *i = new int(33);
	return 0;
}
