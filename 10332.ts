function findItinerary(tickets: string[][]): string[] {
    const map = new Map<string, string[]>();
    for (const [from, to] of tickets) {
        if (!map.has(from)) map.set(from, []);
        map.get(from)!.push(to);
    }
    for (const targets of map.values()) {
        targets.sort((a, b) => b.localeCompare(a));
    }
    const result: string[] = [];
    const dfs = (curr: string) => {
        const neighbors = map.get(curr);
        while (neighbors && neighbors.length > 0) {
            dfs(neighbors.pop()!);
        }
        result.push(curr);
    };
    dfs("JFK");
    return result.reverse();
}