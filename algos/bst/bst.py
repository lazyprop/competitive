import random

class Node:
    def __init__(self, val=None):
        self.left = None
        self.right = None
        self.val = val

def insert(node, val):
    if node.val:
        print(node.val, id(node))
    if node.val is None:
        node.val = val
    elif val < node.val:
        node.left = node.left or Node()
        insert(node.left, val)
    else:
        node.right = node.right or Node()
        insert(node.right, val)


def remove(node, val, par=None):
    if node is None:
        return
    if val < node.val:
        remove(node.left, val, node)
    elif val > node.val:
        remove(node.right, val, node)
    else:
        # case: no children
        if node.left is None and node.right is None:
            remove_from_par(node, par)

        # case: two children
        elif node.left and node.right:
            succ = node.right
            succ_par = node
            while succ.left:
                succ_par = succ
                succ = succ.left
            node.val = succ.val
            remove(succ, succ.val, succ_par)
        
        # case: only left
        elif node.left:
            node.val = node.left.val
            remove_from_par(node.left, node)

        # case: only right
        else:
            node.val = node.right.val
            remove_from_par(node.right, node)

def remove_from_par(node, par):
    if par.left and node == par.left:
        par.left = None
    else:
        par.right = None


def preorder(node):
    if node is None:
        return
    preorder(node.left)
    print(node.val)
    preorder(node.right)


n = 10
a = [random.randint(1, 20) for _ in range(n)]
root = Node()

for u in a:
    insert(root, u)

preorder(root)

for _ in range(3):
    x = random.choice(a)
    print("removing", x)
    remove(root, x)
    a.remove(x)

preorder(root)
