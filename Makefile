threads-demo: threads-demo.c
	gcc -Wall -Wextra -O2 -o threads-demo threads-demo.c
	strip threads-demo

clean:
	rm -f threads-demo
