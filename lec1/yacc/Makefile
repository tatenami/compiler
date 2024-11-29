TARGET=define
LEX=${TARGET}.l
YACC=${TARGET}.y

# 3. Compile define.tab.c and lex.yy.c using gcc
${TARGET}: ${TARGET}.tab.c lex.yy.c
	gcc $^ -o $@ -lfl -ly

# 2. Generate target.tab.{c, h} from define.y using bison 
${TARGET}.tab.c: ${YACC}
	bison -d $^

# 1. Generate lex.yy.c from define.l using flex
lex.yy.c: ${LEX}
	flex $^