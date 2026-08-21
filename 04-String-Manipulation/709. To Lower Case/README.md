<h2><a href="https://leetcode.com/problems/to-lower-case">709. To Lower Case</a></h2>

<p>Given a string <code>s</code>, return <em>the string after replacing every uppercase letter with the same lowercase letter</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "Hello"
<strong>Output:</strong> "hello"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "here"
<strong>Output:</strong> "here"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "LOVELY"
<strong>Output:</strong> "lovely"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of printable ASCII characters.</li>
</ul>


---

# 🛍️ To-Lower-Case | Explained

## Approach 1: ASCII Value Offset via Character Array Mutation

### Intuition
Think of uppercase and lowercase letters as two parallel rows of houses on a street. In the ASCII encoding scheme, the row of uppercase letters starts at address `65` (`'A'`) and ends at `90` (`'Z'`). The row of lowercase letters starts at address `97` (`'a'`) and ends at `122` (`'z'`). 

Notice the distance between any uppercase letter and its lowercase counterpart is always a fixed constant: $97 - 65 = 32$. Therefore, if you are standing at uppercase `'C'` (ASCII `67`), adding `32` transports you directly to lowercase `'c'` (ASCII `99`). Any non-uppercase characters (digits, symbols, already-lowercase letters) fall outside this designated uppercase range and are left untouched.


### Approach
1. **Traverse the Character Array**: Loop sequentially through each character of the input character array `ch` using index `i` from `0` to `ch.length - 1`.
2. **Range Check (Upper-Case Boundary)**: For each character `ch[i]`, evaluate whether its ASCII value lies within the closed interval `['A', 'Z']` (numerically `[65, 90]`).
3. **Apply ASCII Transformation**: If the condition holds true, add `32` to the character's ASCII value to find its lowercase equivalent. Cast the resulting integer back to a `char` and mutate `ch[i]` in place.
4. **Skip Unaffected Characters**: If `ch[i]` is not within the `['A', 'Z']` range, leave it unchanged.
5. **String Construction**: Once all characters have been processed, construct and return a new `String` object from the modified character array.

### Detailed Code Analysis

```java
for(int i = 0; i < ch.length; i++) {
```
- A standard counter-controlled loop iterates through indices `0` through `ch.length - 1`. 
- Using a primitive `char[]` enables direct mutable indexing, avoiding the overhead of generating intermediate immutable strings during transformation.

```java
    if(ch[i] >= 'A' && ch[i] <= 'Z')
```
- Java allows direct comparison between `char` primitives using their underlying 16-bit integer Unicode/ASCII values.
- `'A'` evaluates to `65` and `'Z'` evaluates to `90`. The logical `&&` ensures that only characters strictly inside the English uppercase alphabet trigger transformation. Non-alphabetical characters (e.g., `'@'`, `'1'`, `'!'`) and lowercase letters are safely bypassed.

```java
        ch[i] = (char)(ch[i] + 32);
```
- In Java, arithmetic operations on `char` values automatically promote the operands to 32-bit integers (`int`). Therefore, `ch[i] + 32` evaluates to an `int`.
- The explicit cast `(char)` truncates the resulting `int` back down to a 16-bit `char` before writing it back to index `i`.
- Mutating `ch[i]` directly in place minimizes auxiliary memory usage during iteration.

```java
return new String(ch);
```
- Strings in Java are immutable. To fulfill the method's return type contract (`String`), `new String(ch)` allocates a new `String` instance backed by a copy of the modified character array `ch`.

### Code

```java
class Solution {
    public String toLowerCase(String s) {
        char[] ch = s.toCharArray();
        for (int i = 0; i < ch.length; i++) {
            if (ch[i] >= 'A' && ch[i] <= 'Z') {
                ch[i] = (char)(ch[i] + 32);
            }
        }
        return new String(ch);
    }
}
```

### Complexity
- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `s`. The algorithm iterates through the array of length $N$ exactly once. Each character comparison, arithmetic addition, and in-place assignment executes in $\mathcal{O}(1)$ constant time. Constructing the final `String` also runs in $\mathcal{O}(N)$ time.
- **Space Complexity:** $\mathcal{O}(N)$ auxiliary space. Although the array mutation is done in-place, extracting `s.toCharArray()` and creating `new String(ch)` both allocate a buffer proportional to the length of the input string $N$ to adhere to Java's `String` immutability model.

---

## 🕵️‍♂️ Follow-up Questions

1. **Can we perform the transformation using bitwise operators instead of arithmetic addition?**
   - **Answer:** Yes. In binary, `'A'` is `01000001` ($65$) and `'a'` is `01100001` ($97$). The only difference between any uppercase ASCII letter and its lowercase counterpart is the $6^{\text{th}}$ bit (representing $2^5 = 32$). You can set the $6^{\text{th}}$ bit using the bitwise OR operator:
     ```java
     ch[i] = (char)(ch[i] | ' '); // or ch[i] = (char)(ch[i] | 32);
     ```
     Because the space character `' '` has an ASCII value of `32` (`00100000`), applying `ch[i] | ' '` directly flips uppercase characters to lowercase.

2. **How does this implementation compare to Java's built-in `String.toLowerCase()`?**
   - **Answer:** This manual ASCII-shift approach works only for the basic Latin alphabet (ASCII characters $0$–$127$). Java's built-in `toLowerCase()` method relies on the Unicode standard (`java.lang.CharacterDataLatin1` and `java.lang.Character`), which handles internationalization, locale mappings (such as the Turkish dotted/dotless `i`), and multi-byte surrogate pairs.
