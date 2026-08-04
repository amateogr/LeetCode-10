def my_atoi(s)
    s = s.lstrip
    return 0 if s.empty?
    
    sign = 1
    i = 0
    if s[0] == '-'
        sign = -1
        i += 1
    elsif s[0] == '+'
        i += 1
    end
    
    result = 0
    while i < s.length && s[i] >= '0' && s[i] <= '9'
        result = result * 10 + (s[i].ord - '0'.ord)
        i += 1
    end
    
    result *= sign
    
    int_min = -2147483648
    int_max = 2147483647
    
    if result < int_min
        int_min
    elsif result > int_max
        int_max
    else
        result
    end
end