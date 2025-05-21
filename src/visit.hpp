#pragma once
#include <koopa.h>
#include <iostream>

void Visit(const koopa_raw_program_t &program, std::ostream &os = std::cout);

void Visit(const koopa_raw_slice_t &slicem, std::ostream &os = std::cout);

void Visit(const koopa_raw_function_t &func, std::ostream &os = std::cout);

void Visit(const koopa_raw_basic_block_t &bb, std::ostream &os = std::cout);

void Visit(const koopa_raw_value_t &value, std::ostream &os = std::cout);

void Visit(const koopa_raw_return_t &ret, std::ostream &os = std::cout);

void Visit(const koopa_raw_integer_t &integer, std::ostream &os = std::cout);