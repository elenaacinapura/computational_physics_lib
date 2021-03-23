set datafile separator '\t'
set term png size (1000,1000)
set output 'Output_trajectory/plot.png'

set xlabel 'x'
set ylabel 'y'
set xrange [0:3]
unset key

plot 'Output_trajectory/trajectory.csv' using 2:3 lc 7 w lines