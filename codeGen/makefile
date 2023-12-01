parser:   y.tab.c lex.yy.c table.c proj2.c
	cc  -g -o parser y.tab.c proj2.c -lfl -w
y.tab.c:  grammar.y
	yacc -v grammar.y
lex.yy.c: lex.l 
	flex lex.l

codeGen:  y.tab.c lex.yy.c table.c seman.c proj3.c
	gcc -m32 y.tab.c proj2.c proj3.c proj4.c seman.c -o myCodeGen -w -g

clean:
	rm -f lex.yy.c y.tab.* *.o myCodeGen parser