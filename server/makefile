# natan furer 204594428
# nir azaria 204796338 

a.out: compileAll
	g++ -pthread *.o -o ../../exe/exeSer/runServer 
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp -pthread
