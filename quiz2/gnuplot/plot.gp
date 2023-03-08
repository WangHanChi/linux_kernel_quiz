set title "SWAR perfomance comparison"
set xlabel "Set of records (thousand, K)"
set ylabel "Execution time (Sec)"
set term png enhanced font 'Verdana,12'
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
set output "quiz2-3.png"
set key right
set xrange [10000:90000]
set xtics 10000,10000,90000
set yrange [0:0.08]


plot \
"data.txt" using 1:2 with linespoints linewidth 2 title "Normal",\
"data.txt" using 1:3 with linespoints linewidth 2 title "Using SWAR",\
