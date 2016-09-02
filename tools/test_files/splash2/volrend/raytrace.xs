
Nests:Nest1,Nest2,Nest5
Stmts:Stmt1,Stmt2,Stmt3,Stmt4
Funcs:Func1

ScalarRepl:aref=ray[0][i] dim=Nest1 target=Nest1 init=0 save=1 scalar_num=1 data_type="float"
UnrollLoop:target=Nest1 factor=3
StrengthReduction:target=Nest2 type=3 subexpression=(float(opc_len[i]-1)) data_type="float"
RedundancyElimination:target=Stmt1 type=5 branch_statement=Stmt2
StrengthReduction:target=Nest2 type=4 constant="0.0" data_type="float"
StrengthReduction:target=Nest5 type=4 constant="1.0" data_type="float"
StrengthReduction:target=Func1 type=5 shift_statement=Stmt3,Stmt4 data_type="long"

