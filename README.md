Relax-Tools
===========

Relax Tools is a tool box with easy to use classes for Random, String, Socket and FileSystem ...


Well, all those classes can be improved and optimized ... but I'll do it when I'll need to.


+--------------+
| RxWinFs v1.0 |
+--------------+
- Only available on Windows.
- Missing a HardDeleteADir() function to recursively delete a directory.

+---------------+
| RxRandom v1.1 |
+---------------+
	== Corrected on version 1.1 ==
- Can now roll between 0 and 1.
- Can now pass parameter in any order (max, min) or (min, max).

(todo)
- Missing a function to random between two signed numbers.
- Missing a function to random between two floats / doubles.

+----------------+
| RxWinSock v1.0 |
+----------------+
- Only available on windows.

+---------------+
| RxString v1.1 |
+---------------+
  == Corrected on version 1.1 == 
- Useless RemoveSeparator() function.

  == Version 1.0 ==
- (todo ..) Modify Split() so it can take multiple separators, like Split(const char*);

+-------------+
| RxTime v1.1 |
+-------------+
  == Corrected on version 1.1 ==
- Now used gettimeofday() instead of clock() so it works even with threads.
