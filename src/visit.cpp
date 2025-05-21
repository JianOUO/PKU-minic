#include <cassert>
#include "visit.hpp"

void Visit(const koopa_raw_program_t &program, std::ostream &os) {
 os << "  .text" << std::endl;
 os << "  .global main" << std::endl;
 Visit(program.values, os);
 Visit(program.funcs, os);   
}

void Visit(const koopa_raw_slice_t &slice, std::ostream &os) {
 for (uint32_t i = 0; i < slice.len; i++) {
    auto ptr = slice.buffer[i];
    switch (slice.kind) {
     case KOOPA_RSIK_FUNCTION:
      Visit(reinterpret_cast<koopa_raw_function_t>(ptr), os);
      break;
     case KOOPA_RSIK_BASIC_BLOCK:
      Visit(reinterpret_cast<koopa_raw_basic_block_t>(ptr), os);
      break;
     case KOOPA_RSIK_VALUE:
      Visit(reinterpret_cast<koopa_raw_value_t>(ptr), os);
      break;
      default:
       assert(false);
    }
 }
}

void Visit(const koopa_raw_function_t &func, std::ostream &os) {
 assert(func);
 os << (func->name + 1) << ":" << std::endl;
 Visit(func->bbs, os);
}

void Visit(const koopa_raw_basic_block_t &bbs, std::ostream &os) {
 assert(bbs);
 Visit(bbs->insts, os);
}

void Visit(const koopa_raw_value_t &value, std::ostream &os) {
 assert(value);
 const auto &kind = value->kind;
 switch (kind.tag) {
  case KOOPA_RVT_RETURN:
   Visit(kind.data.ret, os);
   break;
  case KOOPA_RVT_INTEGER:
   Visit(kind.data.integer, os);
   break;
  default:
   assert(false);
 }
}

void Visit(const koopa_raw_return_t &ret, std::ostream &os) {
    os << "  li a0, ";
    Visit(ret.value, os);
    os << std::endl;
    os << "  ret" << std::endl;
}

void Visit(const koopa_raw_integer_t &integer, std::ostream &os) {
    os << integer.value;
}
