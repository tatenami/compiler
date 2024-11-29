# target lex file
TARGET=split_words

# 2. Compile lex..yy.c using gcc
${TARGET}: lex.yy.c
	gcc lex.yy.c -o ${TARGET} -lfl

# 1. Generate lex.yy.c from SRCS flex file
lex.yy.c: ${TARGET}.l
	flex ${TARGET}.l