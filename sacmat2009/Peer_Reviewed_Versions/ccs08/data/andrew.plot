set terminal postscript eps enhanced "Helvetica" 20
set output 'andrew-polex.eps'
set ylabel 'Time (sec)'
set xlabel 'Benchmark Phase'
set xtics nomirror ("untar" 0, "configure" 4, "compile" 8, "install" 12, "remove" 16)
set boxwidth 1 absolute
set yrange[0:50]
set xrange [-3:20]
plot 'andrew-polex.dat' u ($1*4 - 0.5):3 t 'NFS' w boxes fs solid 0.2 border,'andrew-polex.dat' u ($1*4 + 0.5):4 t 'POLEX' w boxes fs solid 0.4 border
