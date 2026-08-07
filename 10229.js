function majorityElement(nums) {
    let count1 = 0;
    let count2 = 0;
    let cand1 = null;
    let cand2 = null;

    for (const num of nums) {
        if (num === cand1) {
            count1++;
        } else if (num === cand2) {
            count2++;
        } else if (count1 === 0) {
            cand1 = num;
            count1 = 1;
        } else if (count2 === 0) {
            cand2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (const num of nums) {
        if (num === cand1) {
            count1++;
        } else if (num === cand2) {
            count2++;
        }
    }

    const result = [];
    const threshold = Math.floor(nums.length / 3);
    if (count1 > threshold) result.push(cand1);
    if (count2 > threshold) result.push(cand2);
    return result;
}