# Introduction to Homework2 of Algorithm
> Author : 大祥  
> StartTime: 2017-06-23 ，ModifyTime：2017-06-23

## Requirement
**Dynamic programming**
**Chap 15-2 Longest palindrome subsequence**

A palindrome is a nonempty string over some alphabet that reads the same forward and backward. Examples of palindromes are all strings of length 1, civic, racecar, and aibohphobia (fear of palindromes). Give an efficient algorithm to find the longest palindrome that is a subsequence of a given input string. For example, given the input character, your algorithm should return carac.

給定字串，請找出其中最長且是迴文的子序列及其長度，字串由連續字符、字母或數字所組成，且其給定字串長度不會超過1000。
螢幕輸入:
輸入測資的第一行(N)為測資個數，代表接下來會有N筆給定字串，每筆測資為一行。

螢幕輸出:
待輸入測資讀取結束後再輸出結果。每筆測資用兩行輸出答案，第一行輸出子序列最長迴文長度，第二行輸出最長迴文子序列。請勿輸出任何其他文字或符號等。

## Test Example
螢幕輸入:   
2    
514a3ab1    
61bca7a8sb6  

螢幕輸出:  
5  
1a3a1  
7  
6ba7ab6  

## Introduction to My Program code
### a.此程式所使用之邏輯、原理及語言之概要性說明
题目要求是找出一个 string 的 longest palindrome subsequence, 但是我们现在已经学过如何找出两个 string 的 longest common subsequence。

所以我们变换思路,只需要把原来的字符串逆序排列成新的 string,再把它和原序 string 做比较,找出它们的 longest common subsequence,也就等同于找出了题目要求的 longest palindrome subsequence。

### b.程式內容細部說明(程式碼及其註解),可配合流程圖解說
main 方法里面获取输入的 string array 后,call findLCS function 去实际执行操作。
findLCS function 用 for 循环对每个 string 做查找 longest palindrome
subsequence。

具体查找时:
通过 reverseString() 得到一个新的逆序 string。
通过 findLCSInTwoSequence() 建立一个保存了每个字符比对后是否增加了
longest palindrome subsequence 结果的 table 以及该字符的 index。

然后通过 createLCS(),根据之前建构的 table 创建出该 string 的 longest
palindrome subsequence。

最后返回到 findLCS 中,print 之前所有操作后得到的 longest palindrome
subsequence。
