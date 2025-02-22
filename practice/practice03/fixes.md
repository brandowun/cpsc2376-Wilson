SumRange
for (int i = start; i < end; i++) { // Bug: Off-by-one error
Fix: the fix will be to add = and make it <= end to ensure it covers end
issue: (< end) is neglecting the last part but not end itself,




ContainsNegative
so for  (size_t i = 0; i <= numbers.size(); i++) {
Fix: I removed the = from <=. This forces it out of the index. 
Issue: It causes random data to be used. 

if (numbers[i] > 0) { // Bug
Fix: i had to add to change the greater than sign from > to <.
Issue: This was checking postives instead of negatives, causing the bool to return true for positive numbers. 





for findMax
for (size_t i = 1; i <= numbers.size(); i++) { // Bug
FIX: So the fix is changing it to just < numbers.size(), it will stay inside the range.
Issue: the issue is with i<=numbers.size(), and the range is from 0 to number.size(), it causes it to outside.

if (numbers[i] >= maxVal) { // Bug
Fix: turn it into > maxVal making it only update if it's greater than maxVal
Issue: the bug here is >= maxVal, meaning it's updating the maxvalue even if numbers is = maxValue. Doesn't
cause huge issue besides just being useless work. 

