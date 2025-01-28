TARGET=lang2
AST=ast2
GEN=code_generation_stack
LEX=${TARGET}.l
YACC=${TARGET}.y
SAMPLE=sample.txt
SRC=kadai1

# 3. Compile define.tab.c and lex.yy.c using gcc
${TARGET}: ${TARGET}.tab.c lex.yy.c ${AST}.c ${GEN}.c
	gcc $^ -o $@ -lfl -ly -DYYERROR_VERBOSE -g

# 2. Generate target.tab.{c, h} from define.y using bison 
${TARGET}.tab.c: ${YACC}
	bison -d $^ -Wconflicts-sr
	
# 1. Generate lex.yy.c from define.l using flex
lex.yy.c: ${LEX}
	flex $^

clean:
	rm ./lex.yy.c ${TARGET}.tab.*

ast: 
	./${TARGET} < resource/${SRC} > json/${SRC}.json

build:
	./${TARGET} asm/${SRC}.s < resource/${SRC}