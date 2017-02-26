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

public class MergeIntervals {
    private class Interval {
        int start;
        int end;
        Interval() { start = 0; end = 0; }
        Interval(int s, int e) { start = s; end = e; }

        @Override
        public String toString() {
            return "[" + start + "," + end + "]";
        }
    }

    private int binarySearch(int[] array, int value) {
        if (array.length == 0) {
            return 0;
        }

        int from = 0;
        int to = array.length-1;
        int mid = 0;

        while (from <= to) {
            mid = (to+from) >>> 1;
            if (array[mid] < value) {
                from = mid + 1;
            } else if (array[mid] > value) {
                to = mid - 1;
            } else {
                return mid;
            }
        }

        if (array[mid] > value) {
            return mid-1;
        } else {
            return mid;
        }
    }

    private boolean overlaps(Interval i1, Interval i2) {
        return !((i1.start > i2.end) || (i1.end < i2.start));
    }

    private Interval merge(Interval i1, Interval i2) {
        return new Interval(Math.min(i1.start, i2.start), Math.max(i1.end, i2.end));
    }

    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> result = new ArrayList<>();
        int size = intervals.size();
        int[] starts = new int[size];
        for (int i = 0; i < size; i++) {
            starts[i] = intervals.get(i).start;
        }

        int start_index = binarySearch(starts, newInterval.start);

        if (start_index >= size) {
            start_index = size - 1;
        }

        if (start_index < 0) {
            start_index = 0;
        }

        for (int i = 0; i < start_index; i++) {
            result.add(intervals.get(i));
        }

        Interval currentInterval = new Interval(newInterval.start, newInterval.end);
        int i;
        for (i = start_index; i < size; ++i) {
            if (overlaps(currentInterval, intervals.get(i))) {
                currentInterval = merge(currentInterval, intervals.get(i));
            } else if (intervals.get(i).start < currentInterval.start) {
                result.add(intervals.get(i));
            } else {
                break;
            }
        }

        if (i < size && intervals.get(i).start < currentInterval.start) {
            result.add(intervals.get(i));
            i++;
        }

        result.add(currentInterval);

        for (; i < size; ++i) {
            result.add(intervals.get(i));
        }

        return result;
    }
}
