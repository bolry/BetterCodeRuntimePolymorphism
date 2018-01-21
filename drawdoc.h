// Copyright © 2018
#ifndef INCLUDED_DRAWDOC
#define INCLUDED_DRAWDOC

#ifndef INCLUDED_VECTOR
#define INCLUDED_VECTOR
#include <vector>
#endif

#ifndef INCLUDED_IOSFWD
#define INCLUDED_IOSFWD
#include <iosfwd>
#endif

namespace SaabAB {
namespace ewcstl {

void draw(int const& x, std::ostream& out, std::size_t position);

class object_t {
	int m_self;
public:
	object_t(int const& x);

	friend void draw(object_t const& x, std::ostream& out,
	                std::size_t position);
};

using document_t = std::vector<object_t>;

void draw(document_t const& x, std::ostream& out, std::size_t position);

}  // close package namespace
}  // close enterprise namespace

#endif
// ----------------------------- END-OF-FILE ----------------------------------
