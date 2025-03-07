
/*
   POET : Parameterized Optimizations for Empirical Tuning
   Copyright (c)  2008,  Qing Yi.  All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
 3. Neither the name of UTSA nor the names of its contributors may be used to
    endorse or promote products derived from this software without specific
    prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISEDOF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef POET_EXT_AST_INTERFACE_H
#define POET_EXT_AST_INTERFACE_H

#include <vector>
#include <map>


class POETCode;
class AstNodeType;
class POETCodeVisitor;
template <typename AST_NODE_PTR>
class POETAstInterface 
{
  static std::map<AST_NODE_PTR, POETCode*> codeMap;
public:
  typedef AST_NODE_PTR Ast;
  typedef AstNodeType AstType;
  typedef std::vector<Ast>  AstList;
  typedef std::vector<AstType>  AstTypeList;

  static std::string Ast2String(const Ast & n);
  static std::string AstTypeName(const Ast& n);
  static void unparse(const Ast& n, std::ostream& out, int align);

   /* matching the external AST node with a POET pattern */
  static POETCode* MatchAstWithPattern(const Ast& n, POETCode* pat);
  static POETCode* getAstAttribute(const Ast& n, POETCode* attr);
  static POETCode* visitAstChildren(const Ast& n, POETCodeVisitor* visitor, bool backward);

  static void set_Ast2POET(const Ast& n, POETCode* p)
    { codeMap[n] = p; }
  static POETCode* find_Ast2POET(const Ast& n)
    {
      typename std::map<AST_NODE_PTR, POETCode*>::const_iterator p = codeMap.find(n);
      if (p != codeMap.end()) { return (*p).second; }
      return 0;
    }
  static POETCode* Ast2POET(const Ast& n) ;
};

#endif
