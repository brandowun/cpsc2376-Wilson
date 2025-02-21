for (int i = start; i < end; i++) { // Bug: Off-by-one error
(< end) is neglecting the last part but not end itself,
the fix will be to add = and make it <= end to ensure it covers end

ContainsNegative
so for  (size_t i = 0; i <= numbers.size(); i++) {
I removed the = from <=. This forces it out of the index. 
It causes random data to be used. 

The second line i had to add to change the greater than sign from > to <.
This was checking postivies instead of negatives
This was causing the bool to return true for positive numbers. 