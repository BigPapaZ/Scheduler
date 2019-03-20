Name: Zaigham A. Randhawa

Project no. 2 Schedulers

Files submitted: 

1. List.hpp: A list base class.

2. ArrayList.hpp/tpp: An arraylist implementation for running an array lists scheduler.

3. LinkedList.hpp/tpp: A linked implementation for running an array lists scheduler.

4. LinkedListNode.hpp/tpp: A node implementation for the linked lists.

5. BSTNode.hpp/tpp: A node implementation for the binary search trees.

6. BSTMultimap.hpp/tpp: A binary search tree implementation for schedulers.

7. BSTForwardIterator.hpp/tpp: An interator implementation for the nodes inside the BST.

8. RBTNode.hpp/tpp: An RBT node implementation for the red black trees.

9. RBTMultimap.hpp/tpp: A red black search tree implementation for schedulers.

10. Process.hpp/cpp: A process implmentation for the simulations.

11. Scheduler.hpp/cpp: A scheduler implementation for various 

12. simulate.hpp/cpp: 

13. schedulsim.cpp: 

14. ArrayList_TEST.cpp: Test for the arraylists.

15. LinkedList_TEST.cpp: Test for the LinkedLists.

16. BSTNode_TEST.cpp: Test for the BSTNodes.

17. BSTMultimap_TEST.cpp: Test for the BSTMultimaps.

18. RBTNode_TEST.cpp: Test for the RBTNodes.

19. RBTMultimap_TEST: Test for the RBTMultimaps.

20. RoundRobin_TEST.cpp: Test for the RoundRobin scheduler.

21. CompletelyFair_TEST.cpp: Test for the CompletelyFair schedulers.

22. catch.hpp: Provides a framework for the test files to run and catch errors.

23. Makefile: Shortens our time spent on the terminal by give us ready made command. 

24. readme.txt: A guide to running this project.
 
How to run :

    Write 'make run_schedulesim' (without the commas) on the command line terminal. You will get all of the times for all of the required processes.

How to run tests:

    Write 'make run_tests' (without the commas) on the command line terminal. The tests will run automatically. 
    
Bugs:

    The simulation doesn't work with IO-bound processes when we are using Completelyfair and FastCompletelyfair. This issue can be resolved by commenting out the lines(the second for loop) which put the IO bound processes into the schdeduler in simulate.cpp.
