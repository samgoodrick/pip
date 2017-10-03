#pragma once

#include <sexpr/translation.hpp>
#include <pip/expr.hpp>
#include <pip/context.hpp>

// TODO: This module will define the sexpr translation.

namespace pip
{
	class translator : public sexpr:translator<translator>
	{		
	public:
		translator( context& cxt );
		
		expr* translate_expr(const sexpr::expr* e);
		expr* translate_int_expr(const sexpr::int_expr* e);
	private:
		context& cxt;
		
	};


} // namespace pip
