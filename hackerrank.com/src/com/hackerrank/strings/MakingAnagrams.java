/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ivan Samsonov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
package com.hackerrank.strings;

import com.hackerrank.Solution;

import java.util.Arrays;

/**
 * An ${Name} class.
 * 
 * <p>
 * Description
 * </p>
 * 
 * @author Ivan Samsonov (hronya@gmail.com) 
 * @since 1.0.0
 *
 */
public class MakingAnagrams extends Solution {
    public void solve() {
        int A = (int)'a';
        String a = in.next();
        String b = in.next();
        int[] a_chars = new int[26];
        int[] b_chars = new int[26];
        int answer = 0;

        Arrays.fill(a_chars, 0);
        Arrays.fill(b_chars, 0);

        for (int i = 0; i < a.length(); i++) {
            a_chars[(int)a.charAt(i)-A]++;
        }

        for (int i = 0; i < b.length(); i++) {
            b_chars[(int)b.charAt(i)-A]++;
        }

        for (int i = 0; i < 26; i++) {
            answer += Math.abs(a_chars[i] - b_chars[i]);
        }
        System.out.println(answer);
    }
}
