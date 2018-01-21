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
	history_t h(1);

	current(h).emplace_back(0);
	current(h).emplace_back(std::string("Hello!"));

	draw(current(h), std::cout, 0);
	std::cout << std::string(25, '-') << '\n';

	commit(h);

	current(h)[0] = 42.5;
	current(h)[1] = std::string("World");
	current(h).emplace_back(current(h));
	current(h).emplace_back(my_class_t());

	draw(current(h), std::cout, 0);
	std::cout << std::string(25, '-') << '\n';

	undo(h);

	draw(current(h), std::cout, 0);
}

// ----------------------------------------------------------------------------

void draw(my_class_t const&, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << "my_class_t\n";
}

// ----------------------------- END-OF-FILE ----------------------------------
