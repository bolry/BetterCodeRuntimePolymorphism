// Copyright © 2018
#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM
#include <iostream>
#endif

#ifndef INCLUDED_MEMORY
#define INCLUDED_MEMORY
#include <memory>
#endif

#ifndef INCLUDED_DRAWDOC
#include "drawdoc.h"
#endif

using namespace SaabAB;
using namespace ewcstl;

namespace {

class my_class_t final : public object_t {
public:
	void draw(std::ostream& out, std::size_t position) const override;
};

}  // close anonymous namespace

int main()
{
	document_t document;

	document.emplace_back(std::make_shared<my_class_t>());

	draw(document, std::cout, 0);
}

namespace {
void my_class_t::draw(std::ostream& out, std::size_t position) const
{
	out << std::string(position, ' ') << "my_class_t\n";
}

}  // close anonymous namespace
// ----------------------------- END-OF-FILE ----------------------------------
