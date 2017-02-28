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
package com.hackerrank.arrays;

import com.hackerrank.Solution;

import java.io.IOException;

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
public class LeftRotation extends Solution {
    public void solve() throws IOException {
        int n = in.nextInt();
        int d = in.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            if (i >= d) {
                a[i-d] = in.nextInt();
            } else {
                a[n-d+i] = in.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(a[i]);
            System.out.print(' ');
        }
    }
}
