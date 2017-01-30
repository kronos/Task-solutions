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
package com.interviewbit;

import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

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
public class FindDuplicateInArray {
    public int repeatedNumber(final List<Integer> a) {
        int answer = -1;
        Set<Integer> set = new TreeSet<>();
        int length = a.size();
        int square = (int)Math.sqrt(length);
        int index = 0;
        int size = length / square;
        int[] counts = new int[size+1];
        int mod = length % size;
        Arrays.fill(counts, 0);
        for (Integer e: a) {
            index = e / square;
            if (e % square == 0) {
                index--;
            }

            counts[index]++;

            if ((counts[index] > square) || (mod > 0 && index == size && counts[index] >= mod)) {
                break;
            }
        }

        for (Integer e : a) {
            int q = e / square;
            if (e % square == 0) {
                q--;
            }
            if (q == index) {
                if (set.contains(e)) {
                    answer = e;
                    break;
                } else {
                    set.add(e);
                }
            }
        }

        return answer;
    }
}
