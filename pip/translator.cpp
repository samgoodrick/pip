#include "translator.hpp"

using cc::as;

translator::operator()(const sexpr::expr* e)
{
	if( const sexpr::list_expr* l = as<sexpr::list_expr>(e))
		return translate_prog(l);
	sexpr::throw_unexpected_term(e);
}
