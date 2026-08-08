class PeekingIterator
    def initialize(iterator)
        @iterator = iterator
        @has_next = @iterator.hasNext
        @next_element = @has_next ? @iterator.next : nil
    end

    def peek
        @next_element
    end

    def next
        res = @next_element
        @has_next = @iterator.hasNext
        @next_element = @has_next ? @iterator.next : nil
        res
    end

    def has_next
        @has_next
    end
    alias hasNext has_next
end