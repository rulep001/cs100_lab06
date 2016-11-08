# cs100_lab06 (Command Pattern)

In this lab we will build upon the composite class that you created in the 
composite and strategy lab to build a (very) simple calculator application. This
calculator will allow the user to do running total calculations (similar to a
simple phone calculator) with the additional function of allowing the user to undo
and redo commands that they have input. We will accomplish this by leveraging the
command pattern to create a history that we can write to, traverse, and overwrite
as necessary, and which will save the state of our calculation every time a new
operation is requested.  

Since this lab relies on a completed composite pattern, you have been provided with
an implementation of the composite pattern that you were to design. You may also
use your own composite classes if you would prefer.