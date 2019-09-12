
dim=1
time=20
elem=float
points=3
comp=diff

now:
	$(top_srcdir)/src/pcg $(debug) -pdim=$(dim) -ptime=$(time) -pelem=$(elem) -ppoints=$(points) $(srcdir)/stencil-gen.pt > out.c

check:
	make now
	$(comp) out.c stencil-3.c

clean:
	rm out.C out2.cu  *.o a.out *_tester.cu

