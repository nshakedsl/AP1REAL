make: server.out client.out
client.out:
	g++ -std=c++11 client.cpp Client.cpp Parser.cpp
server.out:
	g++ -std=c++11 Classification.cpp Distances.cpp File.cpp Parser.cpp server.cpp Server.cpp VectorCollection.cpp
clean:
	rm -f *.o server.out
	rm -f *.o client.out