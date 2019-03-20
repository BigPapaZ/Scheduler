OPTS = -Wall -std=c++11

all: schedulesim

tests: ArrayList_TEST LinkedList_TEST RoundRobin_TEST CompletelyFair_TEST RBTNode_TEST BSTNode_TEST BSTMultimap_TEST RBTMultimap_TEST

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} -o ArrayList_TEST ArrayList_TEST.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp LinkedList.tpp
	g++ ${OPTS} -o LinkedList_TEST LinkedList_TEST.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.cpp Scheduler.hpp ArrayList.hpp ArrayList.tpp Process.cpp Process.hpp LinkedList.hpp LinkedList.tpp
	g++ ${OPTS} -o RoundRobin_TEST RoundRobin_TEST.cpp Scheduler.cpp Process.cpp

schedulesim: schedulesim.cpp simulate.hpp simulate.cpp ArrayList.hpp ArrayList.tpp Scheduler.cpp Scheduler.hpp Process.cpp Process.hpp RBTMultimap.tpp RBTMultimap.tpp BSTMultimap.tpp BSTMultimap.tpp
	g++ ${OPTS} -o schedulesim schedulesim.cpp simulate.cpp Scheduler.cpp Process.cpp

BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp
	g++ ${OPTS} -o BSTNode_TEST BSTNode_TEST.cpp

RBTNode_TEST: RBTNode_TEST.cpp RBTNode.hpp RBTNode.tpp
	g++ ${OPTS} -o RBTNode_TEST RBTNode_TEST.cpp

BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp
	g++ ${OPTS} -o BSTMultimap_TEST BSTMultimap_TEST.cpp

RBTMultimap_TEST: RBTMultimap_TEST.cpp RBTMultimap.hpp RBTMultimap.tpp
	g++ ${OPTS} -o RBTMultimap_TEST RBTMultimap_TEST.cpp

CompletelyFair_TEST: CompletelyFair_TEST.cpp Scheduler.cpp Scheduler.hpp BSTMultimap.hpp BSTMultimap.tpp Process.cpp Process.hpp#LinkedList.hpp LinkedList.tpp
	g++ ${OPTS} -o CompletelyFair_TEST CompletelyFair_TEST.cpp Scheduler.cpp Process.cpp

run_schedulesim:
	make clean
	make schedulesim
	./schedulesim 5000 10 1000000
	./schedulesim 6000 10 1000000
	./schedulesim 7000 10 1000000
	./schedulesim 8000 10 1000000
	./schedulesim 9000 10 1000000
	./schedulesim 10000 10 1000000
	
	make clean

run_tests:
	make clean
	
	make ArrayList_TEST
	make LinkedList_TEST
	make RoundRobin_TEST
	make CompletelyFair_TEST
	make RBTNode_TEST
	make BSTNode_TEST
	make BSTMultimap_TEST
	make RBTMultimap_TEST

	./ArrayList_TEST
	./LinkedList_TEST
	./RoundRobin_TEST
	./RBTNode_TEST
	./BSTNode_TEST
	./BSTMultimap_TEST
	./RBTMultimap_TEST
	./CompletelyFair_TEST
	
	make clean

clean:
	rm -f *.o ArrayList_TEST RoundRobin_TEST LinkedList_TEST schedulesim BSTNode_TEST BSTMultimap_TEST RBTMultimap_TEST RBTNode_TEST CompletelyFair_TEST

cleancov:
	rm -f -r *.gcda *.gcno *.gcov *.info coverage

cleanemacs:
	rm *~