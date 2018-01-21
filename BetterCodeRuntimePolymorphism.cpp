// Copyright © 2018
#ifndef INCLUDED_ALGORITHM
#define INCLUDED_ALGORITHM
#include <algorithm>
#endif

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
	document.reserve(5);

	document.emplace_back(0);
	document.emplace_back(1);
	document.emplace_back(2);
	document.emplace_back(3);

	reverse(begin(document), end(document));

	draw(document, std::cout, 0);
}

// ----------------------------- END-OF-FILE ----------------------------------
