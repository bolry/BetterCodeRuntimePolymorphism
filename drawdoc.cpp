// Copyright © 2018
#ifndef INCLUDED_DRAWDOC
#include "drawdoc.h"
#endif

#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM
#include <iostream>
#endif

namespace SaabAB {
namespace ewcstl {

void draw(const object_t& x, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << x << '\n';
}

 void draw(const document_t& x, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << "<document>\n";
	for (auto const& e : x) {
		draw(e, out, position + 2);
	}
	out << std::string(position, ' ') << "</document>\n";
}

}  // close package namespace
}  // close enterprise namespace

// ----------------------------- END-OF-FILE ----------------------------------
