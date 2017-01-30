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
package com.hackerrank;

import java.io.IOException;
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
// https://www.hackerrank.com/challenges/happy-ladybugs
public class HappyLadyBug extends Solution {

    public void solve() throws IOException {
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            in.nextInt();

            String s = in.next();
            boolean space = false;
            boolean bug = false;
            boolean happy = true;
            boolean pair = true;
            int[] letters = new int[26];
            Arrays.fill(letters, 0);
            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if (c == '_') {
                    space = true;
                } else {
                    bug = true;
                    letters[(int)c - (int)'A']++;

                    happy &= ((j > 0) && (s.charAt(j-1) == c)) ||
                             ((j < s.length()-1) && (s.charAt(j+1) == c));
                }
            }

            for (int j = 0; pair && (j < 26); j++) {
                pair = letters[j] != 1;
            }

            if (happy || !bug || (bug && space && pair)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
