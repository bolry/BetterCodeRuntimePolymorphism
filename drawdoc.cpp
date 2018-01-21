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

object_t::int_model_t::int_model_t(int x) :
		m_data(std::move(x))
{
}

void object_t::int_model_t::draw_(std::ostream& out, std::size_t position) const
{
	draw(m_data, out, position);
}

object_t::object_t(int x) :
		m_self(std::make_unique<int_model_t>(std::move(x)))
{
}

object_t::object_t(const object_t& x) :
		m_self(std::make_unique<int_model_t>(*x.m_self))
{
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

}  // close package namespace
}  // close enterprise namespace

// ----------------------------- END-OF-FILE ----------------------------------
