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

object_t func()
{
	object_t result = 5;
	return result;
}

int main()
{
	//
	// Quiz: What will this print?
	//

	object_t x = func();
}

// ----------------------------- END-OF-FILE ----------------------------------
