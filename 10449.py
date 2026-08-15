import struct

class Codec:
    def serialize(self, root):
        res = bytearray()
        def preorder(node):
            if node:
                res.extend(struct.pack('<H', node.val))
                preorder(node.left)
                preorder(node.right)
        preorder(root)
        return res.decode('latin1')

    def deserialize(self, data):
        b = data.encode('latin1')
        vals = struct.unpack(f'<{len(b)//2}H', b) if b else ()
        i = 0
        def build(min_val, max_val):
            nonlocal i
            if i >= len(vals):
                return None
            val = vals[i]
            if not (min_val < val < max_val):
                return None
            i += 1
            node = TreeNode(val)
            node.left = build(min_val, val)
            node.right = build(val, max_val)
            return node
        return build(-1, 10001)