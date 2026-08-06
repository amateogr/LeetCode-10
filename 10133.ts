function cloneGraph(node: Node | null, map = new Map<Node, Node>()): Node | null {
    if (!node) return null;
    if (map.has(node)) return map.get(node)!;
    const copy = new Node(node.val);
    map.set(node, copy);
    for (const neighbor of node.neighbors) {
        copy.neighbors.push(map.get(neighbor) || cloneGraph(neighbor, map)!);
    }
    return copy;
}