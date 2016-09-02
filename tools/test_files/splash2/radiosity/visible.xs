
Stmts:Stmt1,Stmt2,Stmt3,Stmt4,Stmt5,Stmt6,Stmt8,Stmt10,Stmt11
Funcs:FunctionDecl1

StrengthReduction:target=Stmt1 type=2
RedundancyElimination:target=Stmt4 type=2
RedundancyElimination:target=Stmt6 type=3 function_definition=FunctionDecl1 ret_statement=Stmt5
RedundancyElimination:target=Stmt8 type=3 function_definition=FunctionDecl1 ret_statement=Stmt5
RedundancyElimination:target=Stmt10 type=3 function_definition=FunctionDecl1 ret_statement=Stmt5
RedundancyElimination:target=Stmt11 type=3 function_definition=FunctionDecl1 ret_statement=Stmt5

