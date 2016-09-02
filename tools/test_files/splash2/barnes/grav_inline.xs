Stmts: Stmt1,Stmt2,Stmt3,Stmt4,Stmt5,Stmt6
Funcs: FunctionDecl1,FunctionDecl2

StrengthReduction:target=Stmt6 type=1 fp_division=Stmt4 appendix=Stmt5
InlineFunction:target=Stmt1 function_definition=FunctionDecl1
InlineFunction:target=Stmt2 function_definition=FunctionDecl2
InlineFunction:target=Stmt3 function_definition=FunctionDecl2
