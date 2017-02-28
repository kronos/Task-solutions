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
package com.hackerrank.trees;

import com.hackerrank.Solution;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

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
public class IsThisaBinarySearchTree extends Solution {
    class Node {
        int data;
        Node left;
        Node right;
    }

    public boolean checkBST(Node root) {
        Set<Integer> was = new HashSet<>();
        if (root != null) {
            was.add(root.data);
        }

        return (root != null) &&
               check(root.left, Integer.MIN_VALUE, root.data, was) &&
                check(root.right, root.data, Integer.MAX_VALUE, was);
    }

    private boolean check(Node root, int from, int to, Set<Integer> was) {
        boolean bst = root == null;
        if (!bst) {
            if (!was.contains(root.data)) {
                was.add(root.data);
                bst = (root.data > from) && (root.data < to) &&
                      check(root.left, from ,root.data, was) &&
                      check(root.right, root.data, to, was);
            }
        }
        return bst;
    }
}
