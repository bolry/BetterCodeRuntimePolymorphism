// Copyright © 2018
#ifndef INCLUDED_DRAWDOC
#define INCLUDED_DRAWDOC

#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM
#include <iostream>
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

template<typename T>
void draw(T const& x, std::ostream& out, std::size_t position);

class object_t {
	struct concept_t {
		virtual ~concept_t();
		virtual std::unique_ptr<concept_t> copy_() const = 0;
		virtual void draw_(std::ostream& out,
		                std::size_t position) const = 0;
	};
	template<typename T>
	struct model final : concept_t {
		T m_data;
		model(T x);
		std::unique_ptr<concept_t> copy_() const override;
		void draw_(std::ostream& out, std::size_t position) const
		                override;
	};
	std::unique_ptr<concept_t> m_self;
public:
	template<typename T>
	object_t(T x);
	object_t(object_t const& x);
	object_t(object_t && x) noexcept;
	object_t& operator=(object_t const& x);
	object_t& operator=(object_t&&) noexcept;

	friend void draw(object_t const& x, std::ostream& out,
	                std::size_t position);
};

using document_t = std::vector<object_t>;

void draw(document_t const& x, std::ostream& out, std::size_t position);

}  // close package namespace
}  // close enterprise namespace

// ----------------------------------------------------------------------------

namespace SaabAB {
namespace ewcstl {

template<typename T>
void draw(T const& x, std::ostream& out, std::size_t position)
{
	out << std::string(position, ' ') << x << '\n';
}

template<typename T>
object_t::object_t(T x) : m_self(std::make_unique<model<T>>(std::move(x)))
{
}

template<typename T>
object_t::model<T>::model(T x) :
		m_data(std::move(x))
{
}

template<typename T>
std::unique_ptr<object_t::concept_t> object_t::model<T>::copy_() const
{
	return std::make_unique<model<T>>(*this);
}

template<typename T>
void object_t::model<T>::draw_(std::ostream& out,
                std::size_t position) const
{
	draw(m_data, out, position);
}

}  // close package namespace
}  // close enterprise namespace

#endif
// ----------------------------- END-OF-FILE ----------------------------------
