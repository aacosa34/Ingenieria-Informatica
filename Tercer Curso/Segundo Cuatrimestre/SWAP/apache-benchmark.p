# output as png image
set terminal png

# save file to "benchmark.png"
set output "benchmark.png"

# graph title
set title "10000 peticiones y 50 de ellas concurrentes"

#nicer aspect ratio for image size
set size 1,1

# y-axis grid
set grid y

#x-axis label
set xlabel "peticiones"

#y-axis label
set ylabel "tiempo de respuesta (ms)"

#plot data from "out.data" using column 9 with smooth sbezier lines
plot "nginx-rr.data" using 9 smooth sbezier with lines title "Nginx Round Robin", \
     "nginx-weighted.data" using 9 smooth sbezier with lines title "Nginx Ponderado", \
     "haproxy-rr.data" using 9 smooth sbezier with lines title "HAProxy Round Robin", \
     "haproxy-weighted.data" using 9 smooth sbezier with lines title "HAProxy Ponderado", \
     "gobetween-rr.data" using 9 smooth sbezier with lines title "Gobetween Round Robin", \
     "gobetween-weighted.data" using 9 smooth sbezier with lines title "Gobetween Ponderado", \
     "zevenet-rr.data" using 9 smooth sbezier with lines title "Zevenet Round Robin", \
     "zevenet-weighted.data" using 9 smooth sbezier with lines title "Zevenet Ponderado", \
     "pound-rr.data" using 9 smooth sbezier with lines title "Pound Round Robin", \
     "pound-weighted.data" using 9 smooth sbezier with lines title "Pound Ponderado" 
