make: server.out client.out
client.out:
	g++ -o client.out -std=c++11 Client.cpp Parser.cpp
server.out:
	g++ -o server.out -std=c++11 Classification.cpp Distances.cpp File.cpp Parser.cpp Server.cpp VectorCollection.cpp
clean:
	rm -f *.o server.out
	rm -f *.o client.out