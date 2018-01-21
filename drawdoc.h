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

void draw(std::string const& x, std::ostream& out, std::size_t position);
void draw(int const& x, std::ostream& out, std::size_t position);

class object_t {
	struct concept_t {
		virtual ~concept_t();
		virtual std::unique_ptr<concept_t> copy_() const = 0;
		virtual void draw_(std::ostream& out,
		                std::size_t position) const = 0;
	};
	struct string_model_t final : concept_t {
		std::string m_data;
		string_model_t(std::string x);
		std::unique_ptr<concept_t> copy_() const override;
		void draw_(std::ostream& out, std::size_t position) const
		                override;
	};
	struct int_model_t final : concept_t {
		int m_data;
		int_model_t(int x);
		std::unique_ptr<concept_t> copy_() const override;
		void draw_(std::ostream& out, std::size_t position) const
		                override;
	};
	std::unique_ptr<concept_t> m_self;
public:
	object_t(std::string x);
	object_t(int x);
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

#endif
// ----------------------------- END-OF-FILE ----------------------------------
