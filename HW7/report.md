Arthur Hernandez Report aohernan

This is bomb 121.

It belongs to aohernan (aohernan@iu.edu)
phase 1:
Answer: All your base are belong to us.
Solving: For all phases, my inputs were calulated using rax and rdx. In this phase I used the address of rax to figure out that my input strings were being added and then
It is clear to tell that a string is being placed into address rsi and then checked for its equality to the input inside of the “strings not equal” function. This string,
All your base are belong to us., was what it was checking for. If this was not true the bomb would explode.

phase 2:
Answer: 0 1 2 6 16 44
Solving: Phase two was checking for 6 numbers. This was determined by the function “read six numbers” which contained the format for the input d d d d d d. After this the first
value contained inside address rsp was compared with 0. If this was not true the bomb would explode. That meant my first value would be 0. Rbp was then set to 1 being compared
to rbx which address contained my second input. This was added to itself right after entering a for loop telling me my third and fourth input would be 1 and 2. In the for loop
the main thing happening was value n and n+1 were being added together, and then that value was added to itself (multiplied by 2). This gave me my last 3 values 6, 16, and 44.

phase 3:
Answer: Hih/&Abdsq
Solving: This phase was without a doubt the most difficult for me. I could not use F8 to step through the instructions and so it was difficult to figure out that the value of
rdx would hold a different value before and after an xOR instruction. When stepping through and checking the value of rdx before being changed by the xOR function, I wrote down
the hex values 48 69 68 2f 26 41 62 64 73 and 71 which when checked in char using a ascii chart were Hih/&Abdsq, my answer.

phase 4:
Answer: 1 238
Solving: Using the red indicators on the right side of the assembly, I realized this phase contained a switch case. Just as in the second phase, rax (eax) address is being compared
to 1. This meant my first value would be 1. The scanf function showed my the format of my input had to be %d %d. Using this knowledge when stepping through proved useful. I also
notice rdx was being set to  0x56023e2c39e0, %rdx which was a0ee (238). This value was then being added to rax which was zeroed. This told me my switch case would go to the first
case and my second value would be 238.

phase 5 bonus:
Answer: 8 20
Solving: My scanf function showed me that my input would have to be %d %d.
At first, I thought that without one of my values being 7, a jump instruction would explode my bomb, then I realized that any scanned input would be compared eax and 7, but its
address value would always be set to 8, so I used 8 as my first number. After stepping through the sym.fun5 I would need to have a value equal to 20 in rax. Using any other
number would change rax to 63 (3f) inside the function but using 20 jumped right over it. That is why I choose 8 and 20 as my inputs and it worked!


