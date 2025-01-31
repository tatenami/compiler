SRCS=rep.tex

${SRCS:tex=pdf}: ${SRCS:tex=dvi}
	dvipdfmx $^

${SRCS:tex=dvi}: ${SRCS}
	platex $^