
## Problem Description 


### Part 1

In this problem, you are asked to write a program makeSVG.cppthat creates a scalable vector graphics (svg) file with shapes based on inputread from standard input. Ansvg file can be visualized using a browser such as Firefox, Safari, Chrome or Internet Explorer. See [https://en.wikipedia.org/wiki/Scalable_Vector_Graphics](https://en.wikipedia.org/wiki/Scalable_Vector_Graphics).

### Part 2

In this problem, you are asked to implement a program (named checkpack) that, given a rectangular domain and a list of circles and rectangles, can check if the packing configuration is valid, in the sense that all shapes fit within the domain and there are no overlaps between shapes. This problem occurs e.g. in electronic device design when packing electronic components on a printed circuit board.

The program should create a visual representation of the domain and shapes as a scalable vector graphics (svg) file. 

The positions and sizes of the shapes are specified using integers. The domainis a rectangleof fixed size (600x500).Circles of arbitrary position and radius are read from standard input.Rectangles of arbitrary position and sizes are read from input.Circles and Rectangles can appear in any order in the input.

The program should writeon standard outputthe svg representation ofall the shapes, and includein addition the following diagnostic message:
- `ok` if the configuration is valid, i.e. all shapes fit in the domain and there are no overlaps between shapes. 
- `overlap` if the shapes fit in the domain but some of the shapes overlap 
- `does not fit`if any of the shapes does not fit in the domain.
If some shapes overlap and some shapes do not fit, the program should only print `does not fit`