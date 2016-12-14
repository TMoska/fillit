Libft - TMoska [![Buld Status](https://travis-ci.org/TMoska/fillit.svg)](https://travis-ci.org/TMoska/fillit.svg?branch=master)
===

Algorithm project that uses backtracking technique to find a solution to a smallest possible map, given the tetrimino figures.
Goal is to arrange each tetrimino is such a way that (by priority):

1. Achieve the smallest map size
2. Tetriminos by order are as close to top left corner as possible

Tetriminos are not allowed to be rotated.

This projects has been a part of curriculum for [42 University](https://www.42.us.org) Fillit project.

Usage
---

```
git clone https://github.com/TMoska/fillit.git
cd fillit
make
./gen.py 7 > test.txt
./fillit test.txt
```

Input example
---
```
..##
..##
....
....

....
..##
..##
....

....
..##
...#
...#
```

Output example
---
```
AACC
AA.C
BB.C
BB..
```

Contributing
---

If you feel like contributing or adding new functions, feel free to submit a [Pull Request](https://github.com/TMoska/fillit/pulls).

License
---

MIT License

Copyright (c) 2016 Tomas Moska

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
