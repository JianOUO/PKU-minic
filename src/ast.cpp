#include "ast.hpp"

void CompUnitAST::Dump() const { 
 std::cout << "CompUnitAST { ";
 func_def->Dump();
 std::cout << " }";
}

void CompUnitAST::Dump(std::ostream &os) const {
 func_def->Dump(os);
}

void FuncDefAST::Dump() const {
 std::cout << "FuncDefAST { ";
 func_type->Dump();
 std::cout << ", " << ident << ", ";
 block->Dump();
 std::cout << " }";
}

void FuncDefAST::Dump(std::ostream &os) const { 
 os << "fun @" << ident << "(): ";
 func_type->Dump(os);
 os << "{" << std::endl;
 block->Dump(os);
 os << "}" << std::endl;
}

void FuncTypeAST::Dump() const {
 std::cout << "FuncTypeAST { " << type << " }";
}

void FuncTypeAST::Dump(std::ostream &os) const {
 if (type == "int") {
  os << "i32 "; 
 }
}

void BlockAST::Dump() const { 
 std::cout << "BlockAST { ";
 stmt->Dump();
 std::cout << " }";
}

void BlockAST::Dump(std::ostream& os) const {
 os << "\%entry:" << std::endl;
 stmt->Dump(os);
}

void StmtAST::Dump() const {
 std::cout << "StmtAST { " << number << " }";
}

void StmtAST::Dump(std::ostream& os) const {
 os << "  ret " << number << std::endl;
}