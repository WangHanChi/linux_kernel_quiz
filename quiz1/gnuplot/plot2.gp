set title "Sorting perfomance comparison"
set xlabel "Set of records (thousand, K)"
set ylabel "Execution time (Sec)"
set term png enhanced font 'Verdana,12'
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
set output "quiz1-2-2.png"
set key right
set xrange [10:100]
set xtics 10,10,100
set yrange [0:0.1]


plot \
"data2.txt" using 1:2 with linespoints linewidth 2 title "Recursion",\
"data2.txt" using 1:3 with linespoints linewidth 2 title "Non-Recursion",\