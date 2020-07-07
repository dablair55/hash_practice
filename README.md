# hash_practice
This was used to practice and better understand the functionality of hash tables. By hashing with chaining, I was able to avoid any collisions with data.

In order to speed up the deletion speed, I ended up implementing the hash table using double linked lists. Most of the code was built off of referencing GeeksforGeeks.

Because a large amount of the code came from another source however, I made sure to comment and talk through the various aspects in order to explain it to myself and gain an understanding.

Also, there were several edge cases that were missed (Remove would not say that element was not found if there was at least 1 element under that hash index for example)
by the GeeksforGeeks code, so I modified and improved upon it a bit in order to eliminate those edge cases.
