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
		virtual void draw_(std::ostream& out,
		                std::size_t position) const = 0;
	};
	template<typename T>
	struct model final : concept_t {
		T m_data;
		model(T x);
		void draw_(std::ostream& out, std::size_t position) const
		                override;
	};
	std::shared_ptr<const concept_t> m_self;
public:
	template<typename T>
	object_t(T x);

	friend void draw(object_t const& x, std::ostream& out,
	                std::size_t position);
};

using document_t = std::vector<object_t>;

void draw(document_t const& x, std::ostream& out, std::size_t position);

using history_t = std::vector<document_t>;

void commit(history_t& x);
void undo(history_t& x);
document_t& current(history_t& x);

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
object_t::object_t(T x) :
		m_self(std::make_shared<model<T>>(std::move(x)))
{
}

template<typename T>
object_t::model<T>::model(T x) :
		m_data(std::move(x))
{
}

template<typename T>
void object_t::model<T>::draw_(std::ostream& out, std::size_t position) const
{
	draw(m_data, out, position);
}

}  // close package namespace
}  // close enterprise namespace

#endif
// ----------------------------- END-OF-FILE ----------------------------------
