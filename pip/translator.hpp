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

		operator()(const sexpr::expr* e);
		
		expr* translate_expr(const sexpr::expr* e);
		expr* translate_range_expr(const sexpr::expr* e);
		expr* translate_wild_expr(const sexpr::expr* e);
		expr* translate_miss_expr(const sexpr::expr* e);
		expr* translate_ref_expr(const sexpr::expr* e);
		expr* translate_field_expr(const sexpr::expr* e);
		expr* translate_int_expr(const sexpr::int_expr* e);
	private:
		context& cxt;
		
	};


} // namespace pip
