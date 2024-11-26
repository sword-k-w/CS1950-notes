# CS1950_LectureNote_10
###by **Yihan Zhu**
### Nov 19 2024

##**IBM 083**
###**Basic Principle**:**Radix sort**
###**Description of the process**:
Each time, the numbers are put into the corresponding bucket according to the value of the current digit, and the original relative order in each bucket remains unchanged. Then traverse the buckets of 0~9 and take out the numbers in each bucket (still keeping the original relative order unchanged) to form a new sequence of numbers.

##**The Rankdex Algorithm**
Like the hyperlink idea, the more books about A that point to it, the more relevant the book is to A; This is similar to maintaining an extradimensional space.


##**The Google PageRank Algorithm**

###**About Google**
The big innovation of the late 1990s is the development of search engines.
The heart of which is the **PageRank Algorithm**.
### **The PageRank Algorithm Introduction**
The PageRank algorithm gives each page a rating of its 
importance, which is a recursively defined measure whereby a page becomes important if important pages link to it.
###**Markov Processes**
Google’s random surfer is an example of a **Markov process**, in which a system moves from state to state, based on probability information that shows the likelihood of moving from each state to 
every other possible state. 
$\begin{bmatrix}
TodayTomorrow& sunny & windy & rainy\\
sunny & 0.85 &0.10 &0.05\\
cloudy & 0.60&0.25&0.15\\
rainy& 0.40& 0.40&0.20\\
\end{bmatrix}$
The above matrix shows a prediction of tomorrow's weather using the Markov Processes.

What if we repeat the same process for ten days?

$\begin{bmatrix}
TodayTen-dayLater& sunny & windy & rainy\\
sunny & 0.77 &0.14 &0.07\\
cloudy & 0.77&0.14&0.07\\
rainy& 0.77& 0.14&0.07\\
\end{bmatrix}$
I think what it shows beyond maths calculation is that after ten days the prediction of weather became unclear.
###**The Page Rank Algorithm**
step1.Start with a set of pages

step2.Crawl the web to determine the link structure.

step3. Assign each page an initial rank of 1 / N.

step4.Successively update the rank of each page by adding up the weight of every page that links to it divided by the number of links emanating from the referring page. 
**Example:**
•  Page $\mathbf{E}$ has two incoming links, one from page $\mathbf{C}$ and one from page $\mathbf{D}$. 
• Page C contributes 1/3 of its current page rank to page $\mathbf{E}$ because $\mathbf{E}$ is one of three links from page $\mathbf{C}$. Similarly, page $\mathbf{D}$ offers 1/2 of its rank to $\mathbf{E}$.
• The new page rank for E is PR($\mathbf{E}$) = $\frac{PR(\mathbf{C})}{3}$+$\frac{PR(\mathbf{D})}{2}$ = $\frac{0.2}{3}$+$\frac{0.2}{2}$ = 0.17

And we can get a formula:
$$
R(i)=\sum\frac{1}{d(k)}R(k)
$$
(d(k) is a node k out of degree.)

step5.If a page (such as E in the current example) has no outward links, redistribute its rank equally among the other pages in the graph.

step6.Apply this redistribution to every page in the graph.

step7.Repeat this process until the page ranks stabilize.

step8.In practice, the Page Rank algorithm adds a damping factor at each stage to model the fact that users stop searching.

###**Perhaps a faster way of calculation**
We can use Gaussian elimination ,but it's too slow.In fact,the result of the previous operation is **copied first**, and then the adjustment is made continuously. Prioritize "key elements" with larger R(i) because their adjustments have a greater impact on other elements.




