[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/alex-87/mokitu-solver?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

Mokitu Solver
=============

  This software is a Mokitu Solver and Builder. The Mokitu (Sudoku with letters) is solved using the constraints programming concept. __This is a school project__, for the Master's degree in Computer Sciences.

Libraries
----------

  This project needs [wxWidgets 3](http://www.wxwidgets.org/ "wxWidgets"), and the constraint solver [Gecode 4.2.1](http://www.gecode.org/ "Gecode").
  
Compilation
-----------

  For Linux, the commandline compilation is `make MokituSolver`.

Launching
---------

  The parameters are `<nbRow>` for the number of rows, and `<nbCols>`, the second parameter, for the number of columns. For example, `./MokituSolver 2 4` will create the interface with a `(2 x 4) x (2 x 4)` grid.

License
-------

  This project is under the [MIT License](https://github.com/alex-87/mokitu-solver/blob/master/LICENSE).
