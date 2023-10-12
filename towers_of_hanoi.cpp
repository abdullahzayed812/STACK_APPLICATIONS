
/*
  - Write a computer function that writes down the steps
    needed to move disks from tower 1 to 3 using tower 2
    with the restrictions that:

    1- Only one disk should be removed at a time.
    2- No disk should be placed on top of a smaller disk.

    - The call of this function will be e.g. MoveDisks(7, 1, 3, 2).

  - Solutions:

    1- To move the largest disk from 1 to 3, we have to
       move the all others from 1 to 2.
    2- Move the largest disk from 1 to 3.
    3- Move all others from 2 to 3.

    Then the solutions is:
    MoveDisks(6, 1, 2, 3);
    "Move disk 7 from 1 to 3";
    MoveDisks(6, 2, 3, 1);

    - This is the idea of recursion: define the base step
       and do the same thing again.

    - This is the same concept of divide and conquer, To solve a problem
      split it into a smaller and smaller part.

    - Every recursive process consists of two parts.
      1- A smallest, base case that is processed without recursion.
      2- A general method that reduces a particular case to one or more
          of the  smaller case.
*/
#include <iostream>

using std::cout;

void MoveDisks(int count, int start, int finish, int temp);

void MoveDisks(int count, int start, int finish, int temp) {
  if (count > 0) {
    MoveDisks(count - 1, start, temp, finish);
    cout << "Move disk " << count << " from " << start << " to " << finish << "\n";
    MoveDisks(count - 1, temp, finish, start);
  }
}

int main() {
  MoveDisks(3, 1, 3, 2);
  return 0;
}