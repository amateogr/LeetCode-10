class MedianFinder
    def initialize
        @max_heap = []
        @min_heap = []
    end

    def add_num(num)
        if @max_heap.empty? || num <= -@max_heap[0]
            push(@max_heap, -num)
        else
            push(@min_heap, num)
        end

        if @max_heap.size > @min_heap.size + 1
            push(@min_heap, -pop(@max_heap))
        elsif @min_heap.size > @max_heap.size
            push(@max_heap, -pop(@min_heap))
        end
    end

    def find_median
        if @max_heap.size > @min_heap.size
            -@max_heap[0].to_f
        else
            (-@max_heap[0] + @min_heap[0]) / 2.0
        end
    end

    alias_method :addNum, :add_num
    alias_method :findMedian, :find_median

    private

    def push(heap, val)
        heap << val
        i = heap.size - 1
        while i > 0
            p = (i - 1) / 2
            break if heap[p] <= heap[i]
            heap[p], heap[i] = heap[i], heap[p]
            i = p
        end
    end

    def pop(heap)
        val = heap[0]
        last = heap.pop
        unless heap.empty?
            heap[0] = last
            i = 0
            n = heap.size
            while (l = 2 * i + 1) < n
                smallest = l
                r = l + 1
                smallest = r if r < n && heap[r] < heap[l]
                break if heap[i] <= heap[smallest]
                heap[i], heap[smallest] = heap[smallest], heap[i]
                i = smallest
            end
        end
        val
    end
end