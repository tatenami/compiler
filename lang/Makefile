TARGET=lang
LEX=${TARGET}.l
YACC=${TARGET}.y
SAMPLE=sample.txt

# 3. Compile define.tab.c and lex.yy.c using gcc
${TARGET}: ${TARGET}.tab.c lex.yy.c
	gcc $^ -o $@ -lfl -ly -DYYERROR_VERBOSE

# 2. Generate target.tab.{c, h} from define.y using bison 
${TARGET}.tab.c: ${YACC}
	bison -d $^ -Wconflicts-sr
# 1. Generate lex.yy.c from define.l using flex
lex.yy.c: ${LEX}
	flex $^

clean:
	rm ./lex.yy.c ${TARGET}.tab.*

run:
	./lang < ${SAMPLE}