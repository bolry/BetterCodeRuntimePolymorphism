// Copyright © 2018
#ifndef INCLUDED_CHRONO
#define INCLUDED_CHRONO
#include <chrono>
#endif

#ifndef INCLUDED_FUTURE
#define INCLUDED_FUTURE
#include <future>
#endif

#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM
#include <iostream>
#endif

#ifndef INCLUDED_THREAD
#define INCLUDED_THREAD
#include <thread>
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

	auto saving = std::async([document = current(h)]() {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "---------- 'save' ----------\n";
		draw(document, std::cout, 1);
	});

	current(h)[1] = std::string("World");
	current(h).emplace_back(current(h));
	current(h).emplace_back(my_class_t());

	draw(current(h), std::cout, 0);
	std::cout << std::string(25, '-') << '\n';

	undo(h);

	draw(current(h), std::cout, 0);

	saving.get();
}

// ----------------------------------------------------------------------------

void draw(my_class_t const&, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << "my_class_t\n";
}

// ----------------------------- END-OF-FILE ----------------------------------
