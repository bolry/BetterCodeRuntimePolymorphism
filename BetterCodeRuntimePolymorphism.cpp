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

struct some_t {
	object_t m_member;
};

some_t func()
{
	return { 5 };
}

int main()
{
	//
	// Quiz: What will this print?
	//

	some_t x = { 0 };

	x = func();
}

// ----------------------------- END-OF-FILE ----------------------------------
