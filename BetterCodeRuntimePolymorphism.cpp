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

int main()
{
	document_t document;

	document.emplace_back(0);
	document.emplace_back(std::string("Hello"));
	document.emplace_back(2);
	document.emplace_back(3);

	draw(document, std::cout, 0);
}

// ----------------------------- END-OF-FILE ----------------------------------
