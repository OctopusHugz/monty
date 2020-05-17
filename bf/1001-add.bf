,>,					Store numbers in cells 1 and 2
[<+>-]				Add cell 2 to cell 1 until cell 2 is 0
<					Move back to cell 1

> ++++++			Set counter cell 2 value to 6
[
	<----- ---		Decrement cell 1 value by 8
	>-				Decrement counter cell 2 by 1
]
<.					Print sum
