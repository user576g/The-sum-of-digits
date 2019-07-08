# The-sum-of-digits
This is the solution of a task, proposed Google company on a interview.

On interview.dots.org.ua Google public such problem:
https://github.com/user576g/The-sum-of-digits/blob/master/problem.JPG

To solve this problem first I wrote program that summarise digits of all numbers from range.
You can compile source code of this program from file calcAllSum.cpp and use it for small range. 
When I upload this solution to check out I get time limit (TL).
This solution very slow for big ranges (try to get sum for range from 0 to 1000000000000).

So, I started to consider basic ranges and note that sum from 0 to 9 is 45, from 0 to 99 is 900 and so on.
Using this numbers we faster calculate sum. For example, if we need to calculaate sum from 10 to 20 we can use formula:
1*10 + 45 it will be number 19 and sum of digits of number 20 is + 2. So sum from 10 to 20 is 57.
from 200 to 300 we can use formula:
2*100 + 900 it will be number 299 and sum of digits of number 300 is +3. So sum from 200 to 300 is 1103.

Using these properties of number ranges, I wrote second program, that calculate sum more faster.
Source code this program is in file fastSum.cpp Compile it and try to get sum for range from 0 to 1000000000000.
Is it more faster than first program, isn't?

So, this problem is good example how we can create more better algorithms using mathematical and logic methods.
https://github.com/user576g/The-sum-of-digits/blob/master/solved!.JPG
