# CS1950_LectureNote_10

### Nov 19 2024

**IBM 083**<br>
**Basic Principle**:**Radix sort**<br>
**Description of the process**:<br>
Each time, the numbers are put into the corresponding bucket according to the value of the current digit, and the original relative order in each bucket remains unchanged. Then traverse the buckets of 0~9 and take out the numbers in each bucket (still keeping the original relative order unchanged) to form a new sequence of numbers.

**The Rankdex Algorithm**<br>
Like the hyperlink idea, the more books about A that point to it, the more relevant the book is to A; This is similar to maintaining an extradimensional space.


**The Google PageRank Algorithm**<br>

**About Google**<br>
The big innovation of the late 1990s is the development of search engines.
The heart of which is the **PageRank Algorithm**.<br>
**The PageRank Algorithm Introduction**<br>
The PageRank algorithm gives each page a rating of its 
importance, which is a recursively defined measure whereby a page becomes important if important pages link to it.<br>
**Markov Processes**<br>
Google’s random surfer is an example of a **Markov process**, in which a system moves from state to state, based on probability information that shows the likelihood of moving from each state to 
every other possible state. 

<br>**The Page Rank Algorithm**<br>
step1.Start with a set of pages

step2.Crawl the web to determine the link structure.

step3. Assign each page an initial rank of 1 / N.

step4.Successively update the rank of each page by adding up the weight of every page that links to it divided by the number of links emanating from the referring page. <br>
**Example:**<br>
•  Page $\mathbf{E}$ has two incoming links, one from page $\mathbf{C}$ and one from page $\mathbf{D}$.<br> 
• Page C contributes 1/3 of its current page rank to page $\mathbf{E}$ because $\mathbf{E}$ is one of three links from page $\mathbf{C}$. Similarly, page $\mathbf{D}$ offers 1/2 of its rank to $\mathbf{E}$.<br>
• The new page rank for E is PR($\mathbf{E}$) = $$\frac{PR(\mathbf{C})}{3}+\frac{PR(\mathbf{D})}{2} = \frac{0.2}{3}+\frac{0.2}{2}$$ = 0.17<br>

And we can get a formula:<br>
$$R(i)=\sum\frac{1}{d(k)}R(k)$$<br>
(d(k) is a node k out of degree.)

step5.If a page (such as E in the current example) has no outward links, redistribute its rank equally among the other pages in the graph.

step6.Apply this redistribution to every page in the graph.

step7.Repeat this process until the page ranks stabilize.

step8.In practice, the Page Rank algorithm adds a damping factor at each stage to model the fact that users stop searching.

<br>**Perhaps a faster way of calculation**<br>
We can use Gaussian elimination ,but it's too slow.In fact,the result of the previous operation is **copied first**, and then the adjustment is made continuously. Prioritize "key elements" with larger R(i) because their adjustments have a greater impact on other elements.




