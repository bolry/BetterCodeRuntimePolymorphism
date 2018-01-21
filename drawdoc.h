// Copyright © 2018
#ifndef INCLUDED_DRAWDOC
#define INCLUDED_DRAWDOC

#ifndef INCLUDED_IOSFWD
#define INCLUDED_IOSFWD
#include <iosfwd>
#endif

#ifndef INCLUDED_MEMORY
#define INCLUDED_MEMORY
#include <memory>
#endif

#ifndef INCLUDED_VECTOR
#define INCLUDED_VECTOR
#include <vector>
#endif

namespace SaabAB {
namespace ewcstl {

void draw(int const& x, std::ostream& out, std::size_t position);

class object_t {
	struct int_model_t {
		int m_data;
		int_model_t(int const& x);
		void draw_(std::ostream& out, std::size_t position) const;
	};
	std::unique_ptr<int_model_t> m_self;
public:
	object_t(int const& x);
	object_t(object_t const& x);
	object_t(object_t && x) noexcept;
	object_t& operator=(object_t x) noexcept;

	friend void draw(object_t const& x, std::ostream& out,
	                std::size_t position);
};

using document_t = std::vector<object_t>;

void draw(document_t const& x, std::ostream& out, std::size_t position);

}  // close package namespace
}  // close enterprise namespace

#endif
// ----------------------------- END-OF-FILE ----------------------------------
