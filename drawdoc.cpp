// Copyright © 2018
#ifndef INCLUDED_DRAWDOC
#include "drawdoc.h"
#endif

#ifndef INCLUDED_CASSERT
#define INCLUDED_CASSERT
#include <cassert>
#endif

namespace SaabAB {
namespace ewcstl {

object_t::concept_t::~concept_t() = default;

object_t::object_t(const object_t& x) :
		m_self(x.m_self->copy_())
{
	std::cout << "copy\n";
}

object_t::object_t(object_t&& x) noexcept = default;

object_t& object_t::operator=(object_t const& x)
{
	return *this = object_t(x);
}

object_t& object_t::operator=(object_t&&) noexcept = default;

void draw(object_t const& x, std::ostream& out, std::size_t position)
{
	x.m_self->draw_(out, position);
}

void draw(document_t const& x, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << "<document>\n";
	for (auto const& e : x) {
		draw(e, out, position + 3);
	}
	out << std::string(position, ' ') << "</document>\n";
}

void commit(history_t& x)
{
	assert(!x.empty());
	x.push_back(x.back());
}

void undo(history_t& x)
{
	assert(!x.empty());
	x.pop_back();
}

document_t& current(history_t& x)
{
	assert(!x.empty());
	return x.back();
}

}  // close package namespace
}  // close enterprise namespace

// ----------------------------- END-OF-FILE ----------------------------------
