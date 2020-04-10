The main program has two uses: 

arg1 = true; arg2 = input _ {number of movies} _ {"ordered" OR "random"}.csv; arg3 = {movie prefix}

This will return a list of pre-ordered movies from the binary search tree. Each movie name is listed with
its rating, and the number of nodes visited in the BST to arrive at that movie's node. This is followed by
a line displaying the highest rated movie with the prefix given in arg3.

arg1 = false; arg2 = input _ {number of movies} _ {"ordered" or "random"}.csv; arg3 = {number of movies}

This usage was used in order to find the average search times for the BST. This data can be found in the 
file pa02_sbaweja.pdf. The data charts nodes visited (y axis) to arrive at the node number (x axis). The graphs 
depict a logarithmic trendline when the runtime analysis is done on the input file with the movies in random 
order, and a linear line when the input file has the movies in order. The reason for this is ordered movie list 
places each successive movie in only the right node of the previous node, thus only being ass effective as a 
linked list rather than a tree. 
