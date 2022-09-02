1. <br />
<br />
[aohernan@silo LAB3]$ gcc -Werror multiThreads.c -o mt -lpthread<br />
[aohernan@silo LAB3]$ ./mt clickstream-enwiki-2019-09.tsv football enwik9 username<br />
(First thread)Time spent in thread: 2.640000 substring: username count: 411058<br />
(Second thread)Time spent in thread: 3.770000 substring: football count: 452566<br />
Time spent in main thread: 3.770000<br />
<br />
2. <br />
<br />
The main thread spent the exact amount of time my second thread spent. At first I thought this<br />
had to be incorrect but remembered threads of a same process share their address space <br />
bringing both the second thread and main thread.<br />
<br />
3.<br />
<br />
[aohernan@silo HW1]$ gcc -o singleThread singleThread.c <br />
[aohernan@silo HW1]$ ./singleThread clickstream-enwiki-2019-09.tsv football enwik9 username<br />
File One : clickstream-enwiki-2019-09.tsv <br />
Substring One: football <br />
count: 452566 <br />
File Two: enwik9 <br />
Substring Two: username<br /> 
count: 383595 <br />
Time spent in thread: 3.530000<br />
<br />
The time spent in the single thread implementation in homework one actually took less time than <br />
multi-threading. Although this may be true it does not mean single threading is more efficient <br />
to code or exicute<br />
<br />
4. <br />
<br />
We can’t guarantee the execution order of threads.
