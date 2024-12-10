make clean2
make TARGET=lang2 AST=ast2
echo "----------< RUN MY LANG v2 >----------"

for i in `seq 6`
do 
  ./lang2 < kadai${i} > kadai${i}-2.json
done  
