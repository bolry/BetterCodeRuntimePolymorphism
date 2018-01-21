// Copyright © 2018
#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM
#include <iostream>
#endif

#ifndef INCLUDED_DRAWDOC
#include "drawdoc.h"
#endif

using namespace SaabAB;
using namespace ewcstl;

class my_class_t {
};

void draw(my_class_t const&, std::ostream& out, std::size_t position);

int main()
{
	document_t document;

	document.emplace_back(0);
	document.emplace_back(std::string("Hello"));
	document.emplace_back(2);
	document.emplace_back(my_class_t());

	draw(document, std::cout, 0);
}

// ----------------------------------------------------------------------------

void draw(my_class_t const&, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << "my_class_t\n";
}

// ----------------------------- END-OF-FILE ----------------------------------
