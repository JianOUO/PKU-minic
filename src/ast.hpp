#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <typeinfo>
#include <cstdlib>

// 所有 AST 的基类
class BaseAST {
 public:
  virtual ~BaseAST() = default;
  virtual void Dump() const = 0;
  virtual void Dump(std::ostream &os) const = 0;
};

// CompUnit 是 BaseAST
class CompUnitAST : public BaseAST {
 public:
  // 用智能指针管理对象
  std::unique_ptr<BaseAST> func_def;

  void Dump() const override;
  void Dump(std::ostream &os) const override;
};

// FuncDef 也是 BaseAST
class FuncDefAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> func_type;
  std::string ident;
  std::unique_ptr<BaseAST> block;

  void Dump() const override;
  void Dump(std::ostream &os) const override;
};

class FuncTypeAST : public BaseAST {
 public:
  std::string type;

  void Dump() const override;
  void Dump(std::ostream &os) const override;
};

class BlockAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> stmt;
  
  void Dump() const override;
  void Dump(std::ostream &os) const override;
};

class StmtAST : public BaseAST {
 public:
  int number;

  void Dump() const override;
  void Dump(std::ostream &os) const override;
};