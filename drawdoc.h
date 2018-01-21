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

#include <memory>

namespace SaabAB {
namespace ewcstl {

class object_t {
public:
	virtual ~object_t();
	virtual void draw(std::ostream& out, std::size_t) const = 0;
};

void draw(object_t const& x, std::ostream& out, std::size_t position);

using document_t = std::vector<std::shared_ptr<object_t>>;

void draw(document_t const& x, std::ostream& out, std::size_t position);

}  // close package namespace
}  // close enterprise namespace

#endif
// ----------------------------- END-OF-FILE ----------------------------------
