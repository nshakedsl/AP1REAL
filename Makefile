make: server.out client.out
client.out:
	g++ -o client.out -std=c++11 client.cpp SocketIO.cpp FileIO.cpp DefaultIO.cpp
server.out:
	g++ -o server.out -std=c++11 server.cpp CLI.cpp command.cpp UploadFile.cpp Solver.cpp SocketIO.cpp Exit.cpp setParams.cpp ClassifyData.cpp DownloadRes.cpp DisplayResults.cpp Classification.cpp VectorCollection.cpp DefaultIO.cpp
clean:
	rm -f *.o server.out
	rm -f *.o client.out