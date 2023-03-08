set title "SWAR perfomance comparison"
set xlabel "Set of records (thousand, K)"
set ylabel "Using cpucycles (thousand, K)"
set term png enhanced font 'Verdana,12'
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
set output "quiz2-3.png"
set key right
set xrange [10:100]
set xtics 10,10,100
set yrange [0:1200]


plot \
"data.txt" using 1:2 with linespoints linewidth 2 title "Normal",\
"data.txt" using 1:3 with linespoints linewidth 2 title "Using SWAR",\
