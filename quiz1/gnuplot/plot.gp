set title "Sorting perfomance comparison"
set xlabel "Set of records (thousand, K)"
set ylabel "Execution time (Sec)"
set term png enhanced font 'Verdana,12'
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
set output "quiz1-2.png"
set key right
set xrange [100:1000]
set xtics 100,100,1000
set yrange [0:1.5]


plot \
"data.txt" using 1:2 with linespoints linewidth 2 title "Recursion",\
"data.txt" using 1:3 with linespoints linewidth 2 title "Iteration (Using stack)",\
