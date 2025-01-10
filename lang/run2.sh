make clean
make
echo "----------< RUN MY LANG v2 >----------"

for i in `seq 6`
do 
  ./lang2 < resource/kadai${i} > json/kadai${i}-2.json
done  
