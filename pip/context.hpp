#pragma once

#include <pip/syntax.hpp>
#include <pip/expr.hpp>

#include <cc/diagnostics.hpp>
#include <cc/factory.hpp>
#include <cc/input.hpp>

namespace pip
{
  /// The context provides access to a number of useful translation facilities
  /// and manages memory for expressions.
  class context
  {
  public:
    context(cc::diagnostic_manager& diags, 
            cc::input_manager& in, 
            cc::symbol_table& syms);

    /// Returns the diagnostic manager.
    cc::diagnostic_manager& get_diagnostics() { return diags; }

    /// Returns the input manager.
    cc::input_manager& get_input() const { return input; }

    /// Returns the associated lexical context.
    cc::symbol_table& get_symbol_table() { return syms; }

    /// Returns a unique symbol.
    symbol* get_symbol(const char* str);
    symbol* get_symbol(const std::string& str);

    // TODO: Add factories for creating terms, e.g., make_program.
		expr* make_range_expr(type* t, int l, int h);
		expr* make_wild_expr(type* t, int n, int m);
		expr* make_miss_expr(type* t);
		expr* make_ref_expr(type* t, symbol* id);
		expr* make_field_expr(type* t, expr_kind k);
		expr* make_int_expr(type* t, int val);

  private:
    /// The diagnostic manager.
    cc::diagnostic_manager& diags;

    /// The input manager.
    cc::input_manager& input;

    /// The symbol table.
    cc::symbol_table& syms;
  };

} // namesapce pip
