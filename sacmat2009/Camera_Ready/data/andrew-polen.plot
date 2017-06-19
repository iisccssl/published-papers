set terminal postscript eps enhanced "Helvetica" 20
set output 'andrew-polen.eps'
set ylabel 'Time (sec)'
set xlabel 'Benchmark Phase'
set xtics nomirror ("untar" 0, "configure" 4, "compile" 8, "install" 12, "remove" 16)
set boxwidth 1 absolute
set yrange[0:70]
set xrange [-3:20]
plot 'andrew-polen.dat' u ($1*4 - 0.5):3 t 'NFS' w boxes fs solid 0.2 border,'andrew-polen.dat' u ($1*4 + 0.5):4 t 'POLEN' w boxes fs solid 0.4 border
