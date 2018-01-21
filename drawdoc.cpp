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

void draw(int const& x, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << x << '\n';
}

object_t::object_t(int const& x) :
		m_self(x)
{
}

void draw(object_t const& x, std::ostream& out, std::size_t position)
{
	draw(x.m_self, out, position);
}

void draw(document_t const& x, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << "<document>\n";
	for (auto const& e : x) {
		draw(e, out, position + 3);
	}
	out << std::string(position, ' ') << "</document>\n";
}

}  // close package namespace
}  // close enterprise namespace

// ----------------------------- END-OF-FILE ----------------------------------
