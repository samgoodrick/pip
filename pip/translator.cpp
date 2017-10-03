#include "translator.hpp"

using cc::as;

translator::operator()(const sexpr::expr* e)
{
	if( const sexpr::list_expr* l = as<sexpr::list_expr>(e))
		return translate_prog(l);
	sexpr::throw_unexpected_term(e);
}

translator::translate_int_expr(const sexpr::int_expr* e)
{
	// TODO: Make this take an int_type pointer
	return cxt.make_int_expr(nullptr, e->val)
}
