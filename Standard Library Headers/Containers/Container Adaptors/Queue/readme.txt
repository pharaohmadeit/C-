Queue Adaptor <queue>

First-in, first-out (FIFO) data structure

Insertions only at the back and deletions only from the front
-push inserts an element at the back - calls underlying container's push_back
-emplace contructs an elements in place at the top
-pop removes the front element - calls underlying container's pop_front
-front gets a reference to front elements - calls underlying container's front
-back gets a reference to back element - calls underlying container's back
-empty determines whether the queue is empty - calls underlying container's empty
-size gets the number of elements - calls underlying container's size
