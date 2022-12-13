# Fantastic-roads225

- Final Video Presentation: https://youtu.be/lnGS0h0pUO8
- 10k Generated Matrix: https://drive.google.com/file/d/1WfgX9HDBK0wrgJcXPwWdNcL0xOTRAkCI/view?usp=sharing

- GitHub Organization: 
    - All code files can be found in the [./src](https://github.com/Mankeerat/Fantastic-roads225/tree/main/src) directory.
        - data225.cpp: file that processes and cleans the road network dataset -- also constructs the adjacency matrix with that data.
        - Graph.h/Graph.cpp: contains Graph class and functions for adding/removing edges, and BFS, Dijkstra's and Pagerank algorithms.
        - Utils.cpp/Utils.h: contains algorithms not related to graph class that allowed us to run tests on the adjacency matrix and simple BFS/Dijkstra's tests.
    - Test cases are located in the [./tests](https://github.com/Mankeerat/Fantastic-roads225/tree/main/tests) directory.
    - Test data is stored as a .txt file in the [./tests/data](https://github.com/Mankeerat/Fantastic-roads225/tree/main/tests/data) directory.
    - Team Contract, Project Proposal, Results, and Development Logs can be found in the [./documents](https://github.com/Mankeerat/Fantastic-roads225/tree/main/documents) directory.
        
- Running Instructions:
    -Make sure you are running the program in [Docker](https://courses.engr.illinois.edu/cs225/fa2022/resources/own-machine/).
    - First, using the link above, download the 10k generated adjacency matrix (to save time), and import the file into the tests/data directory (same          directory as "data_10k.txt". *IMPORTANT*. Without this, program will fail to run. 
    - Our project uses CMake and requires you to build your own custom makefiles to compile the program.
    - To do this, run mkdir in the base directory of the project to create a new build directory.
    - Inside of this directory, run cmake .. to create the files needed to setup the program.
    - You can run and compile the program in this build directory going forward.
    - To run main, run make and ./main and follow the instructions given in main to run our Fantastic-Roads225 Program!
        - When running, you will receive different prompts. You will be asked your location, as well as desired destination (Examples will be given if you would like to use them, as well as a valid range of vertices). You will then be prompted to input a number, 1-3 based on your preferred route-- (BFS) least nodes (Cities) passed through, (Dijkstra) shorted distance, (Pagerank) best possible route given all data. You will then receive the output to the chosen algorithm based on the user's preffered route, and you can "proceed" down this route.
    - To run test cases, run make test and ./test. You can run specific test cases by typing the name of the test case along with ./test.
    
- Team: FinalFinishers2022:
    - David Lacayo
    - Mankeerat Singh Sidhu
    - Jason Hu
