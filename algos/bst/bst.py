import random

class Node:
    def __init__(self, key=None):
        self.left = None
        self.right = None
        self.key = key

def insert(node, val):
    if node is None or root.key is None:
        return Node(val)
    if node.key == val:
        return node
    if val <= node.key:
        node.left = insert(node.left, val)
    else:
        node.right = insert(node.right, val)
    return node

def inorder(node):
    if node:
        inorder(node.left)
        print(node.key)
        inorder(node.right)

def search(node, val):
    if node is None or node.key == val:
        return node
    if val <= node.key:
        return search(node.left, val)
    return search(node.right, val)

def tree_min(node):
    while node.left:
        node = node.left
    return node

a = [random.randint(1, 20) for _ in range(20)]
print(a)
print()

root = Node()
for u in a:
    root = insert(root, u)

inorder(root)
print()

for i in range(10):
    x = random.randint(1, 20)
    print(x, search(root, x) is not None)
print()

print("tree_min: {}".format(tree_min(root).key))
