set terminal postscript eps enhanced "Helvetica" 20
set output 'ubench.eps'

set ylabel 'Response Latency (usec)'
set xtics nomirror ("getattr" 0, "lookup" 5, "access" 10, "read" 15, "write" 20, "create" 25)
set boxwidth 1 absolute
set yrange[0:800]
set xrange [-5:30]
plot 'ubench.dat' u ($1*5 - 2):4 t 'NFS-minimal' w boxes fs solid 0.2 border,'ubench.dat' u ($1*5 - 1):5 t 'POLEN-minimal' w boxes fs solid 0.4 border,'ubench.dat' u ($1*5):6 t 'NFS-LAN' w boxes fs solid 0.6 border, 'ubench.dat' u ($1*5 + 1):7 t 'POLEN-LAN' w boxes fs solid 0.8 border

