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

import java.util.ArrayList;

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
public class MaxNonNegativeSubArray {
    public ArrayList<Integer> maxset(ArrayList<Integer> a) {
        int current_from = -1;
        int to = 0;
        int from = a.size();
        long max_sum = 0;
        long current_sum = 0;
        ArrayList<Integer> answer = new ArrayList<>();

        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) < 0) {
                if (current_from != -1) {
                    if (current_sum > max_sum) {
                        from = current_from;
                        to = i;
                        max_sum = current_sum;
                    } else if (current_sum == max_sum && (to - from < i - current_from)) {
                        from = current_from;
                        to = i;
                    }

                    current_sum = 0;
                    current_from = -1;
                }
            } else {
                if (current_from == -1) {
                    current_from = i;
                    current_sum = a.get(i);
                } else {
                    current_sum +=a.get(i);
                }
            }
        }
        if (current_from != -1) {
            if (current_sum > max_sum) {
                from = current_from;
                to = a.size();
            } else if (current_sum == max_sum && (to-from < a.size() - current_from)) {
                from = current_from;
                to = a.size();
            }
        }

        for (int i = from; i < to; i++) {
            answer.add(a.get(i));
        }

        return answer;
    }
}
