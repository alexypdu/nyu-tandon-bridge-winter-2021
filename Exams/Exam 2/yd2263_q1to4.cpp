/* Name: Yun-Ping Du
 * NetID: yd2263
 *
 * === Question 1 ===
 *
 * Notes: Seems there is a typo in the question? I believe that the argument to be proved should be:
 *     for every positive integer n >= 6: a_n >= sqrt(2)^n
 * Since the first five elements in the Fibonacci sequence do not meet the inequality.
 *
 * Proof by strong induction on n.

 * Base case: n = 6 and n = 7. For n = 6, a_6 = 8 >= 8 = sqrt(2)^6. For n = 7, a_7 = 13 >= 8 * sqrt(2) = sqrt(2)^7.
 *
 * Inductive step: We will show that for k >= 7, if any positive integer in the range from 6 through k satisfies
 * a_k >= sqrt(2)^k, then a_{k+1} >= sqrt(2)^(k+1). We have
 *
 *     a_(k + 1)  = a_k + a_{k-1}                (by definition of a_n for n > 2)
 *               >= sqrt(2)^k + sqrt(2)^(k-1)    (by the inductive hypothesis)
 *                = (sqrt(2) + 1) * sqrt(2)^(k-1)
 *               >= 2 * sqrt(2)^(k-1)
 *                = sqrt(2)^2 * sqrt(2)^(k-1)
 *                = sqrt(2)^(k+1)
 *
 * Therefore a_{k+1} >= sqrt(2)^(k+1).
 *
 * === Question 2 ===
 *
 * a. C(10, 4) * 4! = 5040
 *
 * b. C(10, 4) = 210
 *
 * === Question 3 ===
 *
 * a. For X = 1, p(X = 1) = 1/2 * 1/2 = 1/4
 *    For X = 2, p(X = 1) = (1 - 1/4) * 1/4 = 3/16
 *    For X = 3, p(X = 3) = (1 - 1/4) * (1 - 1/4) * 1/4 = 9/64
 *    For X = 4, p(X = 4) = 1 - 1/4 - 3/16 - 9/64 = 27/64
 *    The distribution of X: {(1, 1/4), (2, 3/16), (3, 9/64), (4, 27/64)}
 *
 * b. E(X) = 1 * 1/4 + 2 * 3/16 + 3 * 9/64 + 4 * 27/64 = 175/64
 *
 * === Question 4 ===
 *
 * a) To analyze the asymptotic time complexity, we could first ignore those primitive operations
 *    before and after the for-loop since the running time of them are simply theta(1).
 *    Moreover, as the running time of the statement in the nested for-loop is also theta(1),
 *    we could simply examine the number of iterations of the inner loop.
 *    The number of iterations of the nested loop is: 1 + 2 + ... + log(n), a geometric series.
 *    First note that the number of terms is log(log(n)), and thus we have the sum:
 *
 *        [1 * (2^k - 1)] / (2 - 1) = 2^k - 1
 *
 *    where k denotes the number of terms, that is, log(log(n)). Therefore the sum is:
 *
 *        2^(log(log(n))) - 1 = log(n) - 1
 *
 *    Hence the asymptotic time complexity is: T(n) = theta(log(n)).
 *
 * b)
 *   1. Address of stack memory associated with the local variable 'arr' (in first10squares)
 *      is returned. The memory section is recycled automatically after the execution of the function.
 *      Thus the pointer `arr` in the main function points to memory locations with meaningless values.
 *
 *   2. Ben-El should allocate a dynamic array (heap memory) in the first line of the function first10squares,
 *      that is, `int* arr = new int[10];`, and keep everything else.
 */
