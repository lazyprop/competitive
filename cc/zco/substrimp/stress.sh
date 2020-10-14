while :
do
    python gen.py > in
    ./substrimp < in > out1
    ./brute < in > out2
    diff -w out1 out2 || break
done
